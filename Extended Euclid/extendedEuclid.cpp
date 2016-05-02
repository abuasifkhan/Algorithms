/// Extended_Euclid

#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define mx 100010
#define pii pair <int, int>
#define pb push_back
#define pf printf
#define S(x) scanf("%d", &x);
#define SL(x) scanf("%ld", &x);
#define out(C,x) printf("Case %d: %d\n", C, x);
#define FOR(i, x, y) for(int i=x; i<=y; i++)
#define MAX (1+(1<<5))
#define inf 0x7fffffff
#define i64 long long

int x, y, d;

int extendedEulid(int a, int b)
{
    if(b==0)
    {
        x=1; y=0; d=a;  /// some extensions
        return a;
    }
    int ret = extendedEulid(b, a%b);   /// GCD function
    int x1 = y;         /// some extensions
    int y1 = x - (a/b) *y;
    x = x1;
    y = y1;
    return ret;
}

int main()
{
    int a, b;
    while(cin>>a>>b)
    {
        extendedEulid(a, b);
        printf("x = %d, y = %d, gcd()=%d\n", x, y, d);
    }
}




