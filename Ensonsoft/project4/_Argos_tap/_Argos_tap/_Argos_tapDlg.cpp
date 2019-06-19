
// _Argos_tapDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "_Argos_tap.h"
#include "_Argos_tapDlg.h"
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


// C_Argos_tapDlg ��ȭ ����




C_Argos_tapDlg::C_Argos_tapDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_Argos_tapDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_combo_tap4_combo1 = _T("");
	m_edit_tap1_edit1 = _T("");
	m_edit_tap2_edit1 = _T("");
	m_edit_tap2_edit2 = _T("");
	m_edit_tap3_edit1 = _T("");
	m_edit_tap4_edit1 = _T("");
	m_edit_tap4_edit2 = _T("");
	m_edit_tap5_edit1 = _T("");
	m_edit_tap5_edit2 = _T("");
	m_edit_tap5_edit3 = _T("");
	m_edit_tap5_edit4 = _T("");
}

void C_Argos_tapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_tap5_check, m_check_tap5_check1);
	DDX_Check(pDX, IDC_CHECK_tap5_check2, m_check_tap5_check2);
	DDX_Check(pDX, IDC_CHECK_tap5_check3, m_check_tap5_check3);
	DDX_CBString(pDX, IDC_COMBO_tap4_combo1, m_combo_tap4_combo1);
	DDX_Text(pDX, IDC_EDIT_tab1_edit, m_edit_tap1_edit1);
	DDX_Text(pDX, IDC_EDIT_tap2_edit1, m_edit_tap2_edit1);
	DDX_Text(pDX, IDC_EDIT_tap2_edit2, m_edit_tap2_edit2);
	DDX_Text(pDX, IDC_EDIT_tap3_edit1, m_edit_tap3_edit1);
	DDX_Text(pDX, IDC_EDIT_tap4_edit1, m_edit_tap4_edit1);
	DDX_Text(pDX, IDC_EDIT_tap4_edit2, m_edit_tap4_edit2);
	DDX_Text(pDX, IDC_EDIT_tap5_edit1, m_edit_tap5_edit1);
	DDX_Text(pDX, IDC_EDIT_tap5_edit2, m_edit_tap5_edit2);
	DDX_Text(pDX, IDC_EDIT_tap5_edit3, m_edit_tap5_edit3);
	DDX_Text(pDX, IDC_EDIT_tap5_edit4, m_edit_tap5_edit4);
	DDX_Control(pDX, IDC_TAB_AREA, m_tabArea);
}

BEGIN_MESSAGE_MAP(C_Argos_tapDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_AREA, &C_Argos_tapDlg::OnSelchangeTabArea)
END_MESSAGE_MAP()


// C_Argos_tapDlg �޽��� ó����

BOOL C_Argos_tapDlg::OnInitDialog()
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

	TC_ITEM tabItem;
	LPSTR tabName[5] = {_T("����"),_T("�Ϲ�����"),_T("���̼���"),_T("��������"),_T("��������")};
	for(int nIndex = 0;nIndex<5;nIndex++)
	{
		tabItem.mask = TCIF_TEXT;
		tabItem.pszText = tabName[nIndex];
		m_tabArea.InsertItem(nIndex, &tabItem);
	}

	GetDlgItem(IDC_EDIT_tab1_edit)->SetWindowText("�ý��ۼ����� ������ �����ϴ�.\n0����Ʈ ���� ����\n0����Ʈ ���� ����\n0���̼���Ȯ��\n���念����\n�������� ��������\n\n\n�� �������� ������ �����Ϸ��� \"����\"�����ư�� �����ּ���.\n\n������ �����Ϸ��� �ƹ�â������ ��ħ�� Ŭ���ϼ���. ");
	GetDlgItem(IDC_EDIT_tab1_edit)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_tap2_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap2_edit2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tab2_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap2_static2)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap3_static1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap3_edit1)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap4_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_group1)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit2)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	
	GetDlgItem(IDC_EDIT_tap5_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit2)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit3)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit4)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static4)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check2)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check3)->ShowWindow(false);
	
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void C_Argos_tapDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C_Argos_tapDlg::OnPaint()
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
HCURSOR C_Argos_tapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C_Argos_tapDlg::OnSelchangeTabArea(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	int nSelect = m_tabArea.GetCurSel();

	switch(nSelect)
	{
	case 0:
	GetDlgItem(IDC_EDIT_tab1_edit)->ShowWindow(true);

	GetDlgItem(IDC_EDIT_tap2_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap2_edit2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tab2_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap2_static2)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap3_static1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap3_edit1)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap4_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_group1)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit2)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	
	GetDlgItem(IDC_EDIT_tap5_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit2)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit3)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit4)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static4)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check2)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check3)->ShowWindow(false);
	break;

	case 1:
	GetDlgItem(IDC_EDIT_tab1_edit)->ShowWindow(false);

	GetDlgItem(IDC_EDIT_tap2_edit1)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_tap2_edit2)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tab2_static1)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap2_static2)->ShowWindow(true);

	GetDlgItem(IDC_STATIC_tap3_static1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap3_edit1)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap4_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_group1)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit2)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	
	GetDlgItem(IDC_EDIT_tap5_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit2)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit3)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit4)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static4)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check2)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check3)->ShowWindow(false);
	break;

	case 2:
	GetDlgItem(IDC_EDIT_tab1_edit)->ShowWindow(false);

	GetDlgItem(IDC_EDIT_tap2_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap2_edit2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tab2_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap2_static2)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap3_static1)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_tap3_edit1)->ShowWindow(true);

	GetDlgItem(IDC_STATIC_tap4_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_group1)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit2)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	
	GetDlgItem(IDC_EDIT_tap5_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit2)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit3)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit4)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static4)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check2)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check3)->ShowWindow(false);
	break;

	case 3:
	GetDlgItem(IDC_EDIT_tab1_edit)->ShowWindow(false);

	GetDlgItem(IDC_EDIT_tap2_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap2_edit2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tab2_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap2_static2)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap3_static1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap3_edit1)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap4_static1)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap4_static2)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap4_static3)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap4_group1)->ShowWindow(true);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_tap4_edit1)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_tap4_edit2)->ShowWindow(true);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(true);
	
	GetDlgItem(IDC_EDIT_tap5_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit2)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit3)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap5_edit4)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_group2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap5_static4)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check2)->ShowWindow(false);
	GetDlgItem(IDC_CHECK_tap5_check3)->ShowWindow(false);
	break;

	case 4:
	GetDlgItem(IDC_EDIT_tab1_edit)->ShowWindow(false);

	GetDlgItem(IDC_EDIT_tap2_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap2_edit2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tab2_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap2_static2)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap3_static1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap3_edit1)->ShowWindow(false);

	GetDlgItem(IDC_STATIC_tap4_static1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static2)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_static3)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_tap4_group1)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_tap4_edit2)->ShowWindow(false);
	GetDlgItem(IDC_COMBO_tap4_combo1)->ShowWindow(false);
	
	GetDlgItem(IDC_EDIT_tap5_edit1)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_tap5_edit2)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_tap5_edit3)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_tap5_edit4)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap5_group1)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap5_group2)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap5_static1)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap5_static2)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap5_static3)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_tap5_static4)->ShowWindow(true);
	GetDlgItem(IDC_CHECK_tap5_check)->ShowWindow(true);
	GetDlgItem(IDC_CHECK_tap5_check2)->ShowWindow(true);
	GetDlgItem(IDC_CHECK_tap5_check3)->ShowWindow(true);
	break;
	}
	*pResult = 0;

}
