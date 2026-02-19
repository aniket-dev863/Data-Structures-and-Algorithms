// AZ Question
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, k;
ll a[100100];
ll check(ll num)
{
    ll cnt = 1;
    for (ll i = 0; i < n;)
    {
        auto it = lower_bound(a, a + n, a[i] + num);
        if (it != a + n)
        {
            cnt++;
            i = (it - a);
            if (cnt >= k)
                return 1;
        }
        else
        {
            break;
        }
    }
    return cnt >= k;
}
void solve()
{
    cin >> n >> k;
    ll ma = -1e9;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        ma = max(a[i], ma);
    }
    sort(a, a + n);
    ll l = 0;
    ll h = ma;
    ll ans = -1;
    while (l <= h)
    {
        ll mid = (l + h) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll ts;
    cin >> ts;
    while (ts--)
        solve();
    return 0;
}