//main
#include "Morse_Tree.h"
#include "Encoder.h"
#include <string>
#include <map>
#include <iostream>
using namespace std;


int main(){ 
	Morse_Tree<string> MT;
	MT.buildTree("morse.txt");
	Encoder<char, string> encoder;
	encoder.PopulateMap("morse.txt");
	encoder.Encode("eric luke brad");
	cout << encoder.getEncodedMessage();

	cout << endl << MT.decode(encoder.getEncodedMessage());


	system("pause");

}
