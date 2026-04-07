class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& pair : connections) {
            int u = pair[0];
            int v = pair[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        queue<int> q;
        vector<bool> visited(n, false);
        int res = 0;
        q.push(0);
        visited[0] = true;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(auto& [v, cost] : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    res += cost;
                    q.push(v);
                }
            }
        }
        return res;
    }
};

// Build undirected graph: original edges get cost=1 (need reversal), reverse edges get cost=0.
// BFS from node 0: for each unvisited neighbor, add cost to result.
// Any edge pointing away from 0 (cost=1) must be flipped → count it.
// O(n) time, O(n) space.

