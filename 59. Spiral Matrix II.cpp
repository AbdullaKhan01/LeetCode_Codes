class Solution {
public:
        void spiralOrder(vector<vector<int>>& matrix,int n) { 
        int row=n;
        int col=n;
        int count=1;
        int total=n*n;
        
        // index
        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;
        while(count<=total){

            //print starting row
            for(int index=startingCol; count<=total && index<=endingCol;index++){
                    matrix[startingRow][index]=count;
                    count++;
            }
            startingRow++;
            //print ending col
            for(int index=startingRow; count<=total && index<=endingRow;index++){
               matrix[index][endingCol]=count;
               count++; 
            }
            endingCol--;
            //print ending row
            for(int index=endingCol; count<=total && index>=startingCol;index--){
               matrix[endingRow][index]=count;
               count++; 
            }
            endingRow--;
            //print starting column
            for(int index=endingRow; count<=total && index>=startingRow;index--){
               matrix[index][startingCol]=count;
               count++; 
            }
            startingCol++;
        }     
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>dp(n,vector<int>(n,-1));
        spiralOrder(dp,n);
        return dp;
    }
};
