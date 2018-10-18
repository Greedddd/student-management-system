
// student achievement management system1.0Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "student management system1.0.h"
#include "student management system1.0Dlg.h"
#include "afxdialogex.h"
#include "management.h"


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


// C学生成绩管理系统10Dlg 对话框



C学生成绩管理系统10Dlg::C学生成绩管理系统10Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C学生成绩管理系统10Dlg::IDD, pParent)
	, NAME(_T(""))
	, ID(0)
	, GMATH(0)
	, GCODE(0)
	, m_radio1(0)//默认第一个radiobutton被选中
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C学生成绩管理系统10Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, NAME);
	DDX_Text(pDX, IDC_EDIT2, ID);
	DDX_Text(pDX, IDC_EDIT3, GMATH);
	DDX_Text(pDX, IDC_EDIT4, GCODE);
	DDX_Control(pDX, IDC_LIST1, show);
	DDX_Control(pDX, IDC_name, n_static);
	DDX_Control(pDX, IDC_id, i_static);
	DDX_Control(pDX, IDC_gmath, gmath_static);
	DDX_Control(pDX, IDC_gcode, gcode_static);
	DDX_Radio(pDX, IDC_RADIO1, m_radio1);
}

BEGIN_MESSAGE_MAP(C学生成绩管理系统10Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON1, &C学生成绩管理系统10Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C学生成绩管理系统10Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &C学生成绩管理系统10Dlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT1, &C学生成绩管理系统10Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &C学生成绩管理系统10Dlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT4, &C学生成绩管理系统10Dlg::OnEnChangeEdit4)
	ON_STN_CLICKED(IDC_gcode, &C学生成绩管理系统10Dlg::OnStnClickedgcode)
	ON_BN_CLICKED(IDC_RADIO1, &C学生成绩管理系统10Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &C学生成绩管理系统10Dlg::OnBnClickedRadio1)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// C学生成绩管理系统10Dlg 消息处理程序

BOOL C学生成绩管理系统10Dlg::OnInitDialog()
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

	// TODO:  在此添加额外的初始化代码
	DWORD dwStyle = show.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	show.SetExtendedStyle(dwStyle);
	show.InsertColumn(0, "序号", LVCFMT_CENTER, 40);
	show.InsertColumn(1, "姓名", LVCFMT_CENTER, 80);
	show.InsertColumn(2, "学号", LVCFMT_CENTER, 80);
	show.InsertColumn(3, "高数成绩", LVCFMT_CENTER, 80);
	show.InsertColumn(4, "程序设计", LVCFMT_CENTER, 80);


	//设置Static字体  
	m_Font.CreatePointFont(100, "黑体");
	n_static.SetFont(&m_Font, true);
	n_static.SetWindowText("姓名：");
	i_Font.CreatePointFont(100, "黑体", NULL);
	i_static.SetFont(&m_Font, true);
	i_static.SetWindowText("学号：");//感觉只能改变大小orz
	gmath_Font.CreatePointFont(100, "黑体", NULL);
	gmath_static.SetFont(&m_Font, true);
	gmath_static.SetWindowText("高数成绩：");
	gcode_Font.CreatePointFont(100, "黑体", NULL);
	gcode_static.SetFont(&m_Font, true);
	gcode_static.SetWindowText("程序设计：");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C学生成绩管理系统10Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C学生成绩管理系统10Dlg::OnPaint()
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
HCURSOR C学生成绩管理系统10Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void C学生成绩管理系统10Dlg::OnBnClickedButton1()//增加学生的按钮
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	student stu;
	stu.id = ID;
	stu.Gmath = GMATH;
	stu.Gcode = GCODE;
	strcpy_s(stu.name, (LPCSTR)NAME);
	m.addstudent(stu);
	checkok();
}


void C学生成绩管理系统10Dlg::OnBnClickedButton2()//删除学生的按钮
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	student stu;
	stu.id = ID;
	stu.Gmath = GMATH;
	stu.Gcode = GCODE;
	strcpy_s(stu.name, (LPCSTR)NAME);
	m.deletestudent(stu);
	checkok();
}


void C学生成绩管理系统10Dlg::OnBnClickedButton3()//修改学生的按钮
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	student stu;
	stu.id = ID;
	stu.Gmath = GMATH;
	stu.Gcode = GCODE;
	strcpy_s(stu.name, (LPCSTR)NAME);
	m.modifystudent(stu);
	checkok();
}


void C学生成绩管理系统10Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
void C学生成绩管理系统10Dlg::checkok()
{
	UpdateData(TRUE);
	show.DeleteAllItems();
	m.alist;
	m.checkstudent();
	list<student>::iterator p;//建立list迭代器
	int i = 0;
	CString temp = " ";//转换CString类型
	for (p = m.alist.begin(); p != m.alist.end(); p++){
		temp.Format("%d", i + 1);
		show.InsertItem(i, temp);
		show.SetItemText(i, 1, p->name);
		temp.Format("%d", p->id);
		show.SetItemText(i, 2, temp);
		temp.Format("%d", p->Gmath);
		show.SetItemText(i, 3, temp);
		temp.Format("%d", p->Gcode);
		show.SetItemText(i, 4, temp);
		i++;
	}//将alist中数据写入显示框
}


void C学生成绩管理系统10Dlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void C学生成绩管理系统10Dlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void C学生成绩管理系统10Dlg::OnStnClickedgcode()
{
	// TODO:  在此添加控件通知处理程序代码
}


void C学生成绩管理系统10Dlg::OnBnClickedRadio1()
{
	UpdateData(TRUE);
	if (m_radio1 == 0){
		m.sortstudent(1);
	}
	else m.sortstudent(0);
	checkok();
	// TODO:  在此添加控件通知处理程序代码
}


HBRUSH C学生成绩管理系统10Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (pWnd->GetDlgCtrlID() == IDC_gcode){

		pDC->SelectObject(&m_Font);
	}
	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
