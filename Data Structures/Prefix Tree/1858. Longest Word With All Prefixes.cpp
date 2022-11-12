Question Link: https://leetcode.com/problems/longest-word-with-all-prefixes/


// Approach :   
class Solution {
public:
    
    struct Trienode{
        char ch;
        Trienode *child[26]; // each node will have 26 sub-nodes
        int wordEnd; // count of words ending at current position  
        Trienode(int idx){
            this->ch = idx+'a';
            this->wordEnd=0;
            for(int i=0;i<26;i++) this->child[i]=NULL;
        }
    };
    
    Trienode *root;
    
    void insert(string s) {
        Trienode* cur=root;
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            if(cur->child[idx]==NULL) cur->child[idx]=new Trienode(idx);
            
            cur=cur->child[idx];
        }
        cur->wordEnd++;
    }
    
    bool valid(string s){
        Trienode* cur=root;
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            if(cur->child[idx]==NULL || cur->child[idx]->wordEnd==0) return false;
            
            cur=cur->child[idx];
        }
        return true;
    }
    
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        
        root = new Trienode('*'-'a');
        for(string w : words) insert(w);
        
        string ans="";
        for(string w : words){
            if(valid(w)){
                if(w.length()>ans.length()) ans=w;
            }
        }
        return ans;
    }
};
