Question Link: https://leetcode.com/problems/odd-even-jump/


// Approach 1:                                            
class Solution {
public:
    
    int rightSmallestGreaterEqual(int i, vector<int> &a){
        int n=a.size(), idx=-1;
        int val=INT_MAX;
        for(int j=n-1;j>i;j--){
            if(a[j]>=a[i] && a[j]<=val){
                val=a[j];
                idx=j;
            }
        }
        return idx;
    }
    
    int rightLargestSmallerEqual(int i, vector<int> &a){
        int n=a.size(), idx=-1;
        int val=-1;
        for(int j=n-1;j>i;j--){
            if(a[i]>=a[j] && a[j]>=val){
                val=a[j];
                idx=j;
            }
        }
        return idx;
    }
    
    int oddEvenJumps(vector<int> &a) {
        int n=a.size();
        
        int ans=1;
        for(int i=0;i<n-1;i++){
            int j=i;
            
            while(j<n){
            	// odd jump
                j=rightSmallestGreaterEqual(j,a);
                if(j==n-1){
                    ans++;
                    break;
                }else if(j==-1){
                    break;
                }
                
                // even jump
                j=rightLargestSmallerEqual(j,a);
                if(j==n-1){
                    ans++;
                    break;
                }else if(j==-1){
                    break;
                }
            }
        }
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    
    int rightSmallestGreaterEqual(map<int,int> &mp, int k){
        auto it=mp.lower_bound(k);
        if(it==mp.end()) return -1;
        
        return it->second;
    }
    
    int rightLargestSmallerEqual(map<int,int> &mp, int k){
        auto it=mp.lower_bound(k);
        if(it==mp.end() || it->first > k){
            if(it==mp.begin()) return -1;
            --it;
        }
        
        return (it->second);
    }
    
    int oddEvenJumps(vector<int> &a) {
        int n=a.size();
        
        int ans=1;
        
        map<int,int> mp;
        mp[a[n-1]]=n-1;
        
        vector<bool> odd(n,false), even(n,false);
        odd[n-1]=true, even[n-1]=true;
        
        for(int i=n-2;i>=0;i--){
            int rsg=rightSmallestGreaterEqual(mp,a[i]);
            int rls=rightLargestSmallerEqual(mp,a[i]);
            
            if(rsg!=-1) odd[i]=even[rsg];
            if(rls!=-1) even[i]=odd[rls];
            
            ans += odd[i];
            mp[a[i]]=i;
        }
        return ans; 
    }
};
