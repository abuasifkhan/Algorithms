#include<bits/stdc++.h>
#define PI 2*acos(0)

using namespace std;

main()
{
    int T,cased=0;
    cin>>T;
    while(T--)
    {
        double x1,x2,y1,y2,r1,r2,theta1,theta2,d,output,h;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        //cout<<d<<endl;
        theta1=acos((r1*r1+d*d-r2*r2)/(2.0*r1*d));
        theta2=acos((r2*r2+d*d-r1*r1)/(2.0*r2*d));
       // cout<<theta1<<" "<<theta2<<endl;
        // h1=sqrt(r1*r1-d*d/4)
        output=r1*r1*theta1-r1*r1*sin(2*theta1)/2.0+r2*r2*theta2-r2*r2*sin(2*theta2)/2.0;
        if(r1+r2<=d)
        output=0;
        if(abs(r1-r2)>=d)
        output=min(PI*r1*r1,PI*r2*r2);
       // cout<<theta1<<" "<<theta2<<endl;
        printf("Case %d: %.10lf\n",++cased,output);
    }
}
