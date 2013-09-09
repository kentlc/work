#pragma once


class Draw
{
public:
	int radio;
	int x1,y1,x2,y2;
	Draw(int r) ;
	~Draw();
	void draw(CDC& dc);
};