// Question link : https://atcoder.jp/contests/dp/tasks/dp_d
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
int n, w;
vector<int> val(1001);
vector<int> wght(1001);
int memo[110][100100];
int rec(int level, int weight)
{
    // prunning
    if (weight > w)
    {
        return 0;
    }
    // base case
    if (level == n)
    {
        return 0;
    }
    // cache check
    if(memo[level][weight]!=-1){
        return memo[level][weight];
    }
    // transition
    int ans ;
    if (weight + wght[level] <= w)
    {
        ans = max(val[level] + rec(level + 1, weight + wght[level]), rec(level + 1, weight));
    }
    else
    {
        ans = rec(level + 1, weight);
    }
    // save and return
    return memo[level][weight]=ans;
}

void solve()
{
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        cin >> wght[i] >> val[i];
    }
    memset(memo,-1,sizeof(memo));
    cout << rec(0, 0) << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

/**
 * VERDICT : AC 
 * Source Link: https://atcoder.jp/contests/dp/tasks
 */