# Path Sums in Trees (Binary Lifting & LCA)

This repository contains an optimized C++ implementation for calculating the **Weighted Path Sum** (distance) between any two nodes in a tree using **Binary Lifting** and **Lowest Common Ancestor (LCA)**.

## 🚀 Overview

In many tree-based algorithmic problems, we need to answer multiple queries regarding the distance between nodes efficiently. A naive BFS/DFS for every query would take $O(N)$ per query, leading to $O(N \cdot Q)$ total time, which is too slow for large constraints.

This solution uses **Binary Lifting** to answer queries in **$O(\log N)$** time after an **$O(N \log N)$** pre-computation phase.

## 🧠 Key Concepts

1.  **Binary Lifting:** A dynamic programming approach to store the $2^i$-th ancestor of every node. This allows us to jump up the tree in powers of 2.
2.  **Lowest Common Ancestor (LCA):** The deepest node that is an ancestor of both target nodes.
3.  **Prefix Sums on Trees:** We store `pref[u]`, which is the total distance from the **Root** to node **u**.

## 🔢 The Formula

To find the distance between node `u` and node `v`, we use the following derivation:

$$\text{Dist}(u, v) = \text{pref}[u] + \text{pref}[v] - 2 \times \text{pref}[\text{LCA}(u, v)]$$

**Why?**

- `pref[u]` is the path: Root $\to \dots \to$ LCA $\to \dots \to$ u
- `pref[v]` is the path: Root $\to \dots \to$ LCA $\to \dots \to$ v
- Adding them sums the path from Root $\to$ LCA **twice**.
- Subtracting `2 * pref[LCA]` removes the redundant path segments from the root to the LCA, leaving only the path between `u` and `v`.

## ⏱ Complexity Analysis

| Operation           | Time Complexity | Space Complexity |
| :------------------ | :-------------- | :--------------- |
| **Pre-computation** | $O(N \log N)$   | $O(N \log N)$    |
| **Query**           | $O(\log N)$     | $O(1)$ auxiliary |
| **Total Space**     | -               | $O(N \log N)$    |

- **N**: Number of nodes ($1 \le N \le 10^5$)
- **LOG**: $\approx 20$ (since $2^{20} > 10^5$)

## 🛠️ Input Format

The code expects standard input in the following format:

1.  **N** (Number of nodes).
2.  **N-1** lines containing `u v w` (Edge between $u$ and $v$ with weight $w$).
3.  **Q** (Number of queries).
4.  **Q** lines containing `x y` (Calculate distance between node $x$ and $y$).

### Example Input

```text
5
1 2 1
1 3 2
2 4 5
2 5 3
3
4 5
4 3
2 3
```
