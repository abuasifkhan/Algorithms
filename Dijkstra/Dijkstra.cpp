#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <list>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define max 200
#define ii pair <int, int>
#define inf 32000
vector <  pair<int, int> > matrix[max];
int to, from, nodeValue[max];
int nodes, edges;
bool visited[max];
struct comp {
    bool operator () (const ii& a, const ii& b) {
        return ( a.second > b.second );
    }
};
void dijkstra () {

    priority_queue < ii, vector <ii> , comp > pq;
    int start = from;
    pq.push(ii (start, 0));
    nodeValue[start] = 0;
    while (!pq.empty()) {
        int u= pq.top().first;
        pq.pop();
        if (visited[u])
            continue;
        for (int i=0; i<matrix[u].size(); i++) {
            int v = matrix[u][i].first;
            int w = matrix[u][i].second;
            if (!visited[v] and ( nodeValue[u]+w < nodeValue[v] or nodeValue[v]==-1 )) {
                nodeValue[v] = nodeValue[u] + w;
                pq.push(ii (v, nodeValue[v]));
            }
        }
        visited[u] = true;
    }
}


main () {
    freopen ("D:/b.txt", "r", stdin);

    while ( cin >> nodes >> edges ) {
        for (int i=0; i<max; i++)
            matrix[i].clear();
        CLEAR (visited, false);
        CLEAR (nodeValue, -1);
        for (int i=1; i<=edges; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            matrix[u].push_back( ii(v, w));
        }

        cin >> from >> to;

        for (int i=0; i<nodes; i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                cout << i << " " << matrix[i][j].first << " " << matrix[i][j].second << endl;
            }
            cout << endl;
        }
        dijkstra ();

    }
}





