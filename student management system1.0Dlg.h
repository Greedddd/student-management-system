
// 学生成绩管理系统1.0Dlg.h : 头文件
//
#include "resource.h"
#pragma once
#include"management.h"
#include "afxcmn.h"
#include "afxwin.h"


// C学生成绩管理系统10Dlg 对话框
class C学生成绩管理系统10Dlg : public CDialogEx
{
// 构造
public:
	C学生成绩管理系统10Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY10_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 输入名字的编辑框
	CString NAME;
	// 输入学号的编辑框
	int ID;
	// 输入高等数学成绩的编辑框
	int GMATH;
	// 输入程序设计成绩的编辑框
	int GCODE;
	management m;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeEdit1();
	
	// 显示框
	CListCtrl show;
	afx_msg void OnBnClickedOk();
	void checkok();
	// 姓名文本框
	CStatic n_static;
	CFont m_Font;
	CFont i_Font;
	CFont gmath_Font;
	CFont gcode_Font;
	// 学号文本框
	CStatic i_static;
	// 高数成绩文本框
	CStatic gmath_static;
	// 程序设计文本框
	CStatic gcode_static;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnStnClickedgcode();
	// 排序的按钮
	int m_radio1;
	afx_msg void OnBnClickedRadio1();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
