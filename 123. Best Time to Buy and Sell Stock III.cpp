//TC O(N * 2 * 3) -> O(N)
//SC O(N * 2 * 3 ) -> O(N) for SolveTab 
//SC O(1) for SolveTabSO
class Solution {
public:
    int solve(int index,int buyCost,vector<int>&prices,int limit){
        //base case
        if(index == prices.size())
            return 0;
        if(limit == 0)
            return 0;
        int op1=0;
        int op2 = 0;
        int op3 = 0;
        int op4 = 0;
        if(buyCost == 0)
        {   
            //sell
            op1 = prices[index] + solve(index+1,1,prices,limit-1);
            //not sell
            op2 = solve(index+1,0,prices,limit);
        }
        else
        {
            //include
            op3 = -prices[index]+solve(index+1,0,prices,limit);
            //exclude 
            op4 = solve(index+1,1,prices,limit);
        }
        return max(op1,max(op2,max(op3,op4)));
    }
    int solveMem(int index,int buyCost,vector<int>&prices,int limit,
        vector<vector<vector<int>>>&dp){
        //base case
        if(index == prices.size())
            return 0;
        if(limit == 0)
            return 0;
        if(dp[index][buyCost][limit]!=-1)
            return dp[index][buyCost][limit];
        int op1=0;
        int op2 = 0;
        int op3 = 0;
        int op4 = 0;
        if(buyCost == 0)
        {   
            //sell
            op1 = prices[index] + solveMem(index+1,1,prices,limit-1,dp);
            //not sell
            op2 = solveMem(index+1,0,prices,limit,dp);
        }
        else
        {
            //include
            op3 = -prices[index]+solveMem(index+1,0,prices,limit,dp);
            //exclude 
            op4 = solveMem(index+1,1,prices,limit,dp);
        }
        return dp[index][buyCost][limit]=max(op1,max(op2,max(op3,op4)));
    }
    int solveTab(vector<int>&prices){
        //step 1:create dp array
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        //step 2: analyse base case and fill dp array
        //done
        //step 3: Go from Bottom to Up using for loop and calculate answer
        for(int index = n-1;index>=0;index--)
        {
            for(int buyCost = 0;buyCost<=1;buyCost++)
            {
                for(int limit = 1;limit<=2;limit++)
                {
                    int op1=0;
                    int op2 = 0;
                    int op3 = 0;
                    int op4 = 0;
                    if(buyCost == 0)
                    {   
                        //sell
                        op1 = prices[index] + dp[index+1][1][limit-1];
                        //not sell
                        op2 = dp[index+1][0][limit];
                    }
                    else
                    {
                        //include
                        op3 = -prices[index]+dp[index+1][0][limit];
                        //exclude 
                        op4 = dp[index+1][1][limit];
                    }
                    dp[index][buyCost][limit]=max(op1,max(op2,max(op3,op4)));
                }

            }
        }
        return dp[0][1][2]; 
    }
    int solveTabSO(vector<int>&prices){
        //step 1:create dp array
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2,vector<int>(3,0));
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        //step 2: analyse base case and fill dp array
        //done
        //step 3: Go from Bottom to Up using for loop and calculate answer
        for(int index = n-1;index>=0;index--)
        {
            for(int buyCost = 0;buyCost<=1;buyCost++)
            {
                for(int limit = 1;limit<=2;limit++)
                {
                    int op1=0;
                    int op2 = 0;
                    int op3 = 0;
                    int op4 = 0;
                    if(buyCost == 0)
                    {   
                        //sell
                        op1 = prices[index] + next[1][limit-1];
                        //not sell
                        op2 = next[0][limit];
                    }
                    else
                    {
                        //include
                        op3 = -prices[index]+next[0][limit];
                        //exclude 
                        op4 = next[1][limit];
                    }
                    curr[buyCost][limit]=max(op1,max(op2,max(op3,op4)));
                }
                
            }
            next = curr;
        }
        return next[1][2]; 
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // return solve(0,1,prices,2);
        // return solveMem(0,1,prices,2,dp);
        // return solveTab(prices);
        return solveTabSO(prices);
    }
};
