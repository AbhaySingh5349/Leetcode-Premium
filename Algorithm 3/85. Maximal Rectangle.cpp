Question Link: https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        if(n==0) return 0;
        int m=mat[0].size();
        
        vector<vector<int>> right(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]=='1'){
                    c++;
                }else{
                    c=0;
                }
                right[i][j]=c;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curmax=0;
                if(mat[i][j]=='1'){
                    int rightOnes=right[i][j], bottomOnes=1;
                    curmax=rightOnes*bottomOnes;
                    for(int k=i+1;k<n;k++){
                        if(mat[k][j]=='1'){
                            rightOnes=min(rightOnes,right[k][j]);
                            bottomOnes++;
                            curmax=max(curmax,rightOnes*bottomOnes);
                        }else{
                            break;
                        }
                    }
                }
                ans=max(ans,curmax);
            }
        }
        return ans;
    }
};
