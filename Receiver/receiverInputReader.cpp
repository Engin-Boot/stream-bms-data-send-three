//#define CATCH_CONFIG_MAIN
#include"catch.hpp"
#include "CaptureData.h"
#include <string>
#include<iostream>
#include<vector>
#include<regex>

int main(int argc, char** argv)
{
	std::string input;;
	ReadingData data;
	std::cout << "You have entered " << argc
		<< " arguments:" << "\n";
	for (int i = 0; i < argc; ++i){
		std::cout << argv[i] << "\n";
	//while (std::getline(std::cin, input))
	//{
		//if (input.empty())
		//	break;
		input = argv[i];
		std::regex reg("-?(([1-9]\\d*\\.\\d*)|(0\\.\\d*[1-9]\\d*))");
		const std::sregex_iterator end;
		for (std::sregex_iterator iter(cbegin(input), std::cend(input), reg); iter != end; ++iter) {

			float num_float = std::stof(iter->str());
			data.temp.push_back(num_float);
		}
		data.readingData.push_back(data.temp);
		data.temp.clear();
	}
	
	
	/*------------------------------separate data------------------------------------*/
	data.seperateData(data.readingData);
	
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

	return 0;
}
