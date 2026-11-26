#ifndef CONSTRUCTIONSITE_H
#define CONSTRUCTIONSITE_H

#include "Soil.h"
#include <string>
using namespace std;

const int MAX_SAMPLES = 50;

class ConstructionSite {
private:
    string siteName;
    Soil* samples[MAX_SAMPLES];
    int sampleCount;

public:
    ConstructionSite();
    ConstructionSite(string name);

    ~ConstructionSite();

    void addSample(Soil* s);
    void showAllSamples() const;
    void runFullAnalysis() const;

    static void compareSoils(const Soil& a, const Soil& b);

    int getSampleCount() const;
    Soil* getSampleAt(int index) const;
};

#endif
