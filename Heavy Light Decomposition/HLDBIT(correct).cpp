#include <bits/stdc++.h>

using namespace std;

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

void RESET(){
    for(int i=0;i<mx;i++)
        adj[i].clear();
    T=0;
    nodeId=0;
    MaxVal=n;   // size of set.
}

int queryBIT(int idx){  // Can use ST instead.
    int ret=0;
    while(idx){
        ret+=tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}
void updateBIT(int idx, int val){      // Can use ST instead.
    while(idx<=MaxVal){
        tree[idx]+=val;
        idx += (idx & -idx);
    }
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
    currentIndex[u] = (++nodeId);
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
            ans+=queryBIT(y)-queryBIT(x-1); // You can change here.
            break;
        }
        ans+=queryBIT(y)-queryBIT(x-1); // You can change here.
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
    // Can be done using ST.
    int curVal=queryBIT(currentIndex[u])-queryBIT(currentIndex[u]-1);
    x-=curVal;
    updateBIT(currentIndex[u],x);
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
/*
// Copyright (C) 2012, LamPhanViet
/* Test Cases:
3
4
10 20 30 40
0 1
1 2
1 3
6
0 2 3
1 1 100
0 2 3
0 0 3
0 3 0
0 0 2

7
0 1 2 3 4 5 6
0 6
0 1
1 5
1 2
2 3
3 4
4
0 0 4
0 4 6
0 5 6
0 3 4

11
0 1 2 3 4 5 6 7 8 9 10
0 1
1 3
1 2
2 4
2 5
5 6
6 7
6 8
6 9
6 10
1
0 4 6
// Answer:
// Case 1:
// 90
// 170
// 150
// 150
// 140
// Case 2:
// 10
// 16
// 12
// 7
// Case 3:
// 17
*/
