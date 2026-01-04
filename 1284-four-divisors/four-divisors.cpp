class Solution {
private:

    int countSum(int num){

        int count = 0;
        int sum = (num + 1);

        for(int i = 2; i*i <= num; i++){
            if(num % i == 0){

                if(i * i == num)
                    return 0;
                
                count += 2;
                sum += i;
                sum += (num / i);
                // cout << i << (num / i) << endl;
            }
        }

        return (count == 2) ? sum : 0;
    }

public:
    int sumFourDivisors(vector<int>& nums) {
        
        int ans = 0;

        for(int num: nums){
            
            int sum = countSum(num);
            ans += sum;
        }
        
        return ans;
    }
};