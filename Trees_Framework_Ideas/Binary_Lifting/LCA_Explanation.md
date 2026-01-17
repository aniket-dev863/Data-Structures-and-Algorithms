Lowest Common Ancestor (LCA) via Binary Lifting
This guide explains how to find the Lowest Common Ancestor of two nodes in a tree efficiently using Binary Lifting. This technique reduces the query time from O(N) to O(logN).

1. The Core Concept
   What is LCA?

In a rooted tree, the LCA of two nodes u and v is the deepest node that is an ancestor of both u and v.

What is Binary Lifting?

Instead of moving up one step at a time (parent by parent), we pre-calculate "jumps" of size 1,2,4,8,16,… (powers of 2).

Any integer distance can be represented as a sum of powers of 2 (binary representation).

Therefore, we can reach any ancestor by combining these pre-calculated jumps.

2. The Data Structure: up[][]
   We use a 2D array (often called up, dp, or parent) to store ancestor information.

up[u][i]=The 2
i
-th ancestor of node u
up[u][0]: 2
0
=1st ancestor (immediate parent).

up[u][1]: 2
1
=2nd ancestor (grandparent).

up[u][2]: 2
2
=4th ancestor.

up[u][3]: 2
3
=8th ancestor.

The Recurrence Relation (Dynamic Programming)

How do we find the 8th ancestor? It is the 4th ancestor of the 4th ancestor.

up[u][i]=up[up[u][i−1]][i−1]
Logic: To jump 2
i
steps, we first jump 2
i−1
steps to reach an intermediate node, and from there, we jump another 2
i−1
steps. (2
i−1
+2
i−1
=2
i
)

3. The Algorithm Steps
   Phase 1: Pre-computation (DFS + DP)

Time Complexity: O(NlogN)

DFS: Traverse the tree to calculate the depth of every node and store the immediate parent (up[u][0]).

DP Table Building: Iterate through i from 1 to LOG (max power of 2 needed, usually ≈20 for N=2⋅10
5
). Apply the recurrence relation.

Phase 2: Answering Queries

Time Complexity: O(logN)

To find LCA(u, v):

Level Equalization:

Check depths. If depth[u] < depth[v], swap them so u is always deeper.

Lift u upwards until depth[u] == depth[v]. We do this by iterating through powers of 2 (from largest to smallest). If a jump keeps u below or at v's level, take it.

Check Equality:

If u == v after equalization, then v was the ancestor of u. Return u.

Lift Both Together:

We want to jump as high as possible without reaching a common ancestor.

Iterate i from LOG down to 0.

If up[u][i] != up[v][i]:

This means the 2
i
-th ancestors are different. We haven't overshot the LCA.

Move both u and v up: u = up[u][i], v = up[v][i].

If up[u][i] == up[v][i]:

This means we hit a common ancestor (maybe the LCA, maybe one higher). Do not move. Wait for a smaller jump.

Final Result:

After the loop, u and v are exactly one step below the LCA.

Return up[u][0] (the parent).

4. Implementation (C++)
   C++
   #include <vector>
   #include <iostream>
   #include <algorithm>

using namespace std;

const int MAXN = 200005;
const int LOG = 20; // 2^20 > 200,000

vector<int> adj[MAXN];
int up[MAXN][LOG]; // up[u][i] stores 2^i ancestor
int depth[MAXN];
int n;

// 1. DFS to compute depths and direct parents (2^0)
void dfs(int u, int p, int d) {
depth[u] = d;
up[u][0] = p; // Initialize 2^0 ancestor
for (int v : adj[u]) {
if (v != p) {
dfs(v, u, d + 1);
}
}
}

// 2. Precompute the table
void precompute_lca() {
for (int i = 1; i < LOG; i++) {
for (int u = 1; u <= n; u++) {
if (up[u][i-1] != -1) {
// The 2^i ancestor is the 2^(i-1) ancestor of the 2^(i-1) ancestor
up[u][i] = up[up[u][i-1]][i-1];
} else {
up[u][i] = -1;
}
}
}
}

// 3. Query Function
int get_lca(int u, int v) {
// Step A: Ensure u is deeper
if (depth[u] < depth[v]) swap(u, v);

    // Step B: Lift u to the same depth as v
    int k = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++) {
        if ((k >> i) & 1) { // If i-th bit is set
            u = up[u][i];
        }
    }

    // Check if they met
    if (u == v) return u;

    // Step C: Lift both until they are just below LCA
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != -1 && up[v][i] != -1 && up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    // Step D: Return the immediate parent
    return up[u][0];

} 5. Why Iterate Backwards? (The "Greedy" Strategy)
In Step C (lifting both nodes), we iterate from LOG-1 down to 0.

Imagine the distance to the node just below the LCA is 13.

Binary: 1101 (8+4+1).

We try jump size 16: Too far (ancestors are same), skip.

We try jump size 8: Ancestors different (safe). Jump. (Remaining dist: 5).

We try jump size 4: Ancestors different (safe). Jump. (Remaining dist: 1).

We try jump size 2: Ancestors same (unsafe). Skip.

We try jump size 1: Ancestors different (safe). Jump. (Remaining dist: 0).

Loop ends. We are just below the LCA. Parent is LCA.

6. Edge Cases & Initialization
   Root Node: usually up[root][0] is set to root or -1. If -1, add checks.

Unreachable: If the graph is a forest (disconnected), ensure you run DFS on every component or handle queries carefully.

MAXN: Ensure LOG is sufficient. 2
17
≈1.3×10
5
, so LOG=20 is safe for almost all competitive programming problems.
