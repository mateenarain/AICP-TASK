#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>

using namespace std;

class ElectricMountainRailway {
private:
    unordered_map<string, pair<int, int>> trainSchedule;
    const int maxSeatsPerCoach = 80;
    const int ticketPrice = 25;
    vector<int> passengersUp;
    vector<int> passengersDown;
    vector<int> moneyUp;
    vector<int> moneyDown;

public:
    ElectricMountainRailway() {
        // Initialize data structures
        trainSchedule = {
            {"09:00", {6, 0}},
            {"11:00", {6, 0}},
            {"13:00", {6, 0}},
            {"15:00", {6, 2}},
            {"10:00", {0, 6}},
            {"12:00", {0, 6}},
            {"14:00", {0, 6}},
            {"16:00", {2, 6}}
        };
        passengersUp = {0, 0, 0, 0};
        passengersDown = {0, 0, 0, 0};
        moneyUp = {0, 0, 0, 0};
        moneyDown = {0, 0, 0, 0};
    }

    void displayScreen() {
        // Display the current train schedule
        cout << setw(8) << "Time" << setw(8) << "Up" << setw(8) << "Down" << setw(8) << "Available" << endl;
        for (const auto& entry : trainSchedule) {
            const string& time = entry.first;
            const int upTickets = entry.second.first;
            const int downTickets = entry.second.second;
            string availableTickets = (upTickets == 0) ? "Closed" : to_string(upTickets);
            cout << setw(8) << time << setw(8) << upTickets << setw(8) << downTickets << setw(8) << availableTickets << endl;
        }
        cout << endl;
    }

    void purchaseTickets(const string& time, const string& direction, int numPassengers) {
        // Purchase tickets for a specified time and direction
        auto it = trainSchedule.find(time);
        if (it == trainSchedule.end() || (direction == "up" && it->second.first == 0)) {
            cout << "Invalid train time or no available tickets for the specified direction.\n";
            return;
        }

        int availableTickets = (direction == "up") ? it->second.first : it->second.second;
        if (numPassengers > availableTickets) {
            cout << "Not enough tickets available. Only " << availableTickets << " tickets left.\n";
            return;
        }

        // Calculate total price
        int totalPrice = numPassengers * ticketPrice;
        int groupDiscount = calculateGroupDiscount(numPassengers);
        totalPrice -= groupDiscount;

        // Update data
        if (direction == "up") {
            it->second.first -= numPassengers;
            updatePassengerAndMoney(time, direction, numPassengers, totalPrice);
        } else {
            it->second.second -= numPassengers;
            updatePassengerAndMoney(time, direction, numPassengers, totalPrice);
        }

        cout << "Tickets purchased successfully for " << numPassengers << " passengers.\n";
        cout << "Total Price: $" << totalPrice << "\n\n";
    }

    int calculateGroupDiscount(int numPassengers) {
        // Calculate group discount for every 10 passengers
        return (numPassengers / 10) * ticketPrice;
    }

    void updatePassengerAndMoney(const string& time, const string& direction, int numPassengers, int totalPrice) {
        // Update passenger and money data
        int index = (time < "12:00") ? 0 : 1;
        if (direction == "up") {
            passengersUp[index] += numPassengers;
            moneyUp[index] += totalPrice;
        } else {
            passengersDown[index] += numPassengers;
            moneyDown[index] += totalPrice;
        }
    }

    void endOfDaySummary() {
        // Display the end-of-day summary
        cout << "End of the Day Summary:\n";
        for (size_t i = 0; i < passengersUp.size(); ++i) {
            string time = (i < 2) ? "0" + to_string(9 + i) + ":00" : to_string(9 + i) + ":00";
            cout << time << ": Up - " << passengersUp[i] << " passengers, $" << moneyUp[i]
                      << " | Down - " << passengersDown[i] << " passengers, $" << moneyDown[i] << "\n";
        }

        int totalPassengers = passengersUp[0] + passengersUp[1] + passengersDown[0] + passengersDown[1];
        int totalMoney = moneyUp[0] + moneyUp[1] + moneyDown[0] + moneyDown[1];
        cout << "\nTotal Passengers for the Day: " << totalPassengers << " passengers\n";
        cout << "Total Money Taken for the Day: $" << totalMoney << "\n";

        // Find the train journey with the most passengers
        string maxPassengersTime = (passengersUp[0] > passengersUp[1]) ? "09:00" : "11:00";
        int maxPassengers = max(passengersUp[0], passengersUp[1]);
        cout << "Train journey with the most passengers: " << maxPassengersTime << " - "
                  << maxPassengers << " passengers\n";
    }
};

int main() {
    // Task 1 - Start of the day
    ElectricMountainRailway railway;
    railway.displayScreen();

    // Task 2 - Purchasing tickets
    railway.purchaseTickets("09:00", "up", 15);
    railway.displayScreen();

    // Task 3 - End of the day
    railway.endOfDaySummary();

    return 0;
}
