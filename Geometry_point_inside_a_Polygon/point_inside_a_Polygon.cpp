
#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
using namespace std;
typedef long long LL;

bool pointinpoly(int node, LL *x, LL *y, LL xx, LL yy)  //nodes should be given in clockwise or anti-clockwise order
{
  int i, j;
  bool c=false;
  for (i = 1, j = node; i <= node; j = i++) {
    LL x1,y1,x2,y2;
    x1=x[i];
    y1=y[i];
    x2=x[j];
    y2=y[j];
    //keepin y1 greater
    if(y1<y2)
    {
        swap(x1,x2);
        swap(y1,y2);
    }
    if ( ((y1>yy) != (y2>yy)) && //here all corner(vertex) case are handled
	 ((xx-x1)*(y2-y1) < (x2-x1) * (yy-y1)) ) //cancelling division
       c = !c;
    if(y1>=yy && y2<=yy && xx<=max(x1,x2)&& xx>=min(x1,x2) && (xx-x1)*(y2-y1) == (x2-x1) * (yy-y1)) return true;
  }
  return c;
}


int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    return 0;
}
