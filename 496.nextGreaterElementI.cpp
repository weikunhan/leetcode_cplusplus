// 496. Next Greater Element I
// C++
// Tag: Stack, Hash Table

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