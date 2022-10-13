Question Link: https://leetcode.com/problems/shortest-way-to-form-string/


// Approach :                                            
class Solution {
public:
    
    int search(vector<int> v, int prev){
        int l=0, r=v.size()-1;
        
        while(l<r){
            int m=l+(r-l)/2;
            if(v[m]>prev){
                r=m;
            }else{
                l=m+1;
            }
        }
        return (v[l]>prev ? v[l]:-1);
    }
    
    int shortestWay(string s, string p) {
        int c=0;
        
        map<char,vector<int>> mp;
        for(int i=0;i<s.length();i++) mp[s[i]].push_back(i);
        
        while(p.length()>0){
            int i=0, j=0, prev=-1;
            while(i<s.length() && j<p.length()){
                if(mp.find(p[j]) == mp.end()) break;
                
                i = search(mp[p[j]],prev);
                if(i==-1) break;
                
                prev=i;
                j++;
            }
            
            if(j==0) return -1;
            
            c++;
            p=p.substr(j);
        }
        return c;
    }
};
