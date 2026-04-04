class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        
        int n = encodedText.length();
        int cols = (n / rows);
        string ans;

        for(int j = 0; j < cols; j++) {

            int r = 0;
            int c = j;

            while(r < rows && c < cols) {

                int idx = (r * cols + c);
                ans.push_back(encodedText[idx]);
                r++;
                c++;
            }
        }

        while(!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};