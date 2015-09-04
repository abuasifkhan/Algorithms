#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 100010;
long long tree[maxn << 2], lazy[maxn << 2];
void PushUp(int rt)
{
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}
void PushDown(int rt, int m)
{
    if (lazy[rt])
    {
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        tree[rt << 1] += lazy[rt] * (m - (m >> 1));
        tree[rt << 1 | 1] += lazy[rt] * (m >> 1);
        lazy[rt] = 0;
    }
}
void build(int l, int r, int rt)
{
    tree[rt] = lazy[rt] = 0;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
void update(int ll, int rr, int c, int l, int r, int rt)    /// ll=i, rr=j, l=a, r=b, c=value, rt = node
{
    if (ll <= l && rr >= r)
    {
        tree[rt] += (long long)c * (r - l + 1);
        lazy[rt] += c;
        return;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (ll <= m) update(ll, rr, c, lson);
    if (rr > m) update(ll, rr, c, rson);
    PushUp(rt);
}
long long query(int ll, int rr, int l, int r, int rt)
{
    if (ll <= l && rr >= r) return tree[rt];
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    long long ret = 0;
    if (ll <= m) ret += query(ll, rr, lson);
    if (rr > m) ret += query(ll, rr, rson);
    return ret;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        printf("Case %d:\n", i);
        int n, m;
        scanf("%d%d", &n, &m);
        build(0, n - 1, 1);
        while (m--)
        {
            int d; scanf("%d", &d);
            if (d == 0)
            {
                long long x, y, z;
                scanf("%lld%lld%lld", &x, &y, &z);
                update(x, y, z, 0, n - 1, 1);
            }
            if (d == 1)
            {
                int x, y;
                scanf("%d%d", &x, &y);
                long long ans = query(x, y, 0, n - 1, 1);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
