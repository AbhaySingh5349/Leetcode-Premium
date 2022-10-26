Question Link: https://leetcode.com/problems/shortest-palindrome/


// Approach 1:    
class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.length();
        if(n==0) return "";
        
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        
        for(int len=1;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if(s[i]==s[j]) dp[i][j]=(j-i<2 || dp[i+1][j-1]);
            }
        }
        int maxlen=0;
        for(int j=0;j<n;j++){
            if(dp[0][j]) maxlen=j+1;
        } 
        
        if(maxlen==n) return s;
        
        string suf=s.substr(maxlen);
        reverse(suf.begin(),suf.end());
        suf+=s;
        return suf;
    }
};


// Approach 2:
class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.length();
        if(n==0) return "";
        
        string temp="@#";
        for(int i=0;i<s.length();i++){
            temp+=s[i];
            temp+="#";
        }
        temp+="&";
        n=temp.length();
        vector<int> lps(n,0);
        
        // centre is idx whose lps has been known , right is farthest idx included in its lps
        int centre=0, right=0; 
        for(int i=1;i<n-1;i++){
            int mirror=centre-(i-centre); // mirror Of ith idx element
            if(i<right){
                lps[i]=min(lps[mirror],lps[centre]-(i-centre));
            }
            while(temp[i+lps[i]+1]==temp[i-lps[i]-1]) lps[i]++;
            
            if(i+lps[i]>right){
                centre=i;
                right=i+lps[i];
            }
        }
        int maxlen=0;
        for(int i=1;i<n-1;i++){
            int start=i-lps[i];
            if(start==1 || start==2){
                maxlen=max(maxlen,lps[i]);
            }
        }
        n=s.length();
        
        if(maxlen==n) return s;
        
        string suf=s.substr(maxlen);
        reverse(suf.begin(),suf.end());
        suf+=s;
        return suf; 
    }
};
