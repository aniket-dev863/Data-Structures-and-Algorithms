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
ll check(ll num, ll bd)
{
    return (num >= bd);
}
// This is the standard lower bound function using  check function
// For Upper bound do return (num > bd)
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

    ll x;
    cin >> x;
    ll hi = n - 1;
    ll lo = 0;
    ll ans = n;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2; // to avoid overflow here
        // Technically we are using long long so we can use ll mid = (low +high)/2 ;
        if (check(v[mid], x) == 1)
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
/*
Simulate for Input
5
1 2 3 4 6
5

Here the check function is used :
in a way it makes the array like this :
    0 0 0 0 1
    ans BS template gives is the first occurence of one .

    Converting this array to array of a continous 0s and 1s by a conditional check function
    makes our array conditional sorted for for the Binary search template

    ALWAYS MAKE YOUR ARRAY LIKE THIS : [ 0 0 0 0 0 0 0 1 1 1 1 1 ]
    The First occurence of 1 will be the ans .
*/
