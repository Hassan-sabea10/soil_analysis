#include <iostream>
#include "Soil.h"
#include "ClaySoil.h"
#include "SandySoil.h"
#include "RockySoil.h"
#include "ConstructionSite.h"
using namespace std;

double readDouble(const string& prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return value;
}

void addNewSample(ConstructionSite& site) {
    cout << "\nSelect the soil type:\n";
    cout << "1) Clay\n";
    cout << "2) Sandy\n";
    cout << "3) Rocky\n";
    int choice;
    cout << "Enter soil type number (1-3): ";
    cin >> choice;

    cout << "Enter sample name (one word, no spaces): ";
    string name;
    cin >> name;

    double dens = readDouble("Enter density in kg/m3 (example: 1800): ");
    double moist = readDouble("Enter moisture percentage (example: 25): ");
    double coh = readDouble("Enter cohesion in kPa (example: 40): ");
    double friction = readDouble("Enter internal friction angle in degrees (example: 30): ");
    double slope = readDouble("Enter site slope angle in degrees (example: 10): ");

    Soil* newSoil = nullptr;
    switch (choice) {
        case 1:
            newSoil = new ClaySoil(name, dens, moist, coh, friction, slope);
            break;
        case 2:
            newSoil = new SandySoil(name, dens, moist, coh, friction, slope);
            break;
        case 3:
            newSoil = new RockySoil(name, dens, moist, coh, friction, slope);
            break;
        default:
            cout << "Invalid choice. Sample was not added.\n";
            return;
    }

    site.addSample(newSoil);
    cout << "Sample added successfully.\n";
}

void compareTwoSamples(const ConstructionSite& site) {
    int count = site.getSampleCount();
    if (count < 2) {
        cout << "You need at least two samples to run a comparison.\n";
        return;
    }
    site.showAllSamples();
    int i1, i2;
    cout << "Enter the number of the first sample: ";
    cin >> i1;
    cout << "Enter the number of the second sample: ";
    cin >> i2;

    Soil* a = site.getSampleAt(i1 - 1);
    Soil* b = site.getSampleAt(i2 - 1);
    if (a == nullptr || b == nullptr) {
        cout << "Invalid sample number.\n";
        return;
    }
    ConstructionSite::compareSoils(*a, *b);
}

int main() {
    ConstructionSite site("Test Site 1");
    int option = -1;

    cout << "==================================================\n";
    cout << "        SOIL STABILITY ANALYZER FOR CONSTRUCTION\n";
    cout << "==================================================\n";

    while (option != 5) {
        cout << "\n-------------------- MAIN MENU --------------------\n";
        cout << "1) Add a new soil sample\n";
        cout << "2) Show all samples (summary)\n";
        cout << "3) Run full site analysis (detailed report)\n";
        cout << "4) Compare two samples\n";
        cout << "5) Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> option;

        switch (option) {
            case 1:
                addNewSample(site);
                break;
            case 2:
                site.showAllSamples();
                break;
            case 3:
                site.runFullAnalysis();
                break;
            case 4:
                compareTwoSamples(site);
                break;
            case 5:
                cout << "Total samples in the program (static counter): "
                     << Soil::getTotalSamples() << endl;
                cout << "Thank you for using the program.\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
