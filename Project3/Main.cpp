//main
#include "Morse.h"
#include "Encoder.h"
#include <string>
#include <map>
#include <iostream>
using namespace std;


int main(){ 
	Morse<string> MT("morse.txt");; //I feel that morse tree should be a single object contining
	cout << MT.decode("__. _.") << endl; //decode test
	cout << MT.encode("eric Brad LuKe") << endl; //encode test with random case | is delimiter between words

	system("pause");

}
