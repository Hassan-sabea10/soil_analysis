#include "RockySoil.h"

RockySoil::RockySoil() : Soil() {}

RockySoil::RockySoil(string name, double dens, double moist,
                      double coh, double friction, double slope)
    : Soil(name, dens, moist, coh, friction, slope) {}

double RockySoil::calculateBearingCapacity() const {
    return getDensity() * 1.5;
}

string RockySoil::assessLandslideRisk() const {
    if (getSlopeAngle() > 35.0)
        return "Medium";
    return "Low";
}

string RockySoil::getSoilType() const {
    return "Rocky";
}
