class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int l = nums[0];
        int s;
        int ans = 0;
        for(int i=1;i<nums.size();i++){
            if(l<nums[i]){
                ans = i;
                s = l;
                l = nums[i];
            }
            else{
                s=nums[i];
            }
            if(l<2*s){
                ans = -1;
            }
        }
        return ans;
    }
};
