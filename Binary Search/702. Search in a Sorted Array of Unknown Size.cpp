Question Link: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/


// Approach 1:
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l=0, r=1;
        int outOfBound = (1<<31 - 1);
        while(l<=r){
            int m=l+(r-l)/2;
            if(reader.get(m)==outOfBound || reader.get(m)>target){
                r=m-1;
            }else if(reader.get(m)<target){
                l=m+1;
                r *= 2;
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
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l=0, r=1;
        while(reader.get(r)<target){
            l=r;
            r *= 2;
        }
        
        int outOfBound = (1<<31 - 1);
        while(l<=r){
            int m=l+(r-l)/2;
            if(reader.get(m)>target){
                r=m-1;
            }else if(reader.get(m)<target){
                l=m+1;
            }else{
                return m;
            }
        }
        return -1;
    }
};
