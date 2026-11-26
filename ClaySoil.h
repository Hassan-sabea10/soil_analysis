#ifndef CLAYSOIL_H
#define CLAYSOIL_H

#include "Soil.h"

class ClaySoil : public Soil {
public:
    ClaySoil();
    ClaySoil(string name, double dens, double moist,
             double coh, double friction, double slope);

    double calculateBearingCapacity() const override;
    string assessLandslideRisk() const override;
    string getSoilType() const override;
};

#endif
