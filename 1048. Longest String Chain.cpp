class Solution {
public:
    static bool cmp(string &a,string &b){
        return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
        if(words.size() == 1)
            return 1;
        sort(words.begin(),words.end(),cmp);
        unordered_map<string,int> mp;
        int ans = 1;
        int maxi = 1;
        for(auto i:words){
            mp[i] = 1;
            for(int j=0;j<i.length();j++){
                string s = i.substr(0,j) + i.substr(j+1);
                if(mp.find(s) != mp.end()){
                    mp[i] = max(mp[i],mp[s]+1); 
                }
            maxi = max(maxi,mp[i]);
            }
        }
        return maxi;  
    }
};
