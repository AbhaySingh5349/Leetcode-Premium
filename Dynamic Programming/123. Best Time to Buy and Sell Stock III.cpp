Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        if(n<2) return 0;
        
        int left[n]; // max possible profit if perform 1 transaction from [0,i]
        left[0]=0;
        int minl=a[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],a[i]-minl);
            minl=min(minl,a[i]);
        }
        
        int right[n]; // max possible profit if perform 1 transaction from [i,n-1]
        right[n-1]=0;
        int maxr=a[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],maxr-a[i]);
            maxr=max(maxr,a[i]);
        }
        
        int ans=0;
        for(int i=0;i<n-1;i++){
            // considering 1 transaction
            ans=max(ans,max(left[i],right[i]));
            
            // considering 2 transactiona
            ans=max(ans,left[i]+right[i+1]);
        }
        ans=max(ans,left[n-1]);
        
        return ans;
    }
};
