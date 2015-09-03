/**============= Approach =================**
@Author: A Asif Khan Chowdhury

The algorithm for the solution of 2-SAT can be applied in all tasks
 where there is a set of variables, each of which can take two
  possible values, and there is a connection between these values

Conditional statements like
"(a || c) && (a ||! d) && (b ||! d) && (b ||! e) && (c || d)" can be
solved by 2-SAT.

1- First DFS is for making order, in which SCC is going to be build.
2- Second DFS is for making topsort or SCC.
3- If i and ~i is same colored, 2-SAT is not possible.

/**========================================**/


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
#define open freopen("E:/a.txt", "r", stdin);
#define write freopen("E:/b.txt","w", stdout);
#define MAX (1+(1<<5))
#define inf 0x7fffffff
#define ll long long
#define mod 100000007
#define mx 17000

vector<int>G[mx], GT[mx];
bool visited[mx];
int color[mx];
vector<int>order;
int m, n;

void dfs(int u){        // Making order to be used to top sort
    visited[u]=true;
    for(int i=0; i<G[u].size(); i++){
        int v = G[u][i];
        if(!visited[v]) dfs(v);
    }
    order.pb(u);
}

void topo(int u, int col){  // top sort or SCC
    color[u]=col;
    for(int i=0;i<GT[u].size(); i++){
        int v = GT[u][i];
        if(color[v]==-1)
            topo(v, col);
    }
}

bool isTwoSat(){
    for(int i=2; i<=2*n; i+=2)
        if(color[i]==color[i^1])    // if i and ~i is same colored
            return false;           // 2-sat is not possible
    return true;
}

int main()
{
	// open
    int test;
    S(test);
    FOR(C, 1, test){
        S(m); S(n);
        for(int i=0; i<=2*n+4; i++) G[i].clear(), GT[i].clear();
        while(m--){
            int u, v; S(u); S(v);
            u = (u>0)?2*u : (-u)*2+1;
            v = (v>0)?2*v : (-v)*2+1;

            G[u].pb(v^1);
            G[v].pb(u^1);
            GT[v^1].pb(u);
            GT[u^1].pb(v);
        }
        out(C);
        CLEAR(visited, 0);
        order.clear();
        for(int i=2; i<=2*n+1; i++){
            if(!visited[i])
                dfs(i);
        }
        reverse(order.begin(), order.end());

        int col=0;
        for(int i=0;i<=2*n+2; i++)color[i]=-1;
        for(int i=0; i<order.size(); i++){
            int u = order[i];
            if(color[u]==-1)
                topo(u, col++);
        }

        if(!isTwoSat()){
            printf("%s\n", "No");
        }
        else{
            printf("%s\n", "Yes");
            vector<int>result;
            for(int i=2; i<=2*n; i+=2)
                if(color[i]<color[i^1])
                    result.pb(i/2);
            printf("%d", result.size());
            for(int i=0; i<result.size(); i++)
                printf(" %d", result[i]);
            puts("");
        }

    }
    return 0;
}
