class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int l = to_string(k).length();
        vector<int> ans;
        int carry = 0;
        int e = num.size()-1;
        while(l-- && e>=0){
            int digit = k%10;
            k=k/10;
            int sum = num[e] + digit + carry;
            ans.push_back(sum%10);
            carry=sum/10;
            e--;
        }
        while(e>=0){
            int sum = num[e] + carry;
            ans.push_back(sum%10);
            carry=sum/10;
            e--;
        }
        k+=carry;
        while(k!=0){
            ans.push_back(k%10);
            k/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
