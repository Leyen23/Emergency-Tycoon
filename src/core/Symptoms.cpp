#include "core/Symptoms.hpp"
#include "core/Patient.hpp"

namespace core 
{
    std::string toString(InjuryType type) {
        
        switch(type) 
            { 
            case InjuryType::Fracture: return "Fracture";
            case InjuryType::Burn: return "Burn";
            case InjuryType::Cut: return "Cut";
            case InjuryType::Fever: return "Fever";
            default: return "Unknown";
        }
    }

    int defaultSeverity(InjuryType type)
    { 
        switch(type) 
            {
            case InjuryType::Fracture: return 3;
            case InjuryType::Burn: return 2;
            case InjuryType::Cut: return 1;
            case InjuryType::Fever: return 1;
            default: return 0;
        }
    }

Injury::Injury(InjuryType type, int severity) : type_(type), severity_(severity) {}

    InjuryType Injury::gettypeinjury() const
    {
        return type_;
    }

    int Injury::getseverity() const
    {
        return severity_;
    }

    SeverityGroup Injury::getseveritygroup() const
    {
        if(severity_ <= 1)
            {
            return SeverityGroup::Mild;
        }

        else if(severity_ == 2)
        {
            return SeverityGroup::Moderate;
        }

        else 
        {
            return SeverityGroup::Severe;
        }
    }
}


            