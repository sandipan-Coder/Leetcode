class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        
        int MOD = 1e9 + 7;
        int i = 0;
        int j = 0;
        int n = nums1.size();
        int m = nums2.size();
        long long int sum1 = 0;
        long long int sum2 = 0;
        long long int ans = 0;
        
        while(i < n && j < m) {
            
            if(nums1[i] > nums2[j]) {
                sum2 += nums2[j];
                j++;
            }
            else if(nums1[i] < nums2[j]) {
                sum1 += nums1[i];
                i++;
            }
            else {
                ans = (ans + max(sum1, sum2)) % MOD;
                ans = (ans + nums1[i]) % MOD;
                i++;
                j++;
                sum1 = 0;
                sum2 = 0;
            }
        }
        
        while(i < n){
            sum1 += nums1[i];
            i++;
        }
        
        while(j < m){
            sum2 += nums2[j];
            j++;
        }
        
        ans = (ans + max(sum1, sum2)) % MOD;
        return (int)ans;
    }
};