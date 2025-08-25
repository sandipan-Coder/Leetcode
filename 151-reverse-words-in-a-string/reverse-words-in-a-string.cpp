class Solution {
public:
    string reverseWords(string str) {
        
        int n = str.length();
        int left = 0;
        int right = n-1;

        while(left <= right && str[left] == ' ')
            left++;

        while(right >= left && str[right] == ' ')
            right--;

        string temp = "";
        string ans = "";

        while(left <= right){

            char ch = str[left];
            if(ch != ' ')
                temp += ch;
            else {
            // Only add word when temp is not empty
                if (!temp.empty()) {
                    if (!ans.empty())
                        ans = temp + " " + ans;
                    else
                        ans = temp;
                    temp = "";
                }
            }
            left++;
        }

        if(temp != ""){
            if(ans != "")
                ans = temp + " " + ans;
            else    
                ans = temp;
        }

        return ans;
    }
};