#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>



void main()
{   int gdriver = DETECT, gmode, errorcode;

   initgraph(&gdriver, &gmode, "c:\\tc\\bgi ");


  // arrow keycheck
 int r=50;
   setcolor(6);
   for(int i=0;i<=500;i++)
   { delay(50);
    if(kbhit())
    { char b=getch();
	      r++;
     switch(b)
    { case 75: circle(200,200,r); break;
     case 77: circle(400,200,r); break;
     case 72: circle(300,100,r); break;
     case 80: circle(300,300,r); break; }
					  } }

getch();}