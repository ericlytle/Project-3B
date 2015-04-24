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
	MT.buildTree();
	enc.PopulateMap();
	enc.Encode("eric");
	cout << enc.getEncodedMessage() << endl;


	system("pause");

}
