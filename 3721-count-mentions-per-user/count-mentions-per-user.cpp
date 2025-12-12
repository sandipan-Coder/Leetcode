class Solution {
    int n;
private:

    void updateOnlineUsers(vector<int> &mentions, int offlineStartTime[], 
        unordered_set<int> &offlineUsers, int &time){
        
        vector<int> toRemove;

        for(int i = 0; i < n; i++){
            if(offlineUsers.count(i)){
                int startTime = offlineStartTime[i];
                if(startTime + 60 <= time){
                    toRemove.push_back(i);
                    mentions[i]++;
                }
            } 
            else
                mentions[i]++;
        }

        for(int u : toRemove)
            offlineUsers.erase(u);
    }

    void updateallMentions(vector<int> &mentions, int count){

        for(int i = 0; i < n; i++)
            mentions[i] += count;
    }

public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        
        sort(events.begin(), events.end(), 
            [](const vector<string> &a, const vector<string> &b){
                if(stoi(a[1]) == stoi(b[1]))
                    return a[0] > b[0];
                
                return (stoi(a[1]) < stoi(b[1]));
            });
        
        n = numberOfUsers;
        vector<int> mentions(numberOfUsers, 0);
        int offlineStartTime[100] = {0};
        unordered_set<int> offlineUsers;
        int allcount = 0;

        for(auto &it: events){

            int time = stoi(it[1]);
            if(it[0] == "MESSAGE"){

                string users = it[2];
                if(users == "ALL")
                    allcount++;
                else if(users == "HERE")
                    updateOnlineUsers(mentions, offlineStartTime, offlineUsers, time);
                else {
                    stringstream ss(users);
                    string user;

                    while (ss >> user) {
                        
                        int idx = stoi(user.substr(2));
                        mentions[idx]++;
                    }
                }
            } else {

                int offUser = stoi(it[2]);
                offlineUsers.insert(offUser);
                offlineStartTime[offUser] = time;
            }
        }

        if(allcount)
            updateallMentions(mentions, allcount);
        
        return mentions;
    }
};