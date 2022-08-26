Question Link: https://leetcode.com/problems/design-underground-system/

class UndergroundSystem {
public:
    
    
    struct Event{
        int id;
        string station;
        int time;
    };
    
    struct Average{
        double total=0;
        int count=0;
        
        void updateAverage(int diff){
            count++;
            total+=diff;
        }
        
        double getAverage(){
            return total/count;
        }
    };
    
    map<int,Event> arrivals;
    map<string,Average> averages;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        Event e = {id,stationName,t};
        arrivals[id]=e;
    }
    
    void checkOut(int id, string stationName, int t) {
        Event e = arrivals[id];
        arrivals.erase(id);
        
        int diff = t-e.time;
        string key = e.station + "," + stationName;
        
        Average avg;
        if(averages.find(key)!=averages.end()){
            avg = averages[key];
        }
        avg.updateAverage(diff);
        averages[key]=avg;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "," + endStation;
        return averages[key].getAverage();
    }
};
