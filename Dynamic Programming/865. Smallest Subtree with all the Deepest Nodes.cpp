Question Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/


// Approach 1:
class Solution {
public:
    
    int height(TreeNode* root, map<TreeNode*,int> &depth){
        if(root==NULL) return 0;
        
        int lh=height(root->left,depth);
        int rh=height(root->right,depth);
        
        return depth[root]=1+max(lh,rh);
    }
    
    void solve(TreeNode* root, map<TreeNode*,int> &depth, TreeNode* &ans, bool &found){
        if(root==NULL) return;
        
        int ld=(root->left ? depth[root->left]:-1);
        int rd=(root->right ? depth[root->right]:-1);
        
        if(ld>rd){
            solve(root->left,depth,ans,found);
        }else if(rd>ld){
            solve(root->right,depth,ans,found);
        }else{
            if(found==false){
                found=true;
                ans=root;
            }
        }
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        map<TreeNode*,int> depth;
        depth[root] = height(root,depth);
        
        TreeNode* ans;
        ans=root;
        bool found=false;
        solve(root,depth,ans,found);
        return ans;
    }
};


// Approach 2:
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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        
        if(root==p || root==q) return root;
        
        TreeNode *l = lowestCommonAncestor(root->left,p,q);
        TreeNode *r = lowestCommonAncestor(root->right,p,q);
        
        if(l && r) return root;
        
        return (l!=NULL ? l:r);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        vector<TreeNode*> leaves;
        while(q.size()>0){
            leaves.clear();
            
            int size=q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                
                leaves.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        
        TreeNode* ans=leaves[0];
        for(int i=1;i<leaves.size();i++) ans=lowestCommonAncestor(root,leaves[i],ans);
        
        return ans;
    }
};


// Approach 3: (modified 2)
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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        
        if(root==p || root==q) return root;
        
        TreeNode *l = lowestCommonAncestor(root->left,p,q);
        TreeNode *r = lowestCommonAncestor(root->right,p,q);
        
        if(l && r) return root;
        
        return (l!=NULL ? l:r);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        vector<TreeNode*> leaves;
        while(q.size()>0){
            leaves.clear();
            
            int size=q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                
                leaves.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        
        return lowestCommonAncestor(root,leaves[0],leaves.back());
    }
};
