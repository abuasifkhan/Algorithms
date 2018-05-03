/** ========================================**
 ** Bismillahi-Rahamanirahim.               **
 ** @Author: A Asif Khan Chowdhury          **
 ** ========================================**/

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <deque>
#include <strings.h>
#include <cmath>
#include <cstdio>
#include <set>
#include <list>
#include <algorithm>
#include <map>
#include <bitset>
#include <numeric>
#include <string>

using namespace std;

#define Set(N, j) (N|(1ll<<j))
#define reset(N, j) (N&~(1ll<<j))
#define Check(N, j) (bool)(N&(1ll<<j))
#define toggle(N, j) (N^(1ll<<j))
#define turnOff(N, j) (N & ~(1ll<<j))

#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pii pair <int, int>
#define pb push_back
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf 1e15
#define ll long long
#define ull unsigned ll
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)

#define mx 50010

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while((~c&&c<'0')||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

//int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};   //x 8 direction
//int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};  //y 8 direction
int X[]= {-1, 0, 1, 0};   //x 4 direction
int Y[]= { 0, 1, 0, -1};  //y 4 direction


/* https://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/ */

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;

        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

bool miillerTest(ll d, ll n)
{
    ll a = 2 + rand() % (n - 4);
    ll x = power(a, d, n);

    if (x == 1  || x == n-1)
       return true;

    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    return false;
}

bool isPrime(ll n, int k)
{
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
         if (miillerTest(d, n) == false)
              return false;

    return true;
}

int main() {
    /**
     * Write a method to verify your code (Naive)
     * Learn-Divide-Convert
     **/
#ifdef DEBUG
    freopen("C:/Users/abukha/Desktop/Programming/input.in","r",stdin);
    //    freopen("C:/Users/abu.chowdhury/Desktop/programming/output.out","w",stdout);
#endif

    int k = 10;  // Number of iterations

    cout << "All primes smaller than 100: \n";
    for (int n = 1; n < 100; n++)
       if (isPrime(n, k))
          cout << n << " ";

    return 0;
}





