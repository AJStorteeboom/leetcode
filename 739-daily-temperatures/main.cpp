#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer = vector(temperatures.size(), 0);
        stack<pair<int, int>> badWeatherStack;

        badWeatherStack.push(pair<int,int>(temperatures[0], 0));

        for(int x = 1; x < temperatures.size(); x++) {
            if(temperatures[x] > badWeatherStack.top().first) {
                while (!badWeatherStack.empty() && temperatures[x] > badWeatherStack.top().first) {
                    answer[badWeatherStack.top().second] = x-badWeatherStack.top().second;
                    badWeatherStack.pop();
                }
            }

            badWeatherStack.push(pair<int,int>(temperatures[x], x));
        }

        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
