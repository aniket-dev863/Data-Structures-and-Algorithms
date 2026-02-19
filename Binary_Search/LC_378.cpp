#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int check(vector<vector<int>> &matrix, int k, int num)
{
    int cnt = 0;
    int n = matrix.size();
    for (int i = 0; i < matrix.size(); i++)
    {
        auto it = upper_bound(matrix[i].begin(), matrix[i].end(), num);
        cnt += it - matrix[i].begin();
    }
    return cnt >= k;
}
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    int l = matrix[0][0];
    int h = matrix[n - 1][n - 1];
    int ans = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (check(matrix, k, mid))
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
    cin >> n >> k;
    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    int ans = kthSmallest(grid, k);
    cout << ans << "\n";
    return 0;
}
