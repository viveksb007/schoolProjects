#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>
// spl= speed of line going up
int spl=1;
int sp=6;
int xp,yp;
int x1l,y1l;
int xc=200,yc=50;
int ry[7],rx[7];
int m=0,p;
void upball(int yc)
{  setcolor(0);
  circle(xp,yp,10);
    setcolor(10);
  circle(xc,yc,10);
xp=xc; yp=yc;
}
void dball(int yc)
{   setcolor(0);
  circle(xp,yp,10);
    setcolor(10);
  circle(xc,yc,10);
xp=xc; yp=yc;
}
void lball(int xc)
{  setcolor(0);
  circle(xp,yp,10);
    setcolor(10);
  circle(xc,yc,10);
xp=xc; yp=yc;
}
void rball(int xc)
{  setcolor(0);
  circle(xp,yp,10);
    setcolor(10);
  circle(xc,yc,10);
xp=xc; yp=yc;
}


void main()
{
int gdriver = DETECT, gmode, errorcode;
int left, top, right, bottom;
initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
setcolor(4);
line(0,30,640,30);

time_t t;
srand((unsigned) time(&t));
for(int i=0;i<=6;i++)
{  x1l=random(640-5+1)+35;
y1l=random(500-300+1)+300;
setcolor(1);
line(x1l,y1l,x1l+100,y1l);
ry[i]=y1l;   rx[i]=x1l;
}

for(i=0;i<=6;i++)
{ ry[i]--;}

// main working
// stage 1
for(int j=0;j<=2000;j++)
{ delay(10);
  // printing lines
 for(i=0;i<=6;i++)
 {  setlinestyle(0,0,3);
  setcolor(0);
  line(rx[i],ry[i]+spl,rx[i]+100,ry[i]+spl);
  line(rx[i],ry[i]+spl+1,rx[i]+100,ry[i]+spl+1);
  setcolor(1);
  line(rx[i],ry[i],rx[i]+100,ry[i]);
  setlinestyle(0,0,0);
 }
 // decreasing y coordinate of line
 for(i=0;i<=6;i++)
 { ry[i]-=spl;}

 // when line reaches max point value reassigned
 for(i=0;i<=6;i++)
 { if((ry[i]>=31)&&(ry[i]<=36))
    { ry[i]=500;}
 }
  // downball, rightball,leftball
	if(m==0)
  {  dball(yc); yc++; }

   if(kbhit())
  { char a=getch();
     switch(a)
   { case 77: rball(xc); xc+=sp; break;
     case 75: lball(xc); xc-=sp;  break;
     case 27: exit(0); break;
    }
  }

for(int j=0;j<=6;j++)
{   if((yc+11<=ry[j])&&(xc>=rx[j])&&(xc<=rx[j]+100)&&(yc+11>=ry[j]-3))
     { m++;}
}
if(m!=0)
{ upball(yc); yc--;}

for(j=0;j<=6;j++)
{
    if((yc+11<=ry[j])&&(xc>=rx[j]+100)&&(yc+11>=ry[j]-4))
     { m=0;}
    else
    if((yc+11<=ry[j])&&(xc<=rx[j])&&(yc+11>=ry[j]-4))
     { m=0;}
}
}
// stage 2
srand((unsigned) time(&t));
for(i=0;i<=6;i++)
{  x1l=random(640-5+1)+35;
  rx[i]=x1l;
}
for(i=0;i<=500;i++)
{ setcolor(0); line(0,31+i,640,31+i); }
for(j=0;j<=2000;j++)
{ delay(10);
  // printing lines
 for(i=0;i<=6;i++)
 {  setlinestyle(0,0,3);
  setcolor(0);
  line(rx[i],ry[i]+spl,rx[i]+100,ry[i]+spl);
  line(rx[i],ry[i]+spl+1,rx[i]+100,ry[i]+spl+1);
  setcolor(1);
  line(rx[i],ry[i],rx[i]+100,ry[i]);
  setlinestyle(0,0,0);
 }
 // decreasing y coordinate of line
 for(i=0;i<=6;i++)
 { ry[i]-=spl;}

 // when line reaches max point value reassigned
 for(i=0;i<=6;i++)
 { if((ry[i]>=31)&&(ry[i]<=36))
    { ry[i]=500;}
 }
  // downball, rightball,leftball
	if(m==0)
  {  dball(yc); yc++; }

   if(kbhit())
  { char a=getch();
     switch(a)
   { case 77: rball(xc); xc+=sp; break;
     case 75: lball(xc); xc-=sp;  break;
     case 27: exit(0); break;
    }
  }

for(int j=0;j<=6;j++)
{   if((yc+11<=ry[j])&&(xc>=rx[j])&&(xc<=rx[j]+100)&&(yc+11>=ry[j]-3))
     { m++;}
}
if(m!=0)
{ upball(yc); yc--;}

for(j=0;j<=6;j++)
{
    if((yc+11<=ry[j])&&(xc>=rx[j]+100)&&(yc+11>=ry[j]-4))
     { m=0;}
    else
    if((yc+11<=ry[j])&&(xc<=rx[j])&&(yc+11>=ry[j]-4))
     { m=0;}
}

}




getch();
}