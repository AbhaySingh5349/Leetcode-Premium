Question Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/


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
    
    #define ll long long 
    struct Pair{
        ll int RTNmaxsum; // maxsum possible including current root
        ll int NTNmaxsum; // maxsum possible in subtree (may include cur root or not)
    };
    
    ll int getMax(ll int a, ll int b){
        if(a>=b) return a;
        return b;
    }
    
    struct Pair solve(TreeNode* root){
        if(root==NULL) return {0,INT_MIN};
        
        struct Pair lp=solve(root->left);
        struct Pair rp=solve(root->right);
        
        ll int RTN = root->val + getMax(lp.RTNmaxsum,rp.RTNmaxsum);
        RTN = getMax(RTN,root->val);
        
        ll int NTN = getMax(lp.NTNmaxsum,rp.NTNmaxsum);
        NTN = getMax(NTN,root->val+lp.RTNmaxsum+rp.RTNmaxsum);
        NTN = getMax(NTN,RTN);
        
        struct Pair cp={RTN,NTN};
        return cp;
    }
    
    int maxPathSum(TreeNode* root) {
        struct Pair ans=solve(root);
        return ans.NTNmaxsum;
    }
};
