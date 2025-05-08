#pragma once 
#include <string>
#include <vector>
#include "core/Hash.hpp"

namespace core
{
enum InjuryType
{
    Fracture,
    Burn,
    Cut,
    Fever
};
enum class SeverityGroup
{
    Mild, // 1
    Moderate, // 2
    Severe, // 3
    
};

std::string toString(InjuryType type);

int defaultSeverity(InjuryType type);

enum class Injurytupe;

class Injury
{
    public:
    
    Injury(InjuryType type, int severity);

    explicit Injury(InjuryType type);

    //metodos de acceso
    InjuryType gettypeinjury() const;
    int getseverity() const;
    SeverityGroup getseveritygroup() const;

    private:
    
    InjuryType type_;
    int severity_;
};

}