Question Link: https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/


// Approach :
class Solution {
public:
    
    #define ll long long 
    
    bool possible(ll int num, int k){
        int c=0; // count of trailing zeros in factorial of num
        while(num>0){
            c += num/5;
            num/=5;
        }
        return (c>=k);
    }
    
    // minimum number with 'k' trailing zeroes in its factorial
    int findNum(ll int k){ 
        ll int l=0; 
        ll int r=5*k; 

        while (l<r){ 
            ll int m=l+(r-l)/2;
            
            if(possible(m,k)){
                r=m;
            }else{
                l=m+1;
            }
        } 
        return l; 
    }
    
    int preimageSizeFZF(int k) {
        if(k==1) return 1;
        
        return findNum(k+1)-findNum(k);
    }
};
