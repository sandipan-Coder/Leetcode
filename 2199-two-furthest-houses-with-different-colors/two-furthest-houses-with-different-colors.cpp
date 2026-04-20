class Solution {
public:
    int maxDistance(vector<int>& colors) {

        int i = 0;
        int j = colors.size() - 1;
        int ans = -1;

        while(i < j){

            if(colors[i] != colors[j]){
                ans = max(ans, (j - i));
                break;
            }
            j--;
        }

        if(ans == -1)
            return -1;

        i = 0;
        j = colors.size() - 1;

        while(i < j){
            if(colors[i] != colors[j]){
                ans = max(ans, (j - i));
                break;
            }
            i++;
        }

        return ans;
    }
};