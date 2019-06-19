
// OpDoc.h : COpDoc 클래스의 인터페이스
//


#pragma once

#include "sharedimagebuffer.h"
#include "mythread.h"


using namespace cv;
using namespace boost::interprocess;
using namespace boost::detail;


class COpDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	COpDoc();
	DECLARE_DYNCREATE(COpDoc)

	// 특성입니다.
public:

	// 작업입니다.
public:
	ti t;
	int nchs;
	int dsz;
	std::stringstream s;

	std::thread p1;
	std::thread p2;
	std::thread p3;

	void initialize();
	// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

	//void initialize();
	void done();

	// 구현입니다.
public:
	virtual ~COpDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
