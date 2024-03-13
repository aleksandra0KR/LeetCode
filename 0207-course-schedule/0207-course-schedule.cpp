class Solution {
public:
    bool canFinish(int numCourses, vector <vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> edges;
        unordered_map<int, int> degree;
        int prev;
        int current;
        int course = 0;
        
        if (prerequisites.size() == 0) return true;
        
        for (int i = 0; i < prerequisites.size(); i++) {
            prev = prerequisites[i][0];
            if (degree.find(prev) == degree.end()) {
                degree[prev] = 0;
                course++;
            }
            for (int j = 1; j < prerequisites[i].size(); j++) {
                if (degree.find(prev) == degree.end()) {
                    degree[prev] = 0;
                    course++;
                }
                current = prerequisites[i][j];
                edges[prev].push_back(current);
                if (degree.find(current) == degree.end()) {
                    degree[current] = 1;
                    course++;
                } else degree[current]++;
            }
        }

        queue<int> Q;
        for (int i = 0; i < numCourses; i++) {
            if (degree.find(i) != degree.end()) {
                if (degree[i] == 0) Q.push(i);
            }
        }

        int counter = 0;
        int front;
        
        while (!Q.empty()) {
            front = Q.front();
            Q.pop();
            counter++;
            for (int i = 0; i < edges[front].size(); i++) {
                degree[edges[front][i]]--;
                if (degree[edges[front][i]] == 0) Q.push(edges[front][i]);
            }
        }


        if (counter == course) return true;
        return false;


    }
};