class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 3)
            return -1;
        
        int ans = INT_MAX;
        
        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                for(int k = j+1; k < n; k++){
                    
                    if(nums[i] == nums[j] && nums[j] == nums[k]){
                        
                        int dis = abs(i - j) + abs(j - k) + abs(k - i);
                        ans = min(ans, dis);
                    }
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};