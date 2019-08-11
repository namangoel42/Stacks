#include<iostream>
#include<stack>
using namespace std;
bool function1(string st){
	stack<char> s;
	int i = 0;
	while (st[i] != '\0') {
		if (st[i] == '[' or st[i] == '{' or st[i] == '(') {
			s.push(st[i]);
			i++;
		}
		else {
			char c = s.top();//stack ke top mai kyaa padaa hai
			if (st[i] == '}' and c == '{') {
				i++;
				s.pop();
				continue;
			 }
			if (st[i] == ']' and c == '[') {
				i++;
				s.pop();
				continue;
			}
			if (st[i] == ')' and c == '(') {
				i++;
				s.pop();
				continue;
			}
			else {
				return false;
			}
			
		}
	}
	if (s.empty() == false) {
		return false;
	}

	return true;

}
int main() {
	string s;
	cin >> s;
	bool var = function1(s);
	if (var) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}