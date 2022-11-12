Question Link: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/


// Approach :   
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // to store max. busy time for each server
        set<int> st; // available server
        
        for(int i=0;i<k;i++) st.insert(i);
        
        vector<int> count(k,0);
        
        for(int i=0;i<arrival.size();i++){
            // free servers
            while(pq.size()>0 && arrival[i]>=pq.top().first){
                st.insert(pq.top().second);
                pq.pop();
            }
            
            if(st.size() == 0) continue; // no available servers
            
            // assign request to free server
            int server = i%k;
            
            auto it=st.lower_bound(server);
            if(it == st.end()){
                // no available server from [s,k-1], so search from [0,s-1]
                
                it = st.begin();
                if(it == st.end()) continue; // no available servers
            }
            
            server = *it;
            st.erase(server);
            
            pq.push({arrival[i]+load[i],server});
            
            count[server]++;
        }
        
        int max_c = *max_element(count.begin(),count.end());
        
        vector<int> ans;
        for(int i=0;i<k;i++) if(max_c == count[i]) ans.push_back(i);
        
        return ans;
    }
};
