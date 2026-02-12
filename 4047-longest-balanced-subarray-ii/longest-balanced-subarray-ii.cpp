class Solution {

    vector<int> segMin, segMax, lazy;
    int n;

private:

    void propagate(int i, int l, int r) {
        if (lazy[i] != 0) {
            segMin[i] += lazy[i];
            segMax[i] += lazy[i];

            if (l != r) {
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }

    // Range add val to [start, end]
    void updateRange(int start, int end, int i, int l, int r, int val) {
        propagate(i, l, r); //make sure to propagate before hand

        if (l > end || r < start) return;

        //[start...end[ is fully inside range of current node [l..r]
        if (l >= start && r <= end) {
            lazy[i] += val;
            propagate(i, l, r);
            return;
        }

        int mid = (l + r) / 2;
        updateRange(start, end, 2*i+1, l, mid, val);
        updateRange(start, end, 2*i+2, mid+1, r, val);

        segMin[i] = min(segMin[2*i+1], segMin[2*i+2]);
        segMax[i] = max(segMax[2*i+1], segMax[2*i+2]);
    }

    int findLeftMostZero(int i, int l, int r) {
        propagate(i, l, r);

        if(segMin[i] > 0 || segMax[i] < 0) {
            return -1;
        }

        if(l == r) {
            return l;
        }

        int mid = l + (r-l)/2;
        int leftResult = findLeftMostZero(2*i+1, l, mid);
        if(leftResult != -1)
            return leftResult;
        
        return findLeftMostZero(2*i+2, mid+1, r);
    }


public:

    // *************************  //Approach-1 (Brute Force) - TLE *******************
    //T.C : O(n^2)
    //S.C : O(n)
    /*
    int longestBalanced(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> cumSum(n, 0);
        int maxLen = 0;

        // For even = +1, odd = -1.
        for(int i = 0; i < n; i++) {

            int val = (nums[i] % 2) ? -1 : 1;

            int prevIdx = -1;
            // We will try to find if the current element is previously seen or not.
            if(mp.count(nums[i]))  
                prevIdx = mp[nums[i]];
            

            // If we seen the element before then .......
            // [0 .... prevIdx] add (-val).
            if(prevIdx != -1) {
                for(int j = 0; j <= prevIdx; j++) // Renge Query Update -> Segment Tree log(n).
                    cumSum[j] -= val;
            }

            // [0 .... i] add (+val).
            for(int j = 0; j <= i; j++) // Renge Query Update -> Segment Tree log(n).
                cumSum[j] += val;

            
            // Try to find leftmost 0 of the cumulative sum array.
            for(int j = 0; j <= i; j++) {
                if(cumSum[j] == 0) {  // Renge Search -> Segment Tree log(n).
                    maxLen = max(maxLen, (i - j + 1));
                    break;
                }
            }

            mp[nums[i]] = i;
        }

        return maxLen;
    }

    */

    //******************** Approach - 2 (Using Segment Tree RMin Max Query ************
    //T.C : O(nlogn)
    //S.C : O(n)    

    int longestBalanced(vector<int>& nums) {
        
        n = nums.size();
        segMin.assign(4*n, 0);
        segMax.assign(4*n, 0);
        lazy.assign(4*n, 0);

        unordered_map<int, int> mp;
        int maxLen = 0;

        // For even = +1, odd = -1.
        for(int i = 0; i < n; i++) {

            int val = (nums[i] % 2) ? -1 : 1;

            int prevIdx = -1;
            // We will try to find if the current element is previously seen or not.
            if(mp.count(nums[i]))  
                prevIdx = mp[nums[i]];
            

            // If we seen the element before then .......
            // [0 .... prevIdx] add (-val).
            if(prevIdx != -1) {
                // Renge Query Update -> Segment Tree log(n).
                updateRange(0, prevIdx, 0, 0, n-1, -val);
            }

            // [0 .... i] add (+val).
            // Renge Query Update -> Segment Tree log(n).
            updateRange(0, i, 0, 0, n-1, val);    

            
            // Try to find leftmost 0 of the cumulative sum array.
            int l = findLeftMostZero(0, 0, n-1);
            if(l != -1)
                maxLen = max(maxLen, (i - l + 1));

            mp[nums[i]] = i;
        }

        return maxLen;
    }

};