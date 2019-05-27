#pragma once


// CDlg_PADNumeric 대화 상자입니다.
enum PAD_InputMode { PAD_MDPassword, PAD_MDInteger, PAD_MDReal };
class CDlg_PADNumeric : public CMNVDialogEx
{
	DECLARE_DYNAMIC(CDlg_PADNumeric)
	PAD_InputMode m_Mode;
	bool m_isDecimalPoint;
	__int64 m_nValue;
	__int64 m_nDenominator;
	bool m_isMinus;
public:
	CDlg_PADNumeric(PAD_InputMode __Mode, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_PADNumeric();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PAD_NUMERIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	void SetMode(PAD_InputMode __Mode) { m_Mode = __Mode; }
	virtual void OnOK() { CDialogEx::OnOK(); }
	virtual void OnCancel() { CDialogEx::OnCancel(); }
	void SetPoint() {
		CString strTemp;
		if (m_Mode == PAD_MDPassword) {
		}
		else if (m_nDenominator > 1) {
			SetItemData(IDC_NUM_VALUE, (m_isMinus) ? -m_nValue : m_nValue, m_nDenominator);
		}
		else if (m_isDecimalPoint) {
			strTemp.Format(_T("%d."), m_nValue);
			SetItemData(IDC_NUM_VALUE, strTemp);
		}
		else {
			SetItemData(IDC_NUM_VALUE, (m_isMinus) ? -m_nValue : m_nValue, m_nDenominator);
		}
	}
	void DisplayValue() {
		if (m_nValue == 0) {
			SetItemData(IDC_NUM_VALUE, _T(""));
			return;
		}
		switch(m_Mode) {
			case PAD_MDPassword: {
				int nTemp = (int)log10((double)m_nValue) + 1;
				CString strFormat;
				strFormat.Format(_T("%%0%dd"), nTemp);
				CString temp;
				temp.Format(strFormat, 0);
				temp.Replace(_T('0'), _T('*'));
				SetItemData(IDC_NUM_VALUE, temp);
			}break;
			case PAD_MDReal: {
				SetPoint();
			} break;
			case PAD_MDInteger: {
				SetItemData(IDC_NUM_VALUE, (m_isMinus) ? -m_nValue : m_nValue, m_nDenominator);
			} break;
		}
	}
	void InputNumber(int __nNum) {
		SetFocus();
		if (m_nValue < 999999999999999i64) {
			m_nValue = m_nValue * 10 + __nNum;
			if (m_isDecimalPoint) m_nDenominator *= 10;
		}
		DisplayValue();
	}
	void InputDot() {
		switch(m_Mode) {
		case PAD_MDPassword:break;
		case PAD_MDInteger: break;
		case PAD_MDReal:	m_isDecimalPoint = true; break;
		}
	}
	void InputMinus() { m_isMinus = !m_isMinus; }
	double GetValue() { return (double)((m_isMinus) ? -m_nValue : m_nValue) / m_nDenominator; }
	afx_msg void OnBnClickedNumMinus() { InputMinus(); }
	afx_msg void OnBnClickedNum1() { InputNumber(1); }
	afx_msg void OnBnClickedNum2() { InputNumber(2); }
	afx_msg void OnBnClickedNum3() { InputNumber(3); }
	afx_msg void OnBnClickedNum4() { InputNumber(4); }
	afx_msg void OnBnClickedNum5() { InputNumber(5); }
	afx_msg void OnBnClickedNum6() { InputNumber(6); }
	afx_msg void OnBnClickedNum7() { InputNumber(7); }
	afx_msg void OnBnClickedNum8() { InputNumber(8); }
	afx_msg void OnBnClickedNum9() { InputNumber(9); }
	afx_msg void OnBnClickedNum0() { InputNumber(0); }
	afx_msg void OnBnClickedNumDot() { InputDot(); }
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void InputBackSpace() {
		if (m_nDenominator > 1) {
			m_nDenominator /= 10;
			__int64 Temp = m_nValue / 10;
			m_nValue = Temp;
		}
		else if (m_isDecimalPoint) {
			m_isDecimalPoint = false;
		}
		else {
			__int64 Temp = m_nValue / 10;
			m_nValue = Temp;
		}
		DisplayValue();
	}
	afx_msg void OnBnClickedNumBack() { InputBackSpace(); }
	afx_msg void OnBnClickedNumClear() {
		m_isDecimalPoint = false;
		m_nValue = 0;
		m_nDenominator = 1;
		DisplayValue();
	}
};
