Question Link: https://leetcode.com/problems/find-all-the-lonely-nodes/


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
    
    void solve(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        
        solve(root->left, ans);
        solve(root->right, ans);
        
        if(root->left!=NULL ^ root->right!=NULL){
            if(root->left) ans.push_back(root->left->val);
            if(root->right) ans.push_back(root->right->val);
        }
    }
    
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        
        solve(root,ans);
        
        return ans;
    }
};
