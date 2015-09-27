//! Bismillahi-Rahamanirahim.
/** ========================================**
 ** @Author: A Asif Khan Chowdhury
/** ========================================**/


/**................ Headers ................**/
#include <bits/stdc++.h>

using namespace std;

/**................ Macros ................**/
#define Set(N, j) (N|(1<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1<<j))
#define toggle(N, j) (N^(1<<j))
#define turnOff(N, j) (N & ~(1<<j))
#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pii pair <int, int>
#define pb push_back
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf (1<<30)
#define ll long long
#define mod 1000000007
#define gc getchar
#define debug_array(a,n) for(int i=0;i<n;i++) cout<<a[i].in<<" "; cout<<endl;
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 410
int n=4;
//Fast Reader
template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};   //x 8 direction
int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};  //y 8 direction
// int X[]= {-1, 0, 1, 0};   //x 4 direction
// int Y[]= { 0, 1, 0, -1};  //y 4 direction

void solve(int arr[][n]){
    int status[2*n];
    /*status[i] contains husband/wife of i, initially -1*/
    memset(status,-1,sizeof(status));
    queue<int>Q;
    for(int i=0;i<n;i++)Q.push(i); /* Push all single men */

    /* While there is a single men */
    while(!Q.empty()){
        int men=Q.front();
        Q.pop();
        /* iterate through his preference list */
        for(int j=0;j<n;j++){
            int girl=arr[i][j];
        /* if girl is single marry her to this man*/
            if(status[girl]==-1){
                status[men]=girl; /* set this girl as wife of i */
                status[girl]=men; /*make i as husband of this girl*/
                break; /*break the loop*/
            }

            int rank1, rank2;
            /* for holding priority of current
             husband and most preferable husband*/
            for(int k=0;k<n;k++){
                if(arr[girl][k]==status[girl])rank1=k;
                if(arr[girl][k]==men)rank2=k;
            }
            /* if current husband is less attractive :D
            than divorce him and marry a new one making the old one
            single */
            if(rank2<rank1){
                /* if this girl j prefers current man i
                   more than her present husband */
                status[men]=girl; /* her wife of i */
                int old=status[girl];
                status[old]=-1; /*divorce current husband*/
                Q.push(old); /*add him to list of singles */
                status[girl]=men; /* set new husband for this girl*/
                break;
            }
        }
    }
}

int main() {
    #ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL
    // Can you solve it by brute force?
    // LDC
    // Are you sure you want to code so soon?? -_-
    // Simplify your code a little more. :)

    // 0 to 3 are men, 4 to 7 are women. Descending order priority
    int prefer[][n]={
        {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}




