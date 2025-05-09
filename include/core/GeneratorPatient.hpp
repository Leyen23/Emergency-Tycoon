#pragma once
#include "core/Patient.hpp"
#include "core/Symptoms.hpp"
#include <random>

namespace core 
{

class PatientGenerator 
        {
public:

    PatientGenerator();
    Patient generatePatient();

private:
    std::mt19937 rng_; // Motor de números aleatorios

    // Helpers para generar atributos aleatorios
    std::string generateRandomName();
    int generateRandomAge();
    Agegroup determineAgeGroup(int age);
    Gender generateRandomGender();
    InjuryType generateRandomInjury();
    int generateRandomSeverity();
    Personality generateRandomPersonality();
    Priority generateRandomPriority();
    };

} 
