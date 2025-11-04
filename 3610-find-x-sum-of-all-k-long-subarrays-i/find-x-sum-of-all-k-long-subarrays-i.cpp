class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> ans;

        int idx = 0;

        while(idx < k){
            int ele = nums[idx];
            mp[ele]++;
            idx++;
        }

        for(auto it: mp){
            pq.push({it.second, it.first});
            if(pq.size() > x)
                pq.pop();
        }

        int sum = 0;
        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();
            int count = it.first;
            int ele = it.second;
            sum  += (count * ele);
        }
        ans.push_back(sum);

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