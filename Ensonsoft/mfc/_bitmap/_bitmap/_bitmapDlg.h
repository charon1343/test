
// _bitmapDlg.h : 헤더 파일
//

#pragma once


// C_bitmapDlg 대화 상자
class C_bitmapDlg : public CDialogEx
{
// 생성입니다.
public:
	C_bitmapDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	////////
	HINSTANCE m_hInstance;

	int m_nWidth;
	int m_nHeight;

	////////

// 대화 상자 데이터입니다.
	enum { IDD = IDD__BITMAP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileExit();
	afx_msg void OnHelpAbout();
	int m_menuID;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnZoomIn();
	afx_msg void OnZoomOut();
	afx_msg void OnClickedButtonExit();
};
