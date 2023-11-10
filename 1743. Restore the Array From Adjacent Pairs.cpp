// static auto speed=[](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     return NULL;
// };
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>adj;
        int l;
        for(auto i:adjacentPairs){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        for(auto i:adj){
            if(i.second.size()==1){
                l = i.first;
                break;
            }
        }
        vector<int> ans;
        ans.push_back(l);
        int node = adj[l][0];
        while(adj[node].size()!=1){
            ans.push_back(node);
            if(adj[node][0]==l){ 
            l=node;
            node = adj[node][1];
            }
            else{
                l=node;
                node = adj[node][0];   
            }
        }
        ans.push_back(node);
        return ans;
    }
};
