class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,bool> m1,m2;
       vector<vector<int>>ans;
       for(int i=0;i<nums2.size();i++)
                m2[nums2[i]]=true;
        vector<int> temp;
        for(int i=0;i<nums1.size();i++)
        {
            int x = nums1[i];
            m1[x]=true;
            if(m2.find(x) == m2.end()){
                m2[x]=true;
                temp.push_back(x);
                }
        }
        ans.push_back(temp);
        temp.clear();
        for(int i=0;i<nums2.size();i++){
            int x = nums2[i];
            if(m1.find(x) == m1.end()){  
                m1[x] = true;
                temp.push_back(x);
                
                }
        }
        ans.push_back(temp);
        return ans;
    }
};
