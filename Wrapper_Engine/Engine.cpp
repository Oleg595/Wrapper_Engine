#include"Engine.h"

void Engine::register_command(Wrapper* wrapper, std::string str) {
	vector.push_back(std::make_pair(wrapper, str));
}

int Engine::execute(std::string str, const std::map<std::string, int> arguments) {
	for (int i = 0; i < vector.size(); i++) {
		if (strcmp(vector[i].second.c_str(), str.c_str()) == 0) {
			vector[i].first->NewArgs(arguments);
			return vector[i].first->Execute();
		}
	}
}