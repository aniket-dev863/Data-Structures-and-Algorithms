// Factory machines CSES
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, k;
ll a[200200];
ll check(ll mid)
{
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        cnt += mid / a[i];
        if (cnt >= k)
            return 1;
    }
    return cnt >= k;
}
void solve()
{
    cin >> n >> k;
    ll mi = 1e9;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mi = min(mi, a[i]);
    }
    ll ma = 1e18;
    ll h = ma;
    ll l = mi;
    ll ans = -1;
    while (l <= h)
    {
        ll mid = l + (h - l) / 2;
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
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
// DEBUG :
// Check : 01 Correct :
// TC passed
/*
    Internal TC Not Passed ALL
    Details :
    1 1000000000
    1000000000

    Reason :


*/