Question Link: https://leetcode.com/problems/cutting-ribbons/


// Approach :
class Solution {
public:
    
    bool possible(vector<int>& a, int k, int len){
        int n=a.size(), c=0;
        for(int i=0;i<n;i++){
            c += (a[i]/len);
        }
        
        return (c>=k);
    }
    
    int maxLength(vector<int>& a, int k) {
        int l=0, r=*max_element(a.begin(),a.end());
        while(l<r){
            int m = l+(r-l+1)/2;
            
            if(possible(a,k,m)){
                l=m;
            }else{
                r=m-1;
            }
        }
        return l;
    }
};
