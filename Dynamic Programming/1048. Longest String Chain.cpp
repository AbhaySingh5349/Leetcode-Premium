Question Link: https://leetcode.com/problems/longest-string-chain/


// Approach 1:
class Solution {
public:
    static bool compare(string s1, string s2){
        return s1.length()<s2.length();
    }
    
    bool isPredecessor(string s1, string s2){
        int n1=s1.length(), n2=s2.length();
        
        if(n1+1!=n2) return false;
        
        bool diff=false;
        int i=0, j=0;
        while(i<n1 && j<n2){
            if(s1[i]!=s2[j]){
                if(diff) return false;
                diff=true;
                j++;
            }else{
                i++, j++;
            }
        }
        return true;
    }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),compare);
        
        int dp[n];
        dp[0]=1;
        int ans=dp[0];
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(isPredecessor(words[j],words[i])){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    static bool compare(string s1, string s2){
        return s1.length()<s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),compare);
        
        map<string,int> m;
        m[words[0]]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            string s=words[i];
            int len=1;
            for(int j=0;j<s.length();j++){
                string pre=s.substr(0,j);
                string suf=s.substr(j+1);
                
                string temp=pre+suf;
                if(m.find(temp)!=m.end()) len = max(len,m[temp]+1);
            }
            m[s]=len;
            ans=max(ans,len);
        }
        
        return ans;
    }
};
