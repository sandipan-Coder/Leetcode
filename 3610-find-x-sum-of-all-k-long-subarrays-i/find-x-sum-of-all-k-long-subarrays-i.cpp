class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> ans;
        int idx = 0;

        // Store first K elements frequency in the map
        while(idx < k){
            int ele = nums[idx];
            mp[ele]++;
            idx++;
        }

        // Store first K elements frequency and element itself in the priority_queue
        for(auto it: mp){
            pq.push({it.second, it.first});
            if(pq.size() > x)
                pq.pop();
        }

        // Calculate the first k elements X-Sum
        int sum = 0;
        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();
            int count = it.first;
            int ele = it.second;
            sum  += (count * ele);
        }
        ans.push_back(sum);

        // Using Sliding window technique solve later part of the array
        while(idx < n){
            int ele = nums[idx];
            mp[ele]++;
            int remove = nums[idx - k];
            mp[remove]--;

            if(mp[remove] == 0)
                mp.erase(remove);

            for(auto it: mp){
                pq.push({it.second, it.first});
                if(pq.size() > x)
                    pq.pop();
            }

            sum = 0;
            while(!pq.empty()){

                auto it = pq.top();
                pq.pop();
                int count = it.first;
                int ele = it.second;
                sum  += (count * ele);
            }

            ans.push_back(sum);
            idx++;
        }

        return ans;
    }
};