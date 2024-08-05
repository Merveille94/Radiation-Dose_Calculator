# C++ Radiation Dose Calculator

## Overview

This project is a command-line Radiation Dose Calculator implemented in C++. It allows users to estimate radiation exposure from various sources and calculate effective doses, helping professionals and individuals understand and manage radiation risks.

## Features

- User-friendly command-line interface
- Multiple calculation options:
  - External radiation exposure
  - Internal radiation exposure (ingestion and inhalation)
  - Medical radiation procedures
- Real-time calculation of radiation doses
- Conversion between different dose units (Sv, rem, Gy)
- Comparison with common radiation exposure scenarios
- Informative ASCII art intro

## Benefits

1. Safety: Helps users assess potential radiation exposure risks
2. Education: Provides insights into different sources of radiation
3. Versatility: Allows calculations for various exposure scenarios
4. Accessibility: Easy to use on any system with a C++ compiler

## How to Use

1. Compile the C++ file:
   ```
   g++ radiation_dose_calculator.cpp -o rad_calculator
   ```
2. Run the executable:
   ```
   ./rad_calculator
   ```
3. Follow the on-screen prompts to input exposure data
4. Choose which types of radiation exposure to calculate
5. View your results and total effective dose

## Technical Details

- Language: C++
- Compiler: Any standard C++ compiler (e.g., GCC, Clang)
- No external libraries were required

## Calculations Included

- External Radiation: Based on exposure time and dose rate
- Internal Radiation: Calculates committed effective dose from ingestion or inhalation
- Medical Procedures: Estimates doses from common radiological examinations
- Unit Conversions: Between Sievert (Sv), rem, and Gray (Gy)

## Future Enhancements

- Add more specific radioisotopes and their characteristics
- Implement dose calculations for different body organs
- Create a graphical user interface (GUI) version
- Include a database of common radiation sources for quick reference

## Contribution

Contributions, issues, and feature requests are welcome. Feel free to check [issues page](https://github.com/Merveille94/Radiation-Dose_Calculator.git) if you want to contribute.

## License

MIT license

---

**Note on Project History:**

This C++ Radiation Dose Calculator was developed in [Month] 2024 as a local application to assist in radiation safety and education. It serves as a tool for radiation professionals, students, and anyone interested in understanding radiation exposure.

- C++ Version Development: [September] 2023

---

**Disclaimer:** This calculator is for educational and estimation purposes only. For accurate radiation dose assessments in professional or medical contexts, always consult with qualified radiation protection experts or medical physicists.

For any questions or feedback, please contact [Email: emanueleguehi@gmail.com].
