class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        // vector<int> securityDevices;
        int ans = 0;
        int prevCount = 0;
        
        for(string &str: bank){

            int countOfOne = 0;
            for(char &ch: str){
                if(ch == '1')
                    countOfOne++;
            }

            ans += (prevCount * countOfOne);

            if(countOfOne)
                prevCount = countOfOne;
        }

        // if(securityDevices.size() == 0 || securityDevices.size() == 1)
        //     return 0;
        
        // for(int i = 1; i < securityDevices.size(); i++)
        //     ans += (securityDevices[i] * securityDevices[i - 1]);
        
        return ans;
    }
};