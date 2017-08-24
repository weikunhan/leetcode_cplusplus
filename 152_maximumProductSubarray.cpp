//==============================================================================
// 152. Maximum Product Subarray
// C++
// Tag: Array(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int maxProduct = 0;
        int minProdect = 0;
        
        if (n = 0) {
            return res;
        } else {
            res = nums[0];
            maxProduct = nums[0];
            minProdect = nums[0];
        }
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                maxProduct = max(maxProduct * nums[i], nums[i]);
		minProdect = min(minProdect * nums[i], nums[i]);
            } else {
                int lastMax = maxProduct;
                maxProduct = max(minProdect * nums[i], nums[i]);
                minProdect = min(lastMax * nums[i], nums[i]);			   		
	    }
            res = max(res, maxProduct);
        }
        
        return res;
    }
};
