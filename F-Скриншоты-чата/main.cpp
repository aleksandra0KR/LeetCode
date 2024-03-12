#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::unordered_map;
using std::vector;
using std::queue;

int main() {
    int number_of_data;
    cin >> number_of_data;
    int number_of_users;
    int number_of_screens;
    int prev;
    int current;
    for(int t = 0; t < number_of_data; t++) {
        cin >> number_of_users;
        cin >> number_of_screens;
        unordered_map<int, vector<int>> values;
        vector<int> degree(number_of_users + 1,0);
        for(int i = 0; i < number_of_screens; i++){
            cin >> prev;
            if(number_of_users > 1) cin >> prev;
            for(int j = 2; j < number_of_users; j++){
                cin >> current;
                values[prev].push_back(current);
                degree[current]++;
                prev = current;
            }
        }

        queue<int> Q;
        for(int i = 1; i < number_of_users + 1; i++){
            if(degree[i] == 0) Q.push(i);
        }
        int front;
        int count = 0;
        while(!Q.empty()){
            front = Q.front();
            Q.pop();
            count++;
            for(auto value : values[front]){
                degree[value]--;
                if(degree[value] == 0) Q.push(value);
            }
        }
        if(count == number_of_users || number_of_users == 1) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
