class Row{
    public:
    int oneCount;
    int zeroCount;
    int index;
    Row(){

    }
};
struct row_cmp{
    bool operator()(Row* a,Row* b){
        if(a->oneCount==b->oneCount)
            return a->index>b->index;
        return a->oneCount>b->oneCount;
    }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        priority_queue<Row*,vector<Row*>,row_cmp> pq;
        int index = 0;
        for(auto i:mat){
            int one=0;
            int zero=0;
            for(auto j:i){
                if(j==1)
                    one++;
                else zero++;
            }
            Row* s = new Row();
            s->oneCount=one;
            s->zeroCount=zero;
            s->index=index;
            pq.push(s);
            index++;
        }
        while(!pq.empty() && k--){
        Row* top = pq.top();
        pq.pop();
        ans.push_back(top->index);
        }
        return ans;
    }
};
