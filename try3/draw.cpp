#include "stdafx.h"
#include "draw.h"

Draw::Draw(int r):radio(r)
{

}

Draw::~Draw()
{

}


void Draw::draw (CDC& dc)
{
	switch(radio)
	{
	case 1:
		dc.MoveTo(x1,y1);
		dc.LineTo(x2,y2);
		break;
	case 2:
		dc.MoveTo(x1,y1);
		dc.LineTo(x2,y2);
		break;
	case 3:
		dc.Rectangle(x1,y1,x2,y2);
		break;
	case 4:
		dc.Ellipse(x1,y1,x2,y2);
		break;
	case 5:
// 		dc.SelectObject(&OLD);
// 		dc.MoveTo(x1,y1);                
// 		dc.LineTo(x2,y2);
// 		OLD.DeleteObject();
		break;
	}
}