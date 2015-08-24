#include<iostream>
#include<cstdio>
using namespace std;

int arr[1000];

int LowerBound(int Q, int n) {
    int lo=0, hi=n;
    int best_so_far=-1;
    while(lo<=hi) {
        int mid = (hi+lo)/2;
        if(arr[mid]>=Q) {
            if(arr[mid]==Q)
                best_so_far=mid;
            hi = mid-1;
        } else lo = mid+1;
    }
    return best_so_far;
}


int UpperBound(int Q, int n) {
    int lo=0, hi=n;
    int best_so_far=-1;
    while(lo<=hi) {
        int mid = (hi+lo)/2;
        if (arr[mid]<=Q) {
            if(arr[mid]==Q)
                best_so_far=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    return best_so_far;
}

int main() {
    freopen("E:/a.txt","r", stdin);
    int n;
    cin>>n;
//    cout<<n<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int itm;
    cin>>itm;
    cout<<LowerBound(itm, n-1)<<endl;
    cout<<UpperBound(itm, n-1)<<endl;
}
