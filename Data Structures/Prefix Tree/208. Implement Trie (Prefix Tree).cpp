Question Link: https://leetcode.com/problems/implement-trie-prefix-tree/


// Approach :   
class Trie {
public:
    
    struct Trienode{
        char ch;
        Trienode *child[26]; // each node will have 26 sub-nodes
        int wordEnd; // count of words ending at current position
        int preCount; // count of words starting with given prefix  
        Trienode(int idx){
            this->ch = idx+'a';
            this->preCount = this->wordEnd=0;
            for(int i=0;i<26;i++) this->child[i]=NULL;
        }
    };
    
    Trienode *root;
    
    Trie() {
        root = new Trienode('*'-'a');
    }
    
    void insert(string s) {
        Trienode* cur=root;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            int idx=s[i]-'a';
            if(cur->child[idx]==NULL) cur->child[idx]=new Trienode(idx);
            
            cur->child[idx]->preCount++;
            cur=cur->child[idx];
        }
        cur->wordEnd++;
    }
    
    bool search(string s) {
        Trienode* cur=root;
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            if(cur->child[idx]==NULL) return false;
            
            cur=cur->child[idx];
        }
        return (cur->wordEnd > 0);
    }
    
    bool startsWith(string prefix) {
        Trienode* cur=root;
        for(int i=0;i<prefix.length();i++){
            int idx=prefix[i]-'a';
            if(cur->child[idx]==NULL) return false;
            
            cur=cur->child[idx];
        }
        return (cur->preCount> 0);
    }
};
