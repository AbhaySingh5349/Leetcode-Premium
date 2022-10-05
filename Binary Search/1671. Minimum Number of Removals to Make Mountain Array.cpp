Question Link: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/


// Approach 1:
class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n=a.size();
        
        vector<int> left(n,1);
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--) if(a[i]>a[j]) left[i]=max(left[i],1+left[j]);
        }
        
        vector<int> right(n,1);
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++) if(a[i]>a[j]) right[i]=max(right[i],1+right[j]);
        }
        
        int len=0;
        for(int i=1;i<n-1;i++){
            if(left[i]>1 && right[i]>1) len=max(len,left[i]+right[i]-1);
        }
        return (n-len);
    }
};


// Approach 2:
class Solution {
public:
    int searchCeilIndex(vector<int> &v, int val){
        int l=0, r=v.size()-1;
        while(l<r){
            int m=l+(r-l)/2;
            
            if(v[m]>=val){
                r=m;
            }else{
                l=m+1;
            }
        }
        return (v[l]>=val ? l:-1);
    }
    
    int minimumMountainRemovals(vector<int>& a) {
        int n=a.size();
        
        vector<int> v;
        int left[n], right[n];
        
        v.push_back(a[0]);
        left[0]=1;
        for(int i=1;i<n;i++){
            int x=a[i], t=v.back();
            
            if(x>t){
                v.push_back(x);
            }else{
                int idx=searchCeilIndex(v,x);
                if(idx!=-1) v[idx]=x;
            }
            left[i]=v.size();
        }
        
        v.clear();
        v.push_back(a[n-1]);
        right[n-1]=1;
        for(int i=n-2;i>=0;i--){
            int x=a[i], t=v.back();
            
            if(x>t){
                v.push_back(x);
            }else{
                int idx=searchCeilIndex(v,x);
                if(idx!=-1) v[idx]=x;
            }
            right[i]=v.size();
        }
        
        int len=0;
        for(int i=0;i<n;i++){
            if(left[i]>1 && right[i]>1) len=max(len,left[i]+right[i]-1);
        }
        return (n-len);
    }
};
