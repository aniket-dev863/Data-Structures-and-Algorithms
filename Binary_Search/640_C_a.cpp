#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;
typedef long long ll;
int64_t n, k;
ll check(int64_t num)
{
    return (num - (num / n)) >= k;
}
void solve()
{
    cin >> n >> k;
    int64_t l = 1, h = 2 * k;
    int64_t ans = -1;
    while (l <= h)
    {
        int64_t mid = (l + h) / 2;
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
    {
        solve();
    }
}