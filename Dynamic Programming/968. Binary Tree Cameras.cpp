Question Link: https://leetcode.com/problems/binary-tree-cameras/


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

                      node
            hasCamera      noCamera
                        need     covered
                        
                        
class Solution {
public:
    int solve(TreeNode* root, int &count){
        if(root==NULL) return 1; // covered
        
        int lc=solve(root->left,count);
        int rc=solve(root->right,count);
        
        // if any of child need camera
        if(lc==-1 || rc==-1){
            count++;
            return 0; // camera is placed on parent node
        }
        
        // if any of child has camera, parent is covered
        if(lc==0 || rc==0) return 1;
        
        return -1;
        
    }
    int minCameraCover(TreeNode* root) {
        int count=0;
        int x=solve(root,count);
        
        if(x==-1) count++;
        
        return count;
    }
};
