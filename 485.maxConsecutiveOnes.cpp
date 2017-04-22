// 485. Max Consecutive Ones
// C++
// Tag: Array

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
		int count = 0;
        int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i]& 1) 
                res = res > ++count ? res : count;
			else 
                count = 0;
		}
		return res;
	}   
};
