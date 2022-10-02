Question Link: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/


// Approach :

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
    
    struct info{
        int maxlen;
        int len;
        info(int ml, int l){
            maxlen=ml;
            len=l;
        }
    };
    
    struct info solve(TreeNode* root){
        if(root==NULL) return info(0,0);
        
        struct info lp = solve(root->left);
        struct info rp = solve(root->right);
        
        int len=1;
        if(root->left && root->left->val == root->val+1) len = max(len, 1+lp.len);
        if(root->right && root->right->val == root->val+1) len = max(len, 1+rp.len);
        
        int curMaxlen=max(len,max(lp.maxlen, rp.maxlen));
        
        return info(curMaxlen, len);
    }
    
    int longestConsecutive(TreeNode* root) {
        return solve(root).maxlen;
    }
};
