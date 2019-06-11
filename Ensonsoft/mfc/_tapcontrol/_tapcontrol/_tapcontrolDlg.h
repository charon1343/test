
// _tapcontrolDlg.h : 헤더 파일
//

#pragma once


// C_tapcontrolDlg 대화 상자
class C_tapcontrolDlg : public CDialogEx
{
// 생성입니다.
public:
	C_tapcontrolDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD__TAPCONTROL_DIALOG };

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
	CTabCtrl m_tabArea;
//	double m_dCirR;
//	double m_dCirResult;
//	double m_dTriA;
//	double m_dTriB;
//	double m_dRectA;
//	double m_dRectB;
	double m_dRectA;
	double m_dRectB;
	double m_dCirR;
	double m_dTriA;
	double m_dTriB;
	double m_dTriResult;
	double m_dCirResult;
	double m_dRectResult;
	afx_msg void OnSelchangeTabArea(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedButtonCir();
	afx_msg void OnClickedButtonRect();
	afx_msg void OnClickedButtonTri();
	afx_msg void OnClickedButtonShow();
	afx_msg void OnClickedButtonExit();
};
