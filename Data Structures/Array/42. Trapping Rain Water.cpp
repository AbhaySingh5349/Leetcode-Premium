Question Link: https://leetcode.com/problems/trapping-rain-water/


// Approach 1: 
class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        
        vector<int> left(n,0), right(n,0);
        
        for(int i=1;i<n;i++) left[i]=max(left[i-1],a[i-1]);
        for(int i=n-2;i>=0;i--) right[i]=max(right[i+1],a[i+1]);
        
        int ans=0;
        for(int i=1;i<n-1;i++){
            ans+=max(0,min(left[i],right[i])-a[i]);
        }
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        
        int i=0, j=n-1;
        int left_max=0, right_max=0;
        int ans=0;
        
        while(i<j){
            if(a[i]<a[j]){
                if(a[i]>=left_max){
                    left_max=a[i];
                }else{
                    ans += (left_max-a[i]);
                }
                i++;
            }else{
                if(a[j]>=right_max){
                    right_max=a[j];
                }else{
                    ans += (right_max-a[j]);
                }
                j--;
            }
        }
        
        return ans;
    }
};
