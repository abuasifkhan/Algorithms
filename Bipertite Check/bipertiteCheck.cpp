/// Bipartite checking

#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>

#define INF 1<<20
#define pb(x) push_back(x)
#define pi pair<int,int>
#define pii pair<int,pi>
#define MAX 210
#define fil() freopen("in.txt","r",stdin)

using namespace std;

vector < int > G[MAX];
int cost[MAX],N,E,u,v,parent[MAX];
bool visited[MAX], color[MAX];
bool flag = true;
void init()
{
    for(int i=1; i<=N+5; ++i)
    {
        cost[i]=INF;
        visited[i]=0;
        parent[i]=i;
//        G[i].clear();
    }
}

bool bfs(int start)
{
    queue<int>q;
    q.push(start);
    cost[start]=0;
    visited[start]=1;

    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=0; i<G[u].size(); ++i)
        {
            if(visited[G[u][i]]==0 )
            {

                color[G[u][i]] = 1-color[u];
                q.push(G[u][i]);
                visited[G[u][i]]=1;
                cost[G[u][i]]=cost[u]+1;
            }
            else
            {
                if(color[G[u][i]]==color[u])
                {
                    flag = false;
                    break;
                }
            }
        }
    }
    return flag;
}



int main()
{
//    freopen("D:/a.txt","r",stdin);
    int i,j,k,c,end;

    while(scanf("%d %d",&N,&E)==2 )
    {
//        cout<<N<<" "<<E<<endl;
        if(N==0)
            return 0;
        for(i=0; i<=N+5; i++)
            G[i].clear();
        for(i=1; i<=E; ++i)
        {
            scanf("%d %d",&u,&v);
//            cout<<u<<" "<<v<<endl;
            G[u].pb(v);
            G[v].pb(u);
        }

        init();

//    scanf("%d",&u);
        color[0]=1;
        flag=true;
        bfs(0);
        (flag)?printf("BICOLORABLE.\n"):printf("NOT BICOLORABLE.\n");

    }
    return 0;

}



