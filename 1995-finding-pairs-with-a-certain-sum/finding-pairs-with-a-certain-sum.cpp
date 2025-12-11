class FindSumPairs {

    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> mp;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        
        this->nums1 = nums1;
        this->nums2 = nums2;

        for(auto &num: nums2)
            mp[num]++;
    }
    
    void add(int index, int val) {
        
        mp[nums2[index]]--;
        nums2[index] += val;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        
        int pair = 0;

        for(auto ele: nums1)
            pair += mp[tot - ele];

        return pair;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */