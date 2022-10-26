Question Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/


// Approach :    
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size(), i;
        
        vector<int> ans;
        for(i=0;i<n;i++){
            int idx = abs(nums[i])-1;
            if(nums[idx]>0){
                nums[idx]*=-1;
            }
        }
        for(i=0;i<n;i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
