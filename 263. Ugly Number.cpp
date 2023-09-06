class Solution {
public:
    bool solve(int n){
        //base case
        if(n==0||n==1)
            return n;
        if(n==2 || n==3 || n==5)
            return false;
        if(n%2!=0 && n%3!=0 && n%5 != 0){
            return true;
        }
        bool opt1 = solve(n/2);
        bool opt2 = solve(n/3);
        bool opt3 = solve(n/5);
        return opt1||opt2||opt3;
    }
    bool isUgly(int n) {
        if(n==0 || n==1)
            return n;
        return !solve(n);
    }
};
