Question Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/


// Approach :    
class Solution {
public:
    
    static bool compare(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    
    int findMinArrowShots(vector<vector<int>> &pts) {
        sort(pts.begin(),pts.end(),compare);
        
        int c=1, end=pts[0][1];
        for(int i=1;i<pts.size();i++){
            int s=pts[i][0], e=pts[i][1];
            if(s>end){
                end=e;
                c++;
            }
        }
        return c;
    }
};
