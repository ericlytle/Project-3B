//main
#include "Morse.h"
#include "Encoder.h"
#include <string>
#include <map>
#include <iostream>
using namespace std;


int main(){ 
	Morse<string> MT("morse.txt");; //I feel that morse tree should be a single object contining
	cout << MT.encode("Eric brad luke");


	//cout << endl << MT.decode(encoder.getEncodedMessage());


	system("pause");

}
