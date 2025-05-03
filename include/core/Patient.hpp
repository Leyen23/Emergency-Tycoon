#pragma
#include <string>
#include "core/Hash.hpp"

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

enum class Personality //posibilidades de generacion de pacientes 
{
    calm, // paciente perfecto.
    Depressive, //habla poco y ocultar sintomas.
    Pedantic, // hacer molestar al doctor.
    neutral, // sin rasgos
    Eccentric, // podria inventar sintomas por internet 

};

class Patient 
    {
public:
        auto patient(int id,const std::string& name ,Priority priority, Personality personality);

        //metodos de acceso
        int getid() const;
        const std::string& getname() const;
        Priority getpriority() const;
        Personality getpersonality() const;
        //historial paciente hash

        //mutadores
        void setname() const;
        void setpriority(Priority priority);
        void setpersonality(Personality personality);
        // modificar el historial

        //proximamente implementar behaviur tree para los pacientes 
private:

        int id_;
        std::string name_;
        Priority priority_;
        Personality personality_;
        //historial

};

}
