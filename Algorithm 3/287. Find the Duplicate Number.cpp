Question Link: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& v) {
       int n=v.size(); 
        
       int x=0, i;
        for(i=0;i<v.size();i++){
            x^=v[i];
            x^=(i+1);
        }
        
        int rmsb = x & (-x);
        int a=0, b=0;
        
        for(i=0;i<v.size();i++){
            if(v[i] & rmsb){
                a^=v[i];
            }else{
                b^=v[i];
            }
            
            if((i+1) & rmsb){
                a^=(i+1);
            }else{
                b^=(i+1);
            }
        }
        
        bool f1=false, f2=false;
        for(i=0;i<v.size();i++){
            if(a==v[i]){
                f1=true;
                break;
            }
            if(b==v[i]){
                f2=true;
                break;
            }
        }
        cout<<a<<","<<b;
        if(f1==true) return a;
        return b;
    }
};
