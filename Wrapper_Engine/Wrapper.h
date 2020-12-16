#pragma once

#include<iostream>
#include<functional>
#include<vector>
#include<map>

class Subject {
public:
	int f3(int a, int b) {
		return a + b;
	}
};

class Wrapper {
private:
	std::vector<std::pair<std::string, int>> args;
	std::function<int()> func;

public:
	template<typename T, typename ...Args>
	Wrapper(T* elem, int(T::* method)(Args...), const std::vector<std::pair<std::string, int>>& arguments) {
		args = arguments;
		//std::index_sequence v;
		Function(elem, method, std::make_index_sequence<sizeof...(Args)>());
		//func = std::bind(method, elem, std::cref(v[N])...);
	}

	template<typename T, typename ...Args, size_t ...N>
	void Function(T* elem, int(T::* method)(Args...), std::index_sequence<N...>) {
		func = std::bind(method, elem, std::cref(args[N].second)...);
	}

	void NewArgs(std::map<std::string, int> new_args);

	int Execute();
};