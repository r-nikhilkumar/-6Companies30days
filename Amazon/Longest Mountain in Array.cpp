// https://leetcode.com/problems/longest-mountain-in-array/


class Solution {
public:
    Solution() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
    int longestMountain(vector<int>& arr) {
        bool inc = true;
        int m=0;
        int t=0;
        for(int i=0;i<arr.size()-1;i++){
            if(inc){
                if(arr[i]<arr[i+1]) t++;
                else if(arr[i]>arr[i+1] && t>0){
                    inc = !inc;
                    t++;
                }else t = 0;
            }else if(!inc){
                if(arr[i]>arr[i+1]) t++;
                else{
                    inc = !inc;
                    m = max(m, ++t);
                    t = arr[i]<arr[i+1];
                }
            }
        }
        if(!inc) m = max(m, ++t);
        return m;
    }
};