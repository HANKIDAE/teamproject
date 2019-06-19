
// OpDoc.h : COpDoc Ŭ������ �������̽�
//


#pragma once

#include "sharedimagebuffer.h"
#include "mythread.h"


using namespace cv;
using namespace boost::interprocess;
using namespace boost::detail;


class COpDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	COpDoc();
	DECLARE_DYNCREATE(COpDoc)

	// Ư���Դϴ�.
public:

	// �۾��Դϴ�.
public:
	ti t;
	int nchs;
	int dsz;
	std::stringstream s;

	std::thread p1;
	std::thread p2;
	std::thread p3;

	void initialize();
	// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

	//void initialize();
	void done();

	// �����Դϴ�.
public:
	virtual ~COpDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
