class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1) return {{1}};
        if(numRows == 2) return {{1},{1,1}};
        vector<int> ans={1,1};
        vector<vector<int>>finalAns;
        finalAns.push_back({1});
        finalAns.push_back({1,1}); 
        for(int i=numRows-2;i>0;i--){
            vector<int> temp;
            temp.push_back(1);
            for(int i=1;i<ans.size();i++){
                temp.push_back(ans[i]+ans[i-1]);
            }
            temp.push_back(1);
            ans = temp;
            finalAns.push_back(temp);
        }
        return finalAns;
    }
};
