#include <bits/stdc++.h>

using namespace std;

#define Set(N, j) (N|(1<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1<<j))
#define toggle(N, j) (N^(1<<j))
#define turnOff(N, j) (N & ~(1<<j))
#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pii pair <int, int>
#define pb push_back
#define inf (1ll<<28)
#define ll long long
#define mod 1000000007
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
#define mx 100010

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

int n,q;
int arr[2*mx];
struct p{
    int fs,sc,idx;
}inps[2*mx];
int block;

bool comp(p a, p b){
    if(a.fs/block==b.fs/block)
        return a.sc<b.sc;
    return a.fs/block < b.fs/block;
}

ll freq[10*mx];
ll ans[2*mx];
ll calc=0;

void del(int val){
    calc -= freq[val]*freq[val]*val;
    freq[val]--;
    calc += freq[val]*freq[val]*val;
}

void add(int val){
    calc -= freq[val]*freq[val]*val;
    freq[val]++;
    calc += freq[val]*freq[val]*val;
}

int l=0,r=0;

void query(int L, int R){
    if(l<L)for(int i=l;i<L;i++)del(arr[i]);
    if(l>L)for(int i=l-1;i>=L;i--)add(arr[i]);
    if(r<R)for(int i=r+1;i<=R;i++) add(arr[i]);
    if(r>R)for(int i=r;i>R;i--) del(arr[i]);
//    cout<<L<<" "<<R<<" "<<l<<" "<<r<<endl;
    l=L, r=R;
}

int main() {
    #ifdef LOCAL
    freopen("C:/BIN/a.in", "r", stdin);
    // freopen("C:/BIN/b.out","w",stdout);
    #endif // LOCAL

    read(n);read(q);
    for(int i=1;i<=n;i++)read(arr[i]);
    block=sqrt(n)+1;
    for(int i=1;i<=q;i++){
        int l,r;
        read(l);read(r);
        inps[i]={l,r,i};
//        cout<<inps[i].fs<<" "<<inps[i].sc<<endl;
    }
    sort(inps+1,inps+1+q,comp);

    for(int i=1;i<=q;i++){
        int L=inps[i].fs;
        int R=inps[i].sc;
        int idx = inps[i].idx;
        query(L,R);
        ans[idx]=calc;
    }
    for(int i=1;i<=q;i++) printf("%I64d\n",ans[i]);
    return 0;
}
