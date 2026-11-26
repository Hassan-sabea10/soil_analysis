#include "Soil.h"
#include <iostream>
using namespace std;

int Soil::totalSamples = 0;

Soil::Soil() : sampleName("Unnamed"), density(0), moisture(0),
               cohesion(0), frictionAngle(0), slopeAngle(0) {
    totalSamples++;
}

Soil::Soil(string name, double dens, double moist,
           double coh, double friction, double slope)
    : sampleName(name), density(dens), moisture(moist),
      cohesion(coh), frictionAngle(friction), slopeAngle(slope) {
    totalSamples++;
}

Soil::~Soil() {
    totalSamples--;
}

string Soil::getName() const { return sampleName; }
double Soil::getDensity() const { return density; }
double Soil::getMoisture() const { return moisture; }
double Soil::getCohesion() const { return cohesion; }
double Soil::getFrictionAngle() const { return frictionAngle; }
double Soil::getSlopeAngle() const { return slopeAngle; }
int Soil::getTotalSamples() { return totalSamples; }

bool Soil::isSuitableForConstruction() const {
    double capacity = calculateBearingCapacity();
    string risk = assessLandslideRisk();
    return (capacity >= 100.0) && (risk != "High");
}

void Soil::displayInfo() const {
    cout << sampleName << " [" << getSoilType() << "] - "
         << "Bearing Capacity: " << calculateBearingCapacity()
         << " kPa | Landslide Risk: " << assessLandslideRisk() << endl;
}

void Soil::displayInfo(bool detailed) const {
    if (!detailed) {
        displayInfo();
        return;
    }
    cout << "----------------------------------------------------\n";
    cout << "Sample Name       : " << sampleName << endl;
    cout << "Soil Type         : " << getSoilType() << endl;
    cout << "Density           : " << density << " kg/m3" << endl;
    cout << "Moisture          : " << moisture << " %" << endl;
    cout << "Cohesion          : " << cohesion << " kPa" << endl;
    cout << "Friction Angle    : " << frictionAngle << " degrees" << endl;
    cout << "Slope Angle       : " << slopeAngle << " degrees" << endl;
    cout << "Bearing Capacity  : " << calculateBearingCapacity() << " kPa" << endl;
    cout << "Landslide Risk    : " << assessLandslideRisk() << endl;
    cout << "Final Decision    : "
         << (isSuitableForConstruction() ? "SUITABLE for construction" : "NOT SUITABLE for construction")
         << endl;
    cout << "----------------------------------------------------\n";
}
