#pragma once
#include <iostream>
#include <vector>
#include <string>
class NameGenerator
{
private:
	static NameGenerator* _instance;
	std::vector<std::string> _firstName;
	std::vector<std::string> _secondName;
	std::vector<std::string> _middleAdditive;
	NameGenerator();
public:
	static NameGenerator* Instance();
	std::string GenerateName();
};

