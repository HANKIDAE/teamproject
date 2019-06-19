
// OpView.h : COpView Ŭ������ �������̽�
//

#pragma once

class COpView : public CView
{
protected: // serialization������ ��������ϴ�.
	COpView();
	DECLARE_DYNCREATE(COpView)

	// Ư���Դϴ�.
public:
	COpDoc* GetDocument() const;

	// �۾��Դϴ�.
public:

	CButton m_pushbutton;
	CButton m_pushbutton2;
	
	// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

	// �����Դϴ�.
public:
	virtual ~COpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	void OnButtonClicked();
	void OnButtonClicked2();
};

#ifndef _DEBUG  // OpView.cpp�� ����� ����
inline COpDoc* COpView::GetDocument() const
{
	return reinterpret_cast<COpDoc*>(m_pDocument);
}
#endif

