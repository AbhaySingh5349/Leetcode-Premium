Question Link: https://leetcode.com/problems/leftmost-column-with-at-least-a-one/


// Approach 1:
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    
    int firstOne(BinaryMatrix &binaryMatrix, int row, int m){
        int i=0, j=m-1;
        int idx=m;
        while(i<=j){
            int mid=i+(j-i)/2;
            int val=binaryMatrix.get(row,mid);
            
            if(val==1){
                idx=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return idx;
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int n=binaryMatrix.dimensions()[0], m=binaryMatrix.dimensions()[1];
        
        int ans=m;
        
        for(int i=0;i<n;i++){
            int j=firstOne(binaryMatrix, i, m);
            ans=min(ans,j);
        }
        return (ans==m ? -1:ans);
    }
};


// Approach 2:
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int n=binaryMatrix.dimensions()[0], m=binaryMatrix.dimensions()[1];
        
        int ans=m;
        int i=0, j=m-1;
        
        while(i<n && j>=0){
            int val=binaryMatrix.get(i,j);
            
            if(val==1){
                ans=j;
                j--;
            }else{
                i++;
            }
        }
        return (ans==m ? -1:ans);
    }
};
