Question Link: https://leetcode.com/problems/longest-palindrome/


// Approach :    
class Solution {
public:
    
    int longestPalindrome(string s) {
        int n=s.length();
        
        map<char,int> mp;
        for(char ch:s) mp[ch]++;
        
        map<char,int> :: iterator it;
        int odd=0, ans=0;
        for(it=mp.begin();it!=mp.end();it++){
            int f=it->second;
            if(f%2==0){
                ans += f;
            }else{
                if(f > odd){
                    if(odd != 0) ans--;
                    ans += f;
                    odd=f;
                }else{
                    ans += (f-1);
                }
            }
        }
        return ans;
    }
};
