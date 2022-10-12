Question Link: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/


// Approach :
class Solution {
public:
    
    struct info{
        int maxLeaf;
        int nonLeafSum;
        info(int leaf, int sum){
            maxLeaf = leaf;
            nonLeafSum = sum;
        }
    };
    
    struct info solve(vector<int>& a, int l, int r, vector<vector<pair<int,int>>> &memo){
        struct info p = info(INT_MIN/2, INT_MAX/2);
        if(l>r) return p;
        
        if(l==r) return {a[l],0};
        
        if(memo[l][r].first!=-1 && memo[l][r].second!=-1) return {memo[l][r].first , memo[l][r].second};
        
        for(int i=l;i<r;i++){
            struct info pLeft = solve(a,l,i,memo);
            struct info pRight = solve(a,i+1,r,memo);
            
            int leaf = max(pLeft.maxLeaf, pRight.maxLeaf);
            int sum = pLeft.nonLeafSum + pRight.nonLeafSum + pLeft.maxLeaf*pRight.maxLeaf;
            
            if(sum < p.nonLeafSum){
                p.nonLeafSum = sum;
                p.maxLeaf = max(leaf,p.maxLeaf);
            }
        }
        memo[l][r] = {p.maxLeaf,p.nonLeafSum};
        return p;
    }
    
    int mctFromLeafValues(vector<int>& a) {
        int n=a.size();
        vector<vector<pair<int,int>>> memo(n,vector<pair<int,int>>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) memo[i][j].first=-1 , memo[i][j].second=-1;
        }
        return solve(a,0,n-1,memo).nonLeafSum;
    }
};
