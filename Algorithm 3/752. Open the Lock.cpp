Question Link: https://leetcode.com/problems/open-the-lock/

Time Complexity: O(N^2 * A^N + D)
where A is number of digits in our alphabet, N is the number of digits in the lock, and D is the size of deadends. 
We might visit every lock combination, plus we need to instantiate our set dead
When we visit every lock combination, we spend O(N^2) time enumerating through and constructing each node.

class Solution {
public:
    
    string nextMove(string s, int idx, int direction){
        char newChar = (char)((s[idx]-'0' + direction + 10)%10 + '0');
        s[idx]=newChar;
        
        return s;
    }
    
    int openLock(vector<string>& deadends, string target) {
        set<string> st;
        for(int i=0;i<deadends.size();i++) st.insert(deadends[i]);
        
        queue<string> q;
        if(st.find("0000") == st.end()) q.push("0000");
        
        set<string> visited;
        visited.insert("0000");
        
        int moves=0;
        while(q.size()>0){
            int size=q.size();
            while(size--){
                string cur=q.front();
                q.pop();
                
                if(cur == target) return moves;
                
                for(int i=0;i<cur.length();i++){
                    string s1=nextMove(cur,i,1);
                    if(st.find(s1) == st.end() && visited.find(s1) == visited.end()){
                        q.push(s1);
                        visited.insert(s1);
                    }
                    
                    string s2=nextMove(cur,i,-1);
                    if(st.find(s2) == st.end() && visited.find(s2) == visited.end()){
                        q.push(s2);
                        visited.insert(s2);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
