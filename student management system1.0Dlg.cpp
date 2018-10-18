
// student achievement management system1.0Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "student management system1.0.h"
#include "student management system1.0Dlg.h"
#include "afxdialogex.h"
#include "management.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// Cѧ���ɼ�����ϵͳ10Dlg �Ի���



Cѧ���ɼ�����ϵͳ10Dlg::Cѧ���ɼ�����ϵͳ10Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cѧ���ɼ�����ϵͳ10Dlg::IDD, pParent)
	, NAME(_T(""))
	, ID(0)
	, GMATH(0)
	, GCODE(0)
	, m_radio1(0)//Ĭ�ϵ�һ��radiobutton��ѡ��
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cѧ���ɼ�����ϵͳ10Dlg::DoDataExchange(CDataExchange* pDX)
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

BEGIN_MESSAGE_MAP(Cѧ���ɼ�����ϵͳ10Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON1, &Cѧ���ɼ�����ϵͳ10Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cѧ���ɼ�����ϵͳ10Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cѧ���ɼ�����ϵͳ10Dlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT1, &Cѧ���ɼ�����ϵͳ10Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &Cѧ���ɼ�����ϵͳ10Dlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT4, &Cѧ���ɼ�����ϵͳ10Dlg::OnEnChangeEdit4)
	ON_STN_CLICKED(IDC_gcode, &Cѧ���ɼ�����ϵͳ10Dlg::OnStnClickedgcode)
	ON_BN_CLICKED(IDC_RADIO1, &Cѧ���ɼ�����ϵͳ10Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Cѧ���ɼ�����ϵͳ10Dlg::OnBnClickedRadio1)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// Cѧ���ɼ�����ϵͳ10Dlg ��Ϣ�������

BOOL Cѧ���ɼ�����ϵͳ10Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	DWORD dwStyle = show.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	show.SetExtendedStyle(dwStyle);
	show.InsertColumn(0, "���", LVCFMT_CENTER, 40);
	show.InsertColumn(1, "����", LVCFMT_CENTER, 80);
	show.InsertColumn(2, "ѧ��", LVCFMT_CENTER, 80);
	show.InsertColumn(3, "�����ɼ�", LVCFMT_CENTER, 80);
	show.InsertColumn(4, "�������", LVCFMT_CENTER, 80);


	//����Static����  
	m_Font.CreatePointFont(100, "����");
	n_static.SetFont(&m_Font, true);
	n_static.SetWindowText("������");
	i_Font.CreatePointFont(100, "����", NULL);
	i_static.SetFont(&m_Font, true);
	i_static.SetWindowText("ѧ�ţ�");//�о�ֻ�ܸı��Сorz
	gmath_Font.CreatePointFont(100, "����", NULL);
	gmath_static.SetFont(&m_Font, true);
	gmath_static.SetWindowText("�����ɼ���");
	gcode_Font.CreatePointFont(100, "����", NULL);
	gcode_static.SetFont(&m_Font, true);
	gcode_static.SetWindowText("������ƣ�");
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cѧ���ɼ�����ϵͳ10Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cѧ���ɼ�����ϵͳ10Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
		CDialogEx::OnPaint();
	}

}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cѧ���ɼ�����ϵͳ10Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void Cѧ���ɼ�����ϵͳ10Dlg::OnBnClickedButton1()//����ѧ���İ�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	student stu;
	stu.id = ID;
	stu.Gmath = GMATH;
	stu.Gcode = GCODE;
	strcpy_s(stu.name, (LPCSTR)NAME);
	m.addstudent(stu);
	checkok();
}


void Cѧ���ɼ�����ϵͳ10Dlg::OnBnClickedButton2()//ɾ��ѧ���İ�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	student stu;
	stu.id = ID;
	stu.Gmath = GMATH;
	stu.Gcode = GCODE;
	strcpy_s(stu.name, (LPCSTR)NAME);
	m.deletestudent(stu);
	checkok();
}


void Cѧ���ɼ�����ϵͳ10Dlg::OnBnClickedButton3()//�޸�ѧ���İ�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	student stu;
	stu.id = ID;
	stu.Gmath = GMATH;
	stu.Gcode = GCODE;
	strcpy_s(stu.name, (LPCSTR)NAME);
	m.modifystudent(stu);
	checkok();
}


void Cѧ���ɼ�����ϵͳ10Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
void Cѧ���ɼ�����ϵͳ10Dlg::checkok()
{
	UpdateData(TRUE);
	show.DeleteAllItems();
	m.alist;
	m.checkstudent();
	list<student>::iterator p;//����list������
	int i = 0;
	CString temp = " ";//ת��CString����
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
	}//��alist������д����ʾ��
}


void Cѧ���ɼ�����ϵͳ10Dlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void Cѧ���ɼ�����ϵͳ10Dlg::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Cѧ���ɼ�����ϵͳ10Dlg::OnStnClickedgcode()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Cѧ���ɼ�����ϵͳ10Dlg::OnBnClickedRadio1()
{
	UpdateData(TRUE);
	if (m_radio1 == 0){
		m.sortstudent(1);
	}
	else m.sortstudent(0);
	checkok();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


HBRUSH Cѧ���ɼ�����ϵͳ10Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (pWnd->GetDlgCtrlID() == IDC_gcode){

		pDC->SelectObject(&m_Font);
	}
	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}
