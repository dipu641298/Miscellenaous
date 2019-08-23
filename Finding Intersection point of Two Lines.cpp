/* This code takes four 2 dimentional points as input
and gives intersection point of two lines generated from
that four points
Here you'll see point a and b is creating a line
and point c and p is creating another line
And this code will output the intersection point of
these two lines*/


#include<bits/stdc++.h>
using namespace std;

double ax,ay,bx,by,cx,cy,px,py;
double A1,B1,C1,A2,B2,C2;
double X,Y,slope,xin1,yin1,xin2,yin2,det;

void func()
{
   xin1 = bx-ax;
   yin1 = by-ay;
   if(yin1 == 0){
      Y = ay;

      xin2 = px-cx;
      yin2 = py-cy;
      if(xin2 == 0){
         X = cx; return;
      }
      slope = yin2/xin2;
      X = (cy - slope*cx - Y)/(-slope);
      return;
   }
   else if(xin1 == 0){
      X = ax;

      xin2 = px-cx;
      yin2 = py-cy;
      if(yin2 == 0){
         Y = cy; return;
      }
      slope = yin2/xin2;
      Y = slope*X + cy - slope*cx;
      return;
   }
   else{
      slope = yin1/xin1;
      A1 = -slope;
      B1 = 1;
      C1 = -ay + slope*ax;

      xin2 = px-cx;
      yin2 = py-cy;

      if(xin2==0){
         X = cx;
         Y = slope*X + ay - slope*ax; return;
      }
      else if(yin2==0 ){
         Y = cy;
         X = (ay - slope*ax - Y)/(-slope); return;
      }
      else{
         slope = yin2/xin2;
         A2 = -slope;
         B2 = 1;
         C2 = -cy + slope*cx;

         det = A1*B2 - A2*B1;
         X = (B1*C2-C1*B2)/det;
         Y = (C1*A2-A1*C2)/det;
         return;
      }
   }
}



int main()
{

   cin >> ax >> ay >> bx >> by >> cx >> cy >> px >> py;
   if((cx==px && cy==py) || (ax==bx && ay==by)){printf("Case #%d: No solution!\n",kase); continue;}
   func();

   printf("Case #%d: %.2lf, %.2lf\n",kase,X,Y);

   return 0;
}
