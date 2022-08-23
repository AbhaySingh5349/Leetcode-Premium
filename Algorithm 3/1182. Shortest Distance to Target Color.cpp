Question Link: https://leetcode.com/problems/shortest-distance-to-target-color/

// Approach 1

class Solution {
public:
    
    int distance(set<int> st, int idx, int &d){
        auto itr = lower_bound(st.begin(), st.end(), idx);
        d=min(d,abs(*itr - idx));
        if(itr != st.begin()){
            itr--;
            d=min(d,abs(*itr - idx));
        }
        
        return d;
    }
    
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        set<int> one, two, three;
        
        int n=colors.size();
        bool c1=false, c2=false, c3=false;
        for(int i=0;i<n;i++){
            if(colors[i]==1) one.insert(i), c1=true;
            if(colors[i]==2) two.insert(i), c2=true;
            if(colors[i]==3) three.insert(i), c3=true;
        }
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int idx=queries[i][0], c=queries[i][1];
            
            int d=n+1;
            if(c1 && c==1) distance(one, idx, d);
            if(c2 && c==2) distance(two, idx, d);
            if(c3 && c==3) distance(three, idx, d);
            
            ans.push_back((d==n+1 ? -1:d));
        }
        return ans;
    }
};

// Approach 2:
class Solution {
public:
    
    int distance(vector<int> v, int idx, int &d){
        int l=0, r=v.size()-1;
        while(l<r){
            int m=l+(r-l)/2;
            if(v[m]>=idx){
                r=m;
            }else{
                l=m+1;
            }
        }
        d=min(d,abs(v[l]-idx));
        
        if(l>0) d=min(d,abs(v[l-1]-idx));
        
        return d;
    } 
    
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> one, two, three;
        
        int n=colors.size();
        bool c1=false, c2=false, c3=false;
        for(int i=0;i<n;i++){
            if(colors[i]==1) one.push_back(i), c1=true;
            if(colors[i]==2) two.push_back(i), c2=true;
            if(colors[i]==3) three.push_back(i), c3=true;
        }
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int idx=queries[i][0], c=queries[i][1];
            
            int d=n+1;
            if(c1 && c==1) distance(one, idx, d);
            if(c2 && c==2) distance(two, idx, d);
            if(c3 && c==3) distance(three, idx, d);
            
            ans.push_back((d==n+1 ? -1:d));
        }
        return ans;
    }
};

// Approach 3:
class Solution {
public:
    
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n=colors.size();
        
        vector<vector<int>> left(3, vector<int> (n,-1));
        for(int c=0;c<3;c++){
            for(int i=0;i<n;i++){
                int curColor=colors[i]-1;
                if(c==curColor){
                    left[c][i]=i;
                }else{
                    if(i>0) left[c][i]=left[c][i-1];
                }
            }
        }
        
        vector<vector<int>> right(3, vector<int> (n,n));
        for(int c=0;c<3;c++){
            for(int i=n-1;i>=0;i--){
                int curColor=colors[i]-1;
                if(c==curColor){
                    right[c][i]=i;
                }else{
                    if(i<n-1) right[c][i]=right[c][i+1];
                }
            }
        }
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int idx=queries[i][0], c=queries[i][1]-1;
            
            int d=n+1;
            if(left[c][idx] != -1) d=min(d,idx-left[c][idx]);
            if(right[c][idx] != n) d=min(d,right[c][idx]-idx);
            
            ans.push_back((d==n+1 ? -1:d));
        }
        return ans;
    }
};
