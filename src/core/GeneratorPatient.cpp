#include <array>
#include <string>
#include <vector>
#include "core/GeneratorPatient.hpp"


namespace core {

PatientGenerator::PatientGenerator() : rng_(std::random_device{}()) {}

Patient PatientGenerator::generatePatient() 
    
{
    static int nextId = 1;
    int id = nextId++;
    Gender gender = generateRandomGender();
    std::string name = generateRandomName(gender);
    int age = generateRandomAge();
    Personality personality = generateRandomPersonality();
    Priority priority = generateRandomPriority();

    // Crear paciente
    Patient patient(id, name, priority, personality, gender, age);

    // Generar 1-3 lesiones aleatorias
    std::uniform_int_distribution<int> injuryCountDist(1, 3);
    int numInjuries = injuryCountDist(rng_);

    for (int i = 0; i < numInjuries; ++i) 
        {
        InjuryType injuryType = generateRandomInjury();
        int severity = generateRandomSeverity();
        Injury injury(injuryType, severity);
        
        patient.addInjury(injury);
        
        // Registrar en historial médico (HashTable)
        std::string key = "Injury_" + std::to_string(i + 1);
        std::string value = toString(injuryType) + " (Severity: " + std::to_string(severity) + ")";
        patient.addhistory(key, value);
    }

    return patient;
}

// Generar nombre aleatorio
std::string PatientGenerator::generateRandomName(Gender gender) 
    { 
    
    static std::array<std::string, 10> maleNames = 
        {  
        "Alex", "Jesus", "Gustavo", "Jorge", "Leonardo", "Diego", "Ivan", "Pedro", "Franklin", "Valmore"  
    };  
    static std::array<std::string, 10> femaleNames =
        {  
        "Saray", "Maria", "Evelyn", "Grace", "Janeth", "Maira", "Yoaana", "Sofia", "Sabrina", "Irina"  
    };  

    std::uniform_int_distribution<size_t> dist(0, maleNames.size() - 1);  

    // Usa el género para seleccionar la lista
    if (gender == Gender::Male) 
        {  
        return maleNames[dist(rng_)];  
    } 
    else 
        {  
        return femaleNames[dist(rng_)];  
    }
}

// Generar edad entre 1-100 y asegurar que corresponda a un Agegroup
int PatientGenerator::generateRandomAge() 
    {
    std::uniform_int_distribution<int> ageDist(1, 100);
    return ageDist(rng_);
}

// Determinar Agegroup basado en la edad
Agegroup PatientGenerator::determineAgeGroup(int age) 
    {
    if (age >= 60) 
        {
        return Agegroup::Older_adult;
    }

    else if (age >= 22) 
        {
        return Agegroup::Adult;
    }
    else if (age >= 14)
        {
        return Agegroup::Teen;
    }
    
    else if (age >= 6)
        {
        return Agegroup::Child;
    } 

    else return Agegroup::Child; 
}

// Generar género aleatorio
Gender PatientGenerator::generateRandomGender()
    {
    std::uniform_int_distribution<int> dist(0, 2);
    return static_cast<Gender>(dist(rng_));
}

// Generar tipo de lesión aleatoria (según enum InjuryType)
InjuryType PatientGenerator::generateRandomInjury() 
    {
    std::uniform_int_distribution<int> dist(0, 3);
    return static_cast<InjuryType>(dist(rng_));
}

// Generar severidad (1-3)
int PatientGenerator::generateRandomSeverity() 
    {
    std::uniform_int_distribution<int> dist(1, 3);
    return dist(rng_);
}

// Generar personalidad aleatoria
Personality PatientGenerator::generateRandomPersonality() 
    {
    std::uniform_int_distribution<int> dist(0, 2);
    return static_cast<Personality>(dist(rng_));
}

// Generar prioridad aleatoria
Priority PatientGenerator::generateRandomPriority() 
    {
    std::uniform_int_distribution<int> dist(1, 3);
    return static_cast<Priority>(dist(rng_));
}

} 