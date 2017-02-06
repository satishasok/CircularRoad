#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

#include "Input.h"
#include "GasStation.h"

int main (int argc, char *argv[])
{
	// 1. Read the first argument to get the fileName for input.
	// read that file and populate the vector. Otherwise, read the Standard input.
	std::vector<GasStation> gasStations; // store the list of gas-stations in here
	if (argc < 2) {
		readGasStations(std::cin, gasStations);
	}
	else
	{
		std::ifstream in(argv[1]);
		if (not in) {
			std::perror(argv[1]);
			return EXIT_FAILURE;
		}
		readGasStations(in, gasStations);
	}

	// 2. Handle invalid input (bad data)
	int sumOfReserve = 0;
	for (GasStation gasStation : gasStations) {
		if (gasStation.mCapacity < 0 || gasStation.mDistanceToNextGasStation < 0) {
			std::cerr << "Invalid input data. gasStation cannot have negative capacity or distance to next gas Station cannot be negative." << endl;
			return EXIT_FAILURE;
		}
		sumOfReserve += gasStation.mReserve;
	}
	if (sumOfReserve < 0) {
		std::cout << "Valid input, but there is no possible solution. There is not enough gas to start at a station and finish the circle." << endl;
	} else {
		std::cout << "Valid input. There is atleast 1 solution." << endl;

	}

		
	// 4. 
	for (int i=0; i < gasStations.size(); i++) {
		if (gasStations[i].mReserve < 0) {
			continue;
		} else {
			int cumulativeReserveSum = gasStations[i].mReserve;
			int potentialStartingPoint = gasStations[i].mID;
			for (int j=i+1; j < gasStations.size()*2; j++) {
				int currentID = gasStations[j%gasStations.size()].mID;
				if (currentID == potentialStartingPoint) {
					std::cout << "Gas Station #:" << potentialStartingPoint << " is valid Starting Point." << endl;
					break;
				} else {
					cumulativeReserveSum += gasStations[j%gasStations.size()].mReserve;
					if (cumulativeReserveSum < 0) {
						break;
					}
				}
			}
		}
	}
	return EXIT_SUCCESS;
}
