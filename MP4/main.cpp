/// @file main.cpp
/// @brief Main entry point for the program.
/// @author Joshua Fisher
#include "ServiceCenter.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <inputFile> <outputFile>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    // Create the service center
    ServiceCenter serviceCenter;

    // Process the input file to setup the simulation
    serviceCenter.processFile(inputFile, outputFile);

    // Advance the simulation time, implementing the actual simulation logic
    // This part would require you to loop over time units and trigger events according to the input specifications
    // Here we simply call a placeholder function; you would expand this to handle the full simulation
    serviceCenter.advanceTime();

    // Output results to console or file (you might want to implement a method in ServiceCenter to handle output)
    std::cout << "Simulation results are saved to " << outputFile << std::endl;

    return 0;
}
