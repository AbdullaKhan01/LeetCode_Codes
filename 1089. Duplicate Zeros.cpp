class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int s = arr.size();
        for(int i=0;i<s;i++){
            if(arr[i] == 0){
                arr.insert(arr.begin()+i,0);
                i++;
            }
        }
        while(arr.size()>s)
            arr.pop_back();
    } 
};
