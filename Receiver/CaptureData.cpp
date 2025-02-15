#include"CaptureData.h"
#include<algorithm>
#include<iostream>
#include"CaptureData.h"

bool ReadingData::seperateData(const std::vector < std::vector < float >> & listData) {
	for (const auto & sublist : listData) {
		capturedtemperature.push_back(sublist[0]);
		capturedSoc.push_back(sublist[1]);
		capturedChargingRate.push_back(sublist[2]);
	}
	return true;
}

bool ReadingData::ToConsole(const std::vector<float>& DataToConsole, std::string dataType) {
	std::cout << "------------------" << dataType.data() << "------------------" << "\n";
	std::cout << "MIN : " << DataToConsole[0] << " MAX : " << DataToConsole[1] << " Average : " << DataToConsole[2] << "\n\n\n";
	return true;
}
bool ReadingData::refresh() {
	capturedData.erase(capturedData.begin(), capturedData.end());
	if (capturedData.empty())
		return true;
	return false;
}

bool ReadingData::calculation(const std::vector<float>& data) {
	int limit = 5;
	float sum = 0;
	for (int iter = 0; iter < limit; ++iter) {
		sum = sum + data[iter];
	}

	capturedData.push_back(*min_element(data.begin(), data.end()));
	capturedData.push_back(*max_element(data.begin(), data.end()));
	capturedData.push_back(sum / limit);
	return true;
}

