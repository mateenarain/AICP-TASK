#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // Define arrays to store item information
    string item_codes[] = {"A1", "A2", "B1", "B2", "B3", "C1", "C2", "C3", "D1", "D2", "E1", "E2", "E3", "F1", "F2", "G1", "G2"};
    string descriptions[] = {"Compact", "Tower", "8 GB", "16 GB", "32 GB", "1 TB HDD", "2 TB HDD", "4 TB HDD", "240 GB SSD", "480 GB SSD", "1 TB HDD", "2 TB HDD", "4 TB HDD", "DVD/Blu-Ray Player", "DVD/Blu-Ray Re-writer", "Standard Version", "Professional Version"};
    double prices[] = {75.00, 150.00, 79.99, 149.99, 299.99, 49.99, 89.99, 129.99, 59.99, 119.99, 49.99, 89.99, 129.99, 50.00, 100.00, 100.00, 175.00};

    // Basic set of components cost
    double basic_cost = 200.00;

    // Initialize variables to store user choices
    map<string, string> chosen_items;
    string case_choice, ram_choice, hdd_choice, os_choice;

    // Get user choices
    cout << "Choose one Case:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << item_codes[i] << " - " << descriptions[i] << " - $" << prices[i] << endl;
    }
    cout << "Enter the item code for the case: ";
    cin >> case_choice;

    cout << "Choose one RAM:" << endl;
    for (int i = 2; i < 5; i++) {
        cout << item_codes[i] << " - " << descriptions[i] << " - $" << prices[i] << endl;
    }
    cout << "Enter the item code for the RAM: ";
    cin >> ram_choice;

    cout << "Choose one Main Hard Disk Drive:" << endl;
    for (int i = 5; i < 8; i++) {
        cout << item_codes[i] << " - " << descriptions[i] << " - $" << prices[i] << endl;
    }
    cout << "Enter the item code for the Main HDD: ";
    cin >> hdd_choice;

    cout << "Choose an Operating System:" << endl;
    for (int i = 15; i < 17; i++) {
        cout << item_codes[i] << " - " << descriptions[i] << " - $" << prices[i] << endl;
    }
    cout << "Enter the item code for the Operating System: ";
    cin >> os_choice;

    // Calculate the total price
    double total_price = basic_cost + prices[case_choice == "A1" ? 0 : 1] +
                        prices[ram_choice == "B1" ? 2 : (ram_choice == "B2" ? 3 : 4)] +
                        prices[hdd_choice == "C1" ? 5 : (hdd_choice == "C2" ? 6 : 7)] +
                        prices[os_choice == "G1" ? 15 : 16];

    // Store and output chosen items and total price
    chosen_items["Case"] = case_choice + " - " + descriptions[case_choice == "A1" ? 0 : 1];
    chosen_items["RAM"] = ram_choice + " - " + descriptions[ram_choice == "B1" ? 2 : (ram_choice == "B2" ? 3 : 4)];
    chosen_items["HDD"] = hdd_choice + " - " + descriptions[hdd_choice == "C1" ? 5 : (hdd_choice == "C2" ? 6 : 7)];
    chosen_items["OS"] = os_choice + " - " + descriptions[os_choice == "G1" ? 15 : 16];

    cout << "\nChosen Items:" << endl;
    for (const auto& item : chosen_items) {
        cout << item.first << ": " << item.second << endl;
    }

    cout << "Total Price: $" << total_price << endl;

    // Extend Task 2: Allow the customer to choose additional items
    map<string, string> additional_items;
    double additional_cost = 0.0;

    while (true) {
        char additional_choice;
        cout << "Do you want to purchase additional items (Y/N)? ";
        cin >> additional_choice;
        if (additional_choice == 'N' || additional_choice == 'n') {
            break;
        } else if (additional_choice == 'Y' || additional_choice == 'y') {
            cout << "Additional Items:" << endl;
            for (int i = 8; i < sizeof(prices) / sizeof(prices[0]); i++) {
                cout << item_codes[i] << " - " << descriptions[i] << " - $" << prices[i] << endl;
            }
            int i;  // Declare and initialize "i" as an index
            string item_code;
            cout << "Enter the item code for the additional item: ";
            cin >> item_code;

            // Find the index of the selected item_code in the item_codes array
            for (i = 0; i < sizeof(item_codes) / sizeof(item_codes[0]); i++) {
                if (item_code == item_codes[i]) {
                    break;  // Stop when the item_code is found
                }
            }

            if (i < sizeof(item_codes) / sizeof(item_codes[0])) {
                additional_items[item_code] = descriptions[i] + " - $" + to_string(prices[i]);
                additional_cost += prices[i];
            } else {
                cout << "Invalid item code. Please enter a valid code." << endl;
            }
        } else {
            cout << "Invalid input. Please enter 'Y' for yes or 'N' for no." << endl;
        }
    }

    // Update the total price with additional items
    total_price += additional_cost;

    // Output additional items and new price
    cout << "\nAdditional Items:" << endl;
    for (const auto& item : additional_items) {
        cout << item.first << " - " << item.second << endl;
    }

    cout << "New Total Price: $" << total_price << endl;

    // Extend Task 3: Apply discounts based on the number of additional items
    int num_additional_items = additional_items.size();
    double discount = 0.0;
    double discount_amount = 0.0;

    if (num_additional_items == 1) {
        discount = 0.05;
    } else if (num_additional_items >= 2) {
        discount = 0.10;
    }

    discount_amount = discount * total_price;
    total_price -= discount_amount;

    // Output the amount saved and the final price after the discount
    cout << "Amount Saved: $" << discount_amount << endl;
    cout << "Final Price after Discount: $" << total_price << endl;

    return 0;
}
