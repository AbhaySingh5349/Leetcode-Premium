Question Link: https://leetcode.com/problems/maximal-rectangle/

// Approach 1:
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

// Approach 2:
class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        
        stack<pair<int,int>> st;
        
        vector<int> nsl(n,-1), nsr(n,n);
        for(int i=0;i<n;i++){
            while(st.size()>0 && st.top().first>=heights[i]){
                nsr[st.top().second]=i;
                st.pop();
            }
            if(st.size()>0) nsl[i]=st.top().second;
            st.push({heights[i],i});
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            int curh=heights[i];
            int width=nsr[i]-nsl[i]-1;
            ans=max(ans,curh*width);
        }
        return ans; 
    }
    
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        if(n==0) return 0;
        int m=mat[0].size();
        
        // count of 1s on top for each cell 
        vector<vector<int>> top(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int c=0;
            for(int i=0;i<n;i++){
                if(mat[i][j]=='1'){
                    c++;
                }else{
                    c=0;
                }
                top[i][j]=c;
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            vector<int> heights=top[i];
            int area=largestRectangleArea(heights);
            ans=max(ans,area);
        }
        return ans;
    }
};
