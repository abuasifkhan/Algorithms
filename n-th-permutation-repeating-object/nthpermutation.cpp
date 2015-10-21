//! Bismillahi-Rahamanirahim.
/** ========================================**
 ** @Author: A Asif Khan Chowdhury
/** ========================================**/


/**................ Headers ................**/
#include <bits/stdc++.h>

using namespace std;

/**................ Macros ................**/
#define Set(N, j) (N|(1<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1<<j))
#define toggle(N, j) (N^(1<<j))
#define turnOff(N, j) (N & ~(1<<j))
#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pii pair <int, int>
#define pb push_back
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf (1<<28)
#define ll long long
#define mod 1000000007
#define debug cout<<"ok"<<endl;
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
#define mx 100010

//Fast Reader
template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};   //x 8 direction
int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};  //y 8 direction
// int X[]= {-1, 0, 1, 0};   //x 4 direction
// int Y[]= { 0, 1, 0, -1};  //y 4 direction

ll n;
char s[20];
char ans[20];
ll cnt[30];
ll f[20];

int main() {
    #ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL
    // Can you solve it by brute force?
    // LDC
    // Are you sure you want to code so soon?? -_-
    // Simplify your code a little more. :)

    f[0]=1;
    for(ll i=1;i<=16;i++)f[i]=f[i-1]*i;
    while(~scanf("%s %d",s,&n)){
        if(s[0]=='#' and !n)break;
        ll len=strlen(s);
        memset(cnt,0,sizeof(cnt));
        for(ll i=0;i<len;i++)cnt[s[i]-'A']++;
        for(int i=len-1;i>=0;i--){
            ll now=0;
            ll tmp=0;
            for(ll j=0;j<26;j++){
                if(cnt[j]!=0){
                    tmp=f[i];
                    for(ll k=0;k<26;k++){
                        if(j==k)
                            tmp/=f[cnt[k]-1];
                        else tmp/=f[cnt[k]];
                    }
                    if(now+tmp>=n){
                        ans[i]=j+'A';
                        n-=now;
                        cnt[j]-=1;
                        break;
                    }
                    now=now+tmp;
                }
            }
        }
        for(int i=len-1;i>=0;i--)printf("%c",ans[i]);puts("");
    }


    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}
/*
INPUT:
ACM 5
ICPC 12
REGION 274
# 0

OUTPUT:
MAC
PICC
IGNORE
*/



