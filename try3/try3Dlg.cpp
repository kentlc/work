
// try3Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "try3.h"
#include "try3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctry3Dlg �Ի���




Ctry3Dlg::Ctry3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctry3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//  m_radio = 0;
	m_radio1 = 0;
}

void Ctry3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_RADIO1, m_radio1);
	//  DDX_Radio(pDX, IDC_RADIO1, m_radio);
	DDX_Radio(pDX, IDC_RADIO1, m_radio1);
}

BEGIN_MESSAGE_MAP(Ctry3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &Ctry3Dlg::OnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Ctry3Dlg::OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &Ctry3Dlg::OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &Ctry3Dlg::OnRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &Ctry3Dlg::OnRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &Ctry3Dlg::OnRadio6)
//	ON_WM_NCRBUTTONDOWN()
//	ON_WM_NCRBUTTONUP()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_WM_MOUSEMOVE()
ON_WM_ERASEBKGND()
ON_BN_CLICKED(IDC_OPEN, &Ctry3Dlg::OnBnClickedOpen)
ON_BN_CLICKED(IDC_SAVE, &Ctry3Dlg::OnBnClickedSave)
END_MESSAGE_MAP()


// Ctry3Dlg ��Ϣ�������

BOOL Ctry3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	RECT rect;
	GetClientRect(&rect);
	tmp =NULL;
	img=NULL;

	GetDlgItem(IDC_RADIO1)->MoveWindow(rect.right-rect.left-75,10,70,15);
	GetDlgItem(IDC_RADIO2)->MoveWindow(rect.right-rect.left-75,30,70,15);
	GetDlgItem(IDC_RADIO3)->MoveWindow(rect.right-rect.left-75,50,70,15);
	GetDlgItem(IDC_RADIO4)->MoveWindow(rect.right-rect.left-75,70,70,15);
	GetDlgItem(IDC_RADIO5)->MoveWindow(rect.right-rect.left-75,90,70,15);
	GetDlgItem(IDC_RADIO6)->MoveWindow(rect.right-rect.left-75,110,70,15);
	GetDlgItem(IDC_PICTURE)->MoveWindow(rect.left,rect.top,rect.right-rect.left-80,rect.bottom);
	GetDlgItem(IDC_CLEAR)->MoveWindow(rect.right-rect.left-75,rect.bottom-160,70,30);
	GetDlgItem(IDC_OPEN)->MoveWindow(rect.right-rect.left-75,rect.bottom-120,70,30);
	GetDlgItem(IDC_SAVE)->MoveWindow(rect.right-rect.left-75,rect.bottom-80,70,30);
	GetDlgItem(IDCANCEL)->MoveWindow(rect.right-rect.left-75,rect.bottom-40,70,30);


	ModifyStyle(WS_THICKFRAME, 0, SWP_FRAMECHANGED|SWP_DRAWFRAME);    //��ֹ�Ի����С�ı�

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ctry3Dlg::OnPaint()
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


		CPaintDC dc(this);
		RECT rect;
		GetClientRect(&rect);//�õ��ɻ��Ƶ�����Χ

		CWnd*c=GetDlgItem(IDC_PICTURE);//��ȡ�ؼ����,����ȷ����ʾ��Χ
		c->GetWindowRect(&rect);//�������Ļ
		ScreenToClient(&rect);//����ڸ��ؼ�
		if(img) img->StretchBlt(dc,rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top,0,0,img->GetWidth(),img->GetHeight(),SRCCOPY);


// 		CDC MemDC; //���ȶ���һ����ʾ�豸����  
// 		CBitmap MemBitmap;//����һ��λͼ����  
// 
// 
// 		MemDC.CreateCompatibleDC(NULL);//�������ݾ����λͼ
// 		MemBitmap.CreateCompatibleBitmap(CDC::FromHandle(::GetDC(NULL)),rect.right-rect.left,rect.bottom-rect.top);
// 		
//  		CBitmap *pOldBit=MemDC.SelectObject(&MemBitmap);  
// 		MemDC.FillSolidRect(0,0,rect.right-rect.left,rect.bottom-rect.top,RGB(255,255,255)); ;
// 
// 
		CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		dc.SelectObject(pBrush);

		if(tmp)tmp->draw(dc);
		for(unsigned int i=0;i<data.size();i++)
			data[i]->draw(dc);


// 		dc.BitBlt(0,0,rect.right-rect.left,rect.bottom-rect.top,&MemDC,0,0,SRCCOPY);  
// 
// 		MemDC.DeleteDC();
// 		MemBitmap.DeleteObject();


		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Ctry3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctry3Dlg::OnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void Ctry3Dlg::OnRadio2()
{
	// TODO: �ڴ���������������
	UpdateData(TRUE);
}


void Ctry3Dlg::OnRadio3()
{
	// TODO: �ڴ���������������
	UpdateData(TRUE);
}


void Ctry3Dlg::OnRadio4()
{
	// TODO: �ڴ���������������
	UpdateData(TRUE);
}


void Ctry3Dlg::OnRadio5()
{
	// TODO: �ڴ���������������
	UpdateData(TRUE);
}


void Ctry3Dlg::OnRadio6()
{
	// TODO: �ڴ���������������
	UpdateData(TRUE);
}


//void Ctry3Dlg::OnNcRButtonDown(UINT nHitTest, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	CDialogEx::OnNcRButtonDown(nHitTest, point);
//}


//void Ctry3Dlg::OnNcRButtonUp(UINT nHitTest, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	CDialogEx::OnNcRButtonUp(nHitTest, point);
//}


void Ctry3Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    if(tmp==NULL) tmp=new Draw(m_radio1);
	else {delete tmp; tmp=new Draw(m_radio1);}
	tmp->x1=tmp->x2=point.x;
	tmp->y1=tmp->y2=point.y;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void Ctry3Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(tmp)data.push_back(tmp);
	tmp=NULL;
	CDialogEx::OnLButtonUp(nFlags, point);
}


void Ctry3Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	if(nFlags&MK_LBUTTON)//���������ڰ���״̬�Ž��д���
	{

		if (m_radio1==1||m_radio1==5)
		{
			if(tmp){tmp->x2=point.x;tmp->y2=point.y;data.push_back(tmp);}
			tmp=NULL;
			tmp=new Draw(m_radio1);
			tmp->x1=tmp->x2=point.x;
			tmp->y1=tmp->y2=point.y;
		}
		else
			if(tmp){tmp->x2=point.x;tmp->y2=point.y;}
		Invalidate();
		UpdateWindow();
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


BOOL Ctry3Dlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	return TRUE;

	return CDialogEx::OnEraseBkgnd(pDC);
}


void Ctry3Dlg::OnBnClickedOpen()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,"jpg��ʽ (*.jpg)|*.jpg|bmp��ʽ (*.bmp)|*.bmp||",NULL);
	if(dlg.DoModal()==IDOK)
	{
		if(img==NULL) img=new CImage();
		else img->Destroy();//�ͷ���ǰ��ͼƬ
		img->Load(dlg.GetPathName());
		InvalidateRect(NULL);
		UpdateWindow();
	}
}


void Ctry3Dlg::OnBnClickedSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CWnd*c=GetDlgItem(IDC_PICTURE);//��ȡ�ؼ����
	RECT rect;
	c->GetWindowRect(&rect);//�������Ļ
	ScreenToClient(&rect);//����ڸ��ؼ�
	CDC MemDC;//�ڴ��������ڻ���ͼƬ
	CBitmap MemBitmap;
	MemDC.CreateCompatibleDC(CDC::FromHandle(::GetDC(NULL)));//�������ݾ����λͼ��CDC::FromHandle(::GetDC(NULL))��ʾ��ȡ��Ļ���
	MemBitmap.CreateCompatibleBitmap(CDC::FromHandle(::GetDC(NULL)),rect.right-rect.left,rect.bottom-rect.top);
	MemDC.SelectObject(&MemBitmap);
	MemDC.BitBlt(0,0,rect.right-rect.left,rect.bottom-rect.top,GetDC(),rect.left,rect.top,SRCCOPY);
	SaveBitmap(*(MemDC.GetCurrentBitmap()),"1.bmp");
	MemDC.DeleteDC();
	MemBitmap.DeleteObject();
}
