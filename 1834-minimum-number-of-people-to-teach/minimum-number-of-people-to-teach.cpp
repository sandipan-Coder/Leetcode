class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // Step1 :- Store this friendships which have not any common language.
        // This set is store this friendships which have not any common language.
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

        // Step2 :- Store the frequencies of languages of this friendships which have not any common language.
        unordered_map<int, int> mp;
        for(auto it: st){
            for(int i = 0; i < languages[it - 1].size(); i++)
                mp[languages[it - 1][i]]++;
        }

        // Step3 :- Find the maximum frequency of language
        int count = 0;
        for(auto it: mp){
            int noOfKnownPeople = it.second;
            count = max(count, noOfKnownPeople);
        }

        // Step4 :- Difference of No. of users who are friends but don't have any common language with maximum frequency language.
        int unCommon = st.size();
        return unCommon - count;
    }
};