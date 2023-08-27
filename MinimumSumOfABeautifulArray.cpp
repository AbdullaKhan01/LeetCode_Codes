class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        //base case
        if(target==2)
                return (n*(n+1))/2;
        int n2 = target - 1;
        int n1 = 1;
        long long sum = 0;
        int count =  0;
        while(n1 < n2 && count < n ){
            sum += n1;
            count++ ;
            n2 = target - n1;
            n1++;
        }
        int x = target;
        while(count<n){
            sum += x;
            x++;
            count++ ;
        }
        return sum;
    }
};
