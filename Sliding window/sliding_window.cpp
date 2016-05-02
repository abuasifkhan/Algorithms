#include<iostream>
    #include<cstdio>
    #include<algorithm>
    #include<cstring>
    #include<cmath>
    #include<deque>
    #define maxm 10000200
    #define inf 1000000
    using namespace std;
   int  a[maxm];
   int  n,k;

int main()
    {
         //freopen("a.txt","r",stdin);
         scanf("%d%d",&n,&k);
         for(int i=0;i<n;i++)
         scanf("%d",&a[i]);
         deque<int> q;
         int i=0;
         for(i=0;i<k-1;i++)
         {
             while(!q.empty() && a[i]<=a[q.back()])
                   q.pop_back();
                   q.push_back(i);
         }
         for(;i<n;i++)
         {

             while(!q.empty() && q.front()<=i-k)
             q.pop_front();
              while(!q.empty() && a[i]<=a[q.back()])
                   q.pop_back();
              q.push_back(i);
              if(!q.empty())
              printf("%d ",a[q.front()]);
         }
         printf("\n");
         q.clear();
         i=0;
         for(i=0;i<k-1;i++)
         {
             while(!q.empty() && a[i]>=a[q.back()])
                   q.pop_back();
                   q.push_back(i);
         }
         for(;i<n;i++)
         {

             while(!q.empty() && q.front()<=i-k)
             q.pop_front();
              while(!q.empty() && a[i]>=a[q.back()])
                   q.pop_back();
              q.push_back(i);
              if(!q.empty())
              printf("%d ",a[q.front()]);
         }
             printf("\n");
             return 0;
    }
