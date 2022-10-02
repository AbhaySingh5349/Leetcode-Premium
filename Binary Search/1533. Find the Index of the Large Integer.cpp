Question Link: https://leetcode.com/problems/find-the-index-of-the-large-integer/


// Approach 1:

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int l=0, r=reader.length()-1;

        while(l<=r){
            int m=l+(r-l)/2;
            
            int lLen=m-l+1, rLen=r-m;
            int limit= (lLen > rLen ? m-1:m); // for equal length comparison 
            
            int val=reader.compareSub(l,max(limit,l),min(m+1,r),r);
            
            if(val==1){
                r=limit;
            }else if(val==-1){
                l=limit+1;
            }else{
                return m;
            }
        }
        return -1;
    }
};


// Approach 2:

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int l=0, r=reader.length()-1;

        while(l<r){
            int m=l+(r-l)/2;
            
            int lLen=m-l+1, rLen=r-m;
            int limit= (lLen > rLen ? m-1:m); // for equal length comparison 
            
            int val=reader.compareSub(l,max(limit,l),min(m+1,r),r);
            
            if(val==1){
                r=limit;
            }else if(val==-1){
                l=limit+1;
            }else{
                return m;
            }
        }
        return l;
    }
};
