#pragma once
#include<vector>

class interfaceForReading {
public:
	virtual bool calculation(const std::vector<float>& data) = 0;
};
