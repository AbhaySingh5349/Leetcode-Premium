Question Link: https://leetcode.com/problems/closest-binary-search-tree-value/


// Approach 1:
class Solution {
public:
    
    void solve(TreeNode* root, double target, double &diff, int &ans){
        if(root==NULL) return;
        
        double d=target - (double)root->val;
        
        if(d>0){
            solve(root->right, target, diff, ans);
        }else if(d<0){
            solve(root->left, target, diff, ans);
        }
        
        if(d<0) d*=-1;
        if(d < diff){
            diff=d;
            ans=root->val;
        }
    }
    
    int closestValue(TreeNode* root, double target) {
        double diff=LONG_MAX;
        int ans=-1;
        
        solve(root, target, diff, ans);
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    
    void inorder(TreeNode* root, vector<int> &v){
        if(root==NULL) return;
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    int closestValue(TreeNode* root, double target) {
        vector<int> v;
        inorder(root,v);
        
        double diff=LONG_MAX;
        int ans=-1;
        
        int l=0, r=v.size()-1;
        while(l<r){
            int m=l+(r-l)/2;
            
            double d=target- (double)v[m];
            
            if(d>0){
                l=m+1;
            }else if(d<0){
                r=m;
            }else{
                return v[m];
            }
            
            if(d<0) d*=-1;
            if(d < diff){
                diff=d;
                ans=v[m];
            }
        }
        double d=target- (double)v[l];
        if(d<0) d*=-1;
        if(d < diff){
            diff=d;
            ans=v[l];
        }
        return ans;
    }
};
