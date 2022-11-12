Question Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/


// Approach :   
class WordDictionary {
public:
    
    struct Trienode{
        char ch;
        Trienode *child[26]; // each node will have 26 sub-nodes
        int wordEnd; // count of words ending at current position
        Trienode(int idx){
            this->ch = 'a'+idx;
            for(int i=0;i<26;i++) this->child[i]=NULL;
            this->wordEnd=0;
        }
    };
    
    Trienode *root;
    
    WordDictionary() {
        root = new Trienode('*'-'a');
    }
    
    void addWord(string s) {
        Trienode* cur=root;
        int idx;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            int idx=ch-'a';
            if(cur->child[idx]==NULL) cur->child[idx] = new Trienode(idx);
            
            cur=cur->child[idx];
        }
        cur->wordEnd++;
    }
    
    bool search(string s) {
        return isPresent(s,root);
    }
    
    bool isPresent(string s, Trienode* node){
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='.'){
                for(int j=0;j<26;j++){
                    Trienode* cur=node->child[j];
                    if(cur!=NULL && isPresent(s.substr(i+1),cur)) return true;
                }
                return false;
            }else{
                int idx=ch-'a';
                if(node->child[idx]==NULL) return false;
                
                node=node->child[idx];
            }
        }
        return (node && node->wordEnd > 0);
    }
};
