Question Link: https://leetcode.com/problems/cherry-pickup/


** WRONG APPROACH **
--> Applying "Maximum Sum Path" 2 times : Greedy gives wrong as it is maximizing sum for 1st path only & not the 2nd path
grid = [[1,1,1,0,1],
        [0,0,0,0,0],
        [0,0,0,0,0],
        [0,0,0,0,0],
        [1,0,1,1,1]].
--> Path1: (0, 0) ==> (0, 2) ==> (4, 2) ==> (4, 4) , so sum=6 . But in path 2 we will only be able to collect 1, overall = 7
--> But with different approach, we can easily get  overall = 8
So, max. number of cherries of trip not only depends on the starting position (i, j), but also on the status of the grid matrix when that position is reached. 

--> our subproblems can be denoted as T(i, j, grid.status), where status of grid matrix may be represented by a string with cell values joined row by row.
--> T(i, j, grid.status) = -1, if grid[i][j] == -1 || T(i + d, j, grid.status1) == -1 && T(i + d, j, grid.status2) == -1;
	T(i, j, grid.status) = grid[i][j] + max(T(i + d, j, grid.status1), T(i, j + d, grid.status2))
	d depends on which leg we are during the round trip (d = +1 for the first leg and d = -1 for the second leg)

// Approach 1:
class Solution {
public:
    
    int memo[50][50][50][50];
    int dxy[2][2]={{0,1},{1,0}};
    
    int solve(vector<vector<int>>& grid, int n, int r1, int c1, int r2, int c2){
        if(r1<0 || r2<0 || c1<0 || c2<0 || r1==n || r2==n || c1==n || c2==n || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return INT_MIN/2;
        }
        if(memo[r1][c1][r2][c2]!=-1){
            return memo[r1][c1][r2][c2];
        }
        
        if(r1==n-1 && c1==n-1){
            return grid[r1][c1];
        }
        
        int curcherry=0;
        if(r1==r2 && c1==c2){
            curcherry = grid[r1][c1];
        }else{
            curcherry = grid[r1][c1]+grid[r2][c2];
        }
        
        int newcherry=INT_MIN;
        for(int d1=0;d1<2;d1++){
            for(int d2=0;d2<2;d2++){
                int nr1=r1+dxy[d1][0];
                int nc1=c1+dxy[d1][1];
                int nr2=r2+dxy[d2][0];
                int nc2=c2+dxy[d2][1];
                
                newcherry = max(newcherry,solve(grid,n,nr1,nc1,nr2,nc2));
            }
        }
        curcherry+=newcherry;
        return memo[r1][c1][r2][c2]=curcherry;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(memo,-1,sizeof(memo));
        int n=grid.size();
        
        int ans = solve(grid,n,0,0,0,0);
        return (ans<0 ? 0:ans);
    }
};


// Approach 2:
class Solution {
public:
    
    int memo[50][50][50];
    int dxy[2][2]={{0,1},{1,0}};
    
    int solve(vector<vector<int>>& grid, int n, int r1, int c1, int c2){
        int r2=r1+c1-c2;
        if(r1<0 || r2<0 || c1<0 || c2<0 || r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return INT_MIN/2;
        }
        if(memo[r1][c1][c2]!=-1){
            return memo[r1][c1][c2];
        }
        
        if((r1==n-1 && c1==n-1) && (r2==n-1 && c2==n-1)){
            return grid[r1][c1];
        }
        
        int curcherry=0;
        if(r1==r2 && c1==c2){
            curcherry = grid[r1][c1];
        }else{
            curcherry = grid[r1][c1]+grid[r2][c2];
        }
        
        int newcherry=INT_MIN;
        for(int d1=0;d1<2;d1++){
            for(int d2=0;d2<2;d2++){
                int nr1=r1+dxy[d1][0];
                int nc1=c1+dxy[d1][1];
                int nc2=c2+dxy[d2][1];
                
                newcherry = max(newcherry,solve(grid,n,nr1,nc1,nc2));
            }
        }
        curcherry+=newcherry;
        return memo[r1][c1][c2]=curcherry;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(memo,-1,sizeof(memo));
        int n=grid.size();
        
        int ans = solve(grid,n,0,0,0);
        return (ans<0 ? 0:ans);
    }
};
