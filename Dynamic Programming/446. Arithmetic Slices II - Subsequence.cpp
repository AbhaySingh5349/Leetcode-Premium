Question Link: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/


// Approach :                                            
class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size();
        if(n<3) return 0;
        
        unordered_map<int,unordered_map<int,int>> mp;
        for(int i=0;i<n;i++){
            unordered_map<int,int> temp;
            mp[i]=temp;
        }
        
        int c=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long long int cd=(long)a[i]-a[j];
                
                if (cd < INT_MIN || cd > INT_MAX) continue;
                
                unordered_map<int,int> prev=mp[j];
                if(prev.find(cd)!=prev.end()){
                    c+=prev[cd];
                    mp[i][cd]+=prev[cd]+1;
                }else{
                    mp[i][cd]=1;
                }
            }
        } 
        return c; 
    }
};
