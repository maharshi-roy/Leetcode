class Solution {
public:
    stack<int> st;
    vector<vector<int>> G;
    vector<bool> visited;
    
    void dfs(int u)
    {
        visited[u] = true;
        
        for (auto v: G[u]) {
            if (!visited[v])
                dfs(v);
        }
        
        st.push(u);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        G.resize(numCourses, vector<int>());
        visited.resize(numCourses, false);
        
        while (!st.empty()) st.pop();
        
        for (int i=0; i<prerequisites.size(); i++)
            G[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        for (int i=0;i<numCourses;i++)
            if (!visited[i])
                dfs(i);
        
        //detect cycle
        unordered_map<int, int> time;
        int u, timeNow = 0;        
        vector<int> ans;        
        
        while (!st.empty()) {
            u = st.top();
            st.pop();
            
            time[u] = timeNow++;
            ans.push_back(u);
        }
        
        for (u=0;u<numCourses;u++)
            for (auto v: G[u])
                if (time[u] > time[v])
                    ans.clear();
        
        return ans;        
    }
};