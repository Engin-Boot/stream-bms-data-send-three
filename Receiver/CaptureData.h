#pragma once
#include "CaptureDataInterface.h"
#include "iostream"
#include <vector>
#include <map>

class ReadingData: public interfaceForReading {

public:
	float maxValue;
	float minValue;
	float averageValue;
	std::vector<float> capturedtemperature;
	std::vector<float> capturedSoc;
	std::vector<float> capturedChargingRate;
	std::vector<float> capturedData;
	std::vector<float> temp;
	std::vector < std::vector < float >> readingData;
	bool calculation(const std::vector<float>& temp);
	bool refresh();
	bool ToConsole(const std::vector<float>& DataToConsole, std::string dataType);
	bool seperateData(const std::vector<std::vector<float>>& listData);

};