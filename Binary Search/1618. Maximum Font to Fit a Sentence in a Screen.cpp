Question Link: https://leetcode.com/problems/maximum-font-to-fit-a-sentence-in-a-screen/


// Approach :

/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *     
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
 
class Solution {
public:
    
    bool possible(int w, int h, int fontSize, vector<int> &freq, vector<int>& fonts, FontInfo fontInfo){
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                char ch=(char)(i+'a');
                int curWidth=freq[i]*fontInfo.getWidth(fontSize,ch);
                w -= curWidth;
            }
        }
        return (w>=0);
    }
    
    int maxFont(string s, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++) freq[s[i]-'a']++;
        
        int l=0, r=fonts.size()-1;
        while(l<r){
            int m=l+(r-l+1)/2;
            
            if(fontInfo.getHeight(fonts[m])<=h && possible(w,h,fonts[m],freq,fonts,fontInfo)){
                l=m;
            }else{
                r=m-1;
            }
        }
        bool check = (fontInfo.getHeight(fonts[l])<=h && possible(w,h,fonts[l],freq,fonts,fontInfo));
        return (check ? fonts[l]:-1);
    }
};
