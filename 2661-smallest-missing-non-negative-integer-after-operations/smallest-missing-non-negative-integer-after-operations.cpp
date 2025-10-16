class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        
        int n = nums.size();
        int x;
        int res = 0;
		vector<int> rem(value, 0);

		for (int ele: nums) {
			x = ((ele % value) + value) % value;
			rem[x]++;
		}

		while (rem[res % value]--) 
            res++;

		return res;
    }
};