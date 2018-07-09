#pragma once


// CDlg_MsgLoading ��ȭ �����Դϴ�.

class CDlg_MsgLoading : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_MsgLoading)

public:
	CDlg_MsgLoading(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlg_MsgLoading();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MSG_LOADING };
	void SetProgress(int __nValue) {
		static CString strTemp = _T("������..............................");
		static int nLeft = 3;
		//__nValue = 100;
		//CString strTemp;
		int nL, nU;
		CProgressCtrl * pCtrl = (CProgressCtrl *)GetDlgItem(IDC_INIT_Progress);
		//pCtrl->SetRange(0, 500);
		pCtrl->GetRange(nL, nU);
		pCtrl->SetPos(__nValue);

		int nLength = strTemp.GetLength();
		SetItemData(IDC_STATIC_Message, strTemp.Left(nLeft));
		++nLeft;
		if (nLeft > 33) nLeft = 3;
	}
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	int nCount;
	bool isProcessing;
	virtual void Thread();
};
