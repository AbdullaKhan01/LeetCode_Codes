class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<int> ans;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans.push_back(grid[i][j]);
            }
        }
        int k = grid[0].size();
        int n = ans.size();
        vector<vector<int>>finalAns;
        vector<int> pref(n);
        pref[0] = 1;
        vector<int> suff(n);
        suff[n-1] = 1;
        for(int i=1;i<ans.size();i++){
            pref[i] = ((ans[i-1])%12345 * (pref[i-1])%12345)%12345;
        }
        for(int i=n-2;i>=0;i--){
            suff[i] = ((ans[i+1])%12345 * (suff[i+1])%12345)%12345;
        }
        // for(int i=0;i<n;i++){
        //     cout << pref[i] << " ";
        // }
        // cout << endl;
        vector<int>temp;
        for(int i=0;i<n;i++){
            int element = ((pref[i])%12345 * (suff[i])%12345)%12345;
            temp.push_back(element);
            if(temp.size()==k){
                finalAns.push_back(temp);
                temp.clear();
            }
        }
        return finalAns;
    }
};
