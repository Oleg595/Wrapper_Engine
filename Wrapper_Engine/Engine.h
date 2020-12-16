#pragma once
#include"Wrapper.h"

class Engine {
private:
	std::vector<std::pair<Wrapper*, std::string>> vector;
public:
	Engine() {};

	void register_command(Wrapper* wrapper, std::string str);

	int execute(std::string str, const std::map<std::string, int> arguments);
};