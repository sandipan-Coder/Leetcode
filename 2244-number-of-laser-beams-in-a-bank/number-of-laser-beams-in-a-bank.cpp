class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int ans = 0;
        int prevCount = 0;
        
        for(string &str: bank){

            int countOfOne = 0;
            for(char &ch: str){
                if(ch == '1')
                    countOfOne++;
            }

            if(countOfOne){

                ans += (prevCount * countOfOne);
                prevCount = countOfOne;
            }  
        }
        
        return ans;
    }
};