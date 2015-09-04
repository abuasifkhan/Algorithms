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
#define debug_array(a,n) for(int i=0;i<n;i++) cout<<a[i].in<<" "; cout<<endl;
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 400010

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

struct trie{
    int val;
    trie * lson, *rson;
    trie(){
        lson=NULL, rson=NULL;
    }
    ~trie(){
        if(lson)
            delete(lson);
        if(rson)
            delete(rson);
    }
}*root;

void update(int n){     // XOR update
    trie * tmp=root;
    for(int i=30;i>=0;i--){
        if(Check(n,i)){
            if(!tmp->rson)
                tmp->rson=new trie();
            tmp=tmp->rson;
        }
        else{
            if(!tmp->lson)
                tmp->lson=new trie();
            tmp = tmp->lson;
        }
    }
    tmp->val=n;
}

int query(int n){   // XOR query
    trie * tmp = root;
    int ret=0;
    for(int i=30;i>=0;i--){
        if(Check(n,i)){
            if(tmp->lson){
                tmp=tmp->lson;
                ret|=(1<<i);
            }
            else tmp=tmp->rson;
        }
        else{
            if(tmp->rson){
                tmp=tmp->rson;
                ret|=(1<<i);
            }
            else tmp=tmp->lson;
        }
    }
    return ret;
}
int arr[mx];

int main() {
	#ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL
    // Constrain
    // LDC
    int test;
    read(test);
    FOR(C, 1, test) {
        int n;read(n);
        root=new trie();
        int x=0;
        int ans=0;
        arr[0]=0;
        for(int i=1;i<=n;i++){
            read(arr[i]);
            arr[i]^=arr[i-1];
        }

        for(int i=0;i<n;i++){
            update(arr[i]);
            ans = max(ans, query(arr[i+1]));
        }
        cout<<ans<<endl;
        delete(root);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}
/*
Input:
2
5
3  7  7  7  0
5
3  8  2  6  4
Output:
7
15
*/




