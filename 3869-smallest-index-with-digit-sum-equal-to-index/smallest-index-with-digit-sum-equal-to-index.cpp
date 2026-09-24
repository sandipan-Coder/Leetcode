class Solution {

private:

    int digitSum(int x){

        int num = x;
        int sum = 0;

        while(num){

            int rem = (num % 10);
            sum += rem;
            num /= 10;
        }

        return sum;
    }

public:
    int smallestIndex(vector<int>& nums) {
        
        int n = nums.size();

        for(int i = 0; i < n; i++){

            int sum = digitSum(nums[i]);
            if(sum == i)
                return i;
        }

        return -1;
    }
};