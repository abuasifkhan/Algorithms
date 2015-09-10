#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2*acos(0))
#define ERR        1e-5
#define PRE        1e-8
#define SZ(s)      ((int)s.size())
#define LL           long long
#define ISS         istringstream
#define OSS        ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)
#define fri(a,b)    for(i=a;i<=b;i++)
#define frin(a,b)   for(i=a;i>=b;i--)
#define frj(a,b)    for(j=a;j<=b;j++)
#define frjn(a,b)   for(j=a;j>=b;j--)
#define frk(a,b)    for(k=a;k<=b;k++)
#define frkn(a,b)   for(k=a;k>=b;k--)
#define frl(a,b)    for(l=a;l<=b;l++)
#define frln(a,b)   for(l=a;l>=b;l--)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define typing(j,b) typeof((b).begin()) j=(b).begin();
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
#define cntbit(mask) __builtin_popcount(mask)
#define pii pair<int, int>
#define MP make_pair
#define csprnt printf("Case %d: ", ++cas);
#define lim          1005 //if ed is allowed then the number of edge, else the number of nodes
//1 Based
//no problem in multiple edge and self loop
int tim[lim],low[lim];
int timer;
VI adj[lim]; //only adj should be cleared
stack<pii>S;
pii ed[2*lim];//because one edge can be part of two BCC

void calc_bcc(int u, int v)
{
    int i, j, uu, vv, cur;
    pii now; int tot=0;
    while(!S.empty())
    {
        now = S.top(); S.pop();
        uu = now.first, vv = now.second;
        ed[tot++] = MP(uu, vv);
        if(u==uu && v==vv) break;
        if(u==vv && v==uu) break;
    }
    if(tot<=1) return;

    //doing according to problem
    return;
}

void bcc(int u,int par)// par=-1 dhore call dite hobe(root ar parent nai)
{
    tim[u] = low[u] = ++timer;

    for(int i = 0 ; i<SZ(adj[u]) ; i++)
    {
        int v = adj[u][i];
        if(v==par) continue;
        if(tim[v]==0)
        {
            S.push(MP(u, v));
            bcc(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>=tim[u])
                calc_bcc(u, v);
        }

        else if(tim[v] < tim[u])
        {
            low[u] = min(low[u],tim[v]);
            S.push(MP(u, v));
        }
    }

    return;
}

void BCC(int n)
{
    timer=0;
    mem(tim,0);
    int i;
    fr(i,1,n)
    if(!tim[i])
        bcc(i,-1);
}

void add(int ina,int inb)
{
    adj[ina].pb(inb);
    adj[inb].pb(ina);
}

int main()
{
   return 0;
}
