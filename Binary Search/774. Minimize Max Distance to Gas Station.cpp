Question Link: https://leetcode.com/problems/minimize-max-distance-to-gas-station/


// Approach :
class Solution {
public:
    
    bool possible(vector<int>& stations, int k, double maxd){
        int c=0;
        for(int i=1;i<stations.size();i++){
            double d=stations[i]-stations[i-1];
            
            c += d/maxd;
        }
        return (c<=k);
    }
    
    double minmaxGasDist(vector<int>& stations, int k) {
        double l=0, r=stations.back()-stations[0];
        
        while(r-l > 1e-6){
            double m=l+(r-l)/2.0;
            
            if(possible(stations,k,m)){
                r=m;
            }else{
                l=m;
            }
        }
        return l;
    }
};
