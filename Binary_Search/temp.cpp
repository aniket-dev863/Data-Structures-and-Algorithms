/// this is the general way to write binary search
/// We will always use this simuation where we have
/// 0 0 0 0 1 1 1 1
/// In this we need to find 1st one
/// The simulation should always look like this  /.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll check(ll num)
{
    // make a return 1 and other zeros ie sort the array conditionally  .
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // standard BS template
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    ll hi = n - 1;
    ll lo = 0;
    ll ans = n;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2; // to avoid overflow here
        // Technically we are using long long so we can use ll mid = (low +high)/2 ;
        if (check(mid) == 1)
        {
            hi = mid - 1;
            ans = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
}
// In every different condition we just need to modify the check function
// this Check function shhould be modified in such a way that we get a array as [ 0 0 0 0 1 1 1 1 ]
// In which need to find first occurence of 1
// Everytime