//==============================================================================
// 496. Next Greater Element I
// C++
// Tag: Stack, Hash Table
//==============================================================================
// Summary:
// Suppose we have a decreasing sequence followed by a greater number.
// For example [5, 4, 3, 2, 1, 6]. The greater number 6 is the next greater 
// element for all previous numbers in the sequence. We use a stack to keep a 
// decreasing sub-sequence. Whenever we see a number x greater than stack.top(),
// we pop all elements less than x and for all the popped ones. 
// For example [9, 8, 7, 3, 2, 1, 6]. The stack will first contain 
// [9, 8, 7, 3, 2, 1]. Then we see 6 which is greater than 1 so we pop 1 2 3 
// whose next greater element should be 6.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> stack;
        unordered_map<int, int> hash;
        vector<int> res;
        for (int n : nums) {
            while (stack.size() && (stack.top() < n)) {
                hash[stack.top()] = n;
                stack.pop();
            }
            stack.push(n);
        }
        for (int n : findNums) 
            res.push_back(hash.count(n) ? hash[n] : -1);
        return res;
    }
};
