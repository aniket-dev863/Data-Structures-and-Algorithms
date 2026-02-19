#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m, k;
ll a[1000100];
ll b[1000100];
ll check(ll num)
{
    ll cnt = 0;
    ll mi = min(n, m);
    if (mi == n)
    {
        for (ll i = 0; i < n; i++)
        {
            cnt += upper_bound(b, b + m, num - a[i]) - b;
            if (cnt >= k)
                return 1;
        }
    }
    else
    {
        for (ll i = 0; i < m; i++)
        {
            cnt += upper_bound(a, a + n, num - b[i]) - a;
            if (cnt >= k)
                return 1;
        }
    }
    return cnt >= k;
}
void solve()
{
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    ll h = a[n - 1] + b[m - 1];
    ll l = a[0] + b[0];
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

/*
    Debug Report :

        Mistake 01: Write Code without silly Mistakes

        Mistake 02 : Check The constraints carefully and make the Global Arrays to fulfill constraints

        Mistake 03 : In the check function to reduce time complexity traverse the array with minimum no of elements and take upbd wrt to that of other array .


    Logic was completely correct but implementation was not up to the mark .

*/