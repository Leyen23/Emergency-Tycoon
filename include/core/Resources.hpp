#pragma once 
#include <string>
#include "core/Hash.hpp"

namespace core 
{
enum class SupplyType 
{
    Medicankit_Big,
    Medicalkit_little,
    Bandage,
    burn_kit,
    Bloodbag,
    Antibiotic,
    Paracetamol,
    oxygen, 
    alcohol
};

enum class MachineType
{
    Xray,
    Respirator,
    blood_analyzer
};
class Resources 
{
public:
Resources(double initialFounds = 0.0);

//acceso
int getsupply() const;
int getmachine(MachineType machine) const;
double getfounds() const;

//adds
void addfounds(double amount);
void addsupply(SupplyType item, int quantity);
void addmachine(MachineType machine, int quantity);

//verificadores
bool spendsfounds(double amount) const;
bool usesupply(SupplyType item, int quantity);
bool removemachine(MachineType machine, int quantity);


private:

double founds_;
//hash supply
//hash machine

};

std::string toString(SupplyType tyoe);
std::string toString(MachineType type);

}