#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <set>
#define pb push_back
using namespace std;

//LCA using sparse table
//Complexity: O(NlgN,lgN)
#define mx 100002
int L[mx]; // level
int Parse[mx][22]; // Parse table
int P[mx]; //Parent
vector<int>g[mx];
void dfs(int from,int u,int dep) {
    P[u]=from;
    L[u]=dep;
    for(int i=0; i<(int)g[u].size(); i++) {
        int v=g[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}

int lca_query(int N, int p, int q) {
    int tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    log=1;
    while((1<<(log+1))<=L[p]) log++;
    // while(1) {
    //     int next=log+1;
    //     if((1<<next)>L[p])break;
    //     log++;
    // }
    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q]){
            p = Parse[p][i];
        }
    if (p == q){
        return p;
    }
    for (i = log; i >= 0; i--)
        if (Parse[p][i] != -1 && Parse[p][i] != Parse[q][i]){
            p = Parse[p][i], q = Parse[q][i];
        }
    return P[p];
}

void lca_init(int N) {
    memset (Parse,-1,sizeof(Parse)); // Initially parse[] = -1
    int i, j;
    for (i = 0; i < N; i++)
        Parse[i][0] = P[i];

    for (j = 1; 1 << j < N; j++)
        for (i = 0; i < N; i++)
            if (Parse[i][j - 1] != -1){
                Parse[i][j] = Parse[Parse[i][j - 1]][j - 1];
            }
}

int main(void) {
    g[0].pb(1);
    g[1].pb(2);
    g[1].pb(3);
//    g[2].pb(4);
    dfs(0, 0, 0);
    lca_init(4);
    printf( "%d\n", lca_query(4,2, 3) );
    return 0;
}

