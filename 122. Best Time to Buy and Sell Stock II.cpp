//TC O(N)
//SC O(1)
class Solution {
public:
    int solve(int index,int buyCost,vector<int>&prices,bool BorS){
        //base case
        if(index == prices.size())
            return 0;
        int ans = 0;
        int op1=0;
        int op2 = 0;
        int op3 = 0;
        int op4 = 0;
        if(BorS == false)
        {   
            //sell
            op1 = prices[index]-buyCost + solve(index+1,0,prices,1);
            //not sell
            op2 = solve(index+1,buyCost,prices,0);
        }
        else
        {
            //include
            op3 = solve(index+1,prices[index],prices,0);
            //exclude 
            op4 = solve(index+1,0,prices,1);
        }
        return max(op1,max(op2,max(op3,op4)));
    }
    int solveMem(int index,int buyCost,vector<int>&prices,vector<vector<int>>&dp){
        //base case
        if(index == prices.size())
            return 0;
        if(dp[index][buyCost]!=-1)
        {
            return dp[index][buyCost];
        }
        int op1=0;
        int op2 = 0;
        int op3 = 0;
        int op4 = 0;
        if(buyCost == 0)
        {   
            //sell
            op1 = prices[index] + solveMem(index+1,1,prices,dp);
            //not sell
            op2 = solveMem(index+1,0,prices,dp);
        }
        else
        {
            //include
            op3 = -prices[index]+solveMem(index+1,0,prices,dp);
            //exclude 
            op4 = solveMem(index+1,1,prices,dp);
        }
        return dp[index][buyCost]=max(op1,max(op2,max(op3,op4)));
    }
    int solveTab(vector<int>&prices){
        //step 1:create dp array
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        //step 2: analyse base case and fill dp array
        //done
        //step 3: Go from Bottom to Up using for loop and calculate answer
        for(int index = n-1;index>=0;index--)
        {
            for(int buyCost = 0;buyCost<=1;buyCost++)
            {
                int op1=0;
                int op2 = 0;
                int op3 = 0;
                int op4 = 0;
                if(buyCost == 0)
                {   
                    //sell
                    op1 = prices[index] + dp[index+1][1];
                    //not sell
                    op2 = dp[index+1][0];
                }
                else
                {
                    //include
                    op3 = -prices[index]+dp[index+1][0];
                    //exclude 
                    op4 = dp[index+1][1];
                }
                dp[index][buyCost]=max(op1,max(op2,max(op3,op4)));
                }
        }
        return dp[0][1]; 
    }
    int solveTabSO(vector<int>&prices){
        //step 1:create dp array
        int n = prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);
        // vector<vector<int>>dp(n+1,vector<int>(2,0));

        //step 2: analyse base case and fill dp array
        //done
        //step 3: Go from Bottom to Up using for loop and calculate answer
        for(int index = n-1;index>=0;index--)
        {
            for(int buyCost = 0;buyCost<=1;buyCost++)
            {
                int op1=0;
                int op2 = 0;
                int op3 = 0;
                int op4 = 0;
                if(buyCost == 0)
                {   
                    //sell
                    op1 = prices[index] + next[1];
                    //not sell
                    op2 = next[0];
                }
                else
                {
                    //include
                    op3 = -prices[index]+next[0];
                    //exclude 
                    op4 = next[1];
                }
                curr[buyCost]=max(op1,max(op2,max(op3,op4)));
                }
                next = curr;
        }
        return next[1]; 
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // int m = *max_element(prices.begin(),prices.end());
        // int m = -1;
        // for(auto i:prices)
        //     m = max(m,i);
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(2,-1)));
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // return solve(0,0,prices,1);
        // return solveMem(0,1,prices,dp);
        // return solveTab(prices);
        return solveTabSO(prices);
    }
};
