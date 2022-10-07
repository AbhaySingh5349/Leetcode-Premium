Question Link: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/


// Approach :
class Solution {
public:
    
    int getSum(vector<int> v, int k){
        int n=v.size();
        
        int maxsum=INT_MIN;
        
        set<int> st;
        st.insert(0);
        int pre=0;
        
        for(int i=0;i<n;i++){
            pre+=v[i];
            auto itr = st.lower_bound(pre-k); 
            if(itr!=st.end()){
                maxsum=max(maxsum,pre - *itr);
            } 
            st.insert(pre); 
        } 
        
        return maxsum;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            vector<int> sub(m,0);
            for(int row=i;row<n;row++){
                for(int col=0;col<m;col++){
                    sub[col] += grid[row][col];
                }
                int sum = getSum(sub,k);
                if(sum>ans) ans=sum;
            }
        }
        return (ans == INT_MIN ? -1:ans);
    }
};
