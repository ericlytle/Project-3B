//main
#include "Morse_Tree.h"
#include "Encoder.h"
#include <string>
#include <map>
#include <iostream>
using namespace std;


int main(){ 
	Encoder<char, string> enc;
	Morse_Tree<string> MT;
	Encoder<char, string> encoder;
	encoder.PopulateMap();
	encoder.Encode("eric");
	cout << encoder.getEncodedMessage() << endl;


	system("pause");

}
