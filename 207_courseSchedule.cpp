//==============================================================================
// 207. Course Schedule
// C++
// Tag: Graph(BFS, without DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/course-schedule/description/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        vector<int> degree(numCourses);
        bool res = false;

        for (int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i].second].insert(prerequisites[i].first);
        }

        for (int i = 0; i < graph.size(); ++i) {
            for (auto n:graph[i]) {
                ++degree[n];
            }
        }
        
        for (int i = 0; i < numCourses; ++i) {
            int index = 0;
            while (index < numCourses) {
                if (!degree[index]) {
                    break;
                }
                ++index;
            }
            if (index == numCourses) {
                return res;
            } else {
                degree[index] = -1;
            }
            for (auto n:graph[index]) {
                --degree[n];
            }
        }
        
        return res = true;
    }
};
