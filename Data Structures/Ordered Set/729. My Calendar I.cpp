Question Link: https://leetcode.com/problems/my-calendar-i/


// Approach 1:   
class MyCalendar {
public:
    
    map<int,int> mp;
    
    MyCalendar() {
        mp.clear();
    }
    
    bool book(int start, int end) {
        mp[start]++, mp[end]--;
        
        int count=0;
        for(auto it : mp){
            count += (it.second);
            if(count>1){
                mp[start]--, mp[end]++; // removing double booking scenario
                return false;
            }
        }
        return true;
    }
};


// Approach 2:
class MyCalendar {
public:
    
    map<int,int> mp;
    
    MyCalendar() {
        mp.clear();
    }
    
    bool book(int start, int end) {
        auto it = mp.lower_bound(start);
        
        if(it!=mp.end() && it->first < end) return false;
        
        if(it!=mp.begin()){
            it--;
            if(it->second > start) return false;
        }
        
        mp[start]=end;
        return true;
    }
};

