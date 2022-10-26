Question Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/


// Approach :    
class Solution {
public:
    int minSwaps(vector<int>& a) {
        int n=a.size();
        
        int k=0, zero=0;
        for(int i=0;i<n;i++) k += (a[i]==1);
        
        int ans=n;
        
        int i=0, j=0, one=0;
        while(j<n){
            one += (a[j]==1);
            
            if(j-i+1 == k){
                ans = min(ans,k-one);
                one -= (a[i]==1);
                
                i++;
            }
            j++;
        } 
        return (ans==n ? 0:ans);
    }
};
