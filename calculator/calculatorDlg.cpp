
// calculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include"math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CcalculatorDlg 对话框




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
	, m_str(_T(""))
{
	dec= 0;
	dec2 = 0;
	dec3 = 0;
	t = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0, &CcalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_1, &CcalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CcalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CcalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CcalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CcalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CcalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CcalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CcalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CcalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_POINT, &CcalculatorDlg::OnBnClickedPoint)
	ON_BN_CLICKED(IDC_DEL, &CcalculatorDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_ADD, &CcalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DEC, &CcalculatorDlg::OnBnClickedDec)
	ON_BN_CLICKED(IDC_MNL, &CcalculatorDlg::OnBnClickedMnl)
	ON_BN_CLICKED(IDC_DIVIDE, &CcalculatorDlg::OnBnClickedDivide)
    //ON_BN_CLICKED(IDC_BRA, &CcalculatorDlg::OnBnClickedBra)
	ON_BN_CLICKED(IDC_CAL, &CcalculatorDlg::OnBnClickedCal)
	ON_BN_CLICKED(IDC_BACK, &CcalculatorDlg::OnBnClickedBack)
	ON_BN_CLICKED(IDC_negative, &CcalculatorDlg::OnBnClickednegative)
	ON_BN_CLICKED(IDC_sin, &CcalculatorDlg::OnBnClickedsin)
	ON_BN_CLICKED(IDC_cos, &CcalculatorDlg::OnBnClickedcos)
	ON_BN_CLICKED(IDC_tan, &CcalculatorDlg::OnBnClickedtan)
	ON_BN_CLICKED(IDC_square, &CcalculatorDlg::OnBnClickedsquare)
	ON_BN_CLICKED(IDC_Squareroot, &CcalculatorDlg::OnBnClickedSquareroot)
	ON_BN_CLICKED(IDC_count, &CcalculatorDlg::OnBnClickedcount)
	ON_BN_CLICKED(IDC_Percent, &CcalculatorDlg::OnBnClickedPercent)
	ON_BN_CLICKED(IDC_clock, &CcalculatorDlg::OnBnClickedclock)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CcalculatorDlg 消息处理程序

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"0";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"1";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"2";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"3";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"4";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"5";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"6";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"7";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"8";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"9";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedPoint()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(m_str.Find(L".")==-1)
	m_str=m_str+L".";
	UpdateData(false);
}





void CcalculatorDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=1;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
    UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDec()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=2;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
    UpdateData(false);
}


void CcalculatorDlg::OnBnClickedMnl()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=3;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
    UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDivide()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=4;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
    UpdateData(false);
}
void CcalculatorDlg::OnBnClickedBack()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickednegative()
{
	// TODO: 在此添加控件通知处理程序代码
    UpdateData(true);
	m_str=L"-"+m_str;
	 UpdateData(false);
}

void CcalculatorDlg::OnBnClickedsin()
{
	// TODO: 在此添加控件通知处理程序代码
	    double temp;
	    UpdateData(true);
		temp=_ttof(m_str);
		temp=sin(temp);
		m_str.Format(L"%lf",temp);
		while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	    while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	    UpdateData(false);
}

void CcalculatorDlg::OnBnClickedcos()
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=cos(temp);
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
    UpdateData(false);
}

void CcalculatorDlg::OnBnClickedtan()
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=tan(temp);
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
    UpdateData(false);
}

void CcalculatorDlg::OnBnClickedsquare()
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=pow(temp,3);
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
    UpdateData(false);
}

void CcalculatorDlg::OnBnClickedcount()
{
	// TODO: 在此添加控件通知处理程序代码
    double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str.Format(L"%lf",temp);
	if(temp==0)
		{
			m_str.Format(L"亲，0没有倒数哦");
		}
		else
		{
			temp=1/temp;
		    m_str.Format(L"%lf",temp);
		}

	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
    UpdateData(false);
}

void CcalculatorDlg::OnBnClickedSquareroot()
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=sqrt(temp);
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
    UpdateData(false);
}

void CcalculatorDlg::OnBnClickedPercent()
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
    temp=_ttof(m_str);
	temp=temp/100;
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
	  m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
	  m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedCal()
{
	// TODO: 在此添加控件通知处理程序代码
	TRACE(L"flag=%d",flag);
	UpdateData(true);
	if(flag==1)
	{
		temp=temp+_ttof(m_str);
		m_str.Format(L"%lf",temp);
	}
	if(flag==2)
	{
		temp=temp-_ttof(m_str);
		m_str.Format(L"%lf",temp);
	}
	if(flag==3)
	{
		temp=temp*_ttof(m_str);
		m_str.Format(L"%lf",temp);
	}
	if(flag==4)
	{
		if(_ttof(m_str)==0)
		{
			m_str.Format(L"您该长长知识了");
		}
		else
		{
			temp=temp/_ttof(m_str);
		    m_str.Format(L"%lf",temp);
		}
	}
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}
void CcalculatorDlg::OnBnClickedDel()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str="";
	UpdateData(false);
}




void CcalculatorDlg::OnBnClickedclock()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(1,1000,NULL);
}


void CcalculatorDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int x,y,x2,x3,y2,y3;

		CPen newpen(PS_SOLID,2,RGB(0,0,255));
		CPen minpen(PS_SOLID,6,RGB(0,255,0));
        CPen hourpen(PS_SOLID,9,RGB(255,0,0));
		//CPen delpen(PS_SOLID,9,RGB(255,255,255));
		CPen *oldpen;
		CClientDC DC(this);
		DC.SetWindowOrg (-570,-220);
		DC.Ellipse(-100,100,100,-100);
		

		DC.TextOutW (-10,-90,L"12");                                 
		DC.TextOutW(90,-7,L"3");                                      
		DC.TextOutW(-7,80,L"6");
		DC.TextOutW (-90,-7,L"9");


		DC.SelectObject (&newpen);
		dec = dec - 3.1415926/30;
		x = -80*sin(dec);
		y = -80*cos(dec);
		DC.MoveTo(0,0);
		DC.LineTo(x,y);
	
	
		DC.SelectObject(&minpen);
		dec2 = dec2 - 3.1415926/1800;
        x2 = -60*sin(dec2);
		y2 = -60*cos(dec2);
		DC.MoveTo(0,0);
		DC.LineTo(x2,y2);
		

		DC.SelectObject(&hourpen);
		dec3 = dec3 - 3.1415926/21600;
		x3 = -40*sin(dec3);
		y3 = -40*cos(dec3);
		DC.MoveTo(0,0);
		DC.LineTo(x3,y3);
		

	CDialogEx::OnTimer(nIDEvent);
}
