def display_nrc_standards():
    print("NRC Standards for Radiation Dose Limits (as of January 2022):")
    print("-------------------------------------------------------------")
    print("Occupational Limit: 50 mSv/year")
    print("Environmental Limit: 1 mSv/year")
    print("-------------------------------------------------------------")

def calculate_dose(exposure_time, distance, shielding_thickness, radiation_type, exposure_type):
    # Calculation for demonstration
    # Actual calculation involving factors
    adjusted_dose = exposure_time * distance / (shielding_thickness + 1)
    
    # Adjust dose based on radiation type
    if radiation_type == "alpha":
        radiation_factor = 1.5
    elif radiation_type == "beta":
        radiation_factor = 1.2
    elif radiation_type == "gamma":
        radiation_factor = 1.0
    elif radiation_type == "neutron":
        radiation_factor = 2.0
    
    # Calculate final dose based on exposure type
    if exposure_type == 1:
        # Occupational exposure
        dose = adjusted_dose * radiation_factor
    else:
        # Environmental exposure
        dose = adjusted_dose / radiation_factor
    
    return dose

def classify_dose(dose, exposure_type):
    # Define dose limits based on exposure type
    if exposure_type == 1:
        # Occupational exposure limit
        limit = 50 # mSv/year
    else:
        # Environmental exposure limit
        limit = 1 # mSv/year
    
    # Classify dose
    if dose > limit:
        return "Dangerous"
    else:
        return "Safe"

# Display NRC standards table
display_nrc_standards()

# Prompt user for input
exposure_time = float(input("Enter exposure time (hours): "))
distance = float(input("Enter distance from radiation source (meters): "))
shielding_thickness = float(input("Enter shielding thickness (centimeters): "))
radiation_type = input("Enter radiation type (alpha, beta, gamma, neutron): ")
exposure_type = int(input("Enter exposure type (1 for occupational, 2 for environmental): "))

# Calculate dose
dose = calculate_dose(exposure_time, distance, shielding_thickness, radiation_type, exposure_type)

# Classify dose
dose_classification = classify_dose(dose, exposure_type)

# Display results
print("\nResults:")
print(f"Calculated Dose: {dose} mSv")
print(f"Dose Classification: {dose_classification} for {'occupational' if exposure_type == 1 else 'environmental'} exposure")
