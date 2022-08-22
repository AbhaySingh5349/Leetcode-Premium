Question Link: https://leetcode.com/problems/missing-element-in-sorted-array/

class Solution {
public:
    int missingElement(vector<int>& a, int k) {
        int n=a.size();
        for(int i=1;i<n;i++){
            int missingCount = a[i]-a[i-1]-1;
            if(missingCount >= k) return a[i-1]+k;
             k -= missingCount;
        }
        return a[n-1]+k;
    }
};
