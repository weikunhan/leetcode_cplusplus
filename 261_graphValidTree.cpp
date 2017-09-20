//==============================================================================
// 261. Graph Valid Tree
// C++
// Tag: Graph(without BFS, DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/graph-valid-tree/description/

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> nodes(n, 0);
        bool res = false;
        
        for (int i = 0; i < n; ++i) {
            nodes[i] = i;
        }
        
        for (int i = 0; i < edges.size(); ++i) {
            int first = edges[i].first;
            int second = edges[i].second;
            while (nodes[first] != first) {
                first = nodes[first];
            }
            while (nodes[second] != second) {
                second = nodes[second];
            }
            if (nodes[first] == nodes[second]) {
                return res;
            }
            nodes[second] = first;
        }
        
        return res = edges.size() == n - 1;
    }
};
