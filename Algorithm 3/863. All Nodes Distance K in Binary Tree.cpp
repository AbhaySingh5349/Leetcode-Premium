Question Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

class Solution {
public:
    
    bool rootToNodePath(TreeNode* node, vector<TreeNode*> &path, TreeNode* target){
        if(node==NULL) return false;
        
        path.push_back(node);
        
        if(node==target) return true;
        
        if(rootToNodePath(node->left, path, target) || rootToNodePath(node->right, path, target)) return true;
        
        path.pop_back();
        return false;
    }
    
    void getNodes(TreeNode* root, int k, vector<int> &ans, TreeNode* blocker){
        if(root==NULL || k<0 || root==blocker) return;
        
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        getNodes(root->left,k-1,ans,blocker);
        getNodes(root->right,k-1,ans,blocker);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> path;
        rootToNodePath(root, path, target);
        
        reverse(path.begin(),path.end());
        
        TreeNode* blocker=NULL;
        vector<int> ans;
        for(int i=0;i<path.size();i++){
            getNodes(path[i],k-i,ans,blocker);
            blocker=path[i];
        }
        return ans;
    }
};
