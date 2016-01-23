//! Bismillahi-Rahamanirahim.
/** ========================================**
 ** @Author: A Asif Khan Chowdhury
/** ========================================**/

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
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf (1ll<<28)
#define ll long long
#define mod 1000000007
#define gc getchar
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

const int step = 20;
int parent[mx][step+5], start[mx], finish[mx], Tm;
vector<int>adj[mx];

void dfs(int u, int par){
    start[u] = Tm++;

    parent[u][0]=par;
    for(int i=1;i<=step;i++){
        parent[u][i] = parent[parent[u][i-1]][i-1];
    }

    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v==par)continue;
        dfs(v,u);
    }

    finish[u]=Tm++;
}

bool isAncestor(int u, int v){ // is u ancestor of v?
    if(start[u]<=start[v] and finish[u]>=finish[v])
        return true;
    return false;
}

int lca_query(int u, int v){
    int w = -1;

    if(isAncestor(u,v)) w=u;
    if(isAncestor(v,u)) w=v;

    if(w==-1){
        w=u;
        for(int i=step;i>=0;i--)
            if(!isAncestor(parent[w][i],v))
                w = parent[w][i];
        w=parent[w][0];
    }
    return w;
}

void init(int n){
    Tm=0;
    for(int i=0;i<=n;i++)adj[i].clear();
}

int main() {
    #ifdef LOCAL
    freopen("D:/a.txt", "r", stdin);
    #endif // LOCAL

    dfs(1,1);   // It should be given! No (1,0) or (1,-1)

    return 0;
}




