Question Link: https://leetcode.com/problems/132-pattern/


// Approach 1: 
class Solution {
public:
    bool find132pattern(vector<int>& a) {
        int n=a.size();
        vector<int> mine(n);
        mine[0]=a[0];
        for(int i=1;i<n;i++){
            mine[i]=min(a[i],mine[i-1]);
        }
        
        for(int j=1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(a[j]>mine[j-1] && a[j]>a[k] && a[k]>mine[j-1]) return true;
            }
        }
        return false;
    }
};


// Approach 2:
class Solution {
public:
    bool find132pattern(vector<int>& a) {
        int n=a.size();
        vector<int> mine(n);
        mine[0]=a[0];
        for(int i=1;i<n;i++){
            mine[i]=min(a[i],mine[i-1]);
        }
        
        stack<int> st;
        st.push(a[n-1]);
        for(int j=n-2;j>0;j--){
            int ei=mine[j-1];
            while(st.size()>0 && st.top()<=ei) st.pop();
            if(st.size()>0){
                int ej=a[j];
                int ek=st.top();
                if(ej>ei && ej>ek && ek>ei) return true;
            }
            st.push(a[j]);
        }
        return false;
    } 
};
