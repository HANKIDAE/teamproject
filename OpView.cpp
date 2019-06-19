
// OpView.cpp : COpView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Op.h"
#endif

#include "OpDoc.h"
#include "OpView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COpView

IMPLEMENT_DYNCREATE(COpView, CView)

BEGIN_MESSAGE_MAP(COpView, CView)
	ON_WM_CREATE()
	ON_BN_CLICKED(101, OnButtonClicked)
	ON_BN_CLICKED(102, OnButtonClicked2)
END_MESSAGE_MAP()

// COpView ����/�Ҹ�

COpView::COpView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

COpView::~COpView()
{
}

BOOL COpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// COpView �׸���

void COpView::OnDraw(CDC* /*pDC*/)
{
	COpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// COpView ����

#ifdef _DEBUG
void COpView::AssertValid() const
{
	CView::AssertValid();
}

void COpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpDoc* COpView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpDoc)));
	return (COpDoc*)m_pDocument;
}
#endif //_DEBUG


// COpView �޽��� ó����


int COpView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	
	m_pushbutton.Create(_T("Ǫ�� ��ư1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(20, 20, 160, 50), this, 101);

	m_pushbutton2.Create(_T("Ǫ�� ��ư2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(200, 200, 300, 300), this, 102);

	return 0;
}
void COpView::OnButtonClicked()
{
	//CClientDC dc(this);


	COpDoc *p = GetDocument();
	p->initialize();// ��ư ������ �� �������� �پ��ִ� 	
					//p->done();

}


void COpView::OnButtonClicked2()
{

	CClientDC dc(this);

	/*
	COpDoc *p = GetDocument();
	p->trg();
	*/

}
