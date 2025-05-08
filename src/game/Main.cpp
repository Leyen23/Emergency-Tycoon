#include <iostream>
#include "core/Patient.hpp"

int main() {
    // Crear paciente
    core::Patient patient(
        1,                    // id
        "Juan Pérez",        // nombre
        core::Priority::Medium,       // prioridad
        core::Personality::neutral,   // personalidad
        core::Gender::Male,           // género
        30                             // edad
    );

    // Agregar registros al historial médico
    patient.addhistory("Asma", "Diagnosticada en 2018, crisis moderadas");
    patient.addhistory("Diabetes", "controlada con medicación");

    // Mostrar un ítem del historial en terminal
    const std::string key = "Asma";
    if (patient.getHistory().contains(key)) {
        std::cout << "Historial médico [" << key << "]: ";
        std::cout << patient.getHistory().at(key) << std::endl;
    } else {
        std::cout << "No hay registro para '" << key << "'" << std::endl;
    }

    return 0;
}
