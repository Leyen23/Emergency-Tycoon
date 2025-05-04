#pragma once 
#include <string>
#include "core/Hash.hpp"
#include "core/Patient.hpp"


namespace core
{
enum InjuryType
{
    Minor_fracture,
    Severence_fracture,
    Burn,
    Minor_cut,
    Severence_cut,
    Fever,
    Pain,
    Difficulty_breathing,
    Fatigue,
    Numbness,
    Infected_wound
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