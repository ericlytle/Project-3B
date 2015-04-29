//main
#include "Morse.h"
#include <string>
#include <iostream>
using namespace std;


int main(){ 
	Morse<string> MorseCode("morse.txt");
	
	cout << MorseCode.decode("._ _... _._.") << endl; //decode test
	
	cout << MorseCode.encode("eric Brad LuKe") << endl; //encode test with random case | is delimiter between words
	
	cout << MorseCode.decode(MorseCode.encode("eric Brad LuKe"));
	
	
	
	cout << endl;
	system("pause");
	return 0;
}

