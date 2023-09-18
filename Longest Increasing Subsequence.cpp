class Solution
{
    public:
    int solve(int a[],int n,int curr,int prev){
        if(curr == n){
            return 0;
        }
        
        //include
        int include = 0;
        if(prev == -1 || a[curr] > a[prev]){
            include = 1 + solve(a,n,curr+1,curr);
        }
        //exclude
        int exclude = 0 + solve(a,n,curr+1,prev);
        
        return max(include,exclude);
    }
    int solveMem(int *a,int n,int curr,int prev,vector<vector<int>> &dp){
        if(curr == n){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        //include
        int include = 0;
        if(prev == -1 || a[curr] > a[prev]){
            include = 1 + solveMem(a,n,curr+1,curr,dp);
        }
        //exclude
        int exclude = 0 + solveMem(a,n,curr+1,prev,dp);
        
        return dp[curr][prev+1] = max(include,exclude);
    }
    //Function to find length of longest increasing subsequence.
    int solveTab(int a[],int n){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //base case analysed;
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=n-1;prev>=-1;prev--){
                //include
                int include = 0;
                  if(prev == -1 || a[curr] > a[prev]){
                        include = 1 + dp[curr+1][curr+1];
                     }
                     //exclude
                    int exclude = 0 + dp[curr+1][prev+1];
        
                dp[curr][prev+1] = max(include,exclude); 
            }
        }
        return dp[0][0];
    }
    
    int solveTabSO(int a[],int n){
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        //base case analysed;
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=n-1;prev>=-1;prev--){
                //include
                int include = 0;
                  if(prev == -1 || a[curr] > a[prev]){
                        include = 1 + nextRow[curr+1];
                     }
                     //exclude
                    int exclude = 0 + nextRow[prev+1];
        
                currRow[prev+1] = max(include,exclude); 
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int solveOptimal(int a[],int n){
        if(n==0)
            return 0;
        vector<int> ans;
        ans.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i] > ans.back()){
                ans.push_back(a[i]);
            }
            else{
                //find index of just bada element;
                int index = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }
    int longestSubsequence(int n, int a[])
    {
        //   return solve(a,n,0,-1);
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solveMem(a,n,0,-1,dp);
        // return solveTab(a,n);
        // return solveTabSO(a,n);
        return solveOptimal(a,n);
    }
};
