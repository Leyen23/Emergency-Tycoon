#pragma once 
#include <string>
#include "core/Hash.hpp"
#include "core/Symptoms.hpp"

namespace game 
{
    //using tabla hash recordar hacerla XD
enum class Priority //gravedad para clasificalos
    {  
    low = 1,
    low_medium = 2,
    medium = 3,
    medium_high = 4,
    high = 5
};

enum class Gender
{
    Male,
    Female,
    Other
};

enum class Agegroup
{
    child, //6-13
    teen,   // 14-21
    Adult,  // 22-59
    Older_adult //60+
};

/*enum class Personality //posibilidades de generacion de pacientes 
{
    calm, // paciente perfecto.
    Depressive, //habla poco y ocultar sintomas.
    Pedantic, // hacer molestar al doctor.
    neutral, // sin rasgos
    Eccentric, // podria inventar sintomas por internet 

};
*/
class Patient 
    {
public:      //Personality personality ver si reagregar
        auto patient(int id,const std::string& name ,Priority priority,Gender gender,Agegroup age);

        //metodos de acceso
        int getid() const;
        const std::string& getname() const;
        Priority getpriority() const;
        Gender getgender() const;
        Agegroup getagegroup() const;
        

        //Personality getpersonality() const;
        //historial paciente hash

        //mutadores
        void setname() const;
        void setpriority(Priority priority);
        void setgender(Gender gender);
        void setage(Agegroup age);
        //void setpersonality( Personality personality);
        // modificar el historial

        //proximamente implementar behaviur tree para los pacientes 
private:

        int id_;
        std::string name_;
        Priority priority_;
        int age_;
        Gender gender_;
        //Personality personality_;
        //historial

};

}
