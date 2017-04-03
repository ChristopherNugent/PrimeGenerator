#include <iostream>				// basic IO
#include <fstream>				// writing to files
#include <string>				// storing strings, could be replaced with char[]'s
#include <cmath>				// sqrt function
#include <vector>				// storage, to be replaced eventually with linked list
using namespace std;


void writePrimes(int, ostream&);


int main() {
	int targetCount;
	string filename;
	cout << "Please enter the filename to store the generated primes in, or \"display\" for print to screen: ";
	cin >> filename;
	cout << "Please enter the number of prime numbers to generate: ";
	cin >> targetCount;

	if (filename == "display") 
	{
		writePrimes(targetCount, cout);
	}
	else 
	{
		ofstream ofs;
		ofs.open(filename);
		writePrimes(targetCount, ofs);
	}
}

// TODO: Convert to properly used LinkedList to avoid resize times
void writePrimes(int targetCount, ostream& outStream)
{
	vector<int> primes;
	primes.push_back(2);

	int current = 3;
	while (primes.size() < targetCount)
	{
		bool isPrime = true;
		for (int i = 0; i < primes.size(); i++)
		{
			if (primes.at(i) > sqrt(current))
				break;
			else if (current % primes.at(i) == 0)
				isPrime = false;
		}
		if (isPrime) primes.push_back(current);
		current += 2;
	}
	for (int i = 0; i < primes.size(); i++)
	{
		outStream << primes.at(i) << endl;
	}
}