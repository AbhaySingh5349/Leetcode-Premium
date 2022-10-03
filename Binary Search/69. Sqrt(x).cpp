Question Link: https://leetcode.com/problems/sqrtx/


// Approach 1:
class Solution {
public:
    
    #define ll long long
    int mySqrt(int x) {
        
        if(x<2) return x;
        
        int l=0, r=x/2;
        while(l<r){
            ll int m=l+(r-l+1)/2;
            
            if(m*m <= x){
                l=m;
            }else{
                r=m-1;
            }
        }
        return l; // since 'l' is maximum val <= sqrt(x) 
    }
};


// Approach 2:
class Solution {
public:
    
    #define ll long long
    int mySqrt(int x) {
        
        if(x<2) return x;
        
        int l=0, r=x;
        while(l<r){
            ll int m=l+(r-l)/2;
            
            if(m*m > x){
                r=m;
            }else{
                l=m+1;
            }
        }
        return l-1; // since 'l' is min. value > sqrt(x)
    }
};
