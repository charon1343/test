#pragma once


// CenterX ��ȭ �����Դϴ�.

class CenterX : public CDialogEx
{
	DECLARE_DYNAMIC(CenterX)

public:
	CenterX(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CenterX();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CENTERX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	CButton m_Sel1;
	CButton m_Sel2;
	CButton m_Sel3;
	CButton m_Sel4;
	CButton m_Sel5;
	CButton m_Sel6;
	CButton m_Sel7;
	CButton m_Sel8;
	CButton m_Sel9;
	CButton m_Sel0;
	CButton m_SelChangSign;
	CButton m_SelPoint;
	afx_msg void OnBnClickedButton1();
};
