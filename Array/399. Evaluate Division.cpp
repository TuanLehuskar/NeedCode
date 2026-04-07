class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> graph;
        for(int i = 0; i < n; ++i) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }
        int m = queries.size();
        vector<double> res(m);
        for (int i = 0; i < m; ++i) {
            res[i] = bfs(queries[i][0], queries[i][1], graph);
        }
        return res;
    }

    double bfs(string start, string end, unordered_map<string, vector<pair<string, double>>>& graph) {
        if (!graph.count(start) || !graph.count(end)) return -1.0;
        queue<pair<string, double>> q;
        unordered_set<string> visited;

        q.push({start, 1.0});
        visited.insert(start);
        
        while(!q.empty()) {
            auto [node, val] = q.front();
            q.pop();
            if (node == end) return val;

            for(auto& [nei, weight] : graph[node]) {
                if (!visited.count(nei)){
                    visited.insert(nei);
                    double temp = weight * val;
                    q.push({nei, temp});
                }
            }
        }
        return -1.0;

    }

};

// Model as a weighted directed graph: edge a→b with weight values[i], edge b→a with weight 1/values[i].
// For each query (src→dst), BFS while multiplying edge weights along the path.
// Return -1 if either node is unknown or no path exists.
// O(E + Q*(V+E)) time where E=equations, Q=queries, V=unique variables.