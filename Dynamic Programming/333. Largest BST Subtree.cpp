Question Link: https://leetcode.com/problems/largest-bst-subtree/


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
        int maxSize;
        int size;
        bool isBST;
        int minVal, maxVal;
        info(int ms, int s, bool bst, int minv, int maxv){
            maxSize=ms;
            size=s;
            isBST=bst;
            minVal=minv;
            maxVal=maxv;
        }
    };
    
    struct info solve(TreeNode* root){
        if(root==NULL) return info(0,0,true,INT_MAX,INT_MIN);
        
        struct info lp = solve(root->left);
        struct info rp = solve(root->right);
        
        int curVal=root->val, curSize=1, curMaxSize=1, curMinVal, curMaxVal, bst=false;
        
        if(lp.isBST && rp.isBST && curVal>lp.maxVal && curVal<rp.minVal){
            curSize = 1+lp.size+rp.size;
            bst=true;
        }
        curMaxSize = max(curSize,max(lp.maxSize, rp.maxSize));
        curMinVal = min(root->val,min(lp.minVal,rp.minVal));
        curMaxVal = max(root->val,max(lp.maxVal,rp.maxVal));
        
        return info(curMaxSize,curSize, bst, curMinVal, curMaxVal);
    }
    
    int largestBSTSubtree(TreeNode* root) {
        return solve(root).maxSize;
    }
};
