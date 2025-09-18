
class TaskManager {
private:
    struct Task {
        int priority;
        int taskId;
        bool operator<(const Task& other) const {
            if (priority == other.priority) {
                return taskId < other.taskId; 
            }
            return priority < other.priority; 
        }
    };
    priority_queue<Task> pq; 
    unordered_map<int, pair<int,int>> taskMap; 
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskMap[taskId] = {userId, priority};
            pq.push({priority, taskId});
        }
    }
    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        pq.push({priority, taskId});
    } 
    void edit(int taskId, int newPriority) {
        if (taskMap.find(taskId) == taskMap.end()) return; 
        int userId = taskMap[taskId].first;
        taskMap[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId}); 
    } 
    void rmv(int taskId) {
        taskMap.erase(taskId); 
    }
    int execTop() {
        while (!pq.empty()) {
            Task top = pq.top();
            if (taskMap.find(top.taskId) != taskMap.end() &&
                taskMap[top.taskId].second == top.priority) {
                int userId = taskMap[top.taskId].first;
                taskMap.erase(top.taskId);
                pq.pop();
                return userId;
            }
            pq.pop(); 
        }
        return -1; 
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