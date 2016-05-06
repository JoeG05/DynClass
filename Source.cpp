#include <iostream>
#include <map>
#include <string>

using namespace std;

class Dyn_Class{
private:
	map<string, void (*)()> funcs;

public:
	template<typename retValue>
	void add_func(string funcName, retValue(*func)()){
		auto it = funcs.find(funcName);
		if (it == funcs.end())
			funcs[funcName] = *func;
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

	void operator()(string funcName){
		funcs[funcName]();
	}
};

void print(void){
	cout << "test" << endl;
}


int add(int a, int b)
{
	return a + b;
}


int main() {
	Dyn_Class funcs;
	funcs.add_func("print", print);
	funcs.add_func("print", print);
	
	string name = "print";
	funcs(name);

	funcs.remove_func("p");
	
	funcs.add_func("add", add);

	system("Pause");
}