#pragma once


// dlg_CheckBox 대화 상자입니다.

class dlg_CheckBox : public CDialogEx
{
	DECLARE_DYNAMIC(dlg_CheckBox)

public:
	dlg_CheckBox(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~dlg_CheckBox();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CHECKBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
//	CButton m_check1;
//	CEdit m_edit1;
	BOOL m_check1;
	CString m_edit1;
	afx_msg void OnBnClickedCheck1();
};
