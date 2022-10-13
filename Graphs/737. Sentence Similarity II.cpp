Question Link: https://leetcode.com/problems/sentence-similarity-ii/


// Approach :                                            
class Solution {
public:
    
    string find(map<string, string>& mp, string s) {
        if(mp.find(s) == mp.end()) return mp[s]=s;
        if(mp[s]==s) return s;
        return mp[s]=find(mp,mp[s]);
    }
    
    bool areSentencesSimilarTwo(vector<string>& a, vector<string>& b, vector<vector<string>>& pairs) {
        if (a.size() != b.size()) return false;
        
        map<string, string> mp;
        for (auto p : pairs) {
            string pu = find(mp, p[0]), pv = find(mp, p[1]);
            if (pu != pv) mp[pv] = pu;
        }

        for (int i = 0; i < a.size(); i++){
            if(a[i] != b[i] && find(mp, a[i]) != find(mp, b[i])) return false;
        }

        return true;
    }
};
