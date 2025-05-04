#pragma once 
#include <string>
#include "core/Hash.hpp"
#include "core/Patient.hpp"


namespace game
{
enum InjuryType
{
    minor_fracture,
    severence_fracture,
    minor_burn,
    severence_burn,
    minor_cut,
    severence_cut,
    fever,
    pain,
    nausea,
    difficulty_breathing,
    fatigue,
    numbness,
    Hemophilia, // SANGRE NO CUAGULA 
    Duchenne, // Una enfermedad que causa debilidad muscular progresiva y puede afectar a la respiración y el corazón. 
    hypertension,
    diabetes,
    infected_wound
};
enum class SeverityGroup
{
    Mild, // 1- 3
    Moderate, // 4-5
    Severe, // 6-7
    Critical // 8 10
    
};
class Injurys
{
    public:
    
    Injurys(InjuryType type, int severity);

    //metodos de acceso
    InjuryType gettypeinjury() const;
    int getseverity() const;
    SeverityGroup getseveritygroup() const;

    private:
    
    InjuryType type_;
    int severity_;
};

}