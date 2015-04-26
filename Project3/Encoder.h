#include <map>
using namespace std;


template<typename key_type, typename data_type>
class Encoder
{
public:
	Encoder<key_type, data_type>();
	void Encode(string toBeEncoded);
	void PopulateMap();
	string getEncodedMessage();
private:
	map<key_type, data_type> messageEncoder;
	int index;
	string encodedMessage, WHITESPACE;
	ifstream inputFile;

};

template<typename key_type, typename data_type>
Encoder<key_type, data_type>::Encoder()
{
	index = 0;
	encodedMessage = "";
	WHITESPACE = " ";
	inputFile.open("morse.txt");
}

template<typename key_type, typename data_type>
string Encoder<key_type, data_type>::getEncodedMessage()
{
	return encodedMessage;
}

template<typename key_type, typename data_type>
void Encoder<key_type, data_type>::PopulateMap()
{
	string tempString;
	key_type keyValue;
	while (!inputFile.eof())
	{
		getline(inputFile, tempString);
		keyValue = tempString[0];
		messageEncoder[keyValue] = tempString.substr(1, string::npos);
	}
}

template<typename key_type, typename data_type>
void Encoder<key_type, data_type>::Encode(string toBeEncoded)
{
	key_type keyValue;
	if (index == toBeEncoded.length())
		return;
	keyValue = toBeEncoded[index];
	encodedMessage += messageEncoder[keyValue];
	encodedMessage += WHITESPACE;
	++index;
	Encode(toBeEncoded);
	return;

}
