Question Link: https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
public:
    
    unordered_map<string, map<int, string>> mp;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
        auto itr = mp[key].lower_bound(timestamp);
        
        if(itr->first == timestamp)
            return itr->second;
        else {
            return (itr == mp[key].begin() ? "":(prev(itr))-> second);
         }
    }
};
