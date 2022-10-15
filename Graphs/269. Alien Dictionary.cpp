Question Link: https://leetcode.com/problems/alien-dictionary/


// Approach :                                            
class Solution {
public:
    
    bool isPrefix(string a, string b){
        for(int i=0;i<b.length();i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    
    string alienOrder(vector<string> &words) {
        map<char,set<char>> graph;
        
        map<char,int> indegree;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                char ch=words[i][j];
                indegree[ch]=0;
                
                set<char> st;
                graph[ch]=st; 
            }
        } 
        
        for(int i=0;i<words.size()-1;i++){
            string a=words[i], b=words[i+1];
            
            if((a.length() > b.length()) && isPrefix(a,b)) return "";
            
            for(int j=0;j<min(a.length(),b.length());j++){
                char u=a[j], v=b[j];
                
                if(u!=v){
                    set<char> st;
                    if(graph.find(u)!=graph.end()){
                        st=graph[u];
                        if(st.find(v)==st.end()){
                            st.insert(v);
                            indegree[v]++;
                            graph[u]=st;
                        }
                    }else{
                        st.insert(v);
                        indegree[v]++;
                        graph[u]=st;
                    }
                    break;
                }
            }
        } 
        
        queue<char> q;
        map<char,int> :: iterator it;
        for(it=indegree.begin();it!=indegree.end();it++){
            char ch=it->first, deg=it->second;
            if(deg==0) q.push(ch);
        }
        
        string ans="";
        int c=0;
        while(q.size()>0){
            char u=q.front();
            q.pop();
            
            c++;
            ans+=u;
            
            if(graph.find(u)!=graph.end()){
                set<char> st=graph[u];
                set<char> :: iterator it;
                for(it=st.begin();it!=st.end();it++){
                    char v=*it;
                    indegree[v]--;
                    if(indegree[v]==0){
                        q.push(v);
                    }
                }
            }
        } 
        
        if(c==indegree.size()) return ans; 
        
        return "";
    }
};
