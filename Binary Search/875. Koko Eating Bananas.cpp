Question Link: https://leetcode.com/problems/koko-eating-bananas/


// Approach :
class Solution {
public:
    
    bool possible(vector<int> &a, int h, int k){
        int n=a.size();
        int t=0;
        for(int i=0;i<n;i++) t += a[i]/k + (a[i]%k!=0);
        return (t<=h);
    }
    
    int minEatingSpeed(vector<int> &a, int h) {
        int l=1, r=*max_element(a.begin(),a.end());
        
        while(l<r){
            int m=l+(r-l)/2;
            if(possible(a,h,m)){
                r=m;
            }else{
                l=m+1;
            }
        }
        return l;
    }
};
