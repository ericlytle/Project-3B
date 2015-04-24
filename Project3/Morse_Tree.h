#include "BTNode.h"
#include <istream>
#include <fstream>
#include <string>

using namespace std;

template<typename item_type>
class Morse_Tree
{
public:
	void buildTree();
	Morse_Tree<item_type>();
private:
	BTNode<item_type>* root;
	BTNode<item_type>* dummy;
};

template<typename item_type>
Morse_Tree<item_type>::Morse_Tree(){
	root = new BTNode<item_type>("ROOT");
	dummy = new BTNode<item_type>("DUMMY");
}

template<typename item_type>
void Morse_Tree<item_type>::buildTree()
{

	ifstream file;
	string data;
	string value;
	string morse;
	file.open("morse.txt");
	while (!file.eof())
	{
		dummy = root;
		getline(file, data);
		value = data[0];
		morse = data.substr(1, string::npos);
		for (string::iterator it = morse.begin(); it != morse.end(); ++it)
		{
			if (*it == '.')
			{
				if (dummy->left == NULL) //prevents access read violation
					dummy->left = new BTNode<item_type>("DUMMY");

				if (dummy->data == "DUMMY" || dummy->data == "ROOT"){ //entered if node doesnt have a letter but also not where we want to assign a letter
					dummy = dummy->left;
				}
				else //entered if letter has been assigned
				{
					dummy = dummy->left;
				}
				
			}
			if (*it == '_')
			{
				if (dummy->right == NULL) //prevents access read violation
					dummy->right = new BTNode<item_type>("DUMMY");

				if (dummy->data == "DUMMY" || dummy->data == "ROOT") //entered if node doesnt have a letter but also not where we want to assign a letter
				{
					dummy = dummy->right;	
				}
				else //entered if letter has been assigned
				{
					dummy = dummy->right;
				}
			}
		}
		dummy->data = value; //we have reached our desired node. Assign nodes value
	}
}