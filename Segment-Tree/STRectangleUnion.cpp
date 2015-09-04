//!
///

/** ========================================**
 ** @Author: A Asif Khan Chowdhury
 ** @Category:
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
#define pi 3.141592653589793
#define pii pair <int, int>
#define pb push_back
#define pf printf
#define S(x) scanf("%d", &x)
#define SL(x) scanf("%ld", &x)
#define out(C) printf("Case %d: ", C);
#define FOR(i, x, y) for(int i=x; i<=y; i++)
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define MAX (1+(1<<5))
#define inf 0x7fffffff
#define ll long long
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
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
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};
int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};

struct sgmnt{
    ll y1, y2, x;
    int flag;
    void init(ll Y1,ll Y2, ll X, int Flag){
        y1=Y1;
        y2=Y2;
        x=X;
        flag=Flag;
    }
}edges[70010];
bool comp(sgmnt a, sgmnt b){
    return a.x<b.x;
}
int n;
ll points[4*mx],color[4*mx], st[4*mx];
int pointSize, edgeSize;

void pushUp(int node, int l ,int r){
    if(color[node]){
        st[node] = points[r]-points[l];
//        cout<<"here "<<node<<" "<<points[r]<<" "<<points[l]<<endl;
    }
    else st[node] = st[node*2]+st[node*2+1];
}

void build(int node, int l, int r, ll y1, ll y2, int type){
    if(points[l]>y2 or points[r]<y1)return;
//    cout<<l<<" "<<r<<endl;
    if(points[l]>=y1 and points[r]<=y2){
        color[node]+=type;
        pushUp(node, l, r);
        return;
    }
    if(l+1>=r)return;
    int mid = MID(l,r);
    build(node*2,l,mid,y1,y2,type);
    build(node*2+1,mid,r,y1,y2,type);
    pushUp(node, l ,r);
    return;
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        CLEAR(edges,0);
        CLEAR(points,0);CLEAR(st,0);

        read(n);
        int ps=0;
        pointSize=1,edgeSize=0;
        for(int i=1;i<=n;i++){
            ll x1,y1,x2,y2;
            read(x1);read(y1);read(x2);read(y2);
            points[++ps]=y1;
            points[++ps]=y2;
            edges[edgeSize++].init(y1,y2,x1,1);
            edges[edgeSize++].init(y1,y2,x2,-1);
        }
        sort(edges,edges+edgeSize,comp);
        sort(points+1,points+1+ps);
        for(int i=2;i<=ps;i++)
            if(points[pointSize]!=points[i])
                points[++pointSize]=points[i];
//        for(int i=1;i<=pointSize;i++)cout<<points[i]<<" ";cout<<endl;
        ll area = 0;
        CLEAR(color,0);
        for(int i=0;i<edgeSize-1;i++){
            build(1, 1, pointSize, edges[i].y1, edges[i].y2, edges[i].flag);
            area+=st[1]*(ll)(edges[i+1].x-edges[i].x);
//            cout<<i<<"...."<<st[1]<<" "<<edges[i].y1<<" "<<edges[i].y2<<endl;
        }
        out(C);
        printf("%lld\n",area);
    }
    return 0;
}
