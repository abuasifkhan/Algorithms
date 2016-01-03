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

struct seg{
    ll l,r,y;
    int typ;
    seg(){}
    seg(ll l, ll r, ll y, int typ):l(l),r(r),y(y),typ(typ){}
    bool operator < (const seg a)const{
        return y<a.y;
    }
}ss[3*mx];

ll st[3*mx];
int color[3*mx];
ll pt[3*mx];
int n;

void pushUp(int node, int l, int r){
    if(color[node]){
        st[node]=pt[r]-pt[l-1];
    }
    else{
        st[node]=st[node*2]+st[node*2+1];
    }
}

void build(int node,int l, int r, int x, int y,int val){
//    cout<<node<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
//    _sleep(100);
    if(l>=x and r<=y){
        color[node]+=val;
        pushUp(node, l, r);
        return;
    }
    int mid=MID(l,r);
    if(mid>=x)build(node*2,l,mid,x,y,val);
    if(mid<y)build(node*2+1,mid+1,r,x,y,val);
    pushUp(node,l,r);
}

int main() {
    #ifdef LOCAL
    open
    double sss=clock(),en;
    #endif // LOCAL

    int test;
    read(test);
    for(int C=1;C<=test;C++) {
        read(n);
        CLEAR(st,0);
        CLEAR(color,0);
        printf("Case %d: ", C);
        int m=0;
        for(int i=0;i<n;i++){
            ll a, b, c,d;read(a);read(b);read(c);read(d);
            ss[m]=seg(a,c,b,1);
            pt[m++]=a;
            ss[m]=seg(a,c,d,-1);
            pt[m++]=c;
        }
        sort(ss,ss+m);
        sort(pt,pt+m);
        int sz=unique(pt,pt+m)-pt;
        ll ans=0;
        for(int i=0;i<m-1;i++){
            int l=lower_bound(pt,pt+sz,ss[i].l)-pt+1;
            int r=lower_bound(pt,pt+sz,ss[i].r)-pt;
            if(l<=r) build(1,0,sz-1,l,r,ss[i].typ);
            ans+= st[1]*(ss[i+1].y-ss[i].y);
        }
        printf("%lld\n",ans);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-sss)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}




