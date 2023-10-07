//TC O(n*m*k)
//SC O(n*m*k)
class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int index,int currCost,int currMax,int n,int m,int k){
        //base case
        if(currCost > k) return 0;
        if(index == n) return currCost == k;

        //try all numbers from 1 to m;
        int ans = 0;
        for(int num1=1;num1<=m;num1++){
            if(num1>currMax)
                ans+=solve(index+1,currCost+1,num1,n,m,k);
            else
                ans += solve(index+1,currCost,currMax,n,m,k);
            ans%=MOD;
        }
        return ans;

    }
    int solveMem(int index,int currMax,int currCost,int n,int m,int k
        ,vector<vector<vector<int>>> &dp){
        //base case
        if(currCost > k) return 0;
        if(index == n) return currCost == k;
        if(dp[index][currMax][currCost] != -1)
            return dp[index][currMax][currCost];
        //try all numbers from 1 to m;
        int ans = 0;
        for(int num1=1;num1<=m;num1++){
            if(num1>currMax)
                ans+=solveMem(index+1 ,num1,currCost+1  , n , m , k , dp);
            else
                ans += solveMem( index+1,currMax,currCost,n, m, k, dp);
            ans%=MOD;
        }
        return dp[index][currMax][currCost]=ans;

    }
    int numOfArrays(int n, int m, int k) {
        // vector<vector<int>> dp(k+2,vector<int>(m+2,-1));
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        // return solve(0,0,-1,n,m,k);
        return solveMem(0,0,0,n,m,k,dp);

    }
};
