#include <iostream>
#include <map>
#include <string>
#include <stdarg.h>
#include <vector>
#include <iterator>

using namespace std;

class Dyn_Class{
private:
	map<string, void *> funcs;

public:
	template<typename retValue>
	void add_func(string funcName, retValue(*func)()){
		auto it = funcs.find(funcName);
		if (it == funcs.end())
			funcs[funcName] = func;
		else
			cout << "Function already exists." << endl;
		
	}

	void remove_func(string funcName){
		auto it = funcs.find(funcName);
		if (it != funcs.end())
			funcs.erase(it);
		else
			cout << "Function does not exist." << endl;
	}
	template<typename T>
	void operator()(string funcName, int count, ...){
		va_list vl;
		vector<T> args;
		va_start(vl, count);
		for (int i = 0; i < count; i++)
			args.push_back(va_arg(vl, T));
		funcs[funcName](count, args);
	}
};

template<typename T>
void print(int count, vector<T> args){
	cout << "test" << endl;
}

template<typename T>
T add(int count, vector<T> args)
{
	
}


int main() {
	Dyn_Class funcs;
	funcs.add_func("print", print);
	funcs.add_func("print", print);
	
	string name = "print";
	funcs(name, 0);

	funcs.remove_func("p");
	
	funcs.add_func("add", add);

	system("Pause");
}