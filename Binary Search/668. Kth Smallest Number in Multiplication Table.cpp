Question Link: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/


// Approach 1:
class Solution {
public:
	
    bool possible(vector<vector<int>>& grid, int k, int val){
        int m=grid.size(), n=grid[0].size();
        
        int i=0, j=n-1;
        int c=0;
        while(i<m && j>=0){
            if(grid[i][j]>val){
                j--;
            }else{
                c+=j+1;
                i++;
            }
        }
        return (c>=k);
    }
    
    int findKthNumber(int m, int n, int k) {
        vector<vector<int>> grid(m,vector<int>(n,1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=(i+1)*(j+1);
            }
        }
        int l=grid[0][0], r=grid[m-1][n-1];
        while(l<r){
            int mid=l+(r-l)/2;
            if(possible(grid,k,mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        } 
        return l;
    }
};


// Approach 2:
class Solution {
public:
    
    bool possible(int m, int n, int k, int val){
        int c=0;
        for(int i=1;i<=m;i++){
            c+=min(val/i,n);
        }
        return (c>=k);
    }
    
    int findKthNumber(int m, int n, int k) {
        int l=1, r=m*n;
        while(l<r){
            int mid=l+(r-l)/2;
            if(possible(m,n,k,mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};
