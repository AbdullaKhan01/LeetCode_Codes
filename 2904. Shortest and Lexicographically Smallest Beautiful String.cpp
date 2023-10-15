class Solution {
public:
    // int count(string &s){
    //     return count(s.begin(),s.end(),'1');
    // } 
    bool isTrue(string &a,string &b){
        for(int i=a.length()-1;i>=0;i--){
            if(a[i] == '1' && b[i] =='0'){
                return true;
            }
            else if(b[i] == '1' && a[i] == '0'){
                return false;
            }
        }
        return false;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int l;
        string x;
        string ans = "";
        for(int i=0;i<n;i++){
            for(int j=1;j<n-i+1;j++){
                x = s.substr(i,j);
                l = count(x.begin(),x.end(),'1');
                if(l==k){
                    if(ans==""){
                        ans = x;
                    }
                    else if(ans.length()>x.length()){
                        ans = x;
                    }
                    else if(ans.length()==x.length()){
                        // if(isTrue(x,ans)){
                        //     ans = x;
                        // }
                        if(ans.compare(x)>0){
                            ans = x;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
