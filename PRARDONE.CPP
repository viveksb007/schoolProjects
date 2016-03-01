// power wheel/////
#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<time.h>
#include<fstream.h>
#include<ctype.h>
//rmc=random movement of choppers
// ml=mainloop
//noti=no. of times playing
//cc,cc1,y,y1=chopper coordinate
//q is angle in radians for gun movement
//xm,xm1,ym,ym1=coordinate of manfall
//m,m1,f=used in conditions
//r1,r2=random variables
//xd,xp,yd,yp=jet coordinates
//btd=batman down
//sc: char score
//score score int
//zo used in some loops
//level time
//coc=chopper cancel
//go=game over
//ltc=level time chopper , ltj=level time jet
// coj= cancel of jet
// sorting man`s x-coordinate min. or max. for game over//
// no. of man with min. or max. x-coordinate//
int smcr,smcl,nomr,noml;
struct hsac
{ int hs;
};
int score=0,btdl[4],btdr[4],btdcl=0,btdcr=0,r=0,l=0,cc=-100,cc1=900,go=0,ltc=8,ltj=7;
int zo,i,j,ml,noti=8,m=0,xm,ym,xm1,ym1,y=27,y1=65,m1=0,r1,r2,yd=40,yp=40;
int xb1,xb2,yb1,yb2,mb1,mb2,b1,b2,ymp=433,bd=0,bd1=0,f=0,coc=0,coc1=0,rmc,coj=0,coj1=0;
double q=1.6; fstream high,highw;
char sc[4],hsc[4];hsac hisc,hsic;
float sta[20][2];

 void escape()
{
   setcolor(3);
    outtextxy(200,200,"Do You Want Exit??");
    outtextxy(295,225,"Y/N");
   get1:
  char choice=getch();
    if(choice=='n')
   { setcolor(0);
     outtextxy(200,200,"Do You Want Exit??");
     outtextxy(295,225,"Y/N");
     goto got;
   }
    else
   {
     if(choice=='y')
    {
   if(score>hisc.hs)
  {
   hsic.hs=score;
   hisc.hs=score;
   highw.seekg(0);
   highw.write((char*)&hsic,sizeof(hsic));
  }else
  { highw.write((char*)&hisc,sizeof(hisc));

  }

     exit(0);
    }
     else
     goto get1;
   }
 got:
}

void batmanup(int xm)
{

 ym=434;
  for(i=0;i<=3;i++)
 {
  setcolor(1);
     circle(xm,ym-4,2);
  rectangle(xm-2,ym-2,xm+2,ym+7);
  rectangle(xm+2,ym-2,xm+5,ym+1);
  rectangle(xm-2,ym-2,xm-5,ym+1);
  rectangle(xm+2,ym+7,xm+4,ym+15);
  rectangle(xm-2,ym+7,xm-4,ym+15);
  ym-=19;}
  if(xm==361)
  { xm-=10;}
  if(xm==279)
  { xm+=10;}

   ym+=5;
  circle(xm,ym-4,2);
  rectangle(xm-2,ym-2,xm+2,ym+7);
  rectangle(xm+2,ym-2,xm+5,ym+1);
  rectangle(xm-2,ym-2,xm-5,ym+1);
  rectangle(xm+2,ym+7,xm+4,ym+15);
  rectangle(xm-2,ym+7,xm-4,ym+15);

}
void intro()
{
  sound(7);
  setcolor(3);int parad=70;
  settextstyle(3,0,9);
  outtextxy(parad+60,100,"P");
  outtextxy(parad+95,100,"A");
  outtextxy(parad+150,100,"R");
  outtextxy(parad+200,100,"A");
  outtextxy(parad+250,100,"T");
  outtextxy(parad+300,100,"R");
  outtextxy(parad+345,100,"O");
  outtextxy(parad+400,100,"N");
  int parad1=parad/10-6;
  setcolor(9);
  outtextxy(parad+60,parad1+100,"P");
  outtextxy(parad+95,parad1+100,"A");
  outtextxy(parad+150,parad1+100,"R");
  outtextxy(parad+200,parad1+100,"A");
  outtextxy(parad+250,parad1+100,"T");
  outtextxy(parad+300,parad1+100,"R");
  outtextxy(parad+345,parad1+100,"O");
  outtextxy(parad+400,parad1+100,"N");


  delay(2500);

  cleardevice();
}
 void press()
{
   int x=300,y=150;
   settextstyle(2,0,6);
/////////////////////////////////////////
   outtextxy(x,y-50+2,"Shoot");
   rectangle(x,y-27,x+45,y+18);
   rectangle(x+91,y+66,x+46,y+21);
   rectangle(x-1,y+21,x-46,y+67);
   for(int lala=0;lala<=5;lala++)
  {
   line(x+23-lala,y-13+lala,x+23+lala,y-13+lala);
  }
//////////////////////////////////////

    line(x+60,y+45,x+80,y+45);

  for(lala=0;lala>=-5;lala--)
 {
     line(x+80+lala,y+45-lala,x+80+lala,y+45+lala);
 }
  outtextxy(x+100,y+45,"Right");

////////////////////////////////////////

    line(x-15,y+45,x-35,y+45);

  for(lala=0;lala<=5;lala++)
 {
     line(x-35+lala,y+45-lala,x-35+lala,y+45+lala);
 }
  outtextxy(x-85,y+45,"Left");
/////////////////////////////////
   setcolor(3);
   line(x+23,y-9,x+23,y+5);
   x+=1;y+=1;
    for( lala=0;lala<=5;lala++)
  {
   line(x+23-lala,y-13+lala,x+22+lala,y-13+lala);
  }
   outtextxy(x-2,y-52+2,"Shoot");
    line(x-15,y+45,x-35,y+45);
  outtextxy(x-85-2,y+45-2,"Left");

  for(lala=0;lala<=5;lala++)
 {
     line(x-35+lala,y+45-lala,x-35+lala,y+45+lala);
 }

    line(x+60,y+45,x+80,y+45);

  for(lala=0;lala>=-5;lala--)
 {
     line(x+80+lala,y+45-lala,x+80+lala,y+45+lala);
 }

 ///////////////////////////
   rectangle(x,y-27,x+45,y+18);
   rectangle(x+91,y+66,x+46,y+21);
   rectangle(x-1,y+21,x-46,y+67);
  outtextxy(x+100-2,y+45-2,"Right");

   x=300,y=350;
   setcolor(9);
   settextstyle(8,0,6);
   outtextxy(60,335,"Press");
   outtextxy(350,335,"to begin.");
   setcolor(3);
   settextstyle(8,0,6);
   outtextxy(62,336,"Press");
   outtextxy(352,336,"to begin.");
   setcolor(7);
   rectangle(x+20,y-15,x-30,y+20);
   rectangle(x+20,y+60,x-70,y+20);
   setcolor(3);
   line(x+10,y+38,x+10,y+30);
   line(x+10,y+38,x-10,y+38);
    for(int i=0;i<4;i++)
   {
    line(x-10-i,y+41-i,x-10-i,y+35+i);
   }
   settextstyle(50,0,-5);
   outtextxy(x-60,y+35,"Enter");
   setcolor(9);
   line(x+11,y+38,x+11,y+30);
   line(x+11,y+38,x-9,y+38);
    for( i=0;i<4;i++)
   {
    line(x-9-i,y+41-i,x-9-i,y+35+i);
   }
   settextstyle(50,0,-5);
   outtextxy(x-59,y+36,"Enter");
   setcolor(0);
   line(x-29,y+20,x+19,y+20);
   char a;
    do
   {
    a=getch();
   }
    while(a!=13);
    int yln=0;   // to black screen after pressing enter
    for(int ln=0;ln<=600;ln++)
   {
    setcolor(0);
    line(0,yln,650,yln);
    yln++;
   }

}

 void gameover()
{
  // tank destroy//

 setcolor(0);
  for(i=0;i<10;i++)
 {
  arc(320,375,0,180,16-i);
 }
 for(i=0;i<20;i++)
 {
  arc(320,379,0,180,40-i);
 }

  ////////////////////
  setcolor(3);
  outtextxy(270,200,"GAME OVER");
  go=5;
    if(score>hisc.hs)
 {
    hsic.hs=score;
    hisc.hs=score;
  highw.seekg(0);
  highw.write((char*)&hsic,sizeof(hsic));

 }
}

//////////////////BASE///////////////////////////////////////////////////////
void base()
{
///////////////////////////INITALDRAWING////////////////////////////////////
  setlinestyle(0,0,3);
  setcolor(3);
  for(int j=0;j<=2;j++)
 {
  line(320+(16*cos(q)),379-(16*sin(q)),320+(35*cos(q)),379-(35*sin(q)));
  q-=.06;
 }
  q+=.12;
  setlinestyle(0,0,0);
  setcolor(14);
   for(int i=0;i<2;i++)
  {
   line(0,450+i,650,450+i);
  }
  for(i=0;i<50;i++)
 {
  setcolor(4);
  rectangle(285+i,380+i,355-i,449-i);
 }
   setcolor(6);
   for(i=0;i<10;i++)
  {
   rectangle(309+i,370+i,332-i,378-i);
  }
  for(i=0;i<15;i++)
 {
  arc(320,379,0,180,15-i);
 }
////TEXT/////////////////////////////////////////////////////////////////////

  settextstyle(1,0,3);
  outtextxy(20,450,"SCORE");
  outtextxy(95,448,":");
  outtextxy(562,448,":" );
  outtextxy(420,450,"HIGH SCORE");
  itoa(score,sc,10);
  setcolor(2);
  outtextxy(102,450,sc);
  itoa(hisc.hs,hsc,10);
  setcolor(2);
  outtextxy(569,450,hsc);
}
///////////////BULLET////////////////////////////////////////////////////////
 void bullet(float ang=500)
{
  if( ang!=500)
 {
   for(int i=0;i<20;i++)
  {
    if(sta[i][0]==0)
   {
    sta[i][0]=ang;
   if(score>0)
  {  score-=1;
    itoa(score,sc,10);
    setcolor(0);
     for(int i=0;i<20;i++)
    {
     rectangle(98+i,454+i,160-i,480-i);
    }
    setcolor(2);
    outtextxy(102,450,sc);
}
    break;
   }
  }

   for(i=0;i<20;i++)
  {
    if(sta[i][0]!=0)
   {
     setcolor(5);
     for(int j=0;j<=2;j++)
    {
     setcolor(0);
     circle(320+((sta[i][1]+34.5+1)*cos(sta[i][0])),379-((sta[i][1]+34.5+1)*sin(sta[i][0])),1+j);
     setcolor(3);
     circle(320+((sta[i][1]+40.5+1)*cos(sta[i][0])),379-((sta[i][1]+40.5+1)*sin(sta[i][0])),1+j);
     sta[i][1]+=2;
    }
   }
  }
 }
   else
  {
   for(int i=0 ; i<20; i++)
  {
    if(sta[i][0]!=0)
   {
    setcolor(5);
     for(int j=0;j<=2;j++)
    {
     setcolor(0);
     circle(320+((sta[i][1]+34.5+1)*cos(sta[i][0])),379-((sta[i][1]+34.5+1)*sin(sta[i][0])),1+j);
     setcolor(3);
     circle(320+((sta[i][1]+40.5+1)*cos(sta[i][0])),379-((sta[i][1]+40.5+1)*sin(sta[i][0])),1+j);
     sta[i][1]+=2;
    }
   }
  }
 }
  for(int i=0;i<20;i++)
 {
   if(sta[i][1]>= 700)
  {
   sta[i][0]=0;
   sta[i][1]=0;
  }
 }
}
/////////////////////////////////////////////////////////////////////////////
////////////////////////////////GUNRIGHT/////////////////////////////////////
 void gunr()
{
  if(q>=0.13)
 {
  setcolor(0);
  setlinestyle(0,0,3);
  q=q+.06;
  line(320+(16*cos(q)),379-(16*sin(q)),320+(35*cos(q)),379-(35*sin(q)));
  q-=0.06;
  setcolor(3);
   for(int j=0;j<=2;j++)
  {
   line(320+(16*cos(q)),379-(16*sin(q)),320+(35*cos(q)),379-(35*sin(q)));
   q-=.06;
  }
  q+=.12;f=1;
 }
  setlinestyle(0,0,0);
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////GUNLEFT/////////////////////////////////////////
  void gunl()
{
   if(q<=3.01)
 {
   setcolor(0);
   setlinestyle(0,0,3);
   q=q-.06;
   line(320+(16*cos(q)),379-(16*sin(q)),320+(35*cos(q)),379-(35*sin(q)));
   q+=0.06;
   setcolor(3);
   for(int j=0;j<=2;j++)
  {
   line(320+(16*cos(q)),379-(16*sin(q)),320+(35*cos(q)),379-(35*sin(q)));
   q+=.06;
  }
   q-=.12;
   f=2;
  }
   setlinestyle(0,0,0);
 }

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////BOMBONE/////////////////////////////////////////

 void bomb1()
{
   setcolor(0);
   for(int z1=0;z1<=4;z1++)
  {
   circle(((yb1-380)/mb1)+320,yb1-1,4-z1);
  }
   xb1=((yb1-379)/mb1)+320;
   setcolor(7);

   for(z1=0;z1<=4;z1++)
  {
   circle(xb1,yb1,4-z1);
  }
   yb1++;
   xb1=((yb1-379)/mb1)+320;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////BOMBTWO/////////////////////////////////////////

void bomb2()
{
  setcolor(0);
  for(int z1=0;z1<=4;z1++)
 {
  circle(((yb2-380)/mb2)+320,yb2-1,4-z1);
 }
  xb2=((yb2-379)/mb2)+320;
  setcolor(7);
  for( z1=0;z1<=4;z1++)
 {
  circle(xb2,yb2,4-z1);
 }
  yb2++;
  xb2=((yb2-379)/mb2)+320;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////BATMANLA////////////////////////////////////////

 void batmanla(int xm)
{
  xm--;
  setcolor(0);
  circle(xm,ymp-4,2);
  rectangle(xm-2,ymp-2,xm+2,ymp+7);
  rectangle(xm+2,ymp-2,xm+5,ymp+1);
  rectangle(xm-2,ymp-2,xm-5,ymp+1);
  rectangle(xm+2,ymp+7,xm+4,ymp+15);
  rectangle(xm-2,ymp+7,xm-4,ymp+15);
  xm++;
  setcolor(1);
  circle(xm,ymp-4,2);
  rectangle(xm-2,ymp-2,xm+2,ymp+7);
  rectangle(xm+2,ymp-2,xm+5,ymp+1);
  rectangle(xm-2,ymp-2,xm-5,ymp+1);
  rectangle(xm+2,ymp+7,xm+4,ymp+15);
  rectangle(xm-2,ymp+7,xm-4,ymp+15);
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////BATMANRA////////////////////////////////////////

 void batmanra(int xm)
{
  xm++;
  setcolor(0);
  circle(xm,ymp-4,2);
  rectangle(xm-2,ymp-2,xm+2,ymp+7);
  rectangle(xm+2,ymp-2,xm+5,ymp+1);
  rectangle(xm-2,ymp-2,xm-5,ymp+1);
  rectangle(xm+2,ymp+7,xm+4,ymp+15);
  rectangle(xm-2,ymp+7,xm-4,ymp+15);
  xm--;
  setcolor(1);
  circle(xm,ymp-4,2);
  rectangle(xm-2,ymp-2,xm+2,ymp+7);
  rectangle(xm+2,ymp-2,xm+5,ymp+1);
  rectangle(xm-2,ymp-2,xm-5,ymp+1);
  rectangle(xm+2,ymp+7,xm+4,ymp+15);
  rectangle(xm-2,ymp+7,xm-4,ymp+15);
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////BATMAN//////////////////////////////////////////

 void batman()
{
  if(cc==r1)
 {
  m++;
  ym=y1+13;
  xm=cc;
 }

  if(m==1)
 {
  ym--;
  setcolor(0);
  circle(xm,ym-4,2);
  rectangle(xm-2,ym-2,xm+2,ym+7);
  rectangle(xm+2,ym-2,xm+5,ym+1);
  rectangle(xm-2,ym-2,xm-5,ym+1);
  rectangle(xm+2,ym+7,xm+4,ym+15);
  rectangle(xm-2,ym+7,xm-4,ym+15);
  ym++;
  setcolor(1);
  circle(xm,ym-4,2);
  rectangle(xm-2,ym-2,xm+2,ym+7);
  rectangle(xm+2,ym-2,xm+5,ym+1);
  rectangle(xm-2,ym-2,xm-5,ym+1);
  rectangle(xm+2,ym+7,xm+4,ym+15);
  rectangle(xm-2,ym+7,xm-4,ym+15);
  ym++;
 }



   if(ym==434)
  {
   bd=1;
  }
   if(ym==140)
  {
   m++;
  }
   if((m==2)&&(ym<=434))
  {
   ym--;
   setcolor(0);
   circle(xm,ym-4,2);
   rectangle(xm-2,ym-2,xm+2,ym+7);
   rectangle(xm+2,ym-2,xm+5,ym+1);
   rectangle(xm-2,ym-2,xm-5,ym+1);
   rectangle(xm+2,ym+7,xm+4,ym+15);
   rectangle(xm-2,ym+7,xm-4,ym+15);
   line(xm-2,ym-2,xm-10,ym-15);
   line(xm+2,ym-2,xm+10,ym-15);
   line(xm-10,ym-15,xm+10,ym-15);
   arc(xm,ym-15,0,180,10);
   ym++;
   setcolor(1);
   circle(xm,ym-4,2);
   rectangle(xm-2,ym-2,xm+2,ym+7);
   rectangle(xm+2,ym-2,xm+5,ym+1);
   rectangle(xm-2,ym-2,xm-5,ym+1);
   rectangle(xm+2,ym+7,xm+4,ym+15);
   rectangle(xm-2,ym+7,xm-4,ym+15);
    if(ym!=434)
   {
    setcolor(3);
    line(xm-2,ym-2,xm-10,ym-15);
    line(xm+2,ym-2,xm+10,ym-15);
    line(xm-10,ym-15,xm+10,ym-15);
    arc(xm,ym-15,0,180,10);
    }
    ym++;
  }

    if(cc1==r2)
   {
    m1++ ;
    ym1=y+13;
    xm1=cc1;
   }
    if(m1==1)
   {
    ym1--;
    setcolor(0);
    circle(xm1,ym1-4,2);
    rectangle(xm1-2,ym1-2,xm1+2,ym1+7);
    rectangle(xm1+2,ym1-2,xm1+5,ym1+1);
    rectangle(xm1-2,ym1-2,xm1-5,ym1+1);
    rectangle(xm1+2,ym1+7,xm1+4,ym1+15);
    rectangle(xm1-2,ym1+7,xm1-4,ym1+15);
    ym1++;
    setcolor(1);
    circle(xm1,ym1-4,2);
    rectangle(xm1-2,ym1-2,xm1+2,ym1+7);
    rectangle(xm1+2,ym1-2,xm1+5,ym1+1);
    rectangle(xm1-2,ym1-2,xm1-5,ym1+1);
    rectangle(xm1+2,ym1+7,xm1+4,ym1+15);
    rectangle(xm1-2,ym1+7,xm1-4,ym1+15);
    ym1++;
   }

   if(ym1==434)
   {
    bd1=1;
   }

    if(ym1==140)
   {
    m1++;
   }

    if((m1==2)&&(ym1<=434))
   {
    ym1--;
    setcolor(0);
    circle(xm1,ym1-4,2);
    rectangle(xm1-2,ym1-2,xm1+2,ym1+7);
    rectangle(xm1+2,ym1-2,xm1+5,ym1+1);
    rectangle(xm1-2,ym1-2,xm1-5,ym1+1);
    rectangle(xm1+2,ym1+7,xm1+4,ym1+15);
    rectangle(xm1-2,ym1+7,xm1-4,ym1+15);
    line(xm1-2,ym1-2,xm1-10,ym1-15);
    line(xm1+2,ym1-2,xm1+10,ym1-15);
    line(xm1-10,ym1-15,xm1+10,ym1-15);
    arc(xm1,ym1-15,0,180,10);
    ym1++;
    setcolor(1);
    circle(xm1,ym1-4,2);
    rectangle(xm1-2,ym1-2,xm1+2,ym1+7);
    rectangle(xm1+2,ym1-2,xm1+5,ym1+1);
    rectangle(xm1-2,ym1-2,xm1-5,ym1+1);
    rectangle(xm1+2,ym1+7,xm1+4,ym1+15);
    rectangle(xm1-2,ym1+7,xm1-4,ym1+15);
    if(ym1!=434)
   {
    setcolor(3);
    line(xm1-2,ym1-2,xm1-10,ym1-15);
    line(xm1+2,ym1-2,xm1+10,ym1-15);
    line(xm1-10,ym1-15,xm1+10,ym1-15);
    arc(xm1,ym1-15,0,180,10);
   }
    ym1++;
  }
 }

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////CHOPPERL////////////////////////////////////////

 void chopperl(int x)
{
 setcolor(0);
 rectangle(x-15+1,y-10,x+15+1,y+10);
 line(x-15+1,y-10,x-25+1,y+10);
 line(x-15+1,y+10,x-25+1,y+10);
 line(x+15+1,y-2,x+35+1,y-2);
 line(x+15+1,y+2,x+35+1,y+2);
 circle(x+40+1,y,6);
 putpixel(x+40+1,y,0 );
 line(x-2+1,y-10,x-2+1,y-17);
 line(x+2+1,y-10,x+2+1,y-17);
 line(x-18+1,y-17,x+18+1,y-17);
 line(x-15+1,y+3,x-20+1,y+3);
 line(x-10+1,y+10,x-10+1,y+13);
 line(x+7+1,y+10,x+7+1,y+13);
 line(x-18+1,y+13,x+13+1,y+13);
 setcolor(0);
 line(x-15+1,y+4,x-15+1,y+9);
 setcolor(10);
 rectangle(x-15,y-10,x+15,y+10);
 line(x-15,y-10,x-25,y+10);
 line(x-15,y+10,x-25,y+10);
 line(x+15,y-2,x+35,y-2);
 line(x+15,y+2,x+35,y+2);
 setcolor(11);
 circle(x+40,y,6);
 putpixel(x+40,y,7 );
 line(x-2,y-10,x-2,y-17);
 line(x+2,y-10,x+2,y-17);
 line(x-18,y-17,x+18,y-17);
 line(x-15,y+3,x-20,y+3);
 line(x-10,y+10,x-10,y+13);
 line(x+7,y+10,x+7,y+13);
 line(x-18,y+13,x+13,y+13);
 setcolor(0);
 line(x-15,y+4,x-15,y+9);
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////CHOPPERR////////////////////////////////////////

 void chopperr(int x1)
{
 setcolor(0);
 rectangle(x1+15,y1-10,x1-15,y1+10);
 line(x1+14,y1-10,x1+24,y1+10);
 line(x1+14,y1+10,x1+24,y1+10);
 line(x1-16,y1-2,x1-36,y1-2);
 line(x1-16,y1+2,x1-36,y1+2);
 circle(x1-42,y1,6);
 putpixel(x1-42,y1,0);
 line(x1+1,y1-10,x1+1,y1-17);
 line(x1-3,y1-10,x1-3,y1-17);
 line(x1+17,y1-17,x1-19,y1-17);
 line(x1+16,y1+3,x1+21,y1+3);
 line(x1+9,y1+10,x1+9,y1+13);
 line(x1-8,y1+10,x1-8,y1+13);
 line(x1+17,y1+13,x1-14,y1+13);
 setcolor(0);
 line(x1+15,y1+4,x1+15,y1+9);
 setcolor(10);
 rectangle(x1+16,y1-10,x1-14,y1+10);
 line(x1+15,y1-10,x1+25,y1+10);
 line(x1+15,y1+10,x1+25,y1+10);
 line(x1-15,y1-2,x1-35,y1-2);
 line(x1-15,y1+2,x1-35,y1+2);
 setcolor(3);
 circle(x1-41,y1,6);
 putpixel(x1-41,y1,12);
 line(x1+2,y1-10,x1+2,y1-17);
 line(x1-2,y1-10,x1-2,y1-17);
 line(x1+18,y1-17,x1-18,y1-17);
 line(x1+17,y1+3,x1+22,y1+3);
 line(x1+10,y1+10,x1+10,y1+13);
 line(x1-7,y1+10,x1-7,y1+13);
 line(x1+18,y1+13,x1-13,y1+13);
 setcolor(0);
 line(x1+16,y1+4,x1+16,y1+9);
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////JETL////////////////////////////////////////////

 void jetl(int xd)
{
 xd++;
 setcolor(0);
 line(xd+20,yd+5,xd-45,yd+5);
 line(xd+20,yd+5,xd+20,yd-20);
 line(xd+20,yd-20,xd+10,yd-20);
 line(xd+10,yd-20,xd+5,yd-5);
 line(xd+5,yd-5,xd-30,yd-10);
 line(xd-30,yd-10,xd-45,yd+5);
 line(xd-30,yd,xd-30,yd-10);
 line(xd-30,yd,xd-40,yd);
 xd--;
 setcolor(10);
 line(xd+20,yd+5,xd-45,yd+5);
 line(xd+20,yd+5,xd+20,yd-20);
 line(xd+20,yd-20,xd+10,yd-20);
 line(xd+10,yd-20,xd+5,yd-5);
 line(xd+5,yd-5,xd-30,yd-10);
 line(xd-30,yd-10,xd-45,yd+5);
 setcolor(11);
 line(xd-30,yd,xd-30,yd-10);
 line(xd-30,yd,xd-40,yd);
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////JETR////////////////////////////////////////////

 void jetr(int xp)
{
 xp--;
 setcolor(0);
 line(xp-20,yp+5,xp+45,yp+5);
 line(xp-20,yp+5,xp-20,yp-20);
 line(xp-20,yp-20,xp-10,yp-20);
 line(xp-10,yp-20,xp-5,yp-5);
 line(xp-5,yp-5,xp+30,yp-10);
 line(xp+30,yp-10,xp+45,yp+5);
 line(xp+30,yp,xp+30,yp-10);
 line(xp+30,yp,xp+40,yp);
 xp++;
 setcolor(10);
 line(xp-20,yp+5,xp+45,yp+5);
 line(xp-20,yp+5,xp-20,yp-20);
 line(xp-20,yp-20,xp-10,yp-20);
 line(xp-10,yp-20,xp-5,yp-5);
 line(xp-5,yp-5,xp+30,yp-10);
 line(xp+30,yp-10,xp+45,yp+5);
 setcolor(11);
 line(xp+30,yp,xp+30,yp-9);
 line(xp+30,yp,xp+38,yp);
}

/////////////////////////////////////////////////////////////////////////////
//////////////////////////////////MAIN!//////////////////////////////////////
 void main()
{
   high.open("Score.dat",ios::in|ios::binary|ios::app);
   high.seekp(0);
   high.seekg(0);
   high.read((char*)&hisc,sizeof(hisc));
   remove("Score.dat");
   highw.open("Score.dat",ios::out|ios::binary|ios::app);
  for(int zero=0; zero<20; zero++)
 {
  sta[zero][0]=0;
  sta[zero][1]=0;
 }
  for(zero=0; zero<5; zero++)
 {
  btdr[zero]=0;
  btdl[zero]=0;
 }

  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
  intro();
  press();
  base();
  char choice;
//
  for(ml=0;ml<=noti;ml++)
 {

  // to increase game speed after some time//
  if(ml==4)
  { ltc=6; ltj=5;}
  if(ml==6)
  { ltc=4; ltj=3;}
    if(go==5)
  { setcolor(3);
    outtextxy(150,250,"Do You Want To Play Again??");
    outtextxy(280,275,"Y/N");
 if(score>hisc.hs)
  {
   hsic.hs=score;
   hisc.hs=score;
   highw.seekg(0);
   highw.write((char*)&hsic,sizeof(hsic));
  }
     itoa(hsic.hs,hsc,10);


   get:
    choice=getch();
    if(choice=='n')
    { break;}
    else
   if(choice=='y')
  {
    setcolor(0);
    for(i=0;i<=700;i++)
    { line(0,0+i,650,0+i); }
    go=0;
    for(i=0;i<=4;i++)
    { btdr[i]=0; btdl[i]=0;}
    l=0;r=0;score=0; btdcr=0; btdcl=0; noti++;
    for(zero=0; zero<20; zero++)
 {
  sta[zero][0]=0;
  sta[zero][1]=0;
 }
  for(zero=0; zero<5; zero++)
 {
  btdr[zero]=0;
  btdl[zero]=0;
 }
    base();

    }
      else
      goto get;
  }

//random!!//////////////////////////////////////////////////////////////////
  time_t t;
  srand((unsigned) time(&t));
//level 1///////////////////////////////////////////////////////////////////
 for(j=0;j<=5;j++)
{
//for random movement like right chopper or left one will be crossing centre first generate any no. b/w a range,check divisibiliy by 3 then assign x-coordinate for random
  for(int i=0; i<1; i++)
 {
  rmc=random(90-30+1)+30;
 }

  if(rmc%6==0)
 {
  cc=-50,cc1=700;
 }
  else
 {
   if(rmc%5==0)
  {
   cc=-150,cc1=700;
  }
    else
   {
     if(rmc%3==0)
    {
     cc=-20,cc1=900;
    }
     else
    {
     cc=-200,cc1=700;
    }
   }
  }
////rmc for which chopper will be above/////////////////////////////////////
  for(i=0;i<1;i++)
 {
  rmc=random(20-10+1)+10;
 }
  if(rmc%2==0)
 {
  y=27,y1=65;
 }
  else
 {
  y=65,y1=27;
 }

  for(i=0; i<1; i++)
 {
  r1=random(265-10+1)+10;
 }
  for(i=0; i<1; i++)
 {
  r2=random(635-370+1)+370;
 }

//  conditon for man falling
  m=0;
  m1=0;

// collision condition variables
  coc=0;
  coc1=0;
  bd=0;
  bd1=0;      int mmtn=950;            //man move time needed
 for(int zo=0;zo<=mmtn;zo++)
 {
   /////////////////////////////////////////////////////////////////////////
   if((bd==1)&&(bd1==1)&&(coc==1)&&(coc1==1))
  {
   break;
  }
 //conditon for collison  (gun-chopper collision)
   for(i=0;i<20;i++)
  {
    if(((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))>=cc-41)&&((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))<=cc+25)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))<=y1+10)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))>=y1-10))
   {
    coc=1;
    sta[i][0]=0;
   sta[i][1]=0;
////SCOREUP!///////////////////////////////////////////////////////////////
    score+=10;
    itoa(score,sc,10);
    setcolor(0);
     for(int i=0;i<20;i++)
    {
     rectangle(98+i,454+i,160-i,480-i);
    }
    setcolor(2);
    outtextxy(102,450,sc);
//////////////////////////////////////////////////////////////////////////
    for(i=0;i<=50;i++)
   {
    setcolor(0); rectangle(cc-50+i,y1-20,cc+30-i,y1+15);
   }
    cc=10000;
    break;
   }
  }
    if(cc==700)
   { coc=1; }
    if(coc!=1)
   {
    chopperr(cc);
    cc++;
   }
   for(i=0;i<20;i++)
  {
    if(((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))>=cc1-25)&&((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))<=cc1+41)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))<=y+10)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))>=y-10))
   {
    coc1=1;
    sta[i][0]=0;
   sta[i][1]=0;
////////////////////////////////////SCOREUP!///////////////////////////////
    score+=10;
    itoa(score,sc,10);
    setcolor(0);
    for(int i=0;i<20;i++)
   {
    rectangle(98+i,454+i,160-i,480-i);
   }
    setcolor(2);
    outtextxy(102,450,sc);
////////////////////////////////////////////////////////////////////////
     for(i=0;i<=50;i++)
    {
     setcolor(0);
     rectangle(cc1-30+i,y-20,cc1+50-i,y+15);
    }
     cc1=10000;
     break;
   }
  }
   if(cc1==-60)
   { coc1=1; }
   if(coc1!=1)
  {
   chopperl(cc1);
   cc1--;
  }

//////working done some editing may require (gun-colliding man)////////////
   for(i=0;i<20;i++)
  {
    if(((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))>=xm-10)&&((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))<=xm+10)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))<=ym+15)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))>=ym-25))
   {
    sta[i][0]=0;
   sta[i][1]=0;
    m=15;     bd=1;
//////////////////////////////SCORE!///////////////////////////////////////
    score+=5;
    itoa(score,sc,10);
    setcolor(0);
     for(i=0;i<20;i++)
    {
     rectangle(98+i,454+i,160-i,480-i);
    }
     setcolor(2);
     outtextxy(102,450,sc);
//////////////////////////////////////////////////////////////////////////
    for( i=0;i<=30;i++)
   {
    setcolor(0);
    rectangle(xm-15+i,ym-28,xm+15-i,ym+20);
   }
    xm=10000;
    break;
  }
   if(((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))>=xm1-10)&&((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))<=xm1+10)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))<=ym1+15)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))>=ym1-25))
  {
   sta[i][0]=0;
   sta[i][1]=0;
   m1=15;          bd1=1;
//////////////////////////////////SCORE!///////////////////////////////
   score+=5;
   itoa(score,sc,10);
   setcolor(0);
   for(i=0;i<20;i++)
  {
   rectangle(98+i,454+i,160-i,480-i);
  }
   setcolor(2);
   outtextxy(102,450,sc);
//////////////////////////////////////////////////////////////////////
     for( i=0;i<=30;i++)
    {
     setcolor(0);
     rectangle(xm1-15+i,ym1-28,xm1+15-i,ym1+20);
    }
     xm1=10000;
     break;
   }
  }



 //////////////////  after man down
   if(ym==434)
  {
   btdl[l]=xm;btdcl++;
   l++;
  }
   if(ym1==434)
  {
   btdr[r]=xm1;btdcr++;
   r++;
  }

   if(btdcl>=4)
  {
////batmanla =left attack///////////////////////////////
    for(i=0;i<4;i++)
   {
     if(btdl[i]<280)
    {
     batmanla(btdl[i]);
     btdl[i]++;
    }
   }
  }

  if(btdcr>=4)
 {

////batmanra =right attack////////////////////////////////
   for(i=0;i<4;i++)
  {
    if(btdr[i]>360)
   {
    batmanra(btdr[i]);
    btdr[i]--;
   }
  }
 }

// sorting man`s x-coordinate min. or max. for game over//
// no. of man with min. or max. x-coordinate//

smcr=btdr[0]; smcl=btdl[0];

 if((btdcr>=4)||(btdcl>=4))
  {
     for(i=0;i<=3;i++)
     { if(btdr[i]>smcr)
      { nomr=i; smcr=btdr[i]; }
      if(btdl[i]<smcl)
      { noml=i; smcl=btdl[i]; }
    }
  }

/// game over when 4 beside tank /////////////
 if(btdr[nomr]==360)
  { gameover(); batmanup(361); break; }

 if(btdl[noml]==280)
 { gameover();  batmanup(279); break; }


/////////////////////////////////////////////////////

   if((j==5)&&((btdcr>=4)||(btdcl>=4)))
    { mmtn=1200;}

  batman();
  delay(ltc);
    if(kbhit())
   {
     char a=getch();
     switch(a)
    {
      case 77: gunr(); break;
      case 75: gunl(); break;
      case 27: escape(); break;
      case 72: bullet(q);
    }
   }
    bullet();
  }
/////////   part of second main loop (which runs 5 times) /////////
 if(go==5)
 { break;}
//////////////////////////////////////
 }

// bomb random  mb1,mb2=slopes of bomb eq.
 int br1,br2;
 srand((unsigned) time(&t));
  for( i=0; i<1; i++)
 {
  br1=random(270-10+1)+10;
 }
  for(i=0; i<1; i++)
 {
  br2=random(635-370+1)+370;
 }
  mb1=((379-yp)/(320-br1));
  mb2=((379-yd)/(320-br2));

//level 2  jetstream

  coj=0,coj1=0;
 if(go!=5)
 { int jlc=900;
  for(zo=0;zo<=950;zo++)
 {
//// collision condition(bullet-bomb)
  for(i=0;i<20;i++)
 {
   if(((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))>=xb2-5)&&((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))<=xb2+5)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))>=yb2-5)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))<=yb2+5))
  {
    b2=5;
    sta[i][0]=0;
   sta[i][1]=0;
////////////////////////////////////////////////////////////////SCOREUP!//
   score+=20;
   itoa(score,sc,10);
   setcolor(0);
    for(int i=0;i<20;i++)
   {
    rectangle(98+i,454+i,160-i,480-i);
   }
   setcolor(2);
   outtextxy(102,450,sc);
//////////////////////////////////////////////////////////////////////////

    for(int j=0;j<=10;j++)
   {
    setcolor(0);
    rectangle(xb2-9+j,yb2-9,xb2+9-j,yb2+9);
   }
    xb2=10000;
    break;
  }
 if(((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))>=jlc-45)&&((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))<=jlc+20)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))>=30)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))<=45))
 {    coj=1;
 sta[i][0]=0;
   sta[i][1]=0;
   ////////////////////////////////////SCOREUP!///////////////////////////////
    score+=30;
    itoa(score,sc,10);
    setcolor(0);
    for(int i=0;i<20;i++)
   {
    rectangle(98+i,454+i,160-i,480-i);
   }
    setcolor(2);
    outtextxy(102,450,sc);
////////////////////////////////////////////////////////////////////////
    for(i=0;i<=50;i++)
    {
     setcolor(0);
     rectangle(jlc-50+i,5,jlc+30-i,47);
    }
     jlc=10000;
     break;
   }
 }

  if(yb2==370)
  {  gameover(); break;
 // b2++;
   }

  if(br2==jlc)
 {
  b2=1;
  xb2=jlc;
  yb2=yd;
 }

  if(b2==1)
 {
  bomb2();
 }
  if(coj!=1)
 { jetl(jlc);
  jlc--;}
  delay(ltj);

   if(kbhit())
  {
    char a=getch();
    switch(a)
   {
    case 77: gunr(); break;
    case 75: gunl(); break;
    case 27: escape(); break;
    case 72: bullet(q);
   }
  }
    bullet();
 }
}
 // condition that game is over
 if(go!=5)
 { int jrc=-100;
   for(zo=0;zo<=950;zo++)
  {
  //// collision condition(bullet-bomb)
    for(i=0;i<20;i++)
   {
    if(((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))>=xb1-5)&&((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))<=xb1+5)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))>=yb1-5)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))<=yb1+5))
   {
    b1=5;
    sta[i][0]=0;
   sta[i][1]=0;
////////////////////////////////////////////////////////////////SCOREUP!//
   score+=20;
   itoa(score,sc,10);
   setcolor(0);
    for(int i=0;i<20;i++)
   {
    rectangle(98+i,454+i,160-i,480-i);
   }
   setcolor(2);
   outtextxy(102,450,sc);
//////////////////////////////////////////////////////////////////////////

    for(int j=0;j<=10;j++)
   {
    setcolor(0);
    rectangle(xb1-9+j,yb1-9,xb1+9-j,yb1+9);
   }
   xb1=11000;
    break;
  }
 if(((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))>=jrc-20)&&((320+((sta[i][1]+40.5+1)*cos(sta[i][0])))<=jrc+45)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))>=30)&&((379-((sta[i][1]+40.5+1)*sin(sta[i][0])))<=45))
 {    coj1=1;
 sta[i][0]=0;
   sta[i][1]=0;
   ////////////////////////////////////SCOREUP!///////////////////////////////
    score+=30;
    itoa(score,sc,10);
    setcolor(0);
    for(int i=0;i<20;i++)
   {
    rectangle(98+i,454+i,160-i,480-i);
   }
    setcolor(2);
    outtextxy(102,450,sc);
////////////////////////////////////////////////////////////////////////
    for(i=0;i<=50;i++)
    {
     setcolor(0);
     rectangle(jrc-30+i,5,jrc+50-i,47);
    }
     jrc=10000;
     break;
   }
 }

  if(yb1==370)
  { gameover(); break;
 // b1++;
   }
  if(br1==jrc)
 {
  b1=1;
  xb1=jrc;
  yb1=yp;
 }

  if(b1==1)
 {
  bomb1();
 }
 if(coj1!=1)
 {jetr(jrc);
  jrc++;}
 delay(ltj);

  if(kbhit())
 {
   char a=getch();

   switch(a)
  {
    case 77: gunr(); break;
    case 75: gunl(); break;
    case 27: escape(); break;
    case 72: bullet(q);
  }
 }
   bullet();
}

}
}
}
////////////ENDD!///////////////////////////