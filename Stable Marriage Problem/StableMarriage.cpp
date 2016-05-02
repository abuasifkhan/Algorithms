//! Bismillahi-Rahamanirahim.
/** ========================================**
 ** @Author: A Asif Khan Chowdhury
/** ========================================**/

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




