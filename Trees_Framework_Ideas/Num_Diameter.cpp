#include<iostream>
#include<vector>
#include<numeric> // For accumulate

#define int long long
using namespace std;

int n, chD = 0, D = 0;
vector<int> dep, par;
vector<vector<int>> g;

void Init() {
    cin >> n;
    dep.assign(n + 1, 0);
    g.assign(n + 1, vector<int>());
    par.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

// DFS to find depths and parents
void DFS(int node, int parent, int depth, bool countMode = false, int targetDepth = -1) {
    if (!countMode) {
        par[node] = parent;
        dep[node] = depth;
    } else {
        if (depth == targetDepth) {
            chD++;
            // Optimization: No need to go deeper if we hit target depth
            return; 
        }
    }
    for (auto &child : g[node]) {
        if (child != parent)
            DFS(child, node, depth + 1, countMode, targetDepth);
    }
}

vector<int> findCenter() {
    // 1. Find farthest node from root (end of diameter 1)
    int maxChld = 1;
    DFS(1, 0, 0, false, -1);
    for (int j = 1; j <= n; j++) {
        if (dep[j] > dep[maxChld])
            maxChld = j;
    }

    // 2. Find farthest node from that end (end of diameter 2)
    int nodeA = maxChld;
    DFS(nodeA, 0, 0); // Re-run DFS from one endpoint
    maxChld = nodeA; 
    for (int j = 1; j <= n; j++) {
        if (dep[j] > dep[maxChld])
            maxChld = j;
    }

    int nodeB = maxChld;
    D = dep[nodeB]; // This is the diameter length

    // 3. Backtrack to find center(s)
    vector<int> path;
    int curr = nodeB;
    while (curr != 0) {
        path.push_back(curr);
        curr = par[curr];
    }

    if (path.size() % 2 == 1) {
        return vector<int>{path[path.size() / 2]};
    } else {
        return vector<int>{path[path.size() / 2], path[path.size() / 2 - 1]};
    }
}

void Solve() {
    Init();
    if (n == 1) {
        // Diameter 0, usually implies 0 pairs of distinct nodes at distance > 0.
        // Or 1 pair (1,1) if dist 0 counts. Usually output 0 or handled by logic.
        // Based on logic below: D=0, Center=[1], a sums to 0. Output 0.
        cout << (D == 0 ? 1 : 0) << "\n"; // Adjust based on problem statement 
        return;
    }

    vector<int> cnt = findCenter();

    if (cnt.size() == 1) {
        // Case: One Center (Diameter is Even)
        // We need pairs of nodes (u, v) from DIFFERENT branches 
        // such that dist(u, C) = D/2 and dist(v, C) = D/2.
        
        vector<int> branchCounts;
        int target = D / 2;
        
        for (auto &child : g[cnt[0]]) {
            chD = 0;
            DFS(child, cnt[0], 1, true, target);
            if (chD > 0) branchCounts.push_back(chD);
        }

        // TLE Fix: Use algebra instead of nested loops
        // Pairs = [(Sum)^2 - Sum(Squares)] / 2
        int totalSum = 0;
        int sqSum = 0;
        for (int x : branchCounts) {
            totalSum += x;
            sqSum += x * x;
        }
        
        int ans = (totalSum * totalSum - sqSum) / 2;
        cout << ans << "\n";
    } 
    else {
        // Case: Two Centers (Diameter is Odd)
        // We split edge (c1, c2). 
        // We need nodes in Tree(c1) at dist (D-1)/2 from c1
        // AND nodes in Tree(c2) at dist (D-1)/2 from c2.
        
        int target = D / 2; // integer division handles (D-1)/2 automatically
        
        int countA = 0;
        int countB = 0;

        // Count for Center 1
        if (target == 0) {
            // Special case for D=1: The center itself is the endpoint
            countA = 1;
        } else {
            for (auto &child : g[cnt[0]]) {
                if (child != cnt[1]) {
                    chD = 0;
                    DFS(child, cnt[0], 1, true, target);
                    countA += chD;
                }
            }
        }

        // Count for Center 2
        if (target == 0) {
            countB = 1;
        } else {
            for (auto &child : g[cnt[1]]) {
                if (child != cnt[0]) {
                    chD = 0;
                    DFS(child, cnt[1], 1, true, target);
                    countB += chD;
                }
            }
        }

        // TLE Fix: Simply multiply the totals
        cout << countA * countB << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}