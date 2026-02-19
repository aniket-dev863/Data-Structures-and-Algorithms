#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int check(vector<int> &houses, vector<int> &heaters, int num)
{
    int s = heaters.size();
    int cnt = 0;
    for (int i = 0; i < s; i++)
    {
        auto it1 = lower_bound(houses.begin(), houses.end(), heaters[i] - num) - houses.begin();
        auto it2 = upper_bound(houses.begin(), houses.end(), heaters[i] + num) - houses.begin();
        cnt += it2 - it1;

        if (cnt >= houses.size())
            return 1;
    }
    return cnt >= houses.size();
}
int findRadius(vector<int> &houses, vector<int> &heaters)
{
    int n = houses.size();
    sort(houses.begin(), houses.end());
    int h = houses[n - 1];
    int l = 1;
    int ans = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (check(houses, heaters, mid))
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k; //
    vector<int> houses(n);
    for (int i = 0; i < n; i++)
        cin >> houses[i];

    vector<int> heaters(k);
    for (int i = 0; i < k; i++)
        cin >> heaters[i];

    int ans = findRadius(houses, heaters);
    cout << ans << "\n";
}