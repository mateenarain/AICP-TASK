#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Variables to store input
    int numCement, numGravel, numSand;
    double totalWeight = 0;
    int numRejectedSacks = 0;

    // Input the number of sacks for each type
    cout << "Enter the number of sacks of cement: ";
    cin >> numCement;

    cout << "Enter the number of sacks of gravel: ";
    cin >> numGravel;

    cout << "Enter the number of sacks of sand: ";
    cin >> numSand;

    // Constants for sack prices
    const double cementPrice = 3.0;
    const double gravelPrice = 2.0;
    const double sandPrice = 2.0;
    const double discountPrice = 10.0;

    // Variables for order pricing
    double regularPrice = 0.0;
    int numSpecialPacks = 0;

    // Check each sack in the order
    for (int i = 0; i < numCement; ++i) {
        char contents;
        double weight;

        // Input the contents and weight for each sack
        cout << "Sack " << (i + 1) << " - Cement:\n";
        cout << "Enter the contents (C for cement, G for gravel, S for sand): ";
        cin >> contents;

        cout << "Enter the weight in kilograms: ";
        cin >> weight;

        // Validate contents and weight
        bool validContents = (contents == 'C' || contents == 'G' || contents == 'S');
    bool validWeight = ((contents == 'C' && weight > 24.9 && weight < 25.1) ||
                        ((contents == 'G' || contents == 'S') && weight > 49.9 && weight < 50.1));

        // Output the results for each sack
        if (validContents && validWeight) {
            // Accepted sack
            cout << "Accepted Sack - Contents: " << contents << ", Weight: " << std::fixed << std::setprecision(2) << weight << " kilograms\n";
            totalWeight += weight;

            // Calculate regular price for the sack
            regularPrice += cementPrice;
        } else {
            // Rejected sack with reasons
            cout << "Rejected Sack - ";

            if (!validContents) {
                cout << "Invalid contents. ";
            }

            if (!validWeight) {
                cout << "Invalid weight.";
            }

            cout << endl;

            // Increment the count of rejected sacks
            numRejectedSacks++;
        }
    }

    // Similar logic for gravel and sand sacks (you can copy and paste and modify as necessary)

    // Check for special packs
    int numSpecialCement = numCement;
    int numSpecialSand = numSand;
    int numSpecialGravel = numGravel;

    while (numSpecialCement >= 1 && numSpecialSand >= 2 && numSpecialGravel >= 2) {
        // Apply discount for a special pack
        numSpecialCement -= 1;
        numSpecialSand -= 2;
        numSpecialGravel -= 2;
        numSpecialPacks++;
    }

    // Calculate the discounted price
    double discountedPrice = regularPrice - (numSpecialPacks * discountPrice);

    // Output the total weight of the order and the number of rejected sacks
    cout << "\nTotal Weight of the Order: " << std::fixed << std::setprecision(2) << totalWeight << " kilograms\n";
    cout << "Number of Rejected Sacks: " << numRejectedSacks << endl;

    // Output pricing information
    cout << "\nRegular Price for the Order: $" << std::fixed << std::setprecision(2) << regularPrice << endl;

    if (numSpecialPacks > 0) {
        cout << "Number of Special Packs in the Order: " << numSpecialPacks << endl;
        cout << "Discounted Price for the Order: $" << std::fixed << std::setprecision(2) << discountedPrice << endl;
        cout << "Amount Saved: $" << std::fixed << std::setprecision(2) << (regularPrice - discountedPrice) << endl;
    } else {
        cout << "No special packs in the order. Total price remains unchanged." << endl;
    }

    return 0;
}
