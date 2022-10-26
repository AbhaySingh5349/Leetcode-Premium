Question Link: https://leetcode.com/problems/perform-string-shifts/


// Approach :    
class Solution {
public:
    
    void reverse(string &s, int i, int j){
        while(i<j){
            swap(s[i],s[j]);
            i++, j--;
        }
    }
    
    string stringShift(string s, vector<vector<int>>& shift) {
        int k=0;
        for(vector<int> sft:shift){
            int d=sft[0], val=sft[1];
            
            k += (d==0 ? -val:val);
        }
        
        int n=s.length();
        k %= n;
        if(k<0 )k += n;
        
        reverse(s,0,n-1);
        reverse(s,0,k-1);
        reverse(s,k,n-1);
        
        return s;
    }
};
