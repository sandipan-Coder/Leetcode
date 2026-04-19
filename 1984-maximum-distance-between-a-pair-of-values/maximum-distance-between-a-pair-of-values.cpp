class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        int dist = 0;
        int i = 0, j = 0;

        while(i < n && j < m){

            if(nums1[i] <= nums2[j]) {
                while(j < m && (nums1[i] <= nums2[j]))
                    j++;
                
                int diff = (j - 1 - i);
                dist = max(dist, diff);
            }
            
            i++;
        }

        return dist;
    }
};