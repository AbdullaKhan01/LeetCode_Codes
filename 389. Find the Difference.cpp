class Solution {
public:
char findTheDifference(string s, string t) {
sort(s.rbegin(),s.rend());
sort(t.rbegin(),t.rend());
int index = t.length()-1;
int index2 = s.length()-1;
  while(index >=0 && index2 >=0){
    if(t[index] != s[index2])
        return t[index];
    index--;
    index2--;
  }
return t[0];     
}
};
