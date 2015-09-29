void dijkstra(int *dist, int st, vector<pii>*g){
    set<pii>heap;
    for(int i=0;i<=n;i++)dist[i]=inf;

    heap.insert(pii(0,st));
    dist[st]=0;
    while(!heap.empty()){
        pii data=*heap.begin(); heap.erase(data);
        int u = data.sc;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].fs;
            int w=g[u][i].sc;
            if(dist[v]>dist[u]+w){
                if(dist[v]!=inf)heap.erase(pii(dist[v],v));
                dist[v]=dist[u]+w;
                heap.insert(pii(dist[v],v));
            }
        }
    }
}
