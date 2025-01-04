// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
    int func(vector<int>& nums, int k_odds)
    {
        // Sum can't be -ve
        if(k_odds < 0) return 0;
        int i = 0 , j = 0 , s = 0 , ans = 0;
        while(j < nums.size())
        {
            s += nums[j] % 2;
            // Shrink the Window
            while(s > k_odds)
            {
                s -= nums[i] % 2;
                i++;
            }
            // Each valid window contributes (j - i + 1) subarrays 
            // i.e - all subarrays ending at j starting from i
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums , k) - func(nums , k -1);        
    }
};