Question Link: https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    
    vector<int> greaterEqualOnRight(vector<int>& a){
        int n=a.size();
        vector<int> ngr(n,n);
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && st.top().first<a[i]) st.pop();
            if(st.size()>0) ngr[i]=st.top().second;
            st.push({a[i],i});
        }
        return ngr;
    }
    
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n=a.size();
        vector<int> ngr=greaterEqualOnRight(a);
        
        int i=0, j=0;
        vector<int> ans;
        while(i<=n-k){
            j=max(i,j);
            while(ngr[j]<i+k){
                j=ngr[j];
            }
            ans.push_back(a[j]);
            i++;
        }
        return ans;
    }
};
