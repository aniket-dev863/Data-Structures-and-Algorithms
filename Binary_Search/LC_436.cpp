// 436. Find right interval .
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool comp(pair<int, int> &p, int val)
{
    return p.first < val;
}
vector<int> findRightInterval(vector<vector<int>> &intervals)
{
    int sa = intervals.size();
    vector<pair<int, int>> start(intervals.size());
    vector<int> end(sa);
    for (int i = 0; i < sa; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
                start[i] = {intervals[i][j], i};
            else
            {
                end[i] = intervals[i][j];
            }
        }
    }
    sort(start.begin(), start.end());
    vector<int> ans(sa);
    for (int i = 0; i < sa; i++)
    {
        auto it = lower_bound(start.begin(), start.end(), end[i], comp);
        if (it != start.end())
        {
            ans[i] = it->second;
        }
        else
        {
            ans[i] = -1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++)
    {
        int ta, tb;
        cin >> ta >> tb;
        matrix[i].push_back(ta);
        matrix[i].push_back(tb);
    }
    vector<int> Ans = findRightInterval(matrix);
    for (const auto it : Ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}
