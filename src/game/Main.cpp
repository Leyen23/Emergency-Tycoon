#include <iostream>
#include "core/GeneratorPatient.hpp"
#include "core/Symptoms.hpp"

// Función auxiliar para convertir enums a strings
std::string toString(core::Personality p) {
    switch(p) {
        case core::Personality::Calm: return "Calm";
        case core::Personality::Depressive: return "Depressive";
        case core::Personality::Neutral: return "Neutral";
        default: return "Unknown";
    }
}

std::string toString(core::Gender g) {
    switch(g) {
        case core::Gender::Male: return "Male";
        case core::Gender::Female: return "Female";
        case core::Gender::Other: return "Other";
        default: return "Unknown";
    }
}

std::string toString(core::Agegroup a) {
    switch(a) {
        case core::Agegroup::Child: return "Child";
        case core::Agegroup::Teen: return "Teen";
        case core::Agegroup::Adult: return "Adult";
        case core::Agegroup::Older_adult: return "Older Adult";
        default: return "Unknown";
    }
}

int main() {
    core::PatientGenerator generator;
    
    // Generar paciente aleatorio
    core::Patient patient = generator.generatePatient();

    // Mostrar datos básicos
    std::cout << "=== PACIENTE GENERADO ===" << "\n";
    std::cout << "Nombre: " << patient.getname() << "\n";
    std::cout << "Edad: " << patient.getname() << " (" << toString(patient.getAgeGroup()) << ")\n";
    std::cout << "Género: " << toString(patient.getgender()) << "\n";
    std::cout << "Personalidad: " << toString(patient.getpersonality()) << "\n";
    std::cout << "Prioridad: " << static_cast<int>(patient.getpriority()) << "\n";

    // Mostrar historial médico (HashTable)
    std::cout << "\n=== HISTORIAL MÉDICO ===" << "\n";
    const auto& history = patient.getHistory();
    for (size_t i = 1; i <= patient.getInjuries().size(); ++i) {
        std::string key = "Injury_" + std::to_string(i);
        if (history.contains(key)) {
            std::cout << key << ": " << history.at(key) << "\n";
        }
    }

    return 0;
}