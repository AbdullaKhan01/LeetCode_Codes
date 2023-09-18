//TC O(3*3*n) = O(n) SC = O(1) of optimized Approach
class Solution {
public:
    int solve(vector<int> &obstacles,int currRow,int currLane){
        int n=obstacles.size()-1;
        if(currRow == n){
            return 0;
        }
        if(obstacles[currRow+1]!=currLane){
            return solve(obstacles,currRow+1,currLane);
        }
        else{
            int ans = 1e9;
            for(int i=1;i<=3;i++){
                if(obstacles[currRow]!=i && i!=currLane)
                    ans = min(ans,1+solve(obstacles,currRow,i));
            }
        return ans;
        }
    }
    int solveMem(vector<int> &obstacles,int currRow,int currLane,
        vector<vector<int>> &dp){
        int n=obstacles.size()-1;
        if(currRow == n){
            return 0;
        }
        if(dp[currRow][currLane]!=-1){
            return dp[currRow][currLane];
        }
        if(obstacles[currRow+1]!=currLane){
            return solveMem(obstacles,currRow+1,currLane,dp);
        }
        else{
            int ans = 1e9;
            for(int i=1;i<=3;i++){
                if(obstacles[currRow]!=i && i!=currLane)
                    ans = min(ans,1+solveMem(obstacles,currRow,i,dp));
            }
        dp[currRow][currLane] = ans;
        return dp[currRow][currLane];
        }
    }
    int solveTab(vector<int> &obstacles){
        int n = obstacles.size()-1;
        vector<vector<int>> dp(4,vector<int>(obstacles.size(),1e9));
        dp[0][n]=0;
        dp[1][n]=0;
        dp[2][n]=0;
        dp[3][n]=0;
        for(int currRow = n-1;currRow>=0;currRow--){
            for(int currLane=1;currLane<=3;currLane++){
                    
                    if(obstacles[currRow+1]!=currLane){

                    dp[currLane][currRow] = dp[currLane][currRow+1];
                    
                    }
                else{
                    int ans = 1e9;
                    for(int i=1;i<=3;i++){
                        if(obstacles[currRow]!=i && i!=currLane)
                            ans = min(ans,1+dp[i][currRow+1]);
                    }
                dp[currLane][currRow]=ans;
                }
            }
        }
        return min(dp[2][0],1+min(dp[1][0],dp[3][0]));

    }
    int solveTabSpaceOptimized(vector<int> &obstacles){
        int n = obstacles.size()-1;

        vector<int> curr(4,1e9);
        vector<int> next(4,1e9);
        next[0]=0;
        next[1]=0;
        next[2]=0;
        next[3]=0;
        for(int currRow = n-1;currRow>=0;currRow--){
            for(int currLane=1;currLane<=3;currLane++){
                    
                    if(obstacles[currRow+1]!=currLane){

                    curr[currLane]= next[currLane];
                    
                    }
                else{
                    int ans = 1e9;
                    for(int i=1;i<=3;i++){
                        if(obstacles[currRow]!=i && i!=currLane)
                            ans = min(ans,1+next[i]);
                    }
                curr[currLane]=ans;
                }
            }
            next = curr;
        }
        return min(next[2],1+min(next[1],next[3]));

    }
    int minSideJumps(vector<int>& obstacles) {
        // return solve(obstacles,0,2);
        int n = obstacles.size();
        // vector<vector<int>> dp(n,vector<int>(4,-1));
        // return solveMem(obstacles,0,2,dp);
        // return solveTab(obstacles);
        return solveTabSpaceOptimized(obstacles);
        
    }
};
