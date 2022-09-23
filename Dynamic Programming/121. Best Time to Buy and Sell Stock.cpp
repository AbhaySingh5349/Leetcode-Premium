Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int> &a) {
        int n=a.size();
        
        int left=a[0];
        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,a[i]-left);
            left=min(left,a[i]);
        }
        
        return ans;
    }
};
