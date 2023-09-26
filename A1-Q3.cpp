#include <cstdlib>
#include <iostream>
using namespace std;

class Progression { // a generic progression
public:
	Progression(long f = 0) // constructor
	: first(f), cur(f) {}
	virtual ~Progression(){}; // destructor
	void printProgression(int n); // print the first n values
protected:
	virtual long firstValue(); // reset
	virtual long nextValue(); // advance
	long first; // first value
	long cur; // current value
};

void Progression::printProgression(int n) { // print n values
	cout << firstValue(); // print the first
	for (int i = 2; i <= n; i++) // print 2 through n
	cout << ' ' << nextValue();
	cout << endl;
}

long Progression::firstValue() { // reset
	cur = first;
	return cur;
}
long Progression::nextValue() { // advance
	return ++cur; 
}

class AbsDiffProgression : public Progression {
public:
	AbsDiffProgression(long f = 200, long s = 2) // default constructor
	: Progression(f),base(s) {}
	~AbsDiffProgression(){};
protected:
	virtual long firstValue();
	virtual long nextValue();
private:
	long prev;
	long base;
	
};

long AbsDiffProgression::firstValue() {
	cur=first;
	return abs(cur);
}

long AbsDiffProgression::nextValue() {
	prev = cur;
	cur=abs(prev-base);
	base=prev;
	return cur;
}

int main() {
	AbsDiffProgression defaultProg;
	cout << "Absolute progression with default constructor:\n";
	defaultProg.printProgression(10);
	AbsDiffProgression paramProg(300,3);
	cout << "Absolute progression with custom constructor:\n";
	paramProg.printProgression(10);
return 0;
}
