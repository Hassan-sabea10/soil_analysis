#ifndef SOIL_H
#define SOIL_H

#include <string>
using namespace std;

class Soil {
protected:
    string sampleName;
    double density;
    double moisture;
    double cohesion;
    double frictionAngle;
    double slopeAngle;

    static int totalSamples;

public:
    Soil();
    Soil(string name, double dens, double moist,
         double coh, double friction, double slope);

    virtual ~Soil();

    string getName() const;
    double getDensity() const;
    double getMoisture() const;
    double getCohesion() const;
    double getFrictionAngle() const;
    double getSlopeAngle() const;
    static int getTotalSamples();

    virtual double calculateBearingCapacity() const = 0;
    virtual string assessLandslideRisk() const = 0;
    virtual string getSoilType() const = 0;

    bool isSuitableForConstruction() const;

    void displayInfo() const;
    void displayInfo(bool detailed) const;
};

#endif
