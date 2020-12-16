#include"Wrapper.h"

void Wrapper::NewArgs(std::map<std::string, int> new_args) {
	for (int i = 0; i < args.size(); i++) {
		if (new_args.find(args[i].first) != new_args.end()) {
			args[i].second = new_args[args[i].first];
		}
	}
}

int Wrapper::Execute() {
	return func();
}