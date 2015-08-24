///305- Network
/*
    Theory:
    dfs_num: dfs number. অর্থাৎ কত নাম্বার রিকার্সন কলে আমরা ওই নোডে প্রবেশ করেছি।
    dfs_low: নোডটি যে কয়টা নোডের সাথে সাইকল ফর্ম করেছে তাদের মধ্যে মিনিমাম যে dfs_num সেটা স্টোর করে।
    u থেকে v তে যাওয়া গেলে যদি দেখা যায় যে v অলরেডি ভিজিটেড, তাহলে dfs_low[u] হবে min(dfs_low[u],dfs_low[v])
        অর্থাৎ মিনিমাম dfs_number স্টোর করা হলো।
        আর যদি v ভিজিটেড না হয় তখন dfs_low[u] হবে min(dfs_num[u],dfs_low[v]). এখন যদি দেখা যায় dfs_num[u]>=dfs_low[v]
        তাহলে অবশ্যই এটা আর্টিকুলেশন পয়েন্ট। আর যদি dfs_num[u]>dfs_low[v] অর্থাৎ বড় হয় তাইলে এটা অবশ্যই ব্রিজ। বিশ্বাস না হলে খাতা-কলমে করে দেখ। -_-
*/
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define max 120
#define pii pair <int, int>
#define pb push_back
#define inf 32000
#define pf printf


int node;
vector <int> adjlist[max];
int dfs_num[max], dfs_low[max], rootChildren, dfsRoot, dfs_parent[max], dfsNumberCounter=0, c = 0;
bool articulation_vertex[max];

void articulationPointAndBridges(int u)
{
    dfs_low[u] = dfs_num[u] = ++dfsNumberCounter;
    for (int i=0; i<adjlist[u].size(); i++)
    {
        int v = adjlist[u][i];
        if (dfs_num[v] == 0){
            dfs_parent[v] = u;
            if (u == dfsRoot)   rootChildren++;

            articulationPointAndBridges( v);
            dfs_low[u] = min (dfs_low[u], dfs_low[v]) ;

            if (dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = true;
            if ( dfs_low[v] > dfs_num[u] )
                pf ("Edge (%d %d) is a bridge.\n", u, v);
        }
        else if ( v != dfs_parent[u] )
            dfs_low[u] = min (dfs_low[u], dfs_num[v]);
    }
}

void reset ()
{
    CLEAR (articulation_vertex, false);
    for (int i=0; i<max; i++)
    adjlist[i].clear();
    dfsNumberCounter=0;
    CLEAR (dfs_num, 0);
    CLEAR (dfs_parent, 0);
    CLEAR (dfs_low, 0);
    rootChildren = 0;
}

main ()
{
    int test, c = 0;
    freopen ("E:/a.txt", "r", stdin);
    // cin >>test;
    // while (test--)
    // {
        reset ();
//        freopen ("D:/a.txt", "r", stdin);

        int edge;
        cin >> node >> edge;
        while (edge--)
        {
            int u, v;
            cin >> u >> v;
            adjlist[u].pb(v);
            adjlist[v].pb(u);
        }
        for (int i=1; i<=node; i++)
        {
            if (dfs_num[i] == 0){
                dfsRoot = i; rootChildren = 0;
                articulationPointAndBridges(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }
        cout  << endl;
        cout << "Articulation point:\n";
        for (int i=1; i<=node; i++)
            if (articulation_vertex[i])
            cout << i << endl;
    // }
}







