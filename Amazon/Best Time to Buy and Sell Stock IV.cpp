// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/


class Solution {
    int solve(int index,int buy,int cnt,int n,vector<int> &prices){
        if(index==n){
            return 0;
        }
        if(cnt==0){
            return 0;
        }
        int profit=0;
        if(buy){
            int pick=-prices[index]+solve(index+1,false,cnt,n,prices);
            int notPick=0+solve(index+1,true,cnt,n,prices);
            profit=max(pick,notPick);
        }
        else{
            int pick=prices[index]+solve(index+1,true,cnt-1,n,prices);
            int notPick=0+solve(index+1,false,cnt,n,prices);
            profit=max(pick,notPick);
        }
        return profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        return solve(0,true,k,n,prices);
    }
};