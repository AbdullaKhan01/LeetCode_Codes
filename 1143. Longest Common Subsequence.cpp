class Solution {
public:
    int solve(string &a,string &b,int i,int j){
        if(i>=a.length() || j>=b.length()){
            return 0;
        }
        if(a[i]==b[j]){
            return 1+solve(a,b,i+1,j+1);
        }
        else{
            return max(solve(a,b,i+1,j),solve(a,b,i,j+1));
        }
    }
    int solve2(string &a,string &b,int i,int j,vector<vector<int>>&dp){
        if(i>=a.length() || j>=b.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(a[i]==b[j]){
            return dp[i][j]=1+solve2(a,b,i+1,j+1,dp);
        }
        else{
            return dp[i][j]=max(solve2(a,b,i+1,j,dp),solve2(a,b,i,j+1,dp));
        }
    }
    int solveTab(string &a,string &b){
        int i=a.length();
        int j=b.length();
        vector<vector<int>>dp(i+1,vector<int>(j+1,0));
        for(int x=i-1;x>=0;x--){
            for(int y=j-1;y>=0;y--){
                
                if(a[x]==b[y]){
                        dp[x][y] = 1+dp[x+1][y+1];
                    }
                else{
                    dp[x][y]=max(dp[x+1][y],dp[x][y+1]);
                    }
            }
        }
        return dp[0][0];
    }
    int solveTabSO(string &a,string &b){
        int i=a.length();
        int j=b.length();
        vector<int> curr(j+1,0);
        vector<int> next(j+1,0);
        for(int x=i-1;x>=0;x--){
            for(int y=j-1;y>=0;y--){
                
                if(a[x]==b[y]){
                        curr[y] = 1+next[y+1];
                    }
                else{
                    curr[y]=max(next[y],curr[y+1]);
                    }
            }
            next = curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // int i=text1.length();
        // int j=text2.length();
        // vector<vector<int>>dp(i,vector<int>(j,-1));
        // return solve2(text1,text2,0,0,dp);
        // return solveTab(text1,text2);
        return solveTabSO(text1,text2);
    }
};
