/////////// things TO DO////////////////////
//// enemy attack would be randomised if its in range of shell
//// parameter of shell will be slightly changed////////
//// our bullet won`t affect shell(-ve score on bullet fire)







#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
// bullet left/right
//bullet y initial coordinate
 int bull[20][2],bulr[20][2],j,ybi=400; int x=300,y=425,i;

    ////////////shell parameters///////////////(change when bullet strikes)
    //// shell radius x/y///////////
    int xs=100,ys=330,srx=40,sry=30;

void enemyattack()
{
}

void shell()
{

   for(i=0;i<=2;i++)
   {
     for(j=0;j<=25;j++)
     { ellipse(xs,ys,0,180,srx-j,sry-j);  }

     for(j=0;j<=20;j++)
   {
    line(xs-40+j,ys,xs-40+j,ys+30);
    line(xs+40-j,ys,xs+40-j,ys+30);
    line(xs-20,ys+10,xs-20,ys+30);
    line(xs+20,ys+10,xs+20,ys+30);
    line(xs-20,ys+30,xs-40,ys+30);
    line(xs+20,ys+30,xs+40,ys+30);
    }
     for(j=0;j<=10;j++)
     { line(xs-20,ys+10-j,xs,ys);
       line(xs+20,ys+10-j,xs,ys);
     }
     xs+=210;
    }

}

void conditionchecker()
{
///////// our bullet-shell collision ////////////
  for(i=0;i<20;i++)
  {
   if(((bull[i][0]>=57)&&(bull[i][0]<=143)||(bull[i][0]>=267)&&(bull[i][0]<=353)||(bull[i][0]>=477)&&(bull[i][0]<=563))&&(bull[i][1]<=364))
   {
     bull[i][0]=0;
     bull[i][1]=ybi;
    }
    if(((bulr[i][0]>=57)&&(bulr[i][0]<=143)||(bulr[i][0]>=267)&&(bulr[i][0]<=353)||(bulr[i][0]>=477)&&(bulr[i][0]<=563))&&(bulr[i][1]<=364))
    {
     bulr[i][0]=0;
     bulr[i][1]=ybi;
    }
  }
//////////////////////////////////////////







}






void base()
{
////////////////// initial SHIP/////////////////
  setcolor(6);
  rectangle(x-10,y-15,x+10,y+15);
  line(x+10,y+10,x+35,y+10);
  line(x+35,y+10,x+28,y-15);
  line(x+28,y-15,x+25,y-15);
  line(x+25,y-15,x+20,y-20);
  line(x+20,y-20,x+15,y-15);
  line(x+15,y-15,x+10,y-15);
  rectangle(x+15,y+10,x+25,y+15);
  line(x-10,y+10,x-35,y+10);
  line(x-35,y+10,x-28,y-15);
  line(x-28,y-15,x-25,y-15);
  line(x-25,y-15,x-20,y-20);
  line(x-20,y-20,x-15,y-15);
  line(x-15,y-15,x-10,y-15);
  rectangle(x-15,y+10,x-25,y+15);
  line(x-10,y-15,x,y-25);
  line(x,y-25,x+10,y-15);
/////////////////////////////////////////////

setcolor(14);
   for(i=0;i<2;i++)
  {
   line(0,450+i,650,450+i);
  }
 ////TEXT/////////////////////////////////////////////////////////////////////

  settextstyle(1,0,3);
  outtextxy(20,450,"SCORE");
  outtextxy(95,448,":");
  outtextxy(562,448,":" );
  outtextxy(420,450,"HIGH SCORE");


}


void bullet(int xl=1000,int xr=1000)
{
   if(xl!=1000)
   {  for(i=0;i<20;i++)
      {
	 if(bull[i][0]==0)
	 {  bull[i][0]=xl;  break;}
      }
      for(i=0;i<20;i++)
      {
	 if(bull[i][0]!=0)
	 {    for( j=0;j<=2;j++)
	      {  setcolor(0);
		 circle(bull[i][0],bull[i][1]+3,3-j);
		 setcolor(3);
		 circle(bull[i][0],bull[i][1],3-j);
		 bull[i][1]-=1;
	      }
	 }
      }
   }
   else
  {
   for(i=0;i<20;i++)
      {
	 if(bull[i][0]!=0)
	 {    for( j=0;j<=2;j++)
	      {  setcolor(0);
		 circle(bull[i][0],bull[i][1]+3,3-j);
		 setcolor(3);
		 circle(bull[i][0],bull[i][1],3-j);
		 bull[i][1]-=1;
	      }
	 }
      }
  }
 for(i=0;i<20;i++)
 {  if(bull[i][1]<0)
   { bull[i][0]=0;
     bull[i][1]=ybi;
    }
 }
///////////
 if(xr!=1000)
   {  for(i=0;i<20;i++)
      {
	 if(bulr[i][0]==0)
	 {  bulr[i][0]=xr;  break;}
      }
      for(i=0;i<20;i++)
      {
	 if(bulr[i][0]!=0)
	 {    for( j=0;j<=2;j++)
	      {  setcolor(0);
		 circle(bulr[i][0],bulr[i][1]+3,3-j);
		 setcolor(3);
		 circle(bulr[i][0],bulr[i][1],3-j);
		 bulr[i][1]-=1;
	      }
	 }
      }
   }
   else
  {
   for(i=0;i<20;i++)
      {
	 if(bulr[i][0]!=0)
	 {    for( j=0;j<=2;j++)
	      {  setcolor(0);
		 circle(bulr[i][0],bulr[i][1]+3,3-j);
		 setcolor(3);
		 circle(bulr[i][0],bulr[i][1],3-j);
		 bulr[i][1]-=1;
	      }
	 }
      }
  }
 for(i=0;i<20;i++)
 {  if(bulr[i][1]<0)
   { bulr[i][0]=0;
     bulr[i][1]=ybi;
    }
 }

}


void shipl(int x)
{   setcolor(0);
  rectangle(x-10,y-15,x+10,y+15);
  line(x+10,y+10,x+35,y+10);
  line(x+35,y+10,x+28,y-15);
  line(x+28,y-15,x+25,y-15);
  line(x+25,y-15,x+20,y-20);
  line(x+20,y-20,x+15,y-15);
  line(x+15,y-15,x+10,y-15);
  rectangle(x+15,y+10,x+25,y+15);
  line(x-10,y+10,x-35,y+10);
  line(x-35,y+10,x-28,y-15);
  line(x-28,y-15,x-25,y-15);
  line(x-25,y-15,x-20,y-20);
  line(x-20,y-20,x-15,y-15);
  line(x-15,y-15,x-10,y-15);
  rectangle(x-15,y+10,x-25,y+15);
  line(x-10,y-15,x,y-25);
  line(x,y-25,x+10,y-15);
   setcolor(6);
  rectangle(x-10-3,y-15,x+10-3,y+15);
  line(x+10-3,y+10,x+35-3,y+10);
  line(x+35-3,y+10,x+28-3,y-15);
  line(x+28-3,y-15,x+25-3,y-15);
  line(x+25-3,y-15,x+20-3,y-20);
  line(x+20-3,y-20,x+15-3,y-15);
  line(x+15-3,y-15,x+10-3,y-15);
  rectangle(x+15-3,y+10,x+25-3,y+15);
  line(x-10-3,y+10,x-35-3,y+10);
  line(x-35-3,y+10,x-28-3,y-15);
  line(x-28-3,y-15,x-25-3,y-15);
  line(x-25-3,y-15,x-20-3,y-20);
  line(x-20-3,y-20,x-15-3,y-15);
  line(x-15-3,y-15,x-10-3,y-15);
  rectangle(x-15-3,y+10,x-25-3,y+15);
  line(x-10-3,y-15,x-3,y-25);
  line(x-3,y-25,x+10-3,y-15);
  }

 void shipr(int x)
{
  setcolor(0);
  rectangle(x-10,y-15,x+10,y+15);
  line(x+10,y+10,x+35,y+10);
  line(x+35,y+10,x+28,y-15);
  line(x+28,y-15,x+25,y-15);
  line(x+25,y-15,x+20,y-20);
  line(x+20,y-20,x+15,y-15);
  line(x+15,y-15,x+10,y-15);
  rectangle(x+15,y+10,x+25,y+15);
  line(x-10,y+10,x-35,y+10);
  line(x-35,y+10,x-28,y-15);
  line(x-28,y-15,x-25,y-15);
  line(x-25,y-15,x-20,y-20);
  line(x-20,y-20,x-15,y-15);
  line(x-15,y-15,x-10,y-15);
  rectangle(x-15,y+10,x-25,y+15);
  line(x-10,y-15,x,y-25);
  line(x,y-25,x+10,y-15);
   setcolor(6);
  rectangle(x-10+3,y-15,x+10+3,y+15);
  line(x+10+3,y+10,x+35+3,y+10);
  line(x+35+3,y+10,x+28+3,y-15);
  line(x+28+3,y-15,x+25+3,y-15);
  line(x+25+3,y-15,x+20+3,y-20);
  line(x+20+3,y-20,x+15+3,y-15);
  line(x+15+3,y-15,x+10+3,y-15);
  rectangle(x+15+3,y+10,x+25+3,y+15);
  line(x-10+3,y+10,x-35+3,y+10);
  line(x-35+3,y+10,x-28+3,y-15);
  line(x-28+3,y-15,x-25+3,y-15);
  line(x-25+3,y-15,x-20+3,y-20);
  line(x-20+3,y-20,x-15+3,y-15);
  line(x-15+3,y-15,x-10+3,y-15);
  rectangle(x-15+3,y+10,x-25+3,y+15);
  line(x-10+3,y-15,x+3,y-25);
  line(x+3,y-25,x+10+3,y-15);

    }

void main()
{

   int gdriver = DETECT, gmode, errorcode;

   initgraph(&gdriver, &gmode, "c:\\tc\\bgi ");

 for(i=0;i<20;i++)
 { bull[i][0]=0; bulr[i][0]=0;
   bull[i][1]=ybi; bulr[i][1]=ybi;
 }

 base();
 setcolor(1);
 shell();


 for(i=0;i<=15000;i++)
 {  delay(5);

   enemyattack();

   if(kbhit())
    { char b=getch();
	 switch(b)
	 {
	  case 75: if(x>=35) { shipl(x); x-=3;} break;
	  case 77: if(x<=600){ shipr(x); x+=3;} break;
	  case 27: exit(0); break;
	  case 32: bullet(x-20,x+20); break;
	 }
    }   bullet();

 conditionchecker();

 }
getch();
}













