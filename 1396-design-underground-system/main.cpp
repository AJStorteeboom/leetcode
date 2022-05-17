#include <iostream>
#include <unordered_map>

using namespace std;

class UndergroundSystem {
    unordered_map<int,pair<string,int>> customers;
    unordered_map<string,unordered_map<string,pair<int,int>>> travelData;

public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        if(customers.find(id) != customers.end()) return; //Already checked in

        customers.insert({{id, pair<string,int>(stationName, t)}});
     }

    void checkOut(int id, string stationName, int t) {
        if(customers.find(id) == customers.end()) return; //Not checked in;

        int timeSpend = t-customers[id].second;

        travelData[customers[id].first][stationName].first++; //Increase number of trips
        travelData[customers[id].first][stationName].second += timeSpend; //Increase total time spend

        customers.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        return (double) travelData[startStation][endStation].second / travelData[startStation][endStation].first; //Divide total time spend by number of trips
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
