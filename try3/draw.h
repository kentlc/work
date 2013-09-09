#pragma once


class Draw
{
public:
	int radio;
	int linewide;
	int color;
	int x1,y1,x2,y2;
	Draw(int r,int l,int c) ;
	~Draw();
	void draw(CDC& dc);
};