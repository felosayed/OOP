#include <vector>
#include <string>
#include "Doctor.h"
#include "Patient.h"
#include "Receptionist.h"

class DentalClinic {
private:
    std::vector<Doctor> doctors;
    std::vector<Patient> patients;
    std::vector<Receptionist> receptionists;

public:
    void addDoctor(const Doctor& doctor);
    void addPatient(const Patient& patient);
    void addReceptionist(const Receptionist& receptionist);

    //========================================================
    void displayDoctors() const;
    void displayPatients() const;
    void displayReceptionists() const;

    //=======================================================
    void CreatPrescription(const std::string& doctorName, const std::string& patientName, const std::string& date, const std::string& medicineList, const std::string& notes) const;
  
    //===========================================================================
    bool login(const std::string& username, const std::string& password) const; 
    bool signup(const User& newUser);
    //============================================================================
    void saveData(const std::string& filename) const;
    void loadData(const std::string& filename);

    //==I do really hate this class the most exusating one 
};