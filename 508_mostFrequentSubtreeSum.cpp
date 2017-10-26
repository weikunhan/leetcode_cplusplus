//==============================================================================
// 508. Most Frequent Subtree Sum
// C++
// Tag: Tree(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/most-frequent-subtree-sum/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> tables; //用散列表实现散列函数
        vector<int> res; //保存输出结果
        int sameTime = 0; //记录有多少个相同最高频率和
        int max = INT_MIN; //记录当前的最高频率
        
        if (!root) {
            return res;
        }
        
        helper(root, tables);
        
        for (auto n:tables) {
            if (n.second > max) {
                max = n.second;
                sameTime = 1;
            } else if (n.second == max) {
                ++sameTime;
            }
        }
        
        res.resize(sameTime, 0);
        sameTime = 0;
        
        for (auto n:tables) {
            if (n.second == max) {
                res[sameTime++] = n.first;
            }
        }
        
        return res;
    }

private:
    int helper(TreeNode *rootIn, unordered_map<int, int> &tables) {
        if (!rootIn) {
            return 0;
        }
        
        int tmp = rootIn->val + helper(rootIn->left, tables) + helper(rootIn->right, tables);
        
        if (tables.find(tmp) != tables.end()) {
            ++tables[tmp];
        } else {
            tables[tmp] = 1;
        }
        
        return tmp;
    }
};
