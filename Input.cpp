#include <sstream>

#include "Input.h"

vector<string> tokenizeString(string input, string delimiter)
{
	vector<string> tokens;

	size_t pos = 0;
	string token;
	while ((pos = input.find(delimiter)) != string::npos) {
    		token = input.substr(0, pos);
		tokens.push_back(token);
    		input.erase(0, pos + delimiter.length());
	}
	tokens.push_back(input);

	return tokens;
}

void readGasStations(istream& in, vector<GasStation>& gasStations)
{
        string line;
        while (getline(in, line)) {
		vector<string> gasStationDataVector = tokenizeString(line, string(":"));
		
		int gasStationNumber;
		istringstream(gasStationDataVector[0]) >> gasStationNumber;

		gasStationDataVector = tokenizeString(gasStationDataVector[1], string("/")); 
		int gasStationCapacity;
		int distanceToNextGasStation = 0;
		istringstream(gasStationDataVector[0]) >> gasStationCapacity;
		istringstream(gasStationDataVector[1]) >> distanceToNextGasStation;
		GasStation gasStation(gasStationNumber, gasStationCapacity, distanceToNextGasStation);
		gasStations.push_back(gasStation);				
	}
}
