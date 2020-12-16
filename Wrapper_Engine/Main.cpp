#include"Wrapper.h"
#include"Engine.h"
#include<Windows.h>

int main(void) {
	Subject* subj = new Subject();;
	Wrapper wrapper(subj, &Subject::f3, { {"arg1", 0}, {"arg2", 0} });
	Engine engine;
	engine.register_command(&wrapper, "command1");
	std::cout << engine.execute("command1", { {"arg1", 4}, {"arg2", 5} });
	return 0;
}