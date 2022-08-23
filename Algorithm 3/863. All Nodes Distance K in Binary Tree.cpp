Question Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// Approach 1:

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

// Approach 2: O(1) space

class Solution {
public:
    
    void getNodes(TreeNode* root, int k, TreeNode* blocker, vector<int> &ans){
        if(root==NULL || k<0 || root==blocker) return;
        
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        getNodes(root->left,k-1,blocker,ans);
        getNodes(root->right,k-1,blocker,ans);
    } 
    
    int getDistance(TreeNode* node, int k, TreeNode* &blocker , TreeNode* target, vector<int> &ans){
        if(node==NULL) return -1;
        
        if(node==target){
            getNodes(node,k-0,blocker,ans);
            return 1;
        }
        
        int leftDistanceFromTarget = getDistance(node->left, k, blocker, target, ans);
        if(leftDistanceFromTarget != -1){
            // target is present on left-subtree from current node
            blocker=node->left;
            getNodes(node, k-leftDistanceFromTarget, blocker, ans);
            
            return leftDistanceFromTarget+1;
        }
        
        int rightDistanceFromTarget = getDistance(node->right, k, blocker, target, ans);
        if(rightDistanceFromTarget != -1){
            // target is present on left-subtree from current node
            blocker=node->right;
            getNodes(node, k-rightDistanceFromTarget, blocker, ans);
            
            return rightDistanceFromTarget+1;
        }
        
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        TreeNode* blocker=NULL;
        vector<int> ans;
        getDistance(root,k,blocker,target,ans);
        return ans;
    }
};
