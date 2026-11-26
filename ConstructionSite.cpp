#include "ConstructionSite.h"
#include <iostream>
using namespace std;

ConstructionSite::ConstructionSite() : siteName("Unnamed Site"), sampleCount(0) {}

ConstructionSite::ConstructionSite(string name) : siteName(name), sampleCount(0) {}

ConstructionSite::~ConstructionSite() {
    for (int i = 0; i < sampleCount; i++) {
        delete samples[i];
    }
    sampleCount = 0;
}

void ConstructionSite::addSample(Soil* s) {
    if (sampleCount >= MAX_SAMPLES) {
        cout << "Maximum number of samples reached (" << MAX_SAMPLES << "). Cannot add more.\n";
        delete s;
        return;
    }
    samples[sampleCount] = s;
    sampleCount++;
}

void ConstructionSite::showAllSamples() const {
    cout << "\n=== All samples in site: " << siteName << " ===\n";
    if (sampleCount == 0) {
        cout << "No samples have been added yet.\n";
        return;
    }
    for (int i = 0; i < sampleCount; i++) {
        cout << i + 1 << ") ";
        samples[i]->displayInfo();
    }
}

void ConstructionSite::runFullAnalysis() const {
    cout << "\n######################################################\n";
    cout << "FULL ANALYSIS REPORT FOR SITE: " << siteName << endl;
    cout << "######################################################\n";

    int suitableCount = 0;
    int unsuitableCount = 0;

    for (int i = 0; i < sampleCount; i++) {
        samples[i]->displayInfo(true);
        if (samples[i]->isSuitableForConstruction())
            suitableCount++;
        else
            unsuitableCount++;
    }

    cout << "\n------------------ SITE SUMMARY ------------------\n";
    cout << "Total samples      : " << sampleCount << endl;
    cout << "Suitable samples   : " << suitableCount << endl;
    cout << "Unsuitable samples : " << unsuitableCount << endl;

    if (sampleCount == 0) {
        cout << "Not enough data to give a recommendation.\n";
    } else if (unsuitableCount == 0) {
        cout << "Overall recommendation: The site is fully suitable for construction.\n";
    } else if (suitableCount == 0) {
        cout << "Overall recommendation: The site is not suitable at all, an alternative site is advised.\n";
    } else {
        cout << "Overall recommendation: The site is partially suitable, each unsuitable sample"
             << " needs careful study before the final decision.\n";
    }
    cout << "######################################################\n";
}

void ConstructionSite::compareSoils(const Soil& a, const Soil& b) {
    cout << "\n--- Comparison between: " << a.getName() << " and " << b.getName() << " ---\n";
    double capA = a.calculateBearingCapacity();
    double capB = b.calculateBearingCapacity();

    cout << a.getName() << " (" << a.getSoilType() << ") -> Bearing Capacity: " << capA
         << " kPa | Risk: " << a.assessLandslideRisk() << endl;
    cout << b.getName() << " (" << b.getSoilType() << ") -> Bearing Capacity: " << capB
         << " kPa | Risk: " << b.assessLandslideRisk() << endl;

    if (!a.isSuitableForConstruction() && !b.isSuitableForConstruction()) {
        cout << "Result: Both samples are not suitable for construction.\n";
    } else if (a.isSuitableForConstruction() && !b.isSuitableForConstruction()) {
        cout << "Result: " << a.getName() << " is the better choice for construction.\n";
    } else if (!a.isSuitableForConstruction() && b.isSuitableForConstruction()) {
        cout << "Result: " << b.getName() << " is the better choice for construction.\n";
    } else {
        if (capA >= capB)
            cout << "Result: Both are suitable, but " << a.getName() << " is better (higher bearing capacity).\n";
        else
            cout << "Result: Both are suitable, but " << b.getName() << " is better (higher bearing capacity).\n";
    }
}

int ConstructionSite::getSampleCount() const {
    return sampleCount;
}

Soil* ConstructionSite::getSampleAt(int index) const {
    if (index < 0 || index >= sampleCount) return nullptr;
    return samples[index];
}
