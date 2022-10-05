Question Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/


// Approach :
class Solution {
public:
    
    static bool compare(vector<int> &v1, vector<int> &v2){
        return v1[1]<v2[1];
    }
    
    int maxEvents(vector<vector<int>>& a) {
        int n=a.size();
        sort(a.begin(),a.end(),compare); // sorting by min. end date, as event with greater end date can be attended little later also: [1,1][1,2][3,3][2,5]
        
        int start=1, end=a[n-1][1];
        
        set<int> availbleDays;
        for(int i=start;i<=end;i++) availbleDays.insert(i);
        
        int ans=0;
        for(int i=0;i<n;i++){
            int s=a[i][0], e=a[i][1];
            auto day=availbleDays.lower_bound(s);
            
            if(day==availbleDays.end() || *day>e){
                continue;
            }else{
                ans++;
                availbleDays.erase(*day);
            }
        }
        
        return ans;
    }
};
