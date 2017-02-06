#include "GasStation.h"

GasStation::GasStation(int id, int capacity, int distanceToNextGasStation)
: mID(id), mCapacity(capacity), mDistanceToNextGasStation(distanceToNextGasStation)
{
	this->mReserve = mCapacity - mDistanceToNextGasStation;
}

GasStation::~GasStation()
{
	// TODO: Additional cleanp as needed.
}

