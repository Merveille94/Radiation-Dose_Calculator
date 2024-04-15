# Radiation-Dose_Calculator
This is a Radiation Dose Calculator (RDC) that I developed as a Hobby Project in 2021 Using C++, Now converted into WebApp
I will be uploading the C++ files as a reference or collaboration but the main reason for this repo is to update the dose limit in real-time.
according to NRC or ICRP standard fleet, I could not accomplish in C++ running on my local computer in CodeBlocks.
I also thought of using Python to achieve this but I am currently unable to do so due to certain constraints.

## These are a few of the considered parameters:

 <u>Type of Radiation:</u> Different types of radiation have different effects on the body. Common types include alpha, beta, gamma, and neutron radiation.

 Radiation Source: Whether it's a medical device, nuclear reactor, or environmental exposure.

 Exposure Time: The duration of radiation exposure, measured in seconds, minutes, hours, or years.

 Distance from Source: The distance between the radiation source and the individual or object being exposed. FYI: Radiation intensity decreases with distance.

 Shielding Material and Thickness: If there's any shielding (e.g., lead, concrete) between the radiation source and the exposed object, (material and thickness = take input for that too)

 Energy of Radiation: The energy of radiation can influence its penetration ability and biological effects.

 Body Part Exposed: Different parts of the body have varying sensitivities to radiation. For example, the skin, eyes, and bone marrow are particularly sensitive.

 Dosimetric Data: This includes parameters such as absorbed dose (measured in grey or rad), equivalent dose (measured in sievert or rem), and effective dose, which accounts for the different biological effects of different types of radiation (measured in sievert or rem).

 Biological Factors: Some calculators might also take into account factors such as age, gender, and overall health, as these can affect an individual's sensitivity to radiation.

 Regulatory Limits: For occupational or environmental exposures, it's important to compare calculated doses against regulatory limits set by organizations like the International Commission on Radiological Protection (ICRP) or the Nuclear Regulatory Commission (NRC).

## Initially my C++ did not account for some of this data but you would be able to go through the data yourself in the CPP folder.
