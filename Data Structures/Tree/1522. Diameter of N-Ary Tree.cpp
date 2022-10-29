Question Link: https://leetcode.com/problems/diameter-of-n-ary-tree/


// Approach : 
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    struct info{
        int maxDiameter;
        int curHeight;
    };
    
    struct info solve(Node* root){
        if(root == NULL) return {0,0};
        
        int max_h1=0, max_h2=0, max_d=0;
        
        for(Node* cur : root->children){
            struct info sub_info=solve(cur);
            
            max_d=max(max_d,sub_info.maxDiameter);
            int sub_h=sub_info.curHeight + 1;
            
            if(sub_h > max_h1){
                max_h2=max_h1;
                max_h1=sub_h;
            }else if(sub_h > max_h2){
                max_h2=sub_h;
            }
            
            max_d=max(max_d,max_h1+max_h2);
        }
        
        return {max_d,max_h1};
    }
    
    int diameter(Node* root) {
        return solve(root).maxDiameter;
    }
};
