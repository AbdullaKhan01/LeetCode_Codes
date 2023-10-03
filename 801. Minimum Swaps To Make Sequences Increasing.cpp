//TC O(N)
//SC O(1)
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int index,bool swapped){
        if(index >= nums1.size()){
            return 0;
        }

        int ans = INT_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        //catch
        if(swapped){
            int temp = prev1;
            prev1 = prev2;
            prev2 = temp;
        }

        //noswap
        if(nums1[index]>prev1 && nums2[index]>prev2)
            ans = solve(nums1,nums2,index+1,0);

        //swap
        else if(nums1[index] > prev2 && nums2[index]> prev1)
            ans = min(ans,1 + solve(nums1,nums2,index+1,1));

        return ans;

    }
    int solveMem(vector<int>& nums1, vector<int>& nums2,int index,bool swapped,
        vector<vector<int>>&dp){
        if(index == nums1.size()){
            return 0;
        }
        //step 2:
        if(dp[index][swapped]!=-1){
            return dp[index][swapped];
        }
        

        int ans = INT_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        //catch
        if(swapped){
            swap(prev1,prev2);
        }

        //noswap
        if(nums1[index]>prev1 && nums2[index]>prev2)
            ans = solveMem(nums1,nums2,index+1,0,dp);

        //swap
        if(nums1[index] > prev2 && nums2[index]> prev1)
            ans = min(ans,1 + solveMem(nums1,nums2,index+1,1,dp));

        
        return dp[index][swapped]=ans;

    }
    int solveTab(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        //step1: create dp vector
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        //step2 : analyse base case and fill dp array
        //step3: solve by using loops
        for(int index=n-1;index>=1;index--){
            for(int swapped=1;swapped>=0;swapped--){

                int ans = INT_MAX;
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                //catch
                if(swapped){
                    int temp = prev1;
                    prev1=prev2;
                    prev2=temp;
                }

                //noswap
                if(nums1[index]>prev1 && nums2[index]>prev2)
                    ans = dp[index+1][0];

                //swap
                if(nums1[index] > prev2 && nums2[index]> prev1)
                    ans = min(ans,1 + dp[index+1][1]);
                
                dp[index][swapped]=ans;


            }
        }
        return dp[1][0];

    }
    int solveTabSO(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        //step1: create dp vector
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        int first=0;
        int second=0;

        int currF=0;
        int currS=0;
        //step2 : analyse base case and fill dp array
        //step3: solve by using loops
        for(int index=n-1;index>=1;index--){
            for(int swapped=1;swapped>=0;swapped--){

                int ans = INT_MAX;
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                //catch
                if(swapped){
                    int temp = prev1;
                    prev1=prev2;
                    prev2=temp;
                }

                //noswap
                if(nums1[index]>prev1 && nums2[index]>prev2)
                    ans = second;

                //swap
                if(nums1[index] > prev2 && nums2[index]> prev1)
                    ans = min(ans,1 + first);
                
                if(swapped){
                    currF=ans;
                }
                else{
                    currS=ans;
                }
            }
            first = currF;
            second = currS;
        }
        return min(first,second);

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // bool swapped = 0;
        int n = nums1.size();
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        //step 1:
        //create dp array
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // return solve(nums1,nums2,1,0);
        // return solveMem(nums1,nums2,1,0,dp);
        // return solveTab(nums1,nums2);
        return solveTabSO(nums1,nums2);
    }
};
