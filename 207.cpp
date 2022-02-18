enum class Status
{
    WHITE, GREY, BLACK
};

class Solution {
public:
    vector<vector<int>> G;
    vector<Status> visited;
    
    bool dfs(int u)
    {
        visited[u] = Status::GREY;
        bool ans = true;
        
        for (auto v: G[u]) {
            if (visited[v] == Status::WHITE)
                ans = ans && dfs(v);
            else if (visited[v] == Status::GREY)
                return false;
        }
        
        visited[u] = Status::BLACK;
        
        return ans;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //determine if graph is a DAG or it should not have a cycle
        G.resize(numCourses, vector<int>());
        visited.resize(numCourses, Status::WHITE);
        
        for (int i=0;i<prerequisites.size();i++) 
            G[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        bool ans = true;
        for (int i=0;i<numCourses;i++)
            if (visited[i] == Status::WHITE)
                ans = ans && dfs(i);
        
        return ans;
    }
};