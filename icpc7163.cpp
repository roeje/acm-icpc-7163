//
// Created by Jesse on 11/30/2015.
//
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int solver (int& x, int& n, int& y, int& m);
void read_values(int &x, int &n, int &y, int &m, string &io);
int gcd(int a, int b);
vector <int> vec;

//void readData(istream& input) {
//    int cases;
//    input >> cases;
//    int x, n, y, m;
//    int count = 1;
//
//    while (cases > 0){
//        string temp;
//        getline(cin, temp);
//        read_values(x, n, y, m, temp);
////        cout << to_string(vec.at(0)) << to_string(vec.at(1)) << to_string(vec.at(2)) << to_string(vec.at(3)) << endl;
//        cout << "Case " << to_string(count) << ": " << to_string(solver(vec.at(0), vec.at(1), vec.at(2), vec.at(3))) << endl;
//        vec.clear();
//        cases--;
//        count++;
//    }
//}

void read_values(int &x, int &n, int &y, int &m, string &io){
    stringstream ss(io);
    string temp = "";
    while(ss.good()){
        ss >> temp;
        if(temp != "") {
            vec.push_back(stoi(temp));
        }
    }
}

int solver (int& x, int& n, int& y, int& m) {
    pair<int, int> sum (x, 0);
    for (int i= 0; i < m; i++){
        if(i == n) {
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
//    cout << "first: " << sum.first << " second: " << sum.second << endl;
    return gcd(sum.first, sum.second);
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
//    string ex_data = "";
//    cout << "enter the data: ";//
//    cin.clear();
//    getline(cin, ex_data);
//    istringstream ss(ex_data);
//    readData(ss);


    istream &data = cin;
//    readData(data);

    int cases;
    input >> cases;
    int x, n, y, m;
    int count = 1;

    while (cases > 0){
        string temp;
        getline(cin, temp);
        read_values(x, n, y, m, temp);
//        cout << to_string(vec.at(0)) << to_string(vec.at(1)) << to_string(vec.at(2)) << to_string(vec.at(3)) << endl;
        cout << "Case " << to_string(count) << ": " << to_string(solver(vec.at(0), vec.at(1), vec.at(2), vec.at(3))) << endl;
        vec.clear();
        cases--;
        count++;
    }

//    string temp = "";
//    istringstream is;
//    while(getline(cin, temp)) {
//
//    }
}

//2
//4 3 6 5
//5 1 15 2
