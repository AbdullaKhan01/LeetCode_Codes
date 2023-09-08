class Solution {
public:
    int mod(int x){
        return x%1337;
    }
    int solve(int x,int n){
        if(n==0) return 1;
        int ans = solve(ans,n/2);
        if(n%2==0) return mod(mod(ans)*mod(ans));
        return (mod(mod(mod(x)*mod(ans))*mod(ans)));
    }
    int superPow(int a, vector<int>& b) {
        if(a==1) return 1;
        vector<int> dp(10,0);
        int ans=1;
        int powerFactor = a;
        for(int i=b.size()-1;i>=0;i--){
            int power = b[i];
            ans = mod(ans)*mod(solve(powerFactor,power));
            powerFactor = mod(solve(powerFactor,10));
        }
        return mod(ans); 
    }
};
