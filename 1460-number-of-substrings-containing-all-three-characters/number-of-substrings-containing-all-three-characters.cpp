class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.length();
        int count = 0;
        int left = 0;
        unordered_map<char, int>mpp;

        for(int right = 0; right < n; right++){

            mpp[s[right]]++;

            while(mpp.size() == 3){
                count += n - right;
                mpp[s[left]]--;

                if(mpp[s[left]] == 0)
                    mpp.erase(s[left]);
                left++;
            }

        }

        return count;
    }
};