#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m, k;
ll check(ll num)
{
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
    {
        cnt += (min(num / i, m));
        if (cnt >= k)
            return 1;
    }
    return cnt >= k;
}
void solve()
{
    cin >> n >> m >> k;
    ll l = 1;
    ll h = n * m;
    ll ans = -1;
    while (l <= h)
    {
        ll mid = (l + h) / 2;
        if (check(mid) == 1)
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}