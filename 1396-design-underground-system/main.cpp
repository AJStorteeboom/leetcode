#include <iostream>
#include <unordered_map>

using namespace std;

class UndergroundSystem {
    unordered_map<int,pair<string,int>> customers;
    unordered_map<string,unordered_map<string,pair<int,double>>> travelData;

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



class UndergroundSystem_optimized {
    unordered_map<int,pair<string,int>> customers;
    unordered_map<string,unordered_map<string,pair<int,int>>> travelData;

public:
    UndergroundSystem_optimized() {

    }

    void checkIn(int id, string stationName, int t) {
        if(customers.find(id) != customers.end()) return; //Already checked in

        customers.insert({{id, pair<string,int>(stationName, t)}});
    }

    void checkOut(int id, string stationName, int t) {
        if(customers.find(id) == customers.end()) return; //Not checked in;

        int timeSpend = t-customers[id].second;

        //(avg * total trips + timeSpend) / total trips + 1
        if(travelData[customers[id].first][stationName].first > 0) {
            travelData[customers[id].first][stationName].second =
                    (double) travelData[customers[id].first][stationName].second *
                    travelData[customers[id].first][stationName].first +
                    timeSpend / travelData[customers[id].first][stationName].first + 1;
        } else {
            travelData[customers[id].first][stationName].second = timeSpend;
        }

        travelData[customers[id].first][stationName].first++; //Increase number of trips

        customers.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        return (double) travelData[startStation][endStation].second;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
