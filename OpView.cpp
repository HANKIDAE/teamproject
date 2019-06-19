
// OpView.cpp : COpView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// COpView 생성/소멸

COpView::COpView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

COpView::~COpView()
{
}

BOOL COpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// COpView 그리기

void COpView::OnDraw(CDC* /*pDC*/)
{
	COpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// COpView 진단

#ifdef _DEBUG
void COpView::AssertValid() const
{
	CView::AssertValid();
}

void COpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpDoc* COpView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpDoc)));
	return (COpDoc*)m_pDocument;
}
#endif //_DEBUG


// COpView 메시지 처리기


int COpView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	
	m_pushbutton.Create(_T("푸시 버튼1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(20, 20, 160, 50), this, 101);

	m_pushbutton2.Create(_T("푸시 버튼2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(200, 200, 300, 300), this, 102);

	return 0;
}
void COpView::OnButtonClicked()
{
	//CClientDC dc(this);


	COpDoc *p = GetDocument();
	p->initialize();// 버튼 눌렀을 때 동영상을 뛰어주는 	
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
