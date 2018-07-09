// ModelSet.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SetLightController.h"
#include "ModelSet.h"
#include "afxdialogex.h"


// ModelSet ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(ModelSet, CDialogEx)

ModelSet::ModelSet(CWnd* pParent /*=NULL*/)
	: CDialogEx(ModelSet::IDD, pParent)
{

}

ModelSet::~ModelSet()
{
}

void ModelSet::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ModelAuto, m_modelAuto);
	DDX_Control(pDX, IDC_ModelBaudRate, m_modelBaudRate);
	DDX_Control(pDX, IDC_ModelBaudRateValue, m_modelBaudRateValue);
	DDX_Control(pDX, IDC_ModelComPort, m_modelComPort);
	DDX_Control(pDX, IDC_ModelComPortValue, m_modelComPortValue);
	DDX_Control(pDX, IDC_ModelDataBits, m_modelDataBits);
	//  DDX_Control(pDX, IDC_ModelDataBitsValue, m_ModelDataBitsValue);
	DDX_Control(pDX, IDC_ModelName, m_modelName);
	DDX_Control(pDX, IDC_ModelNameValue, m_modelNameValue);
	DDX_Control(pDX, IDC_ModelParity, m_modelParity);
	DDX_Control(pDX, IDC_ModelParityValue, m_modelParityValue);
	DDX_Control(pDX, IDC_ModelStopBits, m_modelStopBits);
	DDX_Control(pDX, IDC_ModelStopBitsValue, m_modelStopBitsValue);
	DDX_Control(pDX, IDC_LightChannel, m_lightChannel);
	DDX_Control(pDX, IDC_LightChannelValue, m_lightChannelValue);
	DDX_Control(pDX, IDC_LightMax, m_lightMax);
	DDX_Control(pDX, IDC_LightMaxValue, m_lightMaxValue);
	DDX_Control(pDX, IDC_ModelDataBitsValue, m_modelDataBitsValue);
}


BEGIN_MESSAGE_MAP(ModelSet, CDialogEx)
	ON_BN_CLICKED(IDC_ModelName, &ModelSet::OnBnClickedModelname)
	ON_BN_CLICKED(IDC_ModelNameValue, &ModelSet::OnBnClickedModelnamevalue)
	ON_BN_CLICKED(IDC_ModelComPort, &ModelSet::OnBnClickedModelcomport)
	ON_BN_CLICKED(IDC_ModelComPortValue, &ModelSet::OnBnClickedModelcomportvalue)
	ON_BN_CLICKED(IDC_ModelAuto, &ModelSet::OnBnClickedModelauto)
	ON_BN_CLICKED(IDC_ModelBaudRate, &ModelSet::OnBnClickedModelbaudrate)
	ON_BN_CLICKED(IDC_ModelBaudRateValue, &ModelSet::OnBnClickedModelbaudratevalue)
	ON_BN_CLICKED(IDC_ModelParity, &ModelSet::OnBnClickedModelparity)
	ON_BN_CLICKED(IDC_ModelParityValue, &ModelSet::OnBnClickedModelparityvalue)
	ON_BN_CLICKED(IDC_ModelDataBits, &ModelSet::OnBnClickedModeldatabits)
	ON_BN_CLICKED(IDC_ModelDataBitsValue, &ModelSet::OnBnClickedModeldatabitsvalue)
	ON_BN_CLICKED(IDC_ModelStopBits, &ModelSet::OnBnClickedModelstopbits)
	ON_BN_CLICKED(IDC_ModelStopBitsValue, &ModelSet::OnBnClickedModelstopbitsvalue)
	ON_BN_CLICKED(IDC_LightChannel, &ModelSet::OnBnClickedLightchannel)
	ON_BN_CLICKED(IDC_LightChannelValue, &ModelSet::OnBnClickedLightchannelvalue)
	ON_BN_CLICKED(IDC_LightMax, &ModelSet::OnBnClickedLightmax)
	ON_BN_CLICKED(IDC_LightMaxValue, &ModelSet::OnBnClickedLightmaxvalue)
	ON_WM_WINDOWPOSCHANGED()
END_MESSAGE_MAP()


// ModelSet �޽��� ó�����Դϴ�.


void ModelSet::OnBnClickedModelname()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedModelnamevalue()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedModelcomport()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedModelcomportvalue()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedModelauto()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedModelbaudrate()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedModelbaudratevalue()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedModelparity()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedModelparityvalue()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedModeldatabits()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedModeldatabitsvalue()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedModelstopbits()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedModelstopbitsvalue()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedLightchannel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedLightchannelvalue()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedLightmax()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnBnClickedLightmaxvalue()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void ModelSet::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if ((lpwndpos->flags & SWP_NOSIZE) == 0) { On_WindTopPos();}
}


BOOL ModelSet::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	On_WindTopPos();
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void ModelSet::On_WindTopPos(void)
{
	CRect rctTop;
	GetClientRect(&rctTop);

	rctTop.top += 5;
	rctTop.left += 5;
	rctTop.bottom -= 5;
	rctTop.right -= 5;

	CRect rctTab = rctTop;

	int nWidth = (rctTop.Width() + 1) / 4 - 1;
	int nHeight = (rctTop.Height() + 1) / 5 - 1;

	rctTab.bottom = rctTop.top+nHeight;
	rctTab.right = rctTop.left+nWidth;
	m_modelName.SetWindowPos(rctTab);

	rctTab.left = rctTab.right + 1;
	rctTab.right = rctTab.left + nWidth * 3 + 2;
	m_modelNameValue.SetWindowPos(rctTab);


	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctTop.left;
	rctTab.right = rctTab.left + nWidth;
	m_modelComPort.SetWindowPos(rctTab);

	rctTab.left = rctTab.right + 1;
	rctTab.right = rctTab.left + nWidth;
	m_modelComPortValue.SetWindowPos(rctTab);

	rctTab.left = rctTab.right + nWidth + 2;
	rctTab.right = rctTab.left + nWidth;
	m_modelAuto.SetWindowPos(rctTab);


	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctTop.left;
	rctTab.right = rctTab.left + nWidth;
	m_modelBaudRate.SetWindowPos(rctTab);

	rctTab.left = rctTab.right + 1;
	rctTab.right = rctTab.left + nWidth;
	m_modelBaudRateValue.SetWindowPos(rctTab);

	rctTab.left = rctTab.right + 1;
	rctTab.right = rctTab.left + nWidth;
	m_modelParity.SetWindowPos(rctTab);

	rctTab.left = rctTab.right + 1;
	rctTab.right = rctTab.left + nWidth;
	m_modelParityValue.SetWindowPos(rctTab);


	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctTop.left;
	rctTab.right = rctTab.left + nWidth;
	m_modelDataBits.SetWindowPos(rctTab);

	rctTab.left = rctTab.right + 1;
	rctTab.right = rctTab.left + nWidth;
	m_modelDataBitsValue.SetWindowPos(rctTab);

	rctTab.left = rctTab.right + 1;
	rctTab.right = rctTab.left + nWidth;
	m_modelStopBits.SetWindowPos(rctTab);

	rctTab.left = rctTab.right + 1;
	rctTab.right = rctTab.left + nWidth;
	m_modelStopBitsValue.SetWindowPos(rctTab);


	rctTab.top = rctTab.bottom + 1;
	rctTab.bottom = rctTab.top + nHeight;
	rctTab.left = rctTop.left;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannel.SetWindowPos(rctTab);

	rctTab.left = rctTab.right + 1;
	rctTab.right = rctTab.left + nWidth;
	m_lightChannelValue.SetWindowPos(rctTab);

	rctTab.left = rctTab.right + 1;
	rctTab.right = rctTab.left + nWidth;
	m_lightMax.SetWindowPos(rctTab);

	rctTab.left = rctTab.right + 1;
	rctTab.right = rctTab.left + nWidth;
	m_lightMaxValue.SetWindowPos(rctTab);




}
