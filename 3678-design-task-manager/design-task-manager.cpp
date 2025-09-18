struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const{
        if(a.first != b.first)
            return a.first > b.first;
        else
            return a.second > b.second;
    }
};

class TaskManager {

    unordered_map<int, int> taskIdToPriority;
    unordered_map<int, int> taskIdToUser;
    unordered_map<int, set<pair<int, int>, cmp>> userToPriorTask;
    multiset<pair<int, int>, greater<pair<int, int>>> priorToTask;

public:
    TaskManager(vector<vector<int>>& tasks) {
        
        int n = tasks.size();

        for(int i = 0; i < n; i++){
            int userId = tasks[i][0];
            int taskId = tasks[i][1];
            int prior = tasks[i][2];

            // It store in the order of taskId -> priority
            taskIdToPriority[taskId] = prior;

            // It store in the order of taskId -> userId
            taskIdToUser[taskId] = userId;

            // It store in the form of userId -> {priority , taskId}
            userToPriorTask[userId].insert({prior, taskId});

            // It store {prioritry, taskId} in Multiset
            priorToTask.insert({prior, taskId});
        }

    }
    
    void add(int userId, int taskId, int priority) {
        
        // It store in the order of taskId -> priority
        taskIdToPriority[taskId] = priority;

        // It store in the order of taskId -> userId
        taskIdToUser[taskId] = userId;

        // It store in the form of userId -> {priority , taskId}
        userToPriorTask[userId].insert({priority, taskId});

        // It store {prioritry, taskId} in Multiset
        priorToTask.insert({priority, taskId});

    }
    
    void edit(int taskId, int newPriority) {
        
        int oldPriority = taskIdToPriority[taskId];
        int userId = taskIdToUser[taskId];

        // Erase the previous priority
        userToPriorTask[userId].erase({oldPriority, taskId});
        // Erase from multiset
        priorToTask.erase({oldPriority, taskId});

        // Update all places
        taskIdToPriority[taskId] = newPriority;
        userToPriorTask[userId].insert({newPriority, taskId});
        priorToTask.insert({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        
        int priority = taskIdToPriority[taskId];
        int userId = taskIdToUser[taskId];

        // Erase from all places
        userToPriorTask[userId].erase({priority, taskId});
        priorToTask.erase({priority, taskId});
        taskIdToPriority.erase(taskId);
        taskIdToUser.erase(taskId);
    }
    
    int execTop() {
        
        if(priorToTask.size() == 0)
            return -1;
        
        int taskId = priorToTask.begin()->second;
        int priority = priorToTask.begin()->first;
        int userId = taskIdToUser[taskId];
        

        // Erase from all places
        userToPriorTask[userId].erase({priority, taskId});
        priorToTask.erase({priority, taskId});
        taskIdToPriority.erase(taskId);
        taskIdToUser.erase(taskId);
        
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */