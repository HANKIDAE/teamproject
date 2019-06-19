
// OpDoc.cpp : COpDoc Ŭ������ ����
//
#include <windows.h>
#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Op.h"
#endif

#include "OpDoc.h"
#include "mythread.h"

#include <propkey.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// COpDoc

IMPLEMENT_DYNCREATE(COpDoc, CDocument)

BEGIN_MESSAGE_MAP(COpDoc, CDocument)
END_MESSAGE_MAP()


// COpDoc ����/�Ҹ�

COpDoc::COpDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
	//initialize();
}

COpDoc::~COpDoc()
{
}

BOOL COpDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// COpDoc serialization

void COpDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void COpDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void COpDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void COpDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// COpDoc ����

#ifdef _DEBUG
void COpDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COpDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


void COpDoc::initialize() {
	struct shm_remove
	{
		shm_remove() { shared_memory_object::remove("ODSharedMemory"); }
		~shm_remove() { shared_memory_object::remove("ODSharedMemory"); }
	} remover;//
			  //declare var

	do {
		t.cam.vc.open("EXID.mp4");
		std::cout << "Try VideoCapture Open" << std::endl << std::endl;
	} while (!t.cam.vc.isOpened());

	t.cam.vc >> t.cam.image;

	//parameter check
	nchs = t.cam.image.channels();
	std::cout << "\tchannel:" << nchs << std::endl;

	/*if (nchs != 3 && nchs != 4) {
	t.cam.vc.release();
	getchar();
	return 101;
	}// rgb
	*/
	int dsz = t.cam.image.rows * t.cam.image.step;

	//Create a new segment with given name and size
	managed_shared_memory segment(create_only, "ODSharedMemory", dsz * 20);

	//allocation 
	t.od = (odi*)segment.allocate(sizeof(odi));
	assert(t.od != NULL);

	//set image size
	t.od->dsz = dsz;
	t.od->iHeight = t.cam.image.size().height;
	t.od->iWidth = t.cam.image.size().width;

	std::cout << " od dsz   : " << t.od->dsz << std::endl;

	// check allocation , SIB
	assert(&t.od->SIBimage != NULL);

	//SIB allocation, get handle
	for (int i = 0; i < 2; i++) {
		t.od->SIBimage[i]._pMem = segment.allocate(dsz * 3);
		assert(&t.od->SIBimage[i]._pMem != NULL);
		t.od->SIBimage[i]._hMem = segment.get_handle_from_address(t.od->SIBimage[i]._pMem);
		assert(&t.od->SIBimage[i]._hMem != NULL);
	}
	//initial data copy
	memcpy(t.od->SIBimage[0]._pMem, t.cam.image.data, dsz);
	memcpy(t.od->SIBimage[1]._pMem, t.cam.image.data, dsz);

	// get handle
	managed_shared_memory::handle_t handle = segment.get_handle_from_address(t.od);

	//execute
	//std::stringstream s;
	char odc_fn[] = "MFCodclient.exe";

	s << odc_fn << " " << handle << " " << t.od << std::ends;
	std::cout << "Main cmd: " << s.str() << std::endl;

	//for ODector, initial parameter setting
	t.od->nDetections = 0;
	t.od->init_flag = false;
	t.od->index = 0;
	t.od->frame_full = false;
	t.od->ready_flag = false;
	t.od->run_flag = false;

	//AfxMessageBox(_T("�ʱ�ȭ �Ϸ�"));

	std::cout << "\t\tinitialize od\n";



	std::thread p1(program_thread, std::ref(s));
	//p1 = std::thread(program_thread, std::ref(s));

	while (!t.od->init_flag) boost::detail::Sleep(100);

	//p2 = std::thread(_camera, std::ref(t));
	std::thread p2(_camera, std::ref(t));

	//p3 = std::thread(_run, std::ref(t));
	std::thread p3(_run, std::ref(t));
}

void COpDoc::done()
{
	//p1.detach();
	//p2.detach();
	//p3.detach();
}
