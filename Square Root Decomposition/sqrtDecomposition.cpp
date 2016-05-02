#include<bits/stdc++.h>
using namespace std;
const int sz=100005;
const int inf=(1<<28);
template<typename t> t MIN3(t a,t b, t c){return min(a,min(b,c));}
int BLOCK[400];
int arr[sz];
int getId(int indx,int blockSZ)
{
    return indx/blockSZ;
}
void init(int sz)
{
    for(int i=0; i<=sz; i++)BLOCK[i]=inf;
}
void update(int val,int indx,int blockSZ)
{
    int id=getId(indx,blockSZ);
    BLOCK[id]=min(BLOCK[id],val);
}
int query(int L,int R,int blockSZ)
{
    int lid=getId(L,blockSZ);
    int rid=getId(R,blockSZ);
    if(lid==rid)
    {
        int ret=inf;
        for(int i=L; i<=R; i++)ret=min(ret,arr[i]);
        return ret;
    }
    int m1=inf,m2=inf,m3=inf;
    for(int i=L; i<(lid+1)*blockSZ; i++)m1=min(m1,arr[i]);
    for(int i=lid+1;i<rid;i++)m2=min(m2,BLOCK[i]);
    for(int i=rid*blockSZ; i<=R; i++)m3=min(m3,arr[i]);
    return MIN3(m1,m2,m3);
}
int main()
{
    int N,Q;
    scanf("%d %d",&N,&Q);
    int blockSZ=sqrt(N);
    init(blockSZ);
    for(int i=0; i<N; i++)
    {
        int x;
        scanf("%d",&x);
        arr[i]=x;
        update(x,i,blockSZ);
    }
    while(Q--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",query(x,y,blockSZ));
    }
    return 0;
}
