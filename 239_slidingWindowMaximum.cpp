//==============================================================================
// 239. Sliding Window Maximum
// C++
// Tag: Array(without Heap)
//==============================================================================
// Summary:
// https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> window;
        
        for (int i = 0; i < nums.size(); ++i) {
            while (!window.empty() && window.back() < nums[i]) {
                window.pop_back();
            }
            window.push_back(nums[i]);
            if (i >= k - 1) {
                res.push_back(window.front());
                if (nums[i - k + 1] == window.front()) {
                    window.pop_front();
                }
            }
        }
        
        return res;
    }
};
