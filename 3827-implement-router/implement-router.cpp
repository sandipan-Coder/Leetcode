class Router {
    unordered_map<int, set<pair<int, int>>> sourceToDestAndTime; // This store like :- source -> {destination, timestamp}
    queue<vector<int>> packets; // This will store {source, destination, timestamp}.
    unordered_map<int, vector<int>> destiToTime; // This will store like:- {destination -> vector{times}}.
    int maxSize = 0;
public:
    Router(int memoryLimit) {
        maxSize = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        
        if(sourceToDestAndTime[source].count({destination, timestamp}))
            return false;
        
        if(packets.size() == maxSize){
            vector<int> packet = packets.front();
            packets.pop();

            int sour = packet[0];
            int desti = packet[1];
            int time = packet[2];
            sourceToDestAndTime[sour].erase({desti, time});
            auto &vec = destiToTime[desti];
            auto it = lower_bound(vec.begin(), vec.end(), time);
            vec.erase(it);
        }

        packets.push({source, destination, timestamp});
        sourceToDestAndTime[source].insert({destination, timestamp});
        destiToTime[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        
        if(packets.size() == 0)
            return {};

        vector<int> packet = packets.front();
        packets.pop();

        int sour = packet[0];
        int desti = packet[1];
        int time = packet[2];
        sourceToDestAndTime[sour].erase({desti, time});
        auto &vec = destiToTime[desti];
        auto it = lower_bound(vec.begin(), vec.end(), time);
        vec.erase(it);

        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        
        if(!destiToTime.count(destination))
            return 0;

        auto &vec = destiToTime[destination];
        auto it1 = lower_bound(vec.begin(), vec.end(), startTime);
        auto it2 = upper_bound(vec.begin(), vec.end(), endTime);

        return (it2 - it1);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */