#include<bits/stdc++.h>
using namespace std;

#define INF 10000000

struct Point
{
    int x;
    int y;
};
bool f;
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}
bool isInside(Point polygon[], int n, Point p)
{
    if (n < 3)  return false;
    Point extreme = {INF, p.y};
    int count = 0, i = 0;
    do
    {
        int next = (i+1)%n;
        if (doIntersect(polygon[i], polygon[next], p, extreme))
        {
            if (orientation(polygon[i], p, polygon[next]) == 0)
               return f=onSegment(polygon[i], p, polygon[next]);

            count++;
        }
        i = next;
    } while (i != 0);
    return count&1;
}
int main()
{
    int T,n,total;
//    freopen("a.txt","r",stdin);
    Point p[20],q;
    cin>>T;
    while(T--)
    {
        cin>>total>>q.x>>q.y;
        for(int i=0;i<total;i++)
        {
            cin>>n;
            for(int j=0;j<n;j++)
                cin>>p[j].x>>p[j].y;
                f=false;
           bool ans=isInside(p,n,q);
           if(ans)
           {
               if(f)cout<<"on the lne"<<endl;
               else cout<<"inside"<<endl;
           }
           else cout<<"outside"<<endl;
           if(i<total-1)cout<<" ";
        }
        cout<<"\n";
    }


    return 0;
}












