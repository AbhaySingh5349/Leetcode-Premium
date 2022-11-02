Question Link: https://leetcode.com/problems/find-leaves-of-binary-tree/


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
    
    int height(TreeNode* root, vector<vector<int>> &ans){
        if(root==NULL) return -1;
        
        int h = max(height(root->left,ans),height(root->right,ans))+1;
        
        if(ans.size()<=h) ans.push_back({});
        ans[h].push_back(root->val);
        
        return h;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        height(root,ans);
        
        return ans;
    }
};
