/***************************************************************************************
 
Alexis Martinez 
CSC-240-001
06/16/2023

6.1 OVERLOADED HOSPITAL

This program calculates the total charges for a patient's hospital visit.
Depending on whether the patient is admitted as an inpatient or outpatient,
different hosptial charge data will be required. The total cost will then be added up & displayed.

****************************************************************************************/

#include <iostream>
#include <string>
#include <algorithm> // for `transform` & `tolower`
#include <iomanip>   // for `fixed` & `setprecision`
using namespace std;

double totalCharge(double serviceCharges, double medicationCharges, int numDaysInHospital, double dailyStayRate);
double totalCharge(double serviceCharges, double medicationCharges);

int main(){
    string inpatientOrOutpatient;
    double serviceCharges;
    double medicationCharges;
    int numDaysInHospital; // Needed for inpatients only.
    double dailyStayRate; // Needed for inpatients only.
    
    cout << "Hello! Let's calculate the total charge for the patient's hospital visit.\n";

    // This while loop checks for a valid response to the inpatient or outpatient question before proceeding.
    // It also allows for an error message and reprompting to occur for invalid responses.
    while (inpatientOrOutpatient != "inpatient" || inpatientOrOutpatient != "outpatient"){
        // Requests and records an input ("inpatient" or "outpatient") to determine what hospital
        // charge data will be needed.
        cout << "\nWas the patient admitted as an `inpatient` or `outpatient`? ";
        cin >> inpatientOrOutpatient;

        // This function converts the string input `inpatientOrOutpatient` to be all lowercase.
        // EX. "Inpatient", "INPATIENT", "InPaTiEnT" will become "inpatient"
        // This neutralizes case sensitivity when evaluating the string.
        transform(
            inpatientOrOutpatient.begin(),
            inpatientOrOutpatient.end(),
            inpatientOrOutpatient.begin(),
            ::tolower);

        // Prompts user for total services charge, which is needed for both inpatients & outpatients.
        cout << "\nHow much were the services rendered? (i.e. lab tests, etc.)\n"
             << "NOTE: Your response should be numerical only. Do NOT include `$` or any other symbols. ";
        cin >> serviceCharges;

        // Prompts user for total medications charge, which is needed for both inpatients & outpatients.  
        cout << "\nHow much were the medications prescribed?\n"
             << "NOTE: Your response should be numerical only. Do NOT include `$` or any other symbols. ";
        cin >> medicationCharges;

        // Prompts the user for data needed if admission was `inpatient`.
        // Additional data needed is number of days in hospital and the stay rate per day.
        if (inpatientOrOutpatient == "inpatient") {
            cout << "\nHow many days did the patient stay in the hospital?"
                 << "\nNOTE: Your response should be numerical only. ";
            cin >> numDaysInHospital;
            
            cout << "\nHow much was it per day to stay at the hospital?"
                 << "\nNOTE: Your response should be numerical only. Do NOT include `$` or any other symbols. ";
            cin >> dailyStayRate;
            
            // Records & assigns the return value of the totalCharge function.
            double total = totalCharge(
                serviceCharges, medicationCharges, numDaysInHospital, dailyStayRate);

            // Displays the total hospital charge in dollars & cents ($x.xx) format.
            cout << "\n$" << fixed << showpoint << setprecision(2) 
                 << total << " is the total charge for the patient's hospital visit.";

            break;
        } else if (inpatientOrOutpatient == "outpatient") {
            // Records & assigns the return value of the totalCharge function.
            double total = totalCharge(serviceCharges, medicationCharges);

            // Displays the total hospital charge in dollars & cents ($x.xx) format.
            cout << "\n$" << fixed << showpoint << setprecision(2) 
                 << total << " is the total charge for the patient's hospital visit.";

            break;
        } else {
            // Displays error message for invalid response to the inpatient or outpatient question.
            cout << "Invalid response detected. Please respond either 'inpatient' or 'outpatient'.\n";
        }
    }
    return 0;
}

// Calculates the total cost by adding up the relevant inpatient admission charges.
double totalCharge(double serviceCharges, double medicationCharges, int numDaysInHospital, double dailyStayRate){
    return serviceCharges + medicationCharges + (numDaysInHospital * dailyStayRate);
}

// Calculates the total cost by adding up the relevant outpatient admission charges.
double totalCharge(double serviceCharges, double medicationCharges){
    return serviceCharges + medicationCharges; 
}
