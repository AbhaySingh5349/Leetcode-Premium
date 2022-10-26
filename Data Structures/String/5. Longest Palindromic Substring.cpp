Question Link: https://leetcode.com/problems/longest-palindromic-substring/


// Approach 1:    
class Solution {
public:
    
    string getSub(string s, int left, int right){
        int n = s.length();
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
    
    string longestPalindrome(string s) {
        int start=0, end=0;
        string ans="";
        
        for(int i=0;i<s.length();i++){
            string odd = getSub(s,i-1,i+1); // considering sub-string of odd length
            string even = getSub(s,i-1,i); // considering sub-string of even length
        
            string cur = (odd.length() > even.length()) ? odd : even;
            if(cur.length() > ans.length()) ans = cur;
        }
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    string longestPalindrome(string s) {
        string temp="@#";
        for(int i=0;i<s.length();i++){
            temp+=s[i];
            temp+="#";
        }
        temp+="&";
        int n=temp.length();
        vector<int> lps(n,0);
        int maxlen=0;
        
        int centre=0, right=0;
        for(int i=1;i<n-1;i++){
            int mirror=centre-(i-centre); // mirror Of ith idx element
            if(i<right){
                lps[i]=min(lps[mirror],lps[centre]-(i-centre));
            }
            while(temp[i+lps[i]+1]==temp[i-lps[i]-1]) lps[i]++;
            maxlen=max(maxlen,lps[i]);
            if(i+lps[i]>right){
                centre=i;
                right=i+lps[i];
            }
        }
        int si=-1, ej=-1;
        for(int i=1;i<n-1;i++){
            if(maxlen==lps[i]){
                si=i-lps[i], ej=i+lps[i];
                break;
            }
        }
        string ans="";
        for(int i=si;i<=ej;i++){
            if((isalpha(temp[i]) || isdigit(temp[i]))) ans+=temp[i];
        }
        return ans;
    }
};
