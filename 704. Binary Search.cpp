class Solution {
public:
    int solve(vector<int>&nums, int target){
        int s =0,e=nums.size()-1;
        int mid = e+(s-e)/2;
        while(s<=e){
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                e = mid-1;
            else s = mid+1;
            mid = e+(s-e)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return solve(nums,target);
    }
};
