class Solution {
public:
    int solve(vector<int>& arr,map<pair<int,int>,int> &mp,int left,int right){
        if(left == right)
            return 0;
        int ans = INT_MAX;
        for(int i=left;i<right;i++){
            ans = min(ans,mp[{left,i}]*mp[{i+1,right}] + solve(arr,mp,left,i) + solve(arr,mp,i+1,right));
        }
        return ans;
    }
    int solveMem(vector<int>& arr,map<pair<int,int>,int> &mp,int left,int right,vector<vector<int>>&dp){
        if(left == right)
            return 0;
        if(dp[left][right]!=-1)
            return dp[left][right];
        int ans = INT_MAX;
        for(int i=left;i<right;i++){
            ans = min(ans,mp[{left,i}]*mp[{i+1,right}] + solveMem(arr,mp,left,i,dp) + 
            solveMem(arr,mp,i+1,right,dp));
        }
        return dp[left][right]=ans;
    }
    int solveTab(vector<int>& arr,map<pair<int,int>,int> &mp){
        
        int n =arr.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        

        int ans = INT_MAX;
        for(int left = n-1;left>=0;left--){
            for(int right =0;right<n;right++){
                if(left == right){
                    continue;
                }
                else{
                    int ans = INT_MAX;
                    for(int i=left;i<right;i++){
                    ans = min(ans,mp[{left,i}]*mp[{i+1,right}] + dp[left][i] + dp[i+1][right]);
                    }
                    dp[left][right]=ans;
                }
            }
        }
        return dp[0][n-1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> mp;
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            mp[{i,i}] = arr[i];
            for(int j=i+1;j<n;j++){
                mp[{i,j}] = max(arr[j],mp[{i,j-1}]);
            }
        }
        // for(auto i:mp){
        //     cout << "Range :" << i.first.first << " " << i.first.second << "ans : " << i.second <<endl;
        // }
        // return solve(arr,mp,0,n-1);
        // return solveMem(arr,mp,0,n-1,dp);
        return solveTab(arr,mp);

    }
};
