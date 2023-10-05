// TC -> O(N)
// SC -> O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ans1=INT_MIN;
        int ans2=INT_MIN;
        int count1=0;
        int count2=0;
        int l=nums.size()/3;
        for(int i=0;i<nums.size();i++){

            int e = nums[i];
            if(ans1==e){
                count1++;
            }
            else if(ans2 == e){
                count2++;
            }
            else if(count1==0){
                ans1 = e;
                count1++;
            }
            else if(count2==0){
                ans2 = e;
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        int a=0,b=0;
        for(int i=0;i<nums.size();i++){
            a+=(nums[i]==ans1);
            b+=(nums[i]==ans2);
        }
        if(a>l && b>l)
            return {ans1,ans2};
        else if(a<=l && b>l)
            return {ans2};
        else if(b<=l && a>l)
            return {ans1};
        return {};
    }
};
