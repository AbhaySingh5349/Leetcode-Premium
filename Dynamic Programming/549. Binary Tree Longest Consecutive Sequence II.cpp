Question Link: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/


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
        int incLen, decLen;
        info(int ml, int l, int d){
            maxlen=ml;
            incLen=l;
            decLen=d;
        }
    };
    
    struct info solve(TreeNode* root){
        if(root==NULL) return info(0,0,0);
        
        struct info lp = solve(root->left);
        struct info rp = solve(root->right);
        
        int curIncLen=1;
        if(root->left && root->left->val == root->val+1) curIncLen = max(curIncLen, 1+lp.incLen);
        if(root->right && root->right->val == root->val+1) curIncLen = max(curIncLen, 1+rp.incLen);
        
        int curDecLen=1;
        if(root->left && root->left->val+1 == root->val) curDecLen = max(curDecLen, 1+lp.decLen);
        if(root->right && root->right->val+1 == root->val) curDecLen = max(curDecLen, 1+rp.decLen);
        
        int curMaxlen=max(max(curIncLen,curDecLen),max(lp.maxlen, rp.maxlen));
        curMaxlen = max(curMaxlen, curIncLen+curDecLen-1);
        
        return info(curMaxlen, curIncLen, curDecLen);
    }
    
    int longestConsecutive(TreeNode* root) {
        return solve(root).maxlen;
    }
};
