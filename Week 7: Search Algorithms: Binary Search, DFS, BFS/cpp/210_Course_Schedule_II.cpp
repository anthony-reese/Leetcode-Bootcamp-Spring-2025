class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto& prereq : prerequisites) {
            int course = prereq[0];
            int prerequisite = prereq[1];
            adjList[prerequisite].push_back(course);
            inDegree[course]++;
        }
            
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
            
        vector<int> result;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            result.push_back(current);

            for (int neighbor : adjList[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
            
        if (result.size() == numCourses) {
            return result;
        } else {
            return {};
        }
    }
};
