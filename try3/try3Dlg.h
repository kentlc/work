
// try3Dlg.h : 头文件
//

#pragma once
#include "draw.h"
#include <vector>
using namespace std;



// Ctry3Dlg 对话框
class Ctry3Dlg : public CDialogEx
{
// 构造
public:
	Ctry3Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TRY3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	CButton m_radio1;
//	int m_radio;
	afx_msg void OnClickedRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnRadio5();
	afx_msg void OnRadio6();
	int m_radio1;
	vector<Draw*> data;
	Draw* tmp;
	CImage* img;
//	afx_msg void OnNcRButtonDown(UINT nHitTest, CPoint point);
//	afx_msg void OnNcRButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedOpen();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedClear();
//	int m_linewide;
//	afx_msg void OnNMCustomdrawLinewide(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSliderCtrl m_slider;
	CMFCColorButton m_color;
};
