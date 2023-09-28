class Solution {
    void solve(vector<vector<int>>&matrix,vector<vector<int>>&visited,int row,int col,int maxR,int maxC){
        int element = matrix[row][col];
        if(element == 0 && visited[row][col]==0) {
            for(int i = 0; i < maxR; i++){
                if(matrix[i][col]==0 && visited[i][col]!=1)
                    visited[i][col]=0;
                else
                    visited[i][col]=1;
                matrix[i][col] = 0;
            }
            for(int i = 0; i < maxC; i++){
                if(matrix[row][i]==0 && visited[row][i]!=1)
                    visited[row][i]=0;
                else{
                    visited[row][i]=1;
                }
                matrix[row][i] = 0; 
            }
        }
        if(row == maxR-1 && col == maxC-1) return;
        else if(col == maxC-1){
            solve(matrix,visited,row+1,0,maxR,maxC);
        }

        else{
            solve(matrix,visited,row,col+1,maxR,maxC);
        }
    }
    public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        solve(matrix,visited,0,0,matrix.size(),matrix[0].size());
        for(auto i:visited){
            for(auto j:i){
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
