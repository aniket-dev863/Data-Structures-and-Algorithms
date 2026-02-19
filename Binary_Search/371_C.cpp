// C. Hamburgers
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll req[3];
ll a[3];
ll c[3];
ll r;
ll check(ll num)
{
    // Can num amount of burgers be made in n rubles .
    ll cost = 0;
    cost += (req[0] == 0) ? 0 : (((req[0] * num) - a[0]) > 0) ? (((req[0] * num) - a[0]) * c[0])
                                                              : 0;

    if (cost > r)
        return 0;

    cost += (req[1] == 0) ? 0 : (((req[1] * num) - a[1]) > 0) ? (((req[1] * num) - a[1]) * c[1])
                                                              : 0;

    if (cost > r)
        return 0;

    cost += (req[2] == 0) ? 0 : (((req[2] * num) - a[2]) > 0) ? (((req[2] * num) - a[2]) * c[2])
                                                              : 0;

    return cost <= r;
}
void solve()
{
    string s;
    cin >> s;
    for (ll i = 0; i < 3; i++)
        cin >> a[i];
    for (ll i = 0; i < 3; i++)
        cin >> c[i];
    cin >> r;
    int s_c = 0, b_c = 0, c_c = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == 'B')
            b_c++;
        else if (s[i] == 'S')
            s_c++;
        else if (s[i] == 'C')
            c_c++;
    }
    req[0] = b_c;
    req[1] = s_c;
    req[2] = c_c;

    ll l = 0;
    ll h = 1e12 + 300;
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
    solve();
    return 0;
}

// Debug  Report :
/*
    Logical Error :
        Negetive integer formation at the cost += ;
        when the req is 0;
        Solved using a Ternary Operator ;

    All Given TCs Passed :

    Modification 01 :
        Again used ternary function to check if req>av

    Modification 02 :
        Changed the higher limit from 1e12 to 1e12 +300 :

    VERDICT : Accepted .
*/