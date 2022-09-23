Question Link: https://leetcode.com/problems/max-consecutive-ones/

// Approach 1:
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int n=a.size();
        
        int i=-1, j=0;
        int maxlen=0;
        while(j<n){
            if(a[j]==0){
                i=j;
            }else{
                int len=j-i;
                maxlen=max(maxlen,len);
            }
            j++;
        }
        return maxlen;
    }
};

// Approach 2:
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int n=a.size();
        
        int len=0;
        int maxlen=len;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                len=0;
            }else{
                len++;
            }
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};
