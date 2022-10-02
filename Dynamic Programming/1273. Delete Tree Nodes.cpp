Question Link: https://leetcode.com/problems/delete-tree-nodes/


// Approach 1:
class Solution {
public:
    
    int getSum(map<int,vector<int>> &mp, int src, vector<int>& value, vector<bool> &removeSubTree){
        int sum=value[src];
        
        for(int child : mp[src]) sum += getSum(mp,child,value,removeSubTree);
        
        if(sum==0) removeSubTree[src]=true;
        
        return sum;
    }
    
    int removeNodes(map<int,vector<int>> &mp, int src, vector<bool> &removeSubTree){
        if(removeSubTree[src]) return 0;
        
        int nodeCount=1;
        for(int child : mp[src]) nodeCount += removeNodes(mp,child,removeSubTree);
        
        return nodeCount;
    }
    
    int deleteTreeNodes(int n, vector<int>& parent, vector<int>& value) {
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++) mp[parent[i]].push_back(i);
        
        vector<bool> removeSubTree(n,false);
        getSum(mp,0,value,removeSubTree);
        
        return removeNodes(mp,0,removeSubTree);
    }
};


// Approach 2:
class Solution {
public:
    
    //return {num, sum}
    pair<int,int> dfs(map<int,vector<int>> &mp, int src, vector<int> &value){
        int sum = value[src], nodeCount=1;
        
        for(int child : mp[src]){
            pair<int,int> p = dfs(mp, child, value);
            nodeCount += p.first;
            sum += p.second;
        }
        if(sum==0) nodeCount=0;
        return {nodeCount,sum};
    }
    
    int deleteTreeNodes(int n, vector<int>& parent, vector<int>& value) {
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++) mp[parent[i]].push_back(i);
        
        return dfs(mp,0,value).first;
    }
};
