Question Link: https://leetcode.com/problems/daily-temperatures/


// Approach : 
class Solution {
public:
    
    vector<int> greater(vector<int> v){
        int n=v.size();
        vector<int> ngr(n,0);
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && v[i]>=st.top().first) st.pop();
            if(st.size()>0) ngr[i]=st.top().second-i;
            st.push({v[i],i});
        }
        return ngr;
    }
    
    vector<int> dailyTemperatures(vector<int>& a) {
        int n=a.size();
        
        vector<int> ngr=greater(a);
        return ngr;
    }
};
