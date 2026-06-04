class Solution {
private:

    int countWave(int num) {

        string str = to_string(num);
        int len = str.length();

        if(len < 3)
            return 0;

        int waviness = 0;
        for(int i = 1; i < len-1; i++){

            if((str[i] > str[i - 1]) && (str[i] > str[i + 1]))
                waviness++;
            else if((str[i] < str[i - 1]) && (str[i] < str[i + 1]))
                waviness++;
        }

        return waviness;
    }

public:
    int totalWaviness(int num1, int num2) {
        
        int sum = 0;

        for(int i = num1; i <= num2; i++) {
            
            int count = countWave(i);
            sum += count;
        }

        return sum;
    }
};