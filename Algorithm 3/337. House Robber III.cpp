Question Link: https://leetcode.com/problems/house-robber-iii/

class Solution {
public:
    
    map<TreeNode*,int> mp;
    
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        
        if(mp.find(root)!=mp.end()) return mp[root];
        
        // include current node
        int p1=root->val;
        if(root->left) p1 += rob(root->left->left) + rob(root->left->right);
        if(root->right) p1 += rob(root->right->left) + rob(root->right->right);
        
        // exclude current node
        int p2 = rob(root->left) + rob(root->right);
        
        return mp[root] = max(p1,p2);
    }
};
