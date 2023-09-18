//Time Complexity ->  O(N * log N ) 
//Space Complexity -> O(N)
/*
Logic is just sort the array on the basis of their width or the first parameter and if the width are same then sort then in descreasing order of their height 
or second parameter then just find the LIS(Longest Increasing Subsequence) of the array of heights . 
*/
class Solution {
public:
static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
}
int LIS(vector<int> &arr,int n){
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i] > ans.back()){
            ans.push_back(arr[i]);
        }
        else{
            //find index of just bada element;
            int index = lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }
    return ans.size();
}
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp); 
        vector<int> arr;       
        for(int i=0;i<envelopes.size();i++){
            arr.push_back(envelopes[i][1]);
        }
        return LIS(arr,arr.size());
    }
};
