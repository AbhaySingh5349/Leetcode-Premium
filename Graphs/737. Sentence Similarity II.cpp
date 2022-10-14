Question Link: https://leetcode.com/problems/sentence-similarity-ii/


// Approach :                                            
class Solution {
public:
    
    string find(map<string, string>& parent, string s) {
        if(parent.find(s) == parent.end()) return parent[s]=s;
        if(parent[s]==s) return s;
        return parent[s]=find(parent,parent[s]);
    }
    
    bool areSentencesSimilarTwo(vector<string>& a, vector<string>& b, vector<vector<string>>& pairs) {
        if (a.size() != b.size()) return false;
        
        map<string, string> parent;
        for (auto p : pairs) {
            string pu = find(parent, p[0]), pv = find(parent, p[1]);
            if (pu != pv) parent[pv] = pu;
        }
        
        for (int i = 0; i < a.size(); i++){
            if(a[i] != b[i] && find(parent, a[i]) != find(parent, b[i])) return false;
        }

        return true;
    }
};
