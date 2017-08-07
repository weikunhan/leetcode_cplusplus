//==============================================================================
// 210. Course Schedule II
// C++
// Tag: Graph(BFS, without DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/course-schedule-ii/description/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        vector<int> degree(numCourses);
        queue<int> zeros;
        vector<int> res;

        for (int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i].second].insert(prerequisites[i].first);
        }

        for (int i = 0; i < graph.size(); ++i) {
            for (auto n:graph[i]) {
                ++degree[n];
            }
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (!degree[i]) {
                zeros.push(i);
            }
        }   

        for (int i = 0; i < numCourses; ++i) {
            if (zeros.empty()) {
                return res = {};
            }
            int index = zeros.front();
            zeros.pop();
            res.push_back(index);
            for (auto n:graph[index]) {
                if (!--degree[n]) {
                    zeros.push(n);
                }
            }
        }
        
        return res;
    }
};
