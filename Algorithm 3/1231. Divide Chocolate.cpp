Question Link: https://leetcode.com/problems/divide-chocolate/

class Solution {
public:
    
    bool isPossible(vector<int>& a, int maxSweetness, int k){
        int n=a.size();
        int c=0;
        int sweetness=0;
        for(int i=0;i<n;i++){
            sweetness += a[i];
            if(sweetness >= maxSweetness){
                sweetness = 0;
                c++;
            }
        }
        return (c>=k+1);
    }
    
    int maximizeSweetness(vector<int>& a, int k) {
        int r=accumulate(a.begin(),a.end(),0);
        r /= (k+1);
        
        int l=*min_element(a.begin(),a.end());
        
        while(l<r){
            int m = (r+l+1)/2;
            
            if(isPossible(a,m,k)){
                l=m;
            }else{
                r=m-1;
            }
        }
        return r;
    }
};
