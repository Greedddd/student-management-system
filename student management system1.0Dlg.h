
// ѧ���ɼ�����ϵͳ1.0Dlg.h : ͷ�ļ�
//
#include "resource.h"
#pragma once
#include"management.h"
#include "afxcmn.h"
#include "afxwin.h"


// Cѧ���ɼ�����ϵͳ10Dlg �Ի���
class Cѧ���ɼ�����ϵͳ10Dlg : public CDialogEx
{
// ����
public:
	Cѧ���ɼ�����ϵͳ10Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY10_DIALOG };

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
	// �������ֵı༭��
	CString NAME;
	// ����ѧ�ŵı༭��
	int ID;
	// ����ߵ���ѧ�ɼ��ı༭��
	int GMATH;
	// ���������Ƴɼ��ı༭��
	int GCODE;
	management m;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeEdit1();
	
	// ��ʾ��
	CListCtrl show;
	afx_msg void OnBnClickedOk();
	void checkok();
	// �����ı���
	CStatic n_static;
	CFont m_Font;
	CFont i_Font;
	CFont gmath_Font;
	CFont gcode_Font;
	// ѧ���ı���
	CStatic i_static;
	// �����ɼ��ı���
	CStatic gmath_static;
	// ��������ı���
	CStatic gcode_static;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnStnClickedgcode();
	// ����İ�ť
	int m_radio1;
	afx_msg void OnBnClickedRadio1();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
