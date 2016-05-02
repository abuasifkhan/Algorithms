vector<int> CalcLIS(int arr[], int n, int dpLIS[]){
    vector<int>L;
    vector<int>::iterator it;

    // For LDS reverse arr[].

    for(int i=1;i<=n;i++){
        it = lower_bound(L.begin(),L.end(),arr[i]);
        dpLIS[i] = (int)(it-L.begin());
        if(it==L.end()) L.pb(arr[i]);
        else *it = arr[i];
    }
}
