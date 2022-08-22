Question Link: https://leetcode.com/problems/shortest-distance-to-target-color/

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
