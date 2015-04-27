#include "BTNode.h"
#include <istream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include "String_Tokenizer.h"

using namespace std;

template<typename item_type>
class Morse_Tree
{
public:
	Morse_Tree<item_type>();
	void buildTree(string fileName);
	string decode(string encodedMessage); //wrapper 
	void decode(string &code, string::iterator &iter, BTNode<item_type>* &tree, string& decodedPhrase);

private:
	BTNode<item_type>* root;
	BTNode<item_type>* dummy;
	string decodedMessage;
	ifstream inputFile;
	void openFile(string fileName);
	int index;
};

template<typename item_type>
Morse_Tree<item_type>::Morse_Tree(){
	root = new BTNode<item_type>("ROOT");
	dummy = new BTNode<item_type>("DUMMY");
	index = 0;
}

template<typename item_type>
void Morse_Tree<item_type>::openFile(string fileName){
	inputFile.open(fileName);
	if (!inputFile){
		throw std::runtime_error(fileName + " File Not Found");
		exit(1);
	}
}

template<typename item_type>
void Morse_Tree<item_type>::buildTree(string fileName)
{
	openFile(fileName);
	string data, value, morse;
	while (!inputFile.eof())
	{
		dummy = root;
		getline(inputFile, data);
		value = data[0];   //VALUE and MORSE contain the information to build a MAP
		morse = data.substr(1, string::npos);
		for (string::iterator it = morse.begin(); it != morse.end(); ++it)
		{
			if (*it == '.')
			{
				if(dummy->left == NULL) //prevents access read violation
					dummy->left = new BTNode<item_type>("DUMMY");
				dummy = dummy->left;
			}
			if (*it == '_')
			{
				if (dummy->right == NULL) //prevents access read violation
					dummy->right = new BTNode<item_type>("DUMMY");
				dummy = dummy->right;
			}
		}
		dummy->data = value; //we have reached our desired node. Assign nodes value
	}
}
template<typename item_type>
string Morse_Tree<item_type>::decode(string encodedMessage){
	String_Tokenizer tokensPhrase(encodedMessage, ",");
	string decodedPhrase, temp;
	string::iterator iter;

	while(tokensPhrase.has_more_tokens()){//get entire word
		String_Tokenizer tokensWord(tokensPhrase.next_token(), " ");
		while (tokensWord.has_more_tokens())//get letter
		{
			decode(temp = tokensWord.next_token(), iter = temp.begin(), root, decodedPhrase);
		}
		decodedPhrase += " ";
	}	
	return decodedPhrase;
}

template<typename item_type>
void Morse_Tree<item_type>::decode(string &code, string::iterator &iter, BTNode<item_type>* &tree, string& decodedPhrase){
	if (iter == code.end())
	{
		decodedPhrase += tree->data;
		return;
	}
	if (*iter == '.')
		decode(code, ++iter, tree->left, decodedPhrase);
	else
		decode(code, ++iter, tree->right, decodedPhrase);
}