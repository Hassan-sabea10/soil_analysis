# Soil Stability Analyzer

## Project Description
Soil Stability Analyzer is a C++ console application that simulates the work of a civil engineer who inspects several soil samples (Clay, Sandy, Rocky) at one construction site and decides whether each sample is suitable for building. For every sample the program calculates the **Bearing Capacity** (kPa) and assesses the **Landslide Risk** (Low / Medium / High) from simple physical properties: density, moisture, cohesion, internal friction angle and site slope angle.

Note: the formulas are simplified for educational purposes to demonstrate OOP concepts. They are not meant for real engineering use.

## Project Objectives
- Apply Object-Oriented Programming concepts to a practical engineering problem.
- Build an extensible design: adding a new soil type only requires a new class that inherits from `Soil`, with no change to existing code.
- Provide a simple decision-support tool that reports whether a site is suitable for construction.

## OOP Concepts Applied

| Concept | Where it appears |
|---|---|
| Classes and Objects | `Soil` (abstract base), `ClaySoil`, `SandySoil`, `RockySoil`, `ConstructionSite` |
| Encapsulation | `Soil` data members are `protected`, `ConstructionSite` data members are `private`, access is through public getters |
| Constructors and Destructors | Default and parameterized constructors in every class, a `virtual` destructor in `Soil`, and a destructor in `ConstructionSite` that deletes all samples |
| Inheritance | `ClaySoil`, `SandySoil` and `RockySoil` inherit publicly from `Soil` |
| Polymorphism | Pure virtual functions `calculateBearingCapacity()`, `assessLandslideRisk()` and `getSoilType()` are overridden in each derived class and called through `Soil*` pointers |
| Function Overloading | `displayInfo()` and `displayInfo(bool detailed)`, plus overloaded constructors |
| Access Modifiers | `private`, `protected` and `public` are used across the classes |
| Static Members | `Soil::totalSamples` counter and `ConstructionSite::compareSoils()` |

## Soil Formulas

| Soil | Bearing Capacity | Landslide Risk |
|---|---|---|
| Clay | cohesion x 5.7 x (1 - moisture / 150) | High if moisture > 60 and slope > 15, Medium if moisture > 40 or slope > 10, else Low |
| Sandy | density x tan(friction angle) x 0.8 | High if slope > 20, Medium if slope > 10 or moisture < 5, else Low |
| Rocky | density x 1.5 | Medium if slope > 35, else Low |

A sample is suitable for construction when its bearing capacity is at least 100 kPa and its landslide risk is not High.

## Project Structure
```
SoilStabilityAnalyzer/
├── include/
│   ├── Soil.h
│   ├── ClaySoil.h
│   ├── SandySoil.h
│   ├── RockySoil.h
│   └── ConstructionSite.h
├── src/
│   ├── Soil.cpp
│   ├── ClaySoil.cpp
│   ├── SandySoil.cpp
│   ├── RockySoil.cpp
│   ├── ConstructionSite.cpp
│   └── main.cpp
└── README.md
```

## Compile and Run

### Linux / macOS / WSL
```bash
g++ -std=c++11 -Wall -Iinclude src/*.cpp -o soil_app
./soil_app
```

### Windows (MinGW)
```bash
g++ -std=c++11 -Wall -Iinclude src/*.cpp -o soil_app.exe
soil_app.exe
```

### IDE (Code::Blocks, CLion, Visual Studio)
Create a new C++ console project, add the `include` folder as an include directory, add all `.cpp` files from `src`, then build and run.

## How to Use
1. Add a new soil sample (choose the type, then enter the name and properties when prompted).
2. Show all samples (short summary).
3. Run the full site analysis (detailed report and overall recommendation).
4. Compare two samples to find the better one for construction.
5. Exit.

Sample names must be one word without spaces. Every input is requested with a clear prompt that shows the expected unit and an example value.
