
const int EEE=1000100;
int vis[mx];
int dist[mx];
int pre[mx];
struct Edge{
    int u,v,c,cost,next;
}edge[EEE];

int head[mx],cnt;

void init(){
    cnt=0;
    memset(head,-1,sizeof(head));
}
void addEdge(int u, int v, int c, int cost){
    edge[cnt].u=u;edge[cnt].v=v;edge[cnt].cost=cost;
    edge[cnt].c=c;edge[cnt].next=head[u];head[u]=cnt++;

    edge[cnt].u=v;edge[cnt].v=u;edge[cnt].cost=-cost;
    edge[cnt].c=0;edge[cnt].next=head[v];head[v]=cnt++;
}

bool bellman(int begin, int end){
    int u,v;
    queue<int>q;
    for(int i=0;i<=end+2;i++){
        pre[i]=-1;vis[i]=0;dist[i]=inf;
    }
    vis[begin]=1;
    dist[begin]=0;
    q.push(begin);
    while(!q.empty()){
        u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next){
            if(edge[i].c>0){
                v=edge[i].v;
                if(dist[v]>dist[u]+edge[i].cost){
                    dist[v]=dist[u]+edge[i].cost;
                    pre[v]=i;
                    if(!vis[v]){
                        vis[v]=true;
                        q.push(v);
                    }
                }
            }
        }
    }
    return dist[end]!=inf;
}

int minCostMaxFlow(int begin, int end, int &resflow){
    int ans=0,flow;
    int flow_sum=0;
    while(bellman(begin,end)){
        flow=inf;
        for(int i=pre[end];i!=-1;i=pre[edge[i].u])
            if(edge[i].c<flow)
                flow=edge[i].c;
        for(int i=pre[end];i!=-1;i=pre[edge[i].u]){
            edge[i].c-=flow;
            edge[i^1].c+=flow;
        }
        ans+=dist[end];
        flow_sum+=flow;
    }
    resflow=flow_sum;
    return ans;
}





