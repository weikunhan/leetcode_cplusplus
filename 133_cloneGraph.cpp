//==============================================================================
// 133. Clone Graph
// C++
// Tag: Graph(DFS, without BFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/clone-graph/description/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> tables;
        UndirectedGraphNode *res = NULL;
        
        return res = helper(node, tables);
    }

private:
    UndirectedGraphNode *helper(UndirectedGraphNode *nodeIn, 
                                unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &tables) {
        if (!nodeIn) {
            return nodeIn;
        }
        
        if (tables.find(nodeIn) == tables.end()) {
            tables[nodeIn] = new UndirectedGraphNode(nodeIn->label);
            for (int i = 0; i < nodeIn->neighbors.size(); ++i) {
                tables[nodeIn]->neighbors.push_back(helper(nodeIn->neighbors[i], tables));
            }
        }
        
        return tables[nodeIn];
    }
};
