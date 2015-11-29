//
// Created by Jesse on 11/30/2015.
//
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <c++/tuple>

using namespace std;

int solver (int& x, int& n, int& y, int& m);
int gcd(int a, int b);

void readData(istream& input) {
    int cases;
//    cout << "Case Value" << to_string(cases) << endl;
    input >> cases;
    int x, n, y, m;
    int count = 1;
    while (cases > 0){
        input >> x >> n >> y >> m;
//        cout << "x = " << to_string(x) << "n = " << to_string(n) << "y = " << to_string(y) << "m = " << to_string(m) << endl;
        cout << "Case " << to_string(count) << ": " << to_string(solver(x, n, y, m)) << endl;
        cases--;
        count++;
    }
}

int solver (int& x, int& n, int& y, int& m) {
    pair<int, int> sum (x, 0);
    for (int i= 0; i < m; i++){
        if(i == (n - 1)) {
            if(sum.first >= sum.second) {
                sum.first += y;
            }
            else {
                sum.second += y;
            }
        }
        else {
            if(sum.first >= sum.second) {
                sum.second += sum.first;
            }
            else {
                sum.first += sum.second;
            }
        }
    }
    return gcd(sum.first, sum.second);
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    string ex_data = "";
    cout << "enter the data: ";

    cin.clear();
    getline(cin, ex_data);


    istringstream ss(ex_data);
    readData(ss);
//    istream &data = cin;
//    readData(data);
}