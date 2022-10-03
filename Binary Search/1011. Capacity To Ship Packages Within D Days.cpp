Question Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/


// Approach 1:
class Solution {
public:
    
    bool possible(vector<int>& a, int days, int maxWeight){
        int n=a.size();
        
        int c=1, s=a[0];
        for(int i=1;i<n;i++){
            s+=a[i];
            if(s>maxWeight){ // too heavy, wait for the next day
                s=a[i];
                c++;
            }
        }
        return (c<=days);
    }
    
    int shipWithinDays(vector<int>& a, int days) {
        int left = *max_element(a.begin(),a.end());
        int right = accumulate(a.begin(),a.end(),0);
        
        while(left<right){
            int mid=left+(right-left)/2;
            if(possible(a,days,mid)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};



// Approach 2:
class Solution {
public:
    
    bool possible(vector<int>& a, int days, int maxWeight){
        int n=a.size();
        
        int c=1, s=0;
        for(int i=0;i<n;i++){ 
            s+=a[i];
            if(s>maxWeight){ // too heavy, wait for the next day
                s=a[i];
                c++;
            }
        }
        return (c<=days);
    }
    
    int shipWithinDays(vector<int>& a, int days) {
        int left = *max_element(a.begin(),a.end());
        int right = accumulate(a.begin(),a.end(),0);
        
        while(left<right){
            int mid=left+(right-left)/2;
            if(possible(a,days,mid)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};
