class Solution {
    const int MOD = 1e9 + 7;
    # define ll long long

private:

    ll kadaneMaxSubArrSum(vector<int>& arr) {

        int n = arr.size();
        ll currSum = arr[0];
        ll maxSoFar = arr[0];

        for(int i = 1; i < n; i++) {

            currSum = max((ll)arr[i] , currSum + arr[i]);
            maxSoFar = max(maxSoFar, currSum);
        }

        return maxSoFar;
    }

public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        if(k == 1) 
            return max(0LL , kadaneMaxSubArrSum(arr)) % MOD;

        int n = arr.size();

        ll totalSum = 0;
        for(int ele: arr)
            totalSum += ele;
        
        vector<int> twice(2 * n);
        for(int i = 0; i < 2*n; i++)
            twice[i] = arr[i % n];
        
        ll kadaneTwo = kadaneMaxSubArrSum(twice);
        ll ans;

        if(totalSum > 0)
            ans = kadaneTwo + ((ll)(k - 2) * totalSum);
        else
            ans = kadaneTwo;

        return max(0LL, ans % MOD);
    }
};