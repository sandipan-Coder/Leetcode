class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;
        int maxi = 0;
        
        while(left < right){
            int heigh = min(height[left],height[right]);
            int width = right - left;
            int area = heigh * width;
            maxi = max(area, maxi);

            if(height[left] < height[right])
                left++;
            else 
                right--;
        }

        return maxi;
    }
};