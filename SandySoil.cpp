#include "SandySoil.h"
#include <cmath>

SandySoil::SandySoil() : Soil() {}

SandySoil::SandySoil(string name, double dens, double moist,
                      double coh, double friction, double slope)
    : Soil(name, dens, moist, coh, friction, slope) {}

double SandySoil::calculateBearingCapacity() const {
    const double PI = 3.14159265358979323846;
    double angleInRadians = getFrictionAngle() * PI / 180.0;
    double capacity = getDensity() * tan(angleInRadians) * 0.8;
    return capacity;
}

string SandySoil::assessLandslideRisk() const {
    if (getSlopeAngle() > 20.0)
        return "High";
    if (getSlopeAngle() > 10.0 || getMoisture() < 5.0)
        return "Medium";
    return "Low";
}

string SandySoil::getSoilType() const {
    return "Sandy";
}
