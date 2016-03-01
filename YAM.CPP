#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>
// spl= speed of line going up
int ubs=1;  //up ball speed
int spl=1;
int sp=5;
int xp,yp,i,j;
int x1l,y1l;
int xc=200,yc=100;
int ry[7],rx[7];
int m=0,p,go=0;int score = 0;
char string[25],hs[25];
int highscore,q=0;
/*void highscore(int score)
{ ifstream iof; ofstream ifo;char line[80];
iof.open("score.txt");
ifo.open("score1.txt");
ifo<<score<<"/n";
while(!ifo.eof())
{  iof>>line;  }
while(!iof.eof())
{
}
}  */
void destroy(int yc)
{ setcolor(0);
circle(xc,yc+1,10);}
void gameover()
{
 setcolor(13);
 settextstyle(4,0,6);
 outtextxy(200,200,"Game Over");  go=5;
  settextstyle(0,0,0);
 }
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
void sc()
{  setcolor(9);
  settextstyle(1,0,2);
 outtextxy(5,0,"SCORE = ");

 setcolor(0);
  settextstyle(1,0,2);
  outtextxy(100,0,string);
 itoa(score, string,10);
 setcolor(9);
  settextstyle(1,0,2);
  outtextxy(100,0,string);
 setcolor(9);
  settextstyle(1,0,2);
 outtextxy(460,0,"HIGH SCORE = ");
 itoa(highscore, hs,10);
 setcolor(9);
  settextstyle(1,0,2);
 outtextxy(610,0,hs);
  settextstyle(0,0,0);
}

void spikes()
{// SPIKES
  int x1=0,x2=5,x3=10,x4=5;
  setcolor(7);
for(int z=0;z<=100;z++)
 { line(x1,30,x2,45);
    x1=x1+10;
   x2=x2+10; }
   for(z=0;z<=100;z++)
{ line(x3,30,x4,45);
  x3=x3+10; x4=x4+10;
  }
}
void main()
{
int gdriver = DETECT, gmode, errorcode;
int left, top, right, bottom;
initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
  setcolor(9);
    settextstyle(1,0,8);
 outtextxy(100,150,"RAPIDROLL");

 delay(5000);
 setcolor(0);
   settextstyle(1,0,8);
 outtextxy(100,150,"RAPIDROLL");
spikes();

 time_t t;
srand((unsigned) time(&t));
for(i=0;i<=6;i++)
{
x1l=random(550-5+1)+5;
y1l=random(950-400+1)+400;
setcolor(15);
line(x1l,y1l,x1l+100,y1l);
ry[i]=y1l;   rx[i]=x1l;

}
for(i=0;i<=6;i++)
{ ry[i]--;}

// main working
// stage 1
 delay(500);
for(int p=0;p<=20000;p++)
{
      if((p>1000)&&(p<2000))
       {   ubs=2,spl=2; }
      if((p>2000)&&(p<3000))
       {   ubs=3,spl=3; }
      if(p>3000)
       {   ubs=4,spl=4; }

  if((yc<=54)||(yc==491))
  { gameover();
 destroy(yc); highscore=score; }
  if(go==5)
  { delay(1000);   break;}
  sc();
 delay(2);
   setlinestyle(0,0,3);
setcolor(4);
line(0,29,640,29);

   // printing lines
 for(i=0;i<=6;i++)
 {
  setlinestyle(0,0,3);
  setcolor(0);
  line(rx[i],ry[i]+spl,rx[i]+100,ry[i]+spl);
  line(rx[i],ry[i]+spl+1,rx[i]+100,ry[i]+spl+1);
  setcolor(15);
  line(rx[i],ry[i],rx[i]+100,ry[i]);
  setlinestyle(0,0,0);
 }
 // decreasing y coordinate of line
 for(i=0;i<=6;i++)
 { ry[i]-=spl;}

 // when line reaches max point value reassigned
 for(i=0;i<=6;i++)
 { if((ry[i]>=46)&&(ry[i]<=51))
    { ry[i]=500;
   setcolor(0);
   line(rx[i],ry[i],rx[i]+100,ry[i]); }
 }
 for(i=0;i<=6;i++)
 {   setlinestyle(0,0,3);
   setcolor(0);
   line(0,47+i,640,47+i);
   setlinestyle(0,0,0);
   }


for(j=0;j<=6;j++)
{  if((yc+11<=ry[j])&&(xc>=rx[j]+11)&&(xc<=rx[j]+100)&&(yc+11>=ry[j]-4))
     { m++;}
}

for(j=0;j<=6;j++)
{
    if((yc+11<=ry[j])&&(xc+10>=rx[j]+110)&&(yc+11>=ry[j]-4))
     { m=0;}
    else
    if((yc+11<=ry[j])&&(xc+10<=rx[j])&&(yc+11>=ry[j]-4))
     { m=0;}
}

  // downball, rightball,leftball
	if(m==0)
  {  dball(yc); yc++; score++; }

   if(kbhit())
  { char a=getch();
     switch(a)
   { case 77: rball(xc); xc+=sp; break;
     case 75: lball(xc); xc-=sp;  break;
     case 27: exit(0); break;
    }
  }

if(m!=0)
{
   upball(yc); yc-=ubs;}


}


getch();
}