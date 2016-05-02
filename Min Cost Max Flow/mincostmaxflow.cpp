//! Bismillahi-Rahamanirahim.

// Implementation of min cost max flow algorithm using adjacency
// matrix (Edmonds and Karp 1972).  This implementation keeps track of
// forward and reverse edges separately (so you can set cap[i][j] !=
// cap[j][i]).  For a regular max flow, set all edge costs to 0.
//
// Running time, O(|V|^2) cost per augmentation
//     max flow:           O(|V|^3) augmentations
//     min cost max flow:  O(|V|^4 * MAX_EDGE_COST) augmentations
//
// INPUT:
//     - graph, constructed using AddEdge()
//     - source
//     - sink
//
// OUTPUT:
//     - (maximum flow value, minimum cost value)
//     - To obtain the actual flow, look at positive values only.
// Doesn't work with negative weights.

typedef vector<int>VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<pii>VPII;

struct MinCostMaxFlow{
    int N;
    VVL cap, flow, cost;
    VI found;
    VL dist, pi, width;
    VPII dad;
    MinCostMaxFlow(int N):
        N(N), cap(N, VL(N)), flow(N,VL(N)), cost(N,VL(N)),
        found(N), dist(N),pi(N),width(N),dad(N){}

    void AddEdge(int from, int to, ll cap, ll cost){
        this->cap[from][to]=cap;
        this->cost[from][to]=cost;
    }

    void Relax(int s, int k, ll cap, ll cost, int dir){
        ll val = dist[s]+pi[s]-pi[k]+cost;
        if(cap and val<dist[k]){
            dist[k]=val;
            dad[k]=make_pair(s,dir);
            width[k]=min(cap,width[s]);
        }
    }

    ll Dijkstra(int s, int t){
        fill(found.begin(),found.end(),false);
        fill(dist.begin(),dist.end(),inf);
        fill(width.begin(),width.end(),0);
        dist[s]=0;
        width[s]=inf;

        while(s!=-1){
            int best=-1;
            found[s]=true;
            for(int k=0;k<N;k++){
                if(found[k])continue;
                Relax(s,k,cap[s][k]-flow[s][k],cost[s][k],1);
                Relax(s,k,flow[k][s],-cost[k][s],-1);
                if(best==-1 or dist[k]<dist[best])best=k;
            }
            s=best;
        }

        for(int k=0;k<N;k++)
            pi[k]=min(pi[k]+dist[k],inf);
        return width[t];
    }
    pair<ll,ll> GetMaxFlow(int s, int t){
        ll totflow=0, totcost=0;
        while(ll amt=Dijkstra(s,t)){
            totflow+=amt;
            for(int x=t;x!=s; x=dad[x].first){
                if(dad[x].second==1){
                    flow[dad[x].first][x]+=amt;
                    totcost+=amt*cost[dad[x].first][x];
                } else {
                    flow[x][ dad[x].first ]-=amt;
                    totcost -= amt*cost[x][dad[x].first ];
                }
            }
        }

        return make_pair(totflow,totcost);
    }
};
