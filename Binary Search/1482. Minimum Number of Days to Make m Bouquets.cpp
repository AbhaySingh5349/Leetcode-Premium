Question Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/


// Approach :
class Solution {
public:
    
    bool isPossible(vector<int>& bloom, int m, int k, int mid){
        int n=bloom.size();
        
        int b=0, flowers=0;
        for(int i=0;i<n;i++){
            int days=bloom[i];
            if(days<=mid){
                flowers++;
                if(flowers==k){
                    b++;
                    flowers=0;
                }
            }else{
                flowers=0;
            }
        }
        
        return (b>=m);
    }
    
    int minDays(vector<int>& bloom, int m, int k) {
        int left=*min_element(bloom.begin(),bloom.end());
        int right=*max_element(bloom.begin(),bloom.end());
        
        if(m*k > bloom.size()) return -1;
        
        while(left<right){
            int mid=left+(right-left)/2;
            if(isPossible(bloom,m,k,mid)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};
