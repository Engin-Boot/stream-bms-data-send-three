#define CATCH_CONFIG_MAIN
#include"catch.hpp"
#include "CaptureData.h"
#include <string>
#include<iostream>
#include<vector>
#include<regex>


TEST_CASE("Reding input from sender") {
	std::string input;
	float sum = 0;
	int countForParameter = 0;
	ReadingData data;
	while (std::getline(std::cin, input))
	{
		if (input.empty())
			break;

		std::regex reg("-?(([1-9]\\d*\\.\\d*)|(0\\.\\d*[1-9]\\d*))");
		const std::sregex_iterator end;
		for (std::sregex_iterator iter(cbegin(input), std::cend(input), reg); iter != end; ++iter) {
			countForParameter++;
			float num_float = std::stof(iter->str());

			if (countForParameter == 1)
				data.capturedtemperature.push_back(num_float);
			if (countForParameter == 2)
				data.capturedSoc.push_back(num_float);
			if (countForParameter == 3)
				data.capturedChargingRate.push_back(num_float);
		}
		countForParameter = 0;
		
	}
	/*------------------------------capturedtemperature------------------------------*/
	assert(data.calculation(data.capturedtemperature) == true);
	assert(data.ToConsole(data.capturedData, "capturedtemperature") == true);
	assert(data.refresh() == true);
	
	/*------------------------------capturedSoc-------------------------------------*/
	assert(data.calculation(data.capturedSoc) == true);
	assert(data.ToConsole(data.capturedData, "capturedSoc") == true);
	assert(data.refresh() == true);

	/*------------------------------capturedChargingRate-----------------------------*/
	assert(data.calculation(data.capturedChargingRate) == true);
	assert(data.ToConsole(data.capturedData, "capturedSoc") == true);
	assert(data.refresh() == true);
	
	system("pause");
}