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

};

template<typename key_type, typename data_type>
Encoder<key_type, data_type>::Encoder()
{
	index = 0;
	encodedMessage = "";
	WHITESPACE = " ";
}

template<typename key_type, typename data_type>
string Encoder<key_type, data_type>::getEncodedMessage()
{
	return encodedMessage;
}

template<typename key_type, typename data_type>
void Encoder<key_type, data_type>::PopulateMap()
{
	ifstream fin;
	string tempString;
	fin.open("morse.txt");
	while (!fin.eof())
	{
		getline(fin, tempString);
		messageEncoder[tempString.substr(0, 1)] = tempString.substr(1, string::npos);
	}
}

template<typename key_type, typename data_type>
void Encoder<key_type, data_type>::Encode(string toBeEncoded)
{

	if (index == toBeEncoded.length())
		return;
	string temp(1, toBeEncoded[index]);
	encodedMessage += messageEncoder[temp];
	encodedMessage += WHITESPACE;
	++index;
	Encode(toBeEncoded);
	return;

}
