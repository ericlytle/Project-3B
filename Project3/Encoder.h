#include <map>
using namespace std;

template<typename key_type, typename data_type>
class Encoder
{
public:
	Encoder<key_type, data_type>();
	void Encode(string toBeEncoded);
	void PopulateMap(string fileName);
	string getEncodedMessage();

private:
	map<key_type, data_type> messageEncoder;
	int index;
	string encodedMessage, WHITESPACE, COMMA;
	ifstream inputFile;
	void openFile(string fileName);
};

template<typename key_type, typename data_type>
Encoder<key_type, data_type>::Encoder()
{
	index = 0; 
	encodedMessage = "";
	WHITESPACE = " ";
	COMMA = ",";
}

template<typename key_type, typename data_type>
void Encoder<key_type, data_type>::openFile(string fileName){
	inputFile.open(fileName);
	if (!inputFile){
		throw std::runtime_error(fileName + " File Not Found");
		exit(1);
	}
}

template<typename key_type, typename data_type>
string Encoder<key_type, data_type>::getEncodedMessage()
{
	return encodedMessage;
}

template<typename key_type, typename data_type>
void Encoder<key_type, data_type>::PopulateMap(string fileName)
{
	openFile(fileName);
	string tempString;
	while (!inputFile.eof())
	{
		getline(inputFile, tempString);
		messageEncoder[tempString[0]] = tempString.substr(1, string::npos);
	}
}

template<typename key_type, typename data_type>
void Encoder<key_type, data_type>::Encode(string toBeEncoded)
{
	if (index == toBeEncoded.length())                      //comma delimeter between words
		return;
	toBeEncoded[index] == ' ' ? encodedMessage += COMMA 
							  : encodedMessage += messageEncoder[toBeEncoded[index]] + WHITESPACE;	
	++index;
	Encode(toBeEncoded);
	return;
}
