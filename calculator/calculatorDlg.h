
// calculatorDlg.h : ͷ�ļ�
//

#pragma once


// CcalculatorDlg �Ի���
class CcalculatorDlg : public CDialogEx
{
// ����
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	double temp;
	int flag;
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedPoint();
	afx_msg void OnBnClickedDel();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDec();
	afx_msg void OnBnClickedMnl();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedBra();
	afx_msg void OnBnClickedCal();
	CString m_str;
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickednegative();
	afx_msg void OnBnClickedsin();
	afx_msg void OnBnClickedcos();
	afx_msg void OnBnClickedtan();
	afx_msg void OnBnClickedlog();
	afx_msg void OnBnClickedln();
	afx_msg void OnBnClickedsquare();
	afx_msg void OnBnClickedSquareroot();
	afx_msg void OnBnClickedcount();
	afx_msg void OnBnClickedPercent();
	afx_msg void OnBnClickedclock();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	double dec,dec2,dec3;
	int t;
};
