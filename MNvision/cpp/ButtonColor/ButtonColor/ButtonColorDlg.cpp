
// ButtonColorDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ButtonColor.h"
#include "ButtonColorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CButtonColorDlg ��ȭ ����




CButtonColorDlg::CButtonColorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CButtonColorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CButtonColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CButtonColorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_WM_DRAWITEM()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CButtonColorDlg �޽��� ó����

BOOL CButtonColorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CButtonColorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CButtonColorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CButtonColorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CButtonColorDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//
//	CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
//	if(nIDCtl == IDC_BUTTON1)
//
//	{
//
//		CDC dc;
//
//		RECT rect;
//
//		dc.Attach(lpDrawItemStruct->hDC);	//Get the Button DC to CDC
//
//
//
//		rect = lpDrawItemStruct->rcItem	;	//Store the Button rect to local rect
//
//		dc.Draw3dRect(&rect, RGB(0,0,0), RGB(0,0,0));
//
//		dc.FillSolidRect(&rect, RGB(0,0,0));
//
//		
//
//		
//
//		//Show the Effect of Click Event
//
//		UINT state = lpDrawItemStruct->itemState;
//
//		if((state & ODS_SELECTED))
//
//		{
//
//			dc.DrawEdge(&rect, EDGE_SUNKEN, BF_RECT);
//
//		}
//
//		else
//
//		{
//
//			dc.DrawEdge(&rect, EDGE_RAISED, BF_RECT);
//
//		}
//
//
//
//		//Draw Color Text
//
//		dc.SetBkColor(RGB(0,0,0));		//Setting the Text Background Color
//
//		dc.SetTextColor(RGB(255,255,255));		//Setting the Text Color
//
//
//
//		TCHAR buffer[MAX_PATH];
//
//		ZeroMemory(buffer, MAX_PATH);
//
//		::GetWindowText(lpDrawItemStruct->hwndItem, buffer, MAX_PATH);
//
//
//
//		dc.DrawText(buffer, &rect, DT_CENTER|DT_VCENTER |DT_SINGLELINE);
//
//		dc.Detach();							//Detach the Button DC
//
//
//
//	}
//
//}


HBRUSH CButtonColorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.
	switch(nCtlColor){
	case CTLCOLOR_DLG:   /// ���̾�α� ������ white��.
		{
			return (HBRUSH)GetStockObject(WHITE_BRUSH);
			break;
		}
	case CTLCOLOR_BTN :    // ��ư�� ������ ��������...
		{
			pDC->SetTextColor(RGB(255,255,255));
			pDC->SetBkMode(TRANSPARENT);
			return (HBRUSH)::GetStockObject(BLACK_BRUSH);
		}
	case CTLCOLOR_STATIC:
		{
			pDC->SetTextColor(RGB(255,0,0));  // static text ���ڻ� ����
			pDC->SetBkMode(TRANSPARENT);   // static text ���� ����
			return (HBRUSH)::GetStockObject(NULL_BRUSH);
		} 
	}
	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;

}
