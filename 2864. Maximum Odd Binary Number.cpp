class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int x = count(s.begin(),s.end(),'1');
        fill(s.begin(),s.end(),'0');
        int n = s.length();
        s[n-1] = '1';
        x--;
        int index = 0;
        while(x-- && index<n){
            s[index] = '1';
            index+=1;
        }
        return s;
    }
};
