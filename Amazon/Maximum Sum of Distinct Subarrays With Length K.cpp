// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        long long sum=0, mSum=0;
        int i=0, j=0;
        for(;j<k;j++){
            map[nums[j]]++;
            sum+=nums[j];
        }
        if(map.size()==k) mSum = sum;
        while(j<nums.size()){
            sum-=nums[i];
            map[nums[i]]--;
            if(map[nums[i]]==0) map.erase(nums[i]);
            i++;
            sum+=nums[j];
            map[nums[j]]++;
            j++;
            if(map.size()==k) mSum = max(mSum, sum);
        }
        return mSum;
    }
};