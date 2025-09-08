class Solution {
private:

    bool No_Zero(int a, int b){

        string str1 = to_string(a);
        string str2 = to_string(b);
        int i = 0;

        while(i < str1.size()){
            if(str1[i] == '0')
                return false;
            i++;
        }
         
        i = 0;
        while(i < str2.size()){
            if(str2[i] == '0')
                return false;
            i++;
        }

        return true;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        
        vector<int> ans(2);
        for(int i = 1; i <= n; i++){
            
            int a = i;
            int b = n - i;
            if(No_Zero(a, b)){
                ans[0] = a;
                ans[1] = b;
            }
        }

        return ans;
    }
};