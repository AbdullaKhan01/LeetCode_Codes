class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &temp,int index) {
        if(target < 0){
            return ;
        }
        if(target == 0){
            ans.push_back(temp);
        }
        for(int i=index;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,temp,i);
            //backtraking;
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,ans,temp,0);
        return ans;
    }
};
