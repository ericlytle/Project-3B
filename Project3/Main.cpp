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
	MT.PopulateMap();
	MT.Encode("eric");
	cout << MT.getEncodedMessage() << endl;


	system("pause");

}
