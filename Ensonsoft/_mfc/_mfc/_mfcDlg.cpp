
// _mfcDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "_mfc.h"
#include "_mfcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C_mfcDlg ��ȭ ����




C_mfcDlg::C_mfcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_mfcDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strResult = _T("");
}

void C_mfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_strResult);
}

BEGIN_MESSAGE_MAP(C_mfcDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_BUTTON_HELLO, &C_mfcDlg::OnBnClickedButtonHello)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &C_mfcDlg::OnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_YN, &C_mfcDlg::OnBnClickedButtonYn)
	ON_BN_CLICKED(IDC_BUTTON_OC, &C_mfcDlg::OnBnClickedButtonOc)
END_MESSAGE_MAP()


// C_mfcDlg �޽��� ó����

BOOL C_mfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void C_mfcDlg::OnPaint()
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
HCURSOR C_mfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void C_mfcDlg::OnBnClickedButtonHello()
//{
//	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//	MessageBox(_T("MFC WORLD�� ���Ű��� ȯ���մϴ�."));
//}


void C_mfcDlg::OnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


void C_mfcDlg::OnBnClickedButtonYn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int iResults;
	iResults = AfxMessageBox(_T("YES/NO ��Ʋ�� �����̽��ϴ�"),(MB_YESNO|MB_ICONEXCLAMATION));

	if(iResults == IDYES)
	{
		m_strResult = _T("YES ��ư�� �����̽��ϴ�.");
		UpdateData(FALSE);
	}
	if(iResults == IDNO)
	{
		m_strResult = _T("NO��ư�� �����̽��ϴ�!");
		UpdateData(FALSE);
	}
}


void C_mfcDlg::OnBnClickedButtonOc()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int iResults;
	iResults = AfxMessageBox(_T("OK/CANCEL ��ư�� �����̽��ϴ�."),(MB_OKCANCEL|MB_ICONSTOP));

	if(iResults == IDOK)
	{
		m_strResult = _T("OK ��ư�� �����̽��ϴ�.");
		UpdateData(FALSE);
	}
	if(iResults == IDCANCEL)
	{
		m_strResult = _T("CANCEL��ư�� �����̽��ϴ�!");
		UpdateData(FALSE);
	}
}
