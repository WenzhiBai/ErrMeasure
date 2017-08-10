
// ErrMeasureDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ErrMeasure.h"
#include "ErrMeasureDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CErrMeasureDlg 对话框



CErrMeasureDlg::CErrMeasureDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ERRMEASURE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CErrMeasureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CErrMeasureDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CErrMeasureDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CErrMeasureDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CErrMeasureDlg 消息处理程序

BOOL CErrMeasureDlg::OnInitDialog()
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CErrMeasureDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CErrMeasureDlg::OnPaint()
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
HCURSOR CErrMeasureDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CString Distance(CString X, CString Y)
{
	double x, y, result;
	CString Result;
	x = _wtof(X.GetBuffer());
	y = _wtof(Y.GetBuffer());
	result = sqrt(pow(x,2)+pow(y,2));
	Result.Format(_T("%f"), result);
	return Result;
}

CString Calculate(CString X, CString Y)
{
	double x, y, result;
	CString Result;
	x = _wtof(X.GetBuffer());
	y = _wtof(Y.GetBuffer());
	result = x - y;
	Result.Format(_T("%f"), result);
	return Result;
}

void CErrMeasureDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString X1;
	CString	Y1;
	CString M1;
	CString R1;
	CString E1;
	UpdateData(true);
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(X1);
	GetDlgItem(IDC_EDIT1+1)->GetWindowTextW(Y1);
	GetDlgItem(IDC_EDIT1+20)->GetWindowTextW(R1);
	M1 = Distance(X1, Y1);
	GetDlgItem(IDC_STATIC_MEA1)->SetWindowTextW(M1);
	E1 = Calculate(M1, R1);
	GetDlgItem(IDC_STATIC_ERR1)->SetWindowTextW(E1);
	UpdateData(false);
}


void CErrMeasureDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
