class Solution {
public:
    int maximumSwap(int num) {
        
        string str = to_string(num);
        int n = str.length();
        vector<int> last(10, -1);

        for(int i = 0; i < n; i++)
            last[str[i] - '0'] = i;
        
        for(int i = 0; i < n; i++){

            int curr = str[i] - '0';
            for(int d = 9; d > curr; d--){

                if(last[d] > i){
                    swap(str[i], str[last[d]]);
                    return stoi(str);
                }
            }
        }

        return num;
    }
};