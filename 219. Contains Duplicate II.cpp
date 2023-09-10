class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
       for(int i=0;i<nums.size();i++){
           int element = nums[i];
           if(mp.find(element) == mp.end()){
               mp[element] = i;
           }
           else{
               if(abs(i-mp[element])<=k)
                    return true;
                mp[element] = i;
           }
       }
       return false; 
    }
};
