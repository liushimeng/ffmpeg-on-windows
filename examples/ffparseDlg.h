
// ffparseDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include <vector>

// CffparseDlg 对话框
class CffparseDlg : public CDialogEx
{
// 构造
public:
	CffparseDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_FFPARSE_DIALOG };

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
	std::vector<int> vec_SecondIndex;
	std::vector<int> vec_ThirdIndex;
	CListBox m_CMainListBox;
	CListBox m_CSecondListBox;
	CListBox m_CThirdListBox;
	afx_msg void OnLbnDblclkListMain();
	CEdit m_CShowEdit;
	afx_msg void OnLbnDblclkListSecond();
	CStatic m_CThirdStatic;
	CStatic m_CSecondStatic;
	CStatic m_CMainStatic;
	afx_msg void OnLbnSelchangeListThird();
	int index_first;
	int index_second;
	int index_third;
};
