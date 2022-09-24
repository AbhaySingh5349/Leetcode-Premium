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
            if(cur.length() > ans.length()){
                ans = cur;
            }
        }
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    
    string longestPalindrome(string s) {
        int n=s.length();
        
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        int maxlen=0, si, sj;
        for(int len=1;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if(s[i]==s[j]) dp[i][j]=(j-i<2 || dp[i+1][j-1]);
                
                if(dp[i][j]){
                    if(len>maxlen){
                        maxlen=len;
                        si=i, sj=j;
                    }
                }
            }
        }
        
        string ans="";
        for(int i=si;i<=sj;i++) ans+=s[i];
        
        return ans;
    }
};


// Approach 3:
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
        for(int i=2;i<n-2;i++){
            while(temp[i+lps[i]+1]==temp[i-lps[i]-1]) lps[i]++;
            maxlen=max(maxlen,lps[i]);
        }
        int si=-1, ej=-1;
        for(int i=2;i<n-2;i++){
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


// Approach 4:
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
