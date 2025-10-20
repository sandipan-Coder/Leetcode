class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {

        int val = 0;

        for(string str: operations){
            
            bool positive = false;
            bool negative = false;

            for(char ch: str){
                if(ch == '+'){
                    positive = true;
                    break;
                }

                if(ch == '-'){
                    negative = true;
                    break;
                }
            }

            if(positive)
                val = val + 1;
            else
                val = val - 1;
        }

        return val;
    }
};