Question Link: https://leetcode.com/problems/meeting-scheduler/

class Solution {
public:
    
    // sorting on basis of smaller end time
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[1]==b[1]) return (a[0]<b[0]);
        return (a[1]<b[1]);
    }
    
    vector<int> minAvailableDuration(vector<vector<int>>& slot1, vector<vector<int>>& slot2, int duration) {
        sort(slot1.begin(),slot1.end(),compare);
        sort(slot2.begin(),slot2.end(),compare);
        
        int n=slot1.size(), m=slot2.size();
        int i=0, j=0;
        
        while(i<n && j<m){
            int s1=slot1[i][0], e1=slot1[i][1], s2=slot2[j][0], e2=slot2[j][1];
            
            int startTime = max(s1,s2), endTime = min(e1,e2);
            if(endTime -startTime >= duration) return {startTime, startTime+duration};
            
            if(e1 > e2){
                j++;
            }else{
                i++;
            }
        }
        return {};
    }
};
