class Solution {
    bitset<501> visited;
    int freq[501] = {0};
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // Step1 :- Store this friendships which have not any common language.
        // This set is store this friendships which have not any common language.
        unordered_set<int> st;
        for(int i = 0; i < friendships.size(); i++){
            int user1 = friendships[i][0];
            int user2 = friendships[i][1];
            // vector<bool> visited(n+1, false);
            visited.reset();

            // Store all languages that is known by user1;
            for(int j = 0; j < languages[user1 - 1].size(); j++){
                
                int lang = languages[user1 - 1][j];
                visited[lang] = 1;
            }

            // Check if user2 know any of the language of user1;
            bool flag = false;
            for(int j = 0; j < languages[user2 - 1].size(); j++){
                
                int lang = languages[user2 - 1][j];
                if(visited[lang]){
                    flag = true;
                    break;
                }
            }

            if(!flag){
                st.insert(user1);
                st.insert(user2);
            } 
        }

        if(st.size() == 0)
            return 0;

        // Step2 :- Store the frequencies of languages of this friendships which have not any common language.
        // vector<int> freq(n+1, 0);
        for(int it: st){
            for(int i = 0; i < languages[it - 1].size(); i++)
                freq[languages[it - 1][i]]++;
        }

        // Step3 :- Find the maximum frequency of language
        int count = 0;
        for(int ele: freq)
            count = max(count, ele);

        // Step4 :- Difference of No. of users who are friends but don't have any common language with maximum frequency language.
        int unCommon = st.size();
        return unCommon - count;
    }
};