class RangeFreqQuery {
public:

    map<int, vector<int>> mp;

    RangeFreqQuery(vector<int>& arr) {
        
        for(int i = 0; i < arr.size(); i++)
            mp[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        
        if(mp.count(value) == 0)
            return 0;
        
        vector<int> &idx = mp[value];

        auto low = lower_bound(idx.begin(), idx.end(), left);
        auto high = upper_bound(idx.begin(), idx.end(), right);

        return (high - low);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */