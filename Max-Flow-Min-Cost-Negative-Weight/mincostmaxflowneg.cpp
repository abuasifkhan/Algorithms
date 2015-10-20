int source, sink, nNode, nEdge;
int fin[mx],pre[mx],dist[mx];
int cap[100*mx],cost[100*mx],nxt[100*mx],to[100*mx],from[100*mx];

void init (int _src, int _snk, int nodes){
    fill(fin,fin+mx,-1);
    nNode=nodes, nEdge=0;
    source=_src, sink=_snk;
}

void addEdge(int u, int v, int _cap, int _cost){
    from[nEdge]=u, to[nEdge]=v,cap[nEdge]=_cap,cost[nEdge]=_cost;
    nxt[nEdge]=fin[u],fin[u]=nEdge++;
    from[nEdge]=v, to[nEdge]=u, cap[nEdge]=0, cost[nEdge]=-(_cost);
    nxt[nEdge]=fin[v],fin[v]=nEdge++;
}

bool bellman(){
    int iter,u,v,i;
    bool flag=true;
    fill(dist,dist+mx,inf);
    fill(pre,pre+mx,-1);
    dist[source]=0;
    for(iter=1;iter<nNode and flag; iter++){
        flag=false;
        for(u=0;u<nNode;u++){
            for(i=fin[u];i>=0;i=nxt[i]){
                v=to[i];
                if(cap[i] and dist[v]>dist[u]+cost[i]){
                    dist[v]=dist[u]+cost[i];
                    pre[v]=i;
                    flag=true;
                }
            }
        }
    }
    return (dist[sink]<inf);
}

int minCostMaxFlow(int &fcost){
    int netflow,bot,u;
    netflow=fcost=0;
    while(bellman()){
        bot=inf;
        for(u=pre[sink]; u>=0; u=pre[from[u]])
            bot=min(bot,cap[u]);
        for(u=pre[sink];u>=0;u=pre[from[u]]){
            cap[u]-=bot;
            cap[u^1]+=bot;
            fcost+=bot*cost[u];
        }
        netflow+=bot;
    }
    return netflow;
}
