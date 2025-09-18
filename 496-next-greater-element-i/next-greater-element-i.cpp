class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> mp;
        stack<int> st;
        int n = nums2.size();
        int m = nums1.size();
        vector<int> ans(m, -1);

        for(int i = n-1; i >= 0; i--){

            while(!st.empty() && st.top() <= nums2[i])
                st.pop();

            if(!st.empty())
                mp[nums2[i]] = st.top();
            else
                mp[nums2[i]] = -1;
            
            st.push(nums2[i]);
        }

        for(int i = 0; i < m; i++)
            ans[i] = mp[nums1[i]];

        return ans;
    }

};