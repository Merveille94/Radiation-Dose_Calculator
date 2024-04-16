document.getElementById('doseCalculatorForm').addEventListener('submit', function(event) {
    event.preventDefault();

    // Retrieve input values
    const exposureTime = parseFloat(document.getElementById('exposureTime').value);
    const distance = parseFloat(document.getElementById('distance').value);
    const shieldingThickness = parseFloat(document.getElementById('shieldingThickness').value);
    const radiationType = document.getElementById('radiationType').value;
    const exposureType = parseInt(document.getElementById('exposureType').value);

    // Calculate dose
    const dose = calculateDose(exposureTime, distance, shieldingThickness, radiationType, exposureType);

    // Classify dose
    const doseClassification = classifyDose(dose, exposureType);

    // Display results
    document.getElementById('doseResult').innerHTML = `
        <h3>Results:</h3>
        <p>Calculated Dose: ${dose} mSv</p>
        <p>Dose Classification: ${doseClassification}</p>
    `;
});

// Function to calculate radiation dose based on input parameters
function calculateDose(exposureTime, distance, shieldingThickness, radiationType, exposureType) {
    // Placeholder calculation for demonstration
    // Actual calculation would involve more complex factors
    const adjustedDose = exposureTime * distance / (shieldingThickness + 1);
    let radiationFactor = 1.0;

    // Adjust dose based on radiation type
    switch (radiationType) {
        case 'alpha':
            radiationFactor = 1.5;
            break;
        case 'beta':
            radiationFactor = 1.2;
            break;
        case 'gamma':
            radiationFactor = 1.0;
            break;
        case 'neutron':
            radiationFactor = 2.0;
            break;
    }

    // Calculate final dose based on exposure type
    let dose;
    if (exposureType === 1) {
        // Occupational exposure
        dose = adjustedDose * radiationFactor;
    } else {
        // Environmental exposure
        dose = adjustedDose / radiationFactor;
    }

    return dose;
}

// Function to classify dose based on NRC standards
function classifyDose(dose, exposureType) {
    let limit;
    if (exposureType === 1) {
        // Occupational exposure limit
        limit = 50; // mSv/year
    } else {
        // Environmental exposure limit
        limit = 1; // mSv/year
    }

    if (dose > limit) {
        return "Dangerous";
    } else {
        return "Safe";
    }
}