#pragma once

class GasStation {
public:
	GasStation(int id, int capacity, int distanceToNextGasStation);
	~GasStation();

	int mID;
	int mCapacity;
	int mDistanceToNextGasStation;

	int mReserve; // mCapacity - mDistanceToNextGasStation

};
