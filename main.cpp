#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// NRC standards for radiation dose limits (as of January 2022)
const double NRC_OCCUPATIONAL_LIMIT = 50; // Occupational dose limit in millisieverts (mSv) per year
const double NRC_ENVIRONMENTAL_LIMIT = 1; // Environmental dose limit in millisieverts (mSv) per year

// Factors for different radiation types
const double ALPHA_FACTOR = 1.5; // Factor for alpha radiation dose calculation
const double BETA_FACTOR = 1.2;  // Factor for beta radiation dose calculation
const double GAMMA_FACTOR = 1.0; // Factor for gamma radiation dose calculation
const double NEUTRON_FACTOR = 2.0; // Factor for neutron radiation dose calculation

// Function to calculate radiation dose based on input parameters
double calculateDose(double exposureTime, double distance, double shieldingThickness, string radiationType, int exposureType) {
    // Adjusted dose based on distance and shielding
    double adjustedDose = exposureTime * distance / (shieldingThickness + 1);

    // Adjust dose based on radiation type
    double radiationFactor = 1.0;
    if (radiationType == "alpha") {
        radiationFactor = ALPHA_FACTOR;
    } else if (radiationType == "beta") {
        radiationFactor = BETA_FACTOR;
    } else if (radiationType == "gamma") {
        radiationFactor = GAMMA_FACTOR;
    } else if (radiationType == "neutron") {
        radiationFactor = NEUTRON_FACTOR;
    }

    // Calculate final dose based on exposure type (occupational or environmental)
    double dose;
    if (exposureType == 1) {
        // Occupational exposure
        dose = adjustedDose * radiationFactor;
    } else {
        // Environmental exposure
        dose = adjustedDose / radiationFactor;
    }

    return dose;
}

// Function to classify dose based on NRC standards
string classifyDose(double dose, int exposureType) {
    double limit;
    if (exposureType == 1) {
        // Occupational exposure limit
        limit = NRC_OCCUPATIONAL_LIMIT;
    } else {
        // Environmental exposure limit
        limit = NRC_ENVIRONMENTAL_LIMIT;
    }

    if (dose > limit) {
        return "Dangerous";
    } else {
        return "Safe";
    }
}

// Function to display the NRC standards table
void displayNRCTable() {
    cout << "NRC Standards for Radiation Dose Limits (as of January 2022):" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Occupational Limit: " << NRC_OCCUPATIONAL_LIMIT << " mSv/year" << endl;
    cout << "Environmental Limit: " << NRC_ENVIRONMENTAL_LIMIT << " mSv/year" << endl;
    cout << "---------------------------------------------------------" << endl;
}

int main() {
    // Display NRC standards table
    displayNRCTable();

    // Input parameters
    double exposureTime, distance, shieldingThickness;
    string radiationType;
    int exposureType;

    // Prompt user for input
    cout << "Enter exposure time (hours): ";
    cin >> exposureTime;

    cout << "Enter distance from radiation source (meters): ";
    cin >> distance;

    cout << "Enter shielding thickness (centimeters): ";
    cin >> shieldingThickness;

    cout << "Enter radiation type (alpha, beta, gamma, neutron): ";
    cin >> radiationType;

    cout << "Enter exposure type (1 for occupational, 2 for environmental): ";
    cin >> exposureType;

    // Calculate dose
    double dose = calculateDose(exposureTime, distance, shieldingThickness, radiationType, exposureType);

    // Classify dose based on exposure type
    string doseClassification = classifyDose(dose, exposureType);

    // Display results
    cout << "\nCalculated dose: " << dose << " mSv" << endl;
    cout << "Dose classification: " << doseClassification << " for ";
    if (exposureType == 1) {
        cout << "occupational exposure" << endl;
    } else {
        cout << "environmental exposure" << endl;
    }

    // Write results to a file
    ofstream outputFile("radiation_dose_result.txt");
    if (outputFile.is_open()) {
        outputFile << "Exposure Time (hours): " << exposureTime << endl;
        outputFile << "Distance from Source (meters): " << distance << endl;
        outputFile << "Shielding Thickness (centimeters): " << shieldingThickness << endl;
        outputFile << "Radiation Type: " << radiationType << endl;
        outputFile << "Exposure Type: " << (exposureType == 1 ? "Occupational" : "Environmental") << endl;
        outputFile << "Calculated Dose (mSv): " << dose << endl;
        outputFile << "Dose Classification: " << doseClassification << endl;
        outputFile.close();
        cout << "\nResults written to 'radiation_dose_result.txt'" << endl;
    } else {
        cerr << "Error: Unable to write to file." << endl;
    }

    return 0;
}
