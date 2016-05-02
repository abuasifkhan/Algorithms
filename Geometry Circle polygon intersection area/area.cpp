#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define S(X) ((X)*(X))
#define PI   (acos(-1.0))

typedef pair<double,double> PDD; //point

PDD P[5002],R; // P is the points of polygon
double PP,total;
int n;

inline double refine0(double d) { if(fabs(d)<EPS) return 0; return d; }
inline double refine01(double d) { if(fabs(d)<EPS) return 0; if(fabs(d-1)<EPS) return 1.; return d;}

void intersect(double r, int a, int b, vector<double>& V)
{
    double A, B, C, D, t1, t2;

    A = S(P[b].first - P[a].first) + S(P[b].second - P[a].second);
    B = 2*P[a].first*(P[b].first - P[a].first) + 2*P[a].second*(P[b].second - P[a].second);
    C = S(P[a].first) + S(P[a].second) - S(r);

    D = S(B) - 4*A*C;
    D = refine0(D);
    if( D < 0 ) return;

    t1 = (-B + sqrt(D))/(2*A);
    t2 = (-B - sqrt(D))/(2*A);

    t1 = refine01(t1);
    t2 = refine01(t2);

    if(0<=t1 && t1<=1) V.push_back(t1);
    if(0<=t2 && t2<=1) V.push_back(t2);

    sort(V.begin(),V.end());
}

double Angle(PDD A, PDD B)
{
    double angle = atan2(A.second, A.first) - atan2(B.second, B.first);
    return angle;
}

double Area(int a, int b, double t1, double t2, double r)
{
    PDD C1, C2;
    int in1, in2;
    double angle;;

    C1 = PDD( P[a].first + (P[b].first - P[a].first)*t1, P[a].second + (P[b].second - P[a].second)*t1);
    C2 = PDD( P[a].first + (P[b].first - P[a].first)*t2, P[a].second + (P[b].second - P[a].second)*t2);

    in1 = S(C1.first) + S(C1.second) - S(r) <= EPS;
    in2 = S(C2.first) + S(C2.second) - S(r) <= EPS;

    if(!in1 || !in2) //both out
    {
        double d = C1.first*C2.second - C1.second*C2.first;
        angle = Angle(C2,C1);
        while(d>=0 && angle<0) angle+=2*PI;
        while(d<0 && angle>0) angle-=2*PI;
        if(fabs(angle-2*PI)<EPS) angle=0;
        return angle*S(r);
    }
    else
    {
        return C1.first*C2.second - C1.second*C2.first;
    }
}

bool check(double r) //intersection area polygon and circle radious r ;
{
    int i,j,sz,k;
    double area=0;

    for(i=0;i<n;i++)
    {
        j = (i+1)%n;

        vector<double> V;
        V.push_back(0);
        V.push_back(1);
        intersect(r,i,j,V);

        sz = V.size();
        for(k=0;k<sz-1;k++)
        {
            area += Area(i,j,V[k],V[k+1],r);  //area is the intersection area
        }
    }
    return (area*100 >= PP*total);
}

int main()
{
    //freopen("a.txt","r",stdin);
    int T,ks;
    int i,j;
    double lo, hi, mid;
    PDD R;

    scanf("%d",&T);
    for(ks=1;ks<=T;ks++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%lf%lf",&P[i].first,&P[i].second);
        scanf("%lf%lf%lf",&R.first,&R.second,&PP);
        for(i=0;i<n;i++) P[i].first-=R.first, P[i].second-=R.second;

        total = 0;
        for(i=0;i<n;i++)
        {
            j=(i+1)%n;
            total += P[i].first*P[j].second - P[i].second*P[j].first; //area of polygon
        }
        lo = 0;
        hi = 1e6;
        while( hi - lo > 1e-6 )
        {
            mid = (hi + lo)/2.;

            if( check(mid) ) hi = mid;
            else lo = mid;
        }

        printf("Case %d: %.0lf\n",ks,lo);
    }
    return 0;
}
