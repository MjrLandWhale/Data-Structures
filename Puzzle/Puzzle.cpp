#include <iostream>
using namespace std;
//Solution 1: Change i<n to i+n (change 1 character) *WORKS*
//Solution 2: Change i-- to n--  (change 1 character) *WORKS*
//Solution 3: Change i<n to -i<n (add 1 character) *WORKS*


int main(int argc, char** argv)
{
	int i, n = 20;

	for (i=0; i<n; i--)
		cout << "-";
	cout << endl;

	return 0;
}

