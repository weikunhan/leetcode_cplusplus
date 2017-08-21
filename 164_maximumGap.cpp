//==============================================================================
// 164. Maximum Gap
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/maximum-gap/description/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        vector<int> minBucket;
        vector<int> maxBucket;
        int res = 0;
        int minNumber = INT_MAX;  
        int maxNumber = INT_MIN;
    
        if (nums.size() < 2) {
            return res;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            minNumber = min(minNumber, nums[i]);
            maxNumber = max(maxNumber, nums[i]);
        }  
        
        int bucketSize = (maxNumber - minNumber) / (nums.size() - 1);
        
        if (bucketSize == 0) {
            bucketSize = 1;
        }
        
        int totalBucket = (maxNumber - minNumber) / bucketSize + 1;  
        minBucket = vector<int>(totalBucket, INT_MAX);  
        maxBucket = vector<int>(totalBucket, INT_MIN);
        
        for (int i = 0; i < nums.size(); ++i) {
            int index = (nums[i] - minNumber) / bucketSize;  
            minBucket[index] = min(minBucket[index], nums[i]);  
            maxBucket[index] = max(maxBucket[index], nums[i]);  
        }
        
        int preMax = maxBucket[0];
        
        for (int i = 1; i < totalBucket; ++i) {
            if (minBucket[i] != INT_MAX) {
                res = max(res, minBucket[i] - preMax);
                preMax = maxBucket[i];
            }
        }
        
        return res;
    }
};
