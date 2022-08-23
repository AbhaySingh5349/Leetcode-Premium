Question Link: https://leetcode.com/problems/product-of-two-run-length-encoded-arrays/

class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>>ans;
        int prevMultiple=0;
        int i=0, j=0;
        
        while(i<encoded1.size() && j<encoded2.size()){
            int f1=encoded1[i][1], f2=encoded2[j][1];
            
            int minf=min(f1, f2), product=encoded1[i][0]*encoded2[j][0];
            
            if(prevMultiple==product && ans.size()>0){
                ans[ans.size()-1][1]+=minf;
            }else{
                ans.push_back({product, minf});
            }
            prevMultiple = product;
            encoded1[i][1]-=minf, encoded2[j][1]-=minf;
            
            if(!encoded1[i][1]) i++;
            if(!encoded2[j][1]) j++;
        }
        return ans;
    }
};
