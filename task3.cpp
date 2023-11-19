#include <iostream>

// Student ID
const char* student_id = "YourStudentID";

// Source data matrix
int electricity_matrix[3][3] = {
    {50, 120, 250},  // Slab 1 data in the first row
    {80, 180, 280},  // Slab 2 data in the second row
    {150, 250, 350}  // Slab 3 data in the third row
};

// Function to calculate and display cost for slab 1
void costSlab1() {
    int unit_range_low = 0;
    int unit_range_high = 100;
    int unit_cost = 10;
    int units_consumed = electricity_matrix[0][0];
    int total_cost = units_consumed * unit_cost;

    std::cout << "Bill for Slab 1 (Unit Range: " << unit_range_low << "-" << unit_range_high
              << ", Unit Cost: Rs." << unit_cost << "/unit)\n";
    std::cout << "Units Consumed: " << units_consumed << "\n";
    std::cout << "Total Cost: Rs." << total_cost << "\n\n";
}

// Function to calculate and display cost for slab 2
void costSlab2() {
    int unit_range_low = 101;
    int unit_range_high = 200;
    int unit_cost = 15;
    int units_consumed = electricity_matrix[1][0];
    int total_cost = units_consumed * unit_cost;

    std::cout << "Bill for Slab 2 (Unit Range: " << unit_range_low << "-" << unit_range_high
              << ", Unit Cost: Rs." << unit_cost << "/unit)\n";
    std::cout << "Units Consumed: " << units_consumed << "\n";
    std::cout << "Total Cost: Rs." << total_cost << "\n\n";
}

// Function to calculate and display cost for slab 3
void costSlab3() {
    int unit_range_low = 201;
    int unit_range_high = 300;
    int unit_cost = 20;
    int units_consumed = electricity_matrix[2][0];
    int total_cost = units_consumed * unit_cost;

    std::cout << "Bill for Slab 3 (Unit Range: " << unit_range_low << "-" << unit_range_high
              << ", Unit Cost: Rs." << unit_cost << "/unit)\n";
    std::cout << "Units Consumed: " << units_consumed << "\n";
    std::cout << "Total Cost: Rs." << total_cost << "\n\n";
}

int main() {
    char choice;

    // Main menu
    do {
        std::cout << "Student ID: " << student_id << "\n";
        std::cout << "1. Display bill of Slab 1 and Slab 2\n";
        std::cout << "2. Display bill of Slab 3\n";
        std::cout << "Press any other key to exit\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                costSlab1();
                costSlab2();
                break;
            case '2':
                costSlab3();
                break;
            default:
                break;
        }
    } while (choice == '1' || choice == '2');

    return 0;
}
