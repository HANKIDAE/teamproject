
// OpView.h : COpView 클래스의 인터페이스
//

#pragma once

class COpView : public CView
{
protected: // serialization에서만 만들어집니다.
	COpView();
	DECLARE_DYNCREATE(COpView)

	// 특성입니다.
public:
	COpDoc* GetDocument() const;

	// 작업입니다.
public:

	CButton m_pushbutton;
	CButton m_pushbutton2;
	
	// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

	// 구현입니다.
public:
	virtual ~COpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	void OnButtonClicked();
	void OnButtonClicked2();
};

#ifndef _DEBUG  // OpView.cpp의 디버그 버전
inline COpDoc* COpView::GetDocument() const
{
	return reinterpret_cast<COpDoc*>(m_pDocument);
}
#endif

