class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        // int users = languages.size();
        // map<int, unordered_set<int>> mp;  // This store (User -> known languages)

        // // This store one User is known by how many languages.
        // for(int i = 0; i < users; i++){
        //     for(int j = 0; j < languages[i].size(); j++)
        //         mp[i + 1].insert(languages[i][j]);  
        // }

        unordered_set<int> st;
        for(int i = 0; i < friendships.size(); i++){
            int user1 = friendships[i][0];
            int user2 = friendships[i][1];
            bool flag = false;

            for(int j = 0; j < languages[user1 - 1].size(); j++){
                
                int lang = languages[user1 - 1][j];
                int cnt = count(languages[user2 - 1].begin(), languages[user2 - 1].end(), lang);
                if(cnt > 0){
                    flag = true;
                    break;
                }     
            }

            if(!flag){
                st.insert(user1);
                st.insert(user2);
            } 
        }

        unordered_map<int, int> mp;
        for(auto it: st){
            for(int i = 0; i < languages[it - 1].size(); i++)
                mp[languages[it - 1][i]]++;
        }

        int count = 0;
        for(auto it: mp){
            int noOfKnownPeople = it.second;
            count = max(count, noOfKnownPeople);
        }

        int unfriend = st.size();

        return unfriend - count;
    }
};