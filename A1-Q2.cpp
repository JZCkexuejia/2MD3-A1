#include<iostream>
using namespace std;
template<typename T1, typename T2>
class Pair {
    T1 value1;
    T2 value2;

public:
    Pair(T1 v1, T2 v2) : value1(v1), value2(v2) {}

    void print() {
        cout << "<" << value1 << "," << value2 << ">" << endl;
    }
};

int main() {
    Pair<int, double> p1(1, 7.3);
    p1.print();

    Pair<string, double> p2("hello", 7.7);
    p2.print();

    Pair<float, long> p3(1.2, 777777773);
    p3.print();

    return 0;
}

