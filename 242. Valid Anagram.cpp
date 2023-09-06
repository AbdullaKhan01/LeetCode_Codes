class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        int s1[26]={0},m[26]={0};
        for(int i=0;i<s.length();i++){
            int a1 = s[i]-'a';
            int a2 = t[i]-'a';
            s1[a1]++;
            m[a2]++;
        }
        for(int i=0;i<26;i++){
            if(s1[i]!=m[i]){
                return false;
            }
        }
        return true;
    }
};
