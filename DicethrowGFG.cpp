class Solution{
public:
    long long solve(int dice,int faces,int target){
        //base case
        if(target < 0){
            return 0;
        }
        if(dice !=0 && target==0){
            return 0;
        }
        if(dice == 0 && target !=0){
            return 0;
        }
        if(dice ==0 && target == 0){
            return 1;
        }
        long long ans = 0;
        for(int i=1;i<=faces;i++){
            ans = ans + solve(dice-1,faces,target-i);
        }
        return ans;
    }
    long long solveMem(int dice,int faces,int target,vector<vector<long long>>&dp){
        //base case
        if(target < 0){
            return 0;
        }
        if(dice !=0 && target==0){
            return 0;
        }
        if(dice == 0 && target !=0){
            return 0;
        }
        if(dice ==0 && target == 0){
            return 1;
        }
        if(dp[dice][target] != -1)
            return dp[dice][target];
        long long ans = 0;
        for(int i=1;i<=faces;i++){
            ans = ans + solveMem(dice-1,faces,target-i,dp);
        }
        return dp[dice][target]=ans;
    }
    long long solveTab(int d,int faces,int t){
        /*
        TC O(N*M*X)
        SC O(N*X)
        */
        //step 1:create dp array
        vector<vector<long long>>dp(d+1,vector<long long>(t+1,0));
        
        //step 2: analyse base case
        dp[0][0] = 1;
        
        //step 3: apply bottom up loop
        for(int dice = 1;dice<=d;dice++){
            for(int target = 1;target<=t ; target++){
                
                long long ans = 0;
                for(int i=1;i<=faces;i++){
                    if(target-i >=0  )
                        ans = ans + dp[dice-1][target-i];
                }
               dp[dice][target]=ans;
                
            }
        }
        return dp[d][t];
        
    }
    long long solveTabSO(int d,int faces,int t){
        
        /*
        TC O(N*M*X)
        SC O(X)
        */
        //step 1:create dp array
        // vector<vector<long long>>dp(d+1,vector<long long>(t+1,0));
        vector<long long> prev(t+1,0);
        vector<long long> curr(t+1,0);
        
        //step 2: analyse base case
        prev[0] = 1;
        
        //step 3: apply bottom up loop
        for(int dice = 1;dice<=d;dice++){
            for(int target = 1;target<=t ; target++){
                
                long long ans = 0;
                for(int i=1;i<=faces;i++){
                    if(target-i >=0  )
                        ans = ans + prev[target-i];
                }
               curr[target]=ans;
                
            }
            prev = curr;
        }
        return prev[t];
        
    }
    long long noOfWays(int M , int N , int X) {
        // code here
        // return solve(N,M,X);
        // vector<vector<long long>>dp(N+1,vector<long long>(X+1,-1));
        // return solveMem(N,M,X,dp);
        // return solveTab(N,M,X);
        return solveTabSO(N,M,X);
    }
};
