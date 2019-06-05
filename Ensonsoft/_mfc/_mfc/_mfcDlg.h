
// _mfcDlg.h : 헤더 파일
//

#pragma once


// C_mfcDlg 대화 상자
class C_mfcDlg : public CDialogEx
{
// 생성입니다.
public:
	C_mfcDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD__MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedButtonHello();
	afx_msg void OnClickedButtonExit();
	CString m_strResult;
	afx_msg void OnBnClickedButtonYn();
	afx_msg void OnBnClickedButtonOc();
};
