#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <dos.h>

void lineDDA(int xa, int ya, int xb, int yb)
{
	int dx=xb-xa, dy=yb-ya, steps, k;
	float xIncrement, yIncrement, x1=xa, y1=ya, x2=xb, y2=yb, x=(xa+xb)/2.0, y=(ya+yb)/2.0;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	steps/=4.0;
	xIncrement=float(dx)/float(steps);
	yIncrement=float(dy)/float(steps);
	putpixel(round(x), round(y), WHITE);
	putpixel(round(x1), round(y1), WHITE);
	putpixel(round(x2), round(y2), WHITE);
	for(k=0;k<steps;k++)
	{
		x1+=xIncrement;
		y1+=yIncrement;
		x2-=xIncrement;
		y2-=yIncrement;
		x+=xIncrement;
		y+=yIncrement;
		putpixel(round(x1), round(y1), WHITE);
		putpixel(round(x2), round(y2), WHITE);
		putpixel(round(x), round(y), WHITE);
	}
}

void bresenham(int x1, int y1, int x2, int y2)
{
	int m_new=2*(y2-y1);
	int slope_error_new=m_new-(x2-x1);
	for (int x=x1, y=y1;x<=x2;x++)
	{
		slope_error_new+=m_new;
		if (slope_error_new>=0)
		{
			y++;
			slope_error_new-=2*(x2-x1);
		}
		putpixel(x, y, WHITE);
	}
}

void layout()
{
	setcolor(WHITE);
	settextstyle(1,HORIZ_DIR,5);
	outtextxy(485,262,"3");
	outtextxy(137,260,"9");
	outtextxy(309,435,"6");
	outtextxy(289,87,"12");
    circle(327,285,200);
    circle(327,285,150);
    int r=10;
    double inc=22/14.0;
    inc/=3;
    for(double i=0.0;i<6;i+=inc)
    {
    	lineDDA(327+100*cos(i),285-100*sin(i),327+130*cos(i),285-130*sin(i));
	}
	bresenham(527,285,557,285);
	bresenham(97,285,127,285);
	arc(327,285,0,180,230);
	line(329,36,329,55);
	line(325,36,325,55);
	circle(327,30,7);
	setcolor(LIGHTGREEN);
	outtextxy(207,515,"CLOCK");
}

void hrHand(int hr,int min)
{
	float O;
	O=(hr*(22/7.0/6)-(22/7.0/2))+((min/12)*(22/7.0/30));
	setcolor(BLUE);
	line(327,285,327+80*cos(O),285+80*sin(O));
}
 
void minHand(int min)
{
	float O;
	O=(min*(22/7.0/30)-(22/7.0/2));
	setcolor(RED);
	O*=-1;
	line(327,285,327+100*cos(O),285-100*sin(O));
}

void secHand(int sec)
{
	float O;
	O=sec*((22/7.0)/30)-((22/7.0)/2);
	O*=-1;
	setcolor(YELLOW);
	line(327,285,327+100*cos(O),285-100*sin(O));
}

int main( )
{
    initwindow(800, 600, "First Sample");
    time_t rawtime;
    struct tm*  time_;
	while(1)
	{
	    time(&rawtime);
	    time_ = localtime(&rawtime);
		int hr=time_->tm_hour;
		if(hr>12)
		{
			hr-=12;
		}
		int min=time_->tm_min;
		int sec=time_->tm_sec;
		layout();
		secHand(sec);
		minHand(min);
		hrHand(hr,min);
		delay(100);
		cleardevice();
	}
    return 0;
}