// C. K-th Not Divisible by n
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, k;
ll check(ll num)
{
    if (num % n == 0)
        return 0;
    return (num - (num / n)) >= k;
}
void solve()
{
    cin >> n >> k;
    ll l = 1;
    ll h = n * k;
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
    cin.tie(0);
    cout.tie(0);
    ll ts;
    cin >> ts;
    while (ts--)
        solve();
    return 0;
}