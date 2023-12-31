//TC -> O(N)
//SC -> O(1)
//Using Floyd Cycle Detection Algorithm
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=0;
        int slow=0;
        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow){
                break;   
            }
        }
        slow = 0;
        while(slow!=fast){
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;      
    }
};
