#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, k;
ll a[200200];
ll check(ll num)
{
    ll sum_left = 0;
    ll sub_arrays = 0;
    for (ll i = 0; i < n; i++)
    {
        if (sum_left < a[i])
        {
            sub_arrays++;
            sum_left = num;
            if (sub_arrays > k)
                return 0;
            if (sum_left < a[i])
            {
                return 0;
            }
            sum_left -= a[i];
        }
        else
        {
            sum_left -= a[i];
        }
    }
    return sub_arrays <= k;
}
void solve()
{
    cin >> n >> k;
    ll sum = 0;
    ll ma = -1e9;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        ma = max(ma, a[i]);
    }
    ll l = ma;
    ll h = sum;
    ll ans = -1;
    while (l <= h)
    {
        ll mid = (l + h) / 2;
        if (check(mid))
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
    ll ts;
    cin >> ts;
    while (ts--)
    {
        solve();
    }
}