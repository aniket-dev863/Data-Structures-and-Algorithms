#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, q;
ll a[1000100];
ll checkPeak(ll num)
{
    if (num == n - 1)
        return 1;
    else
        return a[num] > a[num + 1];
}
ll findPeak()
{
    ll l = 0;
    ll h = n - 1;
    ll ans = -1;
    while (l <= h)
    {
        ll mid = (l + h) / 2;
        if (checkPeak(mid))
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
void solve()
{
    cin >> n >> q;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll pk = findPeak();
    // cout<<pk<<"\n" ;
    while (q--)
    {
        ll qn;
        cin >> qn;
        ll la = 0, ha = pk;
        ll pos = -1;
        while (la <= ha)
        {
            ll ma = (la + ha) / 2;
            if (a[ma] > qn)
            {
                ha = ma - 1;
            }
            else if (a[ma] < qn)
            {
                la = ma + 1;
            }

            else
            {
                pos = ma;
                break;
            }
        }
        if (pos != -1)
            cout << pos + 1 << " ";

        ll lb = pk + 1, hb = n - 1;
        pos = -1;
        while (lb <= hb)
        {
            ll mb = (lb + hb) / 2;
            if (a[mb] > qn)
            {
                lb = mb + 1;
            }
            else if (a[mb] < qn)
            {
                hb = mb - 1;
            }
            else
            {
                pos = mb;
                break;
            }
        }
        if (pos != -1)
            cout << pos + 1 << " ";

        cout << "\n";
    }
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