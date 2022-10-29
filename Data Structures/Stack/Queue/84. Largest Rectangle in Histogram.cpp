Question Link: https://leetcode.com/problems/largest-rectangle-in-histogram/


// Approach 1: 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int curh=heights[i];
            int c=1;
            for(int j=i-1;j>=0;j--){
                if(heights[j]>=curh){
                    c++;
                }else{
                    break;
                }
            }
            for(int j=i+1;j<n;j++){
                if(heights[j]>=curh){
                    c++;
                }else{
                    break;
                }
            }
            
            ans=max(ans,c*curh);
        }
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        
        vector<int> nsl(n,-1), nsr(n,n);
        stack<pair<int,int>> st;
        
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
};
