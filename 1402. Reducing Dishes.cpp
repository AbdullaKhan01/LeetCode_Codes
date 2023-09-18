//TC ->  O(N^2) SC -> O(N)
class Solution {
public:
    int solve(vector<int>&satisfaction,int index,int time,int n){
        //base case
        if(index>=n)
            return 0;
        
        //include
        int include = time*satisfaction[index] + solve(satisfaction,index+1,time+1,n);

        //exclude
        int exclude = solve(satisfaction,index+1,time,n);

        return max(include,exclude); 
    }
    int solveMem(vector<int>&satisfaction,int index,int time,int n,
        vector<vector<int>>&dp){
        if(index>=n)
            return 0;
        if(dp[index][time]!=-1){
            return dp[index][time];
        }
        //include
        int include = time*satisfaction[index] + solveMem(satisfaction,index+1,time+1,n,dp);

        //exclude
        int exclude = solveMem(satisfaction,index+1,time,n,dp);

        dp[index][time] = max(include,exclude);
        return dp[index][time];
    }
    // int solveTab(vector<int>&satisfaction){
        
    //     int n = satisfaction.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    //     for(int time=1;time<=n;time++){

    //         for(int index=0;index<n;index++){
    //             //include
    //             int include = time*satisfaction[index] + dp[index+1][time+1];

    //             //exclude
    //             int exclude = dp[index+1][time];

    //             dp[index][time] = max(include,exclude);
    //         }
    //     }
    //     return dp[n-1][n];
    // }.
    int solveTab(vector<int>&satisfaction){
        int n = satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int index=n-1;index>=0;index--){
            
            for(int time=index;time>=0;time--){
                //include
             int include = (time+1)*satisfaction[index] + dp[index+1][time+1];

            //exclude
                int exclude = dp[index+1][time];

                dp[index][time] = max(include,exclude);
            }
        }
        return dp[0][0];
    }
    int solveTabSPACEOPTIMIZED(vector<int>&satisfaction){
        int n = satisfaction.size();
        // vector<int> curr(n+1,0);
        vector<int> next(n+1,0);

        for(int index=n-1;index>=0;index--){
            
            for(int time=0;time<=index;time++){
                //include
             int include = (time+1)*satisfaction[index] + next[time+1];

            //exclude
                int exclude = next[time];

                next[time] = max(include,exclude);
            }
            // next = curr;
        }
        return next[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solve(satisfaction,0,1,n);
        // return solveMem(satisfaction,0,1,n,dp);
        // return solveTab(satisfaction);
        return solveTabSPACEOPTIMIZED(satisfaction);
    }
};
