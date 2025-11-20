class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        int nonEqual = 0;
        int n = s1.length();
        vector<int> str1(26, 0);
        vector<int> str2(26, 0);

        for(int i = 0; i < n; i++){

            if(s1[i] != s2[i])
                nonEqual++;

            str1[s1[i] - 'a']++;
            str2[s2[i] - 'a']++;
        }

        return ((str1 == str2) && (nonEqual == 0 || nonEqual == 2));
    }
};