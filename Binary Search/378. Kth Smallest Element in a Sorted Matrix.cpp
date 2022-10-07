Question Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/


// Approach 1:
class Solution {
public:
    
    bool possible(vector<vector<int>>& grid, int k, int val){
        int n=grid.size();
        
        int i=0, j=n-1;
        int c=0;
        while(i<n && j>=0){
            if(grid[i][j]>val){
                j--;
            }else{
                c+=j+1;
                i++;
            }
        }
        return (c>=k);
    }
    int kthSmallest(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        
        int l=grid[0][0], r=grid[n-1][n-1];
        
        while(l<r){
            int m=l+(r-l)/2;
            if(possible(grid,k,m)){
                r=m;
            }else{
                l=m+1;
            }
        }
        return l;
    }
};


// Approach 2:
class Solution {
public:
    
    struct node{
        int val;
        int row;
        int col;
    };
    
    struct compare{
        bool operator()(const node &a, const node &b){
            return a.val > b.val;
        }
    };
	    
    int kthSmallest(vector<vector<int>> &grid, int k) {
        int n=grid.size(), m=grid[0].size();
        
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pq.size()<k){
                    pq.push(grid[i][j]);
                }else if(pq.size()==k){
                    if(pq.top() > grid[i][j]){
                        pq.pop();
                        pq.push(grid[i][j]);
                    }
                }
            }
        }
        return pq.top(); 
    }
};
