//main
#include "Morse.h"
#include <string>
#include <iostream>
using namespace std;


int main(){ 
	Morse<string> MorseCode("morse.txt");
	
	//test decode of a b c
	string testMorse = "._ _... _._.";
	cout << MorseCode.decode(testMorse) << endl; //decode test
	
	string message = "eric LuKe BrAd";

	cout << "\nMessage: " + message << endl;
	cout << "Encoded message: ";
	cout << MorseCode.encode(message) << endl << endl; //encode test with random case | is delimiter between words
	
	cout << "Decoded message:";
	cout << MorseCode.decode(MorseCode.encode(message));
	
	
	
	cout << endl;
	system("pause");
	return 0;
}

