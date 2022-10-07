Question Link: https://leetcode.com/problems/closest-room/


// Approach :
class Solution {
public:
    
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]>b[1];
    }
    
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        vector<vector<int>> qid;
        int n=rooms.size(), m=queries.size();
        for(int i=0;i<m;i++) qid.push_back({queries[i][0], queries[i][1], i});
        
        // sorting queries based on descending order of MinSize required 
        // (as possible rooms will be availble for smaller MinSize queries also)
        sort(qid.begin(),qid.end(),compare);
        
        sort(rooms.begin(),rooms.end(),compare); 
        
        set<int> possibleIds;
        
        vector<int> ans(m,-1);
        int j=0;
        for(int i=0;i<m;i++){
            int prefId=qid[i][0], minSize=qid[i][1], idx=qid[i][2];
            
            while(j<n && rooms[j][1]>=minSize){
                possibleIds.insert(rooms[j][0]);
                j++;
            }
            
            if(possibleIds.size() == 0) continue;
            
            auto idItr = possibleIds.lower_bound(prefId);
            if(idItr == possibleIds.end()) idItr--;
            
            int ansId = *idItr;
            
            int d1=abs(*idItr - prefId);
            
            if(idItr != possibleIds.begin()){
                idItr--;
                
                int d2=INT_MAX/2;
                d2=abs(*idItr - prefId);
                if(d2<=d1) ansId = *idItr; // (if differnece is same, then min roomId)
            } 
            ans[idx]=ansId;
        }
        return ans;
    }
};
