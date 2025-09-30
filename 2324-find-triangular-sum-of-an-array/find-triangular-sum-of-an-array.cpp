class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        int n = nums.size();
        queue<int> qu;

        for(int ele: nums)
            qu.push(ele);

        while(qu.size() > 1){

            int n = qu.size();
            for(int i = 0; i < n-1; i++){

                int ele1 = qu.front();
                qu.pop();
                int ele2 = qu.front();

                int res = (ele1 + ele2) % 10;
                qu.push(res);
            }
            qu.pop();
        }

        int ans = qu.front();

        return ans;
    }
};