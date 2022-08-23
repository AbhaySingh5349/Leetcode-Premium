Question Link: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& v) {
       int n=v.size(); 
        
       for(int i=0;i<n;i++){
            int idx = abs(v[i])-1;
            if(v[idx]<0) return idx+1; 
            v[idx] *= -1;
        }
        return -1;
    }
};
