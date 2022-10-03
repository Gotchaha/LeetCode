#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <sstream>
using namespace std;

stack<char> a;
map<char, char> m {{'(', ')'}, {'[', ']'}, {'{', '}'}};

bool isValid (string s) {
    stringstream ss(s);
    char x = 0, y = 0;
    bool flag = true;
    while (ss >> x)
    {
        if (x == '(' || x == '[' || x == '{')
            a.push(x);
        else if (x == ')' || x == ']' || x == '}')
            {
                if (a.empty())
                {
                    flag = false;
                    break;
                }
                y = a.top();
                a.pop();
                if (x != m[y])
                {
                    flag = false;
                    break;
                }
            }
    }
    
    if (flag) flag = a.empty();
    return flag;
}

int main() {
    string s;
    cin >> s;
    bool flag = isValid(s);
    cout << boolalpha;
    cout << flag;
    return 0;
}