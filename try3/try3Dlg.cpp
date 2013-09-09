
// try3Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "try3.h"
#include "try3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctry3Dlg 对话框




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


// Ctry3Dlg 消息处理程序

BOOL Ctry3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
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


	ModifyStyle(WS_THICKFRAME, 0, SWP_FRAMECHANGED|SWP_DRAWFRAME);    //禁止对话框大小改变

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctry3Dlg::OnPaint()
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


		CPaintDC dc(this);
		RECT rect;
		GetClientRect(&rect);//得到可绘制的区域范围

		CWnd*c=GetDlgItem(IDC_PICTURE);//获取控件句柄,用于确定显示范围
		c->GetWindowRect(&rect);//相对于屏幕
		ScreenToClient(&rect);//相对于父控件
		if(img) img->StretchBlt(dc,rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top,0,0,img->GetWidth(),img->GetHeight(),SRCCOPY);


// 		CDC MemDC; //首先定义一个显示设备对象  
// 		CBitmap MemBitmap;//定义一个位图对象  
// 
// 
// 		MemDC.CreateCompatibleDC(NULL);//创建兼容句柄和位图
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

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ctry3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctry3Dlg::OnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void Ctry3Dlg::OnRadio2()
{
	// TODO: 在此添加命令处理程序代码
	UpdateData(TRUE);
}


void Ctry3Dlg::OnRadio3()
{
	// TODO: 在此添加命令处理程序代码
	UpdateData(TRUE);
}


void Ctry3Dlg::OnRadio4()
{
	// TODO: 在此添加命令处理程序代码
	UpdateData(TRUE);
}


void Ctry3Dlg::OnRadio5()
{
	// TODO: 在此添加命令处理程序代码
	UpdateData(TRUE);
}


void Ctry3Dlg::OnRadio6()
{
	// TODO: 在此添加命令处理程序代码
	UpdateData(TRUE);
}


//void Ctry3Dlg::OnNcRButtonDown(UINT nHitTest, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//
//	CDialogEx::OnNcRButtonDown(nHitTest, point);
//}


//void Ctry3Dlg::OnNcRButtonUp(UINT nHitTest, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//
//	CDialogEx::OnNcRButtonUp(nHitTest, point);
//}


void Ctry3Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    if(tmp==NULL) tmp=new Draw(m_radio1);
	else {delete tmp; tmp=new Draw(m_radio1);}
	tmp->x1=tmp->x2=point.x;
	tmp->y1=tmp->y2=point.y;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void Ctry3Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(tmp)data.push_back(tmp);
	tmp=NULL;
	CDialogEx::OnLButtonUp(nFlags, point);
}


void Ctry3Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if(nFlags&MK_LBUTTON)//鼠标左键处于按下状态才进行处理
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return TRUE;

	return CDialogEx::OnEraseBkgnd(pDC);
}


void Ctry3Dlg::OnBnClickedOpen()
{
	// TODO: 在此添加控件通知处理程序代码

	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,"jpg格式 (*.jpg)|*.jpg|bmp格式 (*.bmp)|*.bmp||",NULL);
	if(dlg.DoModal()==IDOK)
	{
		if(img==NULL) img=new CImage();
		else img->Destroy();//释放以前的图片
		img->Load(dlg.GetPathName());
		InvalidateRect(NULL);
		UpdateWindow();
	}
}


void Ctry3Dlg::OnBnClickedSave()
{
	// TODO: 在此添加控件通知处理程序代码
	CWnd*c=GetDlgItem(IDC_PICTURE);//获取控件句柄
	RECT rect;
	c->GetWindowRect(&rect);//相对于屏幕
	ScreenToClient(&rect);//相对于父控件
	CDC MemDC;//内存句柄，用于缓存图片
	CBitmap MemBitmap;
	MemDC.CreateCompatibleDC(CDC::FromHandle(::GetDC(NULL)));//创建兼容句柄和位图，CDC::FromHandle(::GetDC(NULL))表示获取屏幕句柄
	MemBitmap.CreateCompatibleBitmap(CDC::FromHandle(::GetDC(NULL)),rect.right-rect.left,rect.bottom-rect.top);
	MemDC.SelectObject(&MemBitmap);
	MemDC.BitBlt(0,0,rect.right-rect.left,rect.bottom-rect.top,GetDC(),rect.left,rect.top,SRCCOPY);
	SaveBitmap(*(MemDC.GetCurrentBitmap()),"1.bmp");
	MemDC.DeleteDC();
	MemBitmap.DeleteObject();
}
