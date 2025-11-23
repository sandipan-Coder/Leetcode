class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        
        int sum = 0;
        vector<int> reminder1;
        vector<int> reminder2;

        for(int num: nums){

            sum += num;
            
            if(num % 3 == 1)
                reminder1.push_back(num);
            else if(num % 3 == 2)
                reminder2.push_back(num);
        }

        if(sum % 3 == 0)
            return sum;
        
        sort(begin(reminder1), end(reminder1));
        sort(begin(reminder2), end(reminder2));

        int result = 0;
        int reminder = sum % 3;

        if(reminder == 1){

            int remove1 = (reminder1.size() >= 1) ? reminder1[0] : INT_MAX;
            int remove2 = (reminder2.size() >= 2) ? reminder2[0] + reminder2[1] : INT_MAX;

            result = sum - min(remove1, remove2);
        }
        else {

            int remove1 = (reminder2.size() >= 1) ? reminder2[0] : INT_MAX;
            int remove2 = (reminder1.size() >= 2) ? reminder1[0] + reminder1[1] : INT_MAX;

            result = sum - min(remove1, remove2);
        }

        return result;
    }
};