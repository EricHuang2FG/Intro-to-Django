#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void print(vector <vector <int>> text) {
    string display = "";
    for (int i = 0; i < text.size(); i++) {
        display += "(" + to_string(text[i][0]) + ", " + to_string(text[i][1]) + "), ";
    }
    display = display.substr(0, display.size() - 2);
    cout << display << endl;
}

bool isInteger(string val) {
    for (int i = 0; i < val.length(); i++) {
        if (!isdigit(val[i])) {
            return false;
        }
    }
    return true;
}

int getInput(string prompt) {
    string val;
    while (true) {
        try {
            cout << prompt;
            cin >> val;
            if (isInteger(val)) {
                return stoi(val);
            } else {
                throw val;
            }
        } catch (string val) {
            cout << "Not an integer" << endl;
        }
    }
}

int f(int x, int m) {
    double ySqr = 1.0 * (((1.0 * x * x) - (1 + 0.0)) / (m * 1.0));
    double y = sqrt(ySqr);
    if (y == floor(y)) {
        return y;
    }
    return -1;
}

int main() {
    int m = getInput("m = ");
    int n = getInput("n = ");
    vector <vector <int>> solutions = {};
    for (int x = 2; x != 0; x++) {
        vector <int> solution = {x};
        if (f(x, m) != -1) {
            solution.push_back(f(x, m));
            solutions.push_back(solution);
        }
        if (solutions.size() == n) {
            break;
        }
    }
    print(solutions);
    return 0;
}