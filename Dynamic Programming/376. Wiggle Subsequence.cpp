Question Link: https://leetcode.com/problems/wiggle-subsequence/

class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int n=a.size();
        
        if(n==1) return 1;
        
        // maxlen if previous sequence ended with +ve or -ve difference
        vector<int> posLen(n) , negLen(n);
        
        posLen[0]=1, negLen[0]=1;
        
        for(int i=1;i<n;i++){
            int diff=a[i]-a[i-1];
            
            posLen[i]=posLen[i-1], negLen[i]=negLen[i-1];
            if(diff>0) posLen[i]=max(posLen[i],1+negLen[i-1]);
            if(diff<0) negLen[i]=max(negLen[i],1+posLen[i-1]);
        }
        return max(posLen[n-1],negLen[n-1]);
    }
};
