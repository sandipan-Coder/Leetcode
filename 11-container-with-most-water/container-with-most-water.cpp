class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int ans = INT_MIN;
        int i = 0;
        int j = n-1;

        while(i < j) {
            
            int length = min(height[i], height[j]);
            int width = (j - i);
            int area = (1LL * length * width);

            ans = max(ans, area);

            if(height[i] < height[j])
                i++;
            else
                j--;
        }

        return ans;
    }
};