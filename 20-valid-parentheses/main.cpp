#include <iostream>

using namespace std;

#include <stack>

bool isValid(string s) {
	stack<char> memory;

	for (char const &c: s) {
		if(c == '{' || c == '[' || c == '(') {
			memory.push(c);
		} else if (!memory.empty() && (memory.top() == '[' && c == ']' || memory.top() == '{' && c == '}' || memory.top() == '(' && c == ')')) {
			memory.pop();
		} else {
			return false;
		}
	}

	return memory.empty();
}

int main() {
	std::cout << isValid("{{[]}}") << std::endl;
	return 0;
}
