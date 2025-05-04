#pragma once 
#include <string>
#include "core/Hash.hpp"
#include "core/Symptoms.hpp"


namespace core
{

using MedicalHistory = core::HashTable<std::string, std::string>;

enum class Priority //gravedad para clasificalos
    {  
    Low = 1,
    Low_medium = 2,
    Medium = 3,
    Medium_high = 4,
    High = 5
};

enum class Personality //posibilidades de generacion de pacientes 
{
    calm, // paciente perfecto.
    Depressive, //habla poco y ocultar sintomas.
    Pedantic, // hacer molestar al doctor.
    neutral, // sin rasgos
    Eccentric, // podria inventar sintomas por internet 

};

enum class Gender
{
    Male,
    Female,
    Other
};

enum class Agegroup
{
    Child, //6-13
    Teen,   // 14-21
    Adult,  // 22-59
    Older_adult //60+
};


class Patient
    {
    public:      
        Patient(int id,
                const std::string& name ,
                Priority priority,
                Personality personality,
                Gender gender,
                int age);

        //metodos de acceso
        int getid() const;
        const std::string& getname() const;
        Priority getpriority() const;
        Personality getpersonality() const;
        Gender getgender() const;
        Agegroup getage() const;
        const MedicalHistory& getHistory() const;
        const std::vector<core::Injurys>& getInjuries() const;

        //mutadores
        void setname(const std::string& name);
        void setpriority(Priority priority);
        void setgender(Gender gender);
        void setage(Agegroup age);
        void setpersonality( Personality personality);
        void addhistory(const std::string& key, const std::string& detail);
        void addInjury (const core::Injurys& injury);
        //proximamente implementar behaviur tree para los pacientes 
private:

        int id_;
        std::string name_;
        Priority priority_;
        Personality personality_;
        Gender gender_;
        int age_;
        MedicalHistory history_;
        std::vector<core::Injurys> injuries_;

    };
}
