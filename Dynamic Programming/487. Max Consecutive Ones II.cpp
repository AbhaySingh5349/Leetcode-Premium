Question Link: https://leetcode.com/problems/max-consecutive-ones-ii/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int n=a.size();
        
        int i=0, j=0;
        int zero=0, maxlen=0;
        while(j<n){
            if(a[j]==0) zero++;
            
            while(i<j && zero>1){
                if(a[i]==0) zero--;
                i++;
            }
            int len=j-i+1;
            maxlen=max(maxlen,len);
            j++;
        }
        return maxlen;
    }
};
