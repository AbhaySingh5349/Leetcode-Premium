Question Link: https://leetcode.com/problems/maximum-students-taking-exam/


// Approach :
class Solution {
public:
    map<string,int> memo;
    
    int solve(vector<vector<char>>& seats, int n, int m, int pos, int prerow, int currow){
        
        if(pos==n*m) return 0;
        
        int i=pos/m, j=pos%m;
        
        if(j==0){
            prerow=currow;
            currow=0;
        }
        string state=to_string(pos)+"$"+to_string(prerow)+"$"+to_string(currow);
        if(memo.find(state)!=memo.end()) return memo[state];
        
        int ans=solve(seats,n,m,pos+1,prerow,currow);
        
        if(seats[i][j]=='.'){
            bool tl=true, tr=true, l=true;
            
            if(j>0){
                l=((currow & (1<<(j-1))) == 0);
                if(i>0){
                    tl=((prerow & (1<<(j-1))) == 0);
                }
            }
            if(j<m-1){
                if(i>0){
                    tr=((prerow & (1<<(j+1))) == 0);
                }
            }
            
            if(tl && tr && l) ans=max(ans,1+solve(seats,n,m,pos+1,prerow,currow | (1<<j)));
        }
        
        return memo[state]=ans;
    }
    
    int maxStudents(vector<vector<char>>& seats) {
        int n=seats.size(), m=seats[0].size();
        
        return solve(seats,n,m,0,0,0);
    }
};
