
// try3Dlg.h : ͷ�ļ�
//

#pragma once
#include "draw.h"
#include <vector>
using namespace std;



// Ctry3Dlg �Ի���
class Ctry3Dlg : public CDialogEx
{
// ����
public:
	Ctry3Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TRY3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
};
