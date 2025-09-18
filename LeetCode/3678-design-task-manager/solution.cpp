class TaskManager {
private:
    struct CustomComparator {
        bool operator()(const tuple<int, int, int>& a,
                        const tuple<int, int, int>& b) const {
            if (get<0>(a) != get<0>(b)) {
                return get<0>(a) > get<0>(b);
            }
            return get<2>(a) > get<2>(b);
        }
    };

    unordered_map<int, int> TaskUser;
    unordered_map<int, int> TaskPriorty;
    set<tuple<int, int, int>, CustomComparator> Tasks;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& it : tasks) {
            int userid = it[0], taskid = it[1], prio = it[2];
            this->add(userid, taskid, prio);
        }
    }
    void add(int userId, int taskId, int prio) {
        Tasks.insert(make_tuple(prio, userId, taskId));
        TaskUser[taskId] = userId;
        TaskPriorty[taskId] = prio;
    }

    void edit(int taskId, int newPriority) {
        int userid = TaskUser[taskId];
        rmv(taskId);
        TaskUser[taskId] = userid;
        auto newTask = make_tuple(newPriority, userid, taskId);
        Tasks.insert(newTask);
        TaskPriorty[taskId] = newPriority;
        
    }

    void rmv(int taskId) {
        int userid = TaskUser[taskId];
        int prio = TaskPriorty[taskId];
        auto Task = Tasks.find(make_tuple(prio, userid, taskId));
        Tasks.erase(Task);
        TaskUser.erase(TaskUser.find(taskId));
        TaskPriorty.erase(TaskPriorty.find(taskId));
    }

    int execTop() {
        if (Tasks.empty())
            return -1;
        auto [prio, userid, taskid] = *Tasks.begin();
        rmv(taskid);
        return userid;
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
