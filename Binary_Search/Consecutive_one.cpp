// Consecutive one
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, k;
ll a[100100];
ll check(ll num)
{
    if (num > n)
        return 0;
    ll z_c = 0;
    for (ll i = 0; i < num; i++)
    {
        if (a[i] == 0)
            z_c++;
    }
    ll mi = z_c;
    ll st = 0;
    ll en = num - 1;
    for (ll i = 0; i < n - num; i++)
    {
        if (a[st] == 0)
            z_c--;
        if (a[en + 1] == 0)
            z_c++;
        st++;
        en++;
        mi = min(mi, z_c);
    }
    return mi <= k;
}
void solve()
{
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = -1;
    ll l = 0;
    ll h = n + 1;
    while (l <= h)
    {
        ll mid = (h + l) / 2;
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

// STATUS  : Passed all TCS ;
// VERDICT : Accepted