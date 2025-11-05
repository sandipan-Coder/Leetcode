class Solution {
    long long sum;
    set<pair<int, int>> main;
    set<pair<int, int>> secondary;
private:

    void insertAtSet(const pair<int, int> &node, int x){

        if(main.size() < x || node > *main.begin()){

            sum += (1LL * node.first * node.second);
            main.insert(node);

            if(main.size() > x){

                auto smallest = *main.begin();
                sum -= (1LL * smallest.first * smallest.second);
                main.erase(smallest);
                secondary.insert(smallest);
            }
        }
        else
            secondary.insert(node); 
    }

    void removeFromSet(const pair<int, int>& node, int x){

        if(main.count(node)){

            sum -= (1LL * node.first * node.second);
            main.erase(node);

            if((main.size() < x) && (secondary.size() != 0)){

                auto largest = *secondary.rbegin();;
                sum += (1LL * largest.first * largest.second);
                main.insert(largest);
                secondary.erase(largest);
            }
        }
        else
            secondary.erase(node);
    }

public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        
        sum = 0;
        main.clear();
        secondary.clear();
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<long long> ans;

        int i = 0;
        int j = 0;

        while(j < n){

            if(mp.count(nums[j]))
                removeFromSet({mp[nums[j]], nums[j]}, x);
            
            mp[nums[j]]++;
            insertAtSet({mp[nums[j]], nums[j]}, x);
            
            if(j - i + 1 == k){
                ans.push_back(sum);

                removeFromSet({mp[nums[i]], nums[i]}, x);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                else
                   insertAtSet({mp[nums[i]], nums[i]}, x); 
                
                i++;
            }

            j++;
        }

        return ans;
    }
};