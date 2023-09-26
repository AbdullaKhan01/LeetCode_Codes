#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        bool ans=false;
        int k;cin >> k;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin >> arr[i];
            ans |= arr[i] == k;
        }
        cout << (ans?"YES":"NO") << endl;
    }
}
