#pragma once


// CDlg_MsgLoading 대화 상자입니다.

class CDlg_MsgLoading : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_MsgLoading)

public:
	CDlg_MsgLoading(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_MsgLoading();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MSG_LOADING };
	void SetProgress(int __nValue) {
		static CString strTemp = _T("구동중..............................");
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	int nCount;
	bool isProcessing;
	virtual void Thread();
};
