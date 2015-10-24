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

//used for LCA
int n, parent[mx][22], start[mx],finish[mx],T; // T = time
vector<int>adj[mx];
// Used for HLD
int child[mx],nodeId,firstNode[mx],currentIndex[mx];
// Used for segment tree
// 1 based index is used
int tree[mx];
int MaxVal; // Always should be set (size of the set len)
int st[3*mx];

void RESET(){
    for(int i=0;i<mx;i++)
        adj[i].clear();
    T=0;
    CLEAR(st,0);
    nodeId=0;
    MaxVal=n;   // size of set.
}

void updateST(int node, int l, int r,int x, int val){
    if(l>r or l>x or r<x)return;
    if(l==r){
        st[node]=val;
        return;
    }
    updateST(ls(node),l,MID(l,r),x,val);
    updateST(rs(node),MID(l,r)+1,r,x,val);
    st[node]=st[ls(node)]+st[rs(node)];
}
int queryST(int node, int l, int r, int x, int y){
    if(l>y or r<x or l>r)return 0;
    if(l>=x and r<=y){
        return st[node];
    }
    return queryST(ls(node),l,MID(l,r),x,y)+
        queryST(rs(node),MID(l,r)+1,r,x,y);
}
int dfs(int u, int p){  // No need to change it.
    start[u]=T++;
    parent[u][0]=p;
    for(int i=1;i<=17;i++){   // recursively done ( LCA init)
        parent[u][i]=parent[parent[u][i-1]][i-1];
    }
    child[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v==p)continue;
        child[u]+=dfs(v,u);
    }
    finish[u]=T++;
    return child[u];
}

bool isAncestor(int u, int v){
    if(start[u]<=start[v] and finish[u]>=finish[v])return true;
    return 0;
}

int lca_query(int u, int v){    // No need to change it.
    int w=-1, temp=u;
    if(isAncestor(u,v))w=u;
    if(isAncestor(v,u))w=v;
    if(w==-1){
        for( int i=17;i>=0;i--)
            if(!isAncestor(parent[temp][i],v))
                temp=parent[temp][i];
        w=parent[temp][0];
    }
    return w;
}

int hld(int u, int p, int lastNode){    // No need to change it.
    currentIndex[u] = (++nodeId);       // dfs order
    firstNode[u]=lastNode;

    int ind=-1, ma=-1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v==p)continue;
        if(ma>=child[v])continue;
        ma=child[v];
        ind=i;
    }
    if(ind>=0) hld(adj[u][ind],u,lastNode); //Same Segment
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v==p or i==ind)continue;
        hld(v,u,v);
    }
}

int arr[mx];
// u should be upper node (closer to root)
int query_up(int u, int v){
    int ans=0;
    while(true){
        int y=currentIndex[v];
        int x=currentIndex[firstNode[v]];
        int z=currentIndex[u];
        if(z>=x and z<=y){
            x=z;
            ans+=queryST(1,1,n,x,y);
            break;
        }
        ans+=queryST(1,1,n,x,y);
        v=parent[firstNode[v]][0];
    }
    return ans;
}

int query(int u, int v){
    int lca=lca_query(u,v);
    // You can change here accordingly
    return query_up(lca,u)+query_up(lca,v)-query_up(lca,lca);
}

void update(int u,int x){
    updateST(1,1,n,currentIndex[u],x);
}

int main() {
    #ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL

    int test;
    read(test);
    for(int C=1;C<=test;C++) {
        printf("Case %d:\n", C);
        read(n);
        RESET();
        for(int i=0;i<n;i++){
            read(arr[i]);
        }
        int u,v;
        for(int i=0;i<n-1;i++){
            read(u);read(v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(0,0);
        hld(0,0,0);
        MaxVal=nodeId+1;
        for(int i=0;i<n;i++)
            update(i,arr[i]);
//        for(int i=0;i<n;i++){
//            cout<<i<<" "<<currentIndex[i]<<endl;
//        }
        int q;read(q);
        while(q--){
            int c;
            read(c);
            if(!c){
                read(u);read(v);
                printf("%d\n",query(u,v));
            }else{
                read(u);read(v);
                update(u,v);
            }
        }
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}




