/** ========================================**
 ** Bismillahi-Rahamanirahim.               **
 ** @Author: A Asif Khan Chowdhury          **
 ** https://toph.co/p/distinct-dishting     **
 ** ========================================**/

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <deque>
#include <strings.h>
#include <cmath>
#include <cstdio>
#include <set>
#include <list>
#include <algorithm>
#include <map>
#include <bitset>
#include <unordered_map>

using namespace std;

#define Set(N, j) (N|(1ll<<j))
#define reset(N, j) (N&~(1ll<<j))
#define Check(N, j) (bool)(N&(1ll<<j))
#define toggle(N, j) (N^(1ll<<j))
#define turnOff(N, j) (N & ~(1ll<<j))

#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pii pair <int, int>
#define pb push_back
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf (1ll<<28)
#define ll long long
#define ull unsigned ll
#define sz(x) (int)x.size()
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
#define mx 300010

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while((~c&&c<'0')||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
//int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};   //x 8 direction
//int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};  //y 8 direction
int X[]= {-1, 0, 1, 0};   //x 4 direction
int Y[]= { 0, 1, 0, -1};  //y 4 direction


int n,q;
ll arr[mx];
ll res[mx], tmp[mx], freq[mx], originalValue[mx];
unordered_map<ll,ll>seen;
vector<ll>positions[mx];
int location[mx];
ll result[mx];

struct node{
    int idx, l, r, sql, sqr, updateAbove;
}query[mx];
struct node2{
    int idx;
    ll val, pre;
} update[mx];

bool comp(node a, node b){
    if(a.sql==b.sql){
        if(a.sqr==b.sqr){
            return a.updateAbove<b.updateAbove;
        } else{
            return a.sqr<b.sqr;
        }
    }else{
        return a.sql<b.sql;
    }
}

int ct;
int block;

void updateFrequency(int idx, int val){
    freq[arr[idx]] += val;
}
bool isFirstTimeInserted(int idx){
    return (arr[idx] and freq[arr[idx]]==1);
}

bool isRemoved(int idx){
    return (arr[idx] and freq[arr[idx]]==0);
}

ll getOriginalValue(int idx){
    return originalValue[arr[idx]];
}


ll del(int idx){
    updateFrequency(idx,-1);
    return isRemoved(idx)*getOriginalValue(idx);
}
ll add(int idx){
    updateFrequency(idx,+1);
    return isFirstTimeInserted(idx)*getOriginalValue(idx);
}

ll adjustUpdates(int &cur, int st, int en, int updateAbove){
    ll ans = 0;
    while(cur<updateAbove){
        int idx = update[cur].idx;

        if(idx>=st && idx<=en){
            ans -= del(idx);
        }
        arr[idx] = update[cur].val;
        if(idx>=st and idx<=en){
            ans += add(idx);
        }
        /// TODO above this
        cur++;
    }
    while(cur>updateAbove){
        cur--;
        /// TODO below this
        int idx = update[cur].idx;
        if(idx>=st and idx<=en){
            ans -= del(idx);
        }

        arr[idx] = update[cur].val;
        if(idx>=st and idx<=en){
            ans += add(idx);
        }
    }
    return ans;
}


ll adjustQueries(int &st, int &en, int l, int r){
    ll ans = 0;
    while(st<l){
        ans-=del(st);
        /// TODO delete above this
        st++;
    }
    while(st>l){
        st--;
        /// TODO add below this
        ans+=add(st);
    }
    while(en<r){
        en++;
        /// TODO add below this
        ans+=add(en);
    }
    while(en>r){
        ans-=del(en);
        /// TODO delete above this
        en--;
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("C:/Users/abu.chowdhury/Desktop/programming/input.in","r",stdin);
//    freopen("C:/Users/abu.chowdhury/Desktop/programming/output.out","w",stdout);
#endif

    read(n);
    read(q);
    ct=1;


    for(int i=0;i<n;i++){
        int num;
        read(num);
        if(!num or num%3){
            arr[i]=0;
            originalValue[arr[i]] = 0;
        }else{
            if(seen.count(num)==0){
                seen[num] = ct;
                originalValue[ct]=num;
                ct++;
            }
            arr[i] = seen[num];
        }
        positions[i].pb(arr[i]);
    }

    block = pow(n, 0.667);
    int upd = 0, qry=0;

    for(int i=0;i<q;i++){
        int t;read(t);
        if(!t){
            int idx, val;
            read(idx);read(val);
            idx--;
            if(val==0 or val%3) val=0;
            else{
                if(seen.count(val)==0){
                    seen[val]=ct;
                    originalValue[ct]=val;
                    ct++;
                }
                val = seen[val];
            }
            update[upd]={ idx, val, positions[idx][location[idx]] };

            positions[idx].pb(val);
            location[idx]++;
            upd++;
        }
        else{
            int l,r;
            read(l);read(r);l--,r--;
            query[qry] = { qry, l, r, l/block, r/block, upd };
            qry++;
        }
    }

    sort(query, query+qry, comp);

    int cur=0,st=0,en=-1,ans=0;

    for(int i=0;i<qry;i++){
        ans += adjustUpdates(cur,st,en, query[i].updateAbove);
        ans += adjustQueries(st,en,query[i].l,query[i].r);
        result[query[i].idx]=ans;
    }


    for(int i=0;i<qry;i++){
        printf("%lld\n",result[i]);
    }
    return 0;
}










