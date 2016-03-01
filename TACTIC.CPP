#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>
// wcoc=whether cross or circle// coorc=coordinate checker // t=move turn
int  i,x=235,y=235,wcoc=4,t=0,win=0; int m=0; char ch; int coorc[9][2],check[3][3];
/////// displays winner//////////
void initialise();
void windisplay()
{ setcolor(3);
  if(win==2)
  { outtextxy(480,100,"Circle Wins");}
  if(win==1)
  { outtextxy(480,100,"Cross Wins");}
  setcolor(3);
  outtextxy(480,250,"Play Again??");
  outtextxy(480,275,"Y/N");
 getz:
 gotoxy(80,80);
 ch=getch();
 if(ch=='y')
 { initialise(); x=235,y=235,wcoc=4,t=0,win=0,m=0; }
 if(ch=='n')
 { exit(0); }
 if((ch!='n')&&(ch!='y'))
 {goto getz;  }

}
void trademark()
{
  setcolor(15);
  for(i=0;i<=30;i++)
  { line(460,417+i,630,417+i);}
  settextstyle(1,0,3);
  setcolor(0);
  outtextxy(490,417,"VIVEK INC.");
}
///// check (checks whether place is empty for circle/cross)///
void check2()
{
   for(i=0;i<=8;i++)
   { if((coorc[i][0]==x)&&(coorc[i][1]==y))
      { m=1;}
    }
}
////////// storecoor(stores coordinate in 3*3 to check winner/////
void storecoor()
{
  switch(x)
  { case 92: switch(y)
	     { case 92: if(wcoc==4) check[0][0]=2; else check[0][0]=1; break;
	       case 235:if(wcoc==4) check[0][1]=2; else check[0][1]=1; break;
	       case 378:if(wcoc==4) check[0][2]=2; else check[0][2]=1; break;
	     }    break;
    case 235: switch(y)
	     { case 92: if(wcoc==4) check[1][0]=2; else check[1][0]=1; break;
	       case 235:if(wcoc==4) check[1][1]=2; else check[1][1]=1; break;
	       case 378:if(wcoc==4) check[1][2]=2; else check[1][2]=1; break;
	     }    break;
    case 378: switch(y)
	     { case 92: if(wcoc==4) check[2][0]=2; else check[2][0]=1; break;
	       case 235:if(wcoc==4) check[2][1]=2; else check[2][1]=1; break;
	       case 378:if(wcoc==4) check[2][2]=2; else check[2][2]=1; break;
	     }    break;
  }
}
//////move (print circle/cross) /////////
void move()
{ storecoor();
  coorc[t][0]=x;coorc[t][1]=y; t++;
  setcolor(15);
  if(wcoc==4)
  {  circle(x,y,65); wcoc=3;}
  else
  {
    line(x-62,y-62,x+62,y+62);
    line(x+62,y-62,x-62,y+62);
    wcoc=4;
  }
}
//// selected rectangle/////
void sr()
{ setcolor(3); rectangle(x-72,y-72,x+71,y+71);}
void base()
{
  setcolor(1);
 setlinestyle(0,0,3);
 line(20,20,449,20);
 line(449,20,449,449);
 line(20,449,449,449);
 line(20,20,20,449);
 line(163,20,163,449);
 line(306,20,306,449);
 line(20,163,449,163);
 line(20,306,449,306);
}
void initialise()
{ ///// blackening screen  ///////////
 for(i=0;i<=600;i++) { setcolor(0); line(0,0+i,650,0+i);}
 base();
 setcolor(3); rectangle(163,163,306,306);
 trademark();
 for(i=0;i<=8;i++)
 { coorc[i][0]=0;  coorc[i][1]=0; }
 for(i=0;i<=2;i++)
 { for(int j=0;j<=2;j++)
   { check[i][j]=0;}
 }
}
void wincheck()
{
///// horizontal check/////
for(i=0;i<=2;i++)
{ if((check[0][i]==2)&&(check[1][i]==2)&&(check[2][i]==2))
   { win=2; windisplay(); break; }
  if((check[0][i]==1)&&(check[1][i]==1)&&(check[2][i]==1))
   { win=1; windisplay(); break; }
}
///// vertical check /////////
for(i=0;i<=2;i++)
{
  if((check[i][0]==2)&&(check[i][1]==2)&&(check[i][2]==2))
   { win=2; windisplay(); break; }
  if((check[i][0]==1)&&(check[i][1]==1)&&(check[i][2]==1))
   { win=1; windisplay(); break; }
}
////// diagonal check////////
if((check[0][0]==2)&&(check[1][1]==2)&&(check[2][2]==2))
{ win=2; windisplay(); }
if((check[0][0]==1)&&(check[1][1]==1)&&(check[2][2]==1))
{ win=1; windisplay(); }
if((check[2][0]==2)&&(check[1][1]==2)&&(check[0][2]==2))
{ win=2; windisplay(); }
if((check[2][0]==1)&&(check[1][1]==1)&&(check[0][2]==1))
{ win=1; windisplay(); }
}
void main()
{
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "c:\\tc\\bgi ");
  initialise();
///////////////
  start:
  m=0;
  char b=getch();
  switch(b)
  {
     case 75: if(x!=92) { base(); x-=143;  sr(); }  break;
     case 77: if(x!=378) { base(); x+=143;  sr(); } break;
     case 72:  if(y!=92) { base(); y-=143;  sr(); } break;
     case 80:  if(y!=378) { base(); y+=143;  sr(); } break;
     case 13:  check2();   if(m==0) {move();} break;
     case 27: exit(0); break;
   }
 wincheck();

goto start;
}


