class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0)
            return ans;
        int s = nums[0];
        int e = nums[0];
        if(nums.size()==1){
            ans.push_back(to_string(s));
            return ans;
        }
        for(int i=1;i<nums.size();i++){
            int element = nums[i];
            if(element != e+1){
                if(e-s >= 1){
                    string temp = to_string(s) + "->" + to_string(e);
                    ans.push_back(temp);
                }
                else{
                    ans.push_back(to_string(s));
                }
                s = element;
                e = element;
            }
            else{
                e = element;
            }
        }
        if(s==e)
            ans.push_back(to_string(s));
        else{
            ans.push_back((to_string(s)+"->"+to_string(e)));
        }
        return ans;
    }
};
