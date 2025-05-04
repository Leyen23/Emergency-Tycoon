#include "core/Patient.hpp"
#include "core/Hash.hpp"


namespace core {

Patient::Patient(int id,
                const std::string& name,
                Priority priority,
                Personality personality,
                Gender gender,
                int age)
    :id_(id),
    name_(name),
    priority_(priority),
    personality_(personality),
    gender_(gender),
    age_(age),
    history_(),
    injuries_() {}

int Patient::getid() const {
    return id_;
}

const std::string& Patient::getname() const {
    return name_;
}

Priority Patient::getpriority() const {
    return priority_;
}

Personality Patient::getpersonality() const {
    return personality_;
}

Gender Patient::getgender() const {
    return gender_;
}

Agegroup Patient::getage() const {
    // Calcula el grupo etario en base a age_
    if (age_ >= 6 && age_ <= 13) return Agegroup::Child;
    else if (age_ >= 14 && age_ <= 21) return Agegroup::Teen;
    else if (age_ >= 22 && age_ <= 59) return Agegroup::Adult;
    else return Agegroup::Older_adult;
}

const MedicalHistory& Patient::getHistory() const {
    return history_;
}

const std::vector<core::Injurys>& Patient::getInjuries() const {
    return injuries_;
}

// Mutadores
void Patient::setname(const std::string& name) {
    name_ = name;
}

void Patient::setpriority(Priority priority) {
    priority_ = priority;
}

void Patient::setgender(Gender gender) {
    gender_ = gender;
}

void Patient::setage(Agegroup age) {
    // Ajusta age_ según el grupo etario seleccionado
    switch (age) {
        case Agegroup::Child:       age_ = 6;  break;
        case Agegroup::Teen:        age_ = 14; break;
        case Agegroup::Adult:       age_ = 22; break;
        case Agegroup::Older_adult: age_ = 60; break;
    }
}

void Patient::setpersonality(Personality personality) {
    personality_ = personality;
}

void Patient::addhistory(const std::string& key, const std::string& detail) {
    history_.insert(key, detail);
}

void Patient::addInjury(const core::Injurys& injury) {
    injuries_.push_back(injury);
}

} // namespace core