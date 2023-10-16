//TIME COMPLEXITY -> O(rowIndex*rowIndex) 
//SPACE COMPLEXITY -> O(rowIndex)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1,1};
        vector<int> arr={1,1};
        // vector<int> temp={1};
        rowIndex-=1;
        while(rowIndex--){
            arr.push_back(1);
            for(int i=arr.size()-2;i>0;i--){
                arr[i] = arr[i-1]+arr[i];
            }
        }
        return arr;
    }
};
