// Aho Cordasick algorithm implimentation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cstring>
#include<time.h>
#include<vector>
#include<chrono>

using namespace std;

//#define short_Max = INT16_MAX;
const unsigned char ALPHABET_SIZE = 26;


struct Trie_Node
{

	//typename std::aligned_storage<sizeof(T), alignof(T)>::type data[N];
	//std::size_t m_size = 0;

	struct Trie_Node* ChildNode_ptr_arr[ALPHABET_SIZE];

	bool AtEndofWord = false;

	Trie_Node() : ChildNode_ptr_arr() {  }//will initalize ptrs to null 

	


};

class Trie
{
private:
	
	int charArrlen = 0;
	int numberOfTriewords;
	int numberOfTriewordsDeleted;
	int numberOfTrieWordsAdded;
	int numberofTrieSearches;
	int numberOfsuccessfulSearches;
	///////////////////////////////////////////
	////This data structure shall be the MAIN and ONLY data structure used when converting a string into a 
	////char array to use in operations 
	/////////////////////////////////////////////////////
	char* charArr;
	////////////////////////////////////////////////////
	//			END	
	////////////////////////////////////////////////////


	////////////////////////////////////////////////////
	//	Padded variables to align cache
	////////////////////////////////////////////////////
	int pad1;
	char pad2;
	char pad3;
	char pad4;
	///////////////////////////////////////////////////
	//		END PADDED VARIABLES
	///////////////////////////////////////////////////



	//////////////////////////////////////////////////
	//		Root Node of Trie
	//////////////////////////////////////////////////
	Trie_Node* root_Node; 
	//////////////////////////////////////////////////
	//
	///////////////////////////////////////////////////




	//vector<Trie_Node*> AllLinkedTrieNodes;


public:

	

	Trie()
	{
		/*Trie_Node tn;
		for (int t = 0; t < ALPHABET_SIZE; t++)
		{
			tn.ChildNode_ptr_arr[t] = nullptr;
		}
		tn.AtEndofWord = false;*/
		cout << "\nTrie Created\n" << endl;

		numberOfTriewords = 0;
		numberOfTrieWordsAdded = 0;
		numberOfTriewordsDeleted = 0;
		numberofTrieSearches = 0;
		numberOfsuccessfulSearches = 0;


		root_Node = new Trie_Node;//instantiate new trie root node
	

	}

	

	void createArr(string word)
	{
		int size = word.length();
		charArr = new char[size];
		strncpy(charArr, word.c_str(), size); //SAFER CODE HERE!
		//charArr[sizeof(charArr) - 1] = 0;
		charArrlen = size;

	}

	void DestroyRecursive(Trie_Node* node)
	{
		if (node)
		{
			for (int t = 0; t < ALPHABET_SIZE; t++)
			{
				DestroyRecursive(node->ChildNode_ptr_arr[t]);
			}
			
			
			delete node;
		}
	}

	~Trie()
	{
		DestroyRecursive( root_Node);

		/*for (int t = 0; t < AllLinkedTrieNodes.size(); t++)
		{
			delete AllLinkedTrieNodes[t];
			cout << "Trie Node deleted" << endl;
		}*/

	//	AllLinkedTrieNodes.clear();

		cout << "Trie Deleted" << endl;
		
	}

	

	//returns the proper index that a child node pointer should be placed 
	//in array of parent node
	inline void add_pointer_to_vector(Trie_Node* tn_ptr)
	{
	//	AllLinkedTrieNodes.push_back(tn_ptr);
	}

	inline int getNumberofWordsSearched()
	{
		return numberofTrieSearches;
	}
	inline int getNumberofWordsAdded()
	{
		return numberOfTrieWordsAdded;
	}

	inline int getNumberofWordsDeleted()
	{
		return numberOfTriewordsDeleted;
	}

	inline int getNumberofwordsinTrie()
	{
		return numberOfTriewords;
	}


	inline unsigned char Assign_ptr_to_child_index(char NodeChar)
	{
		//97 is the ASCII decimal value of the first lowercase
		//character, 'a', of the english alphabet. This means that 
		//a - 97 = 0, mapping 'a' to the 0th index of thechild ptr arr 
		//for any proceeding lowercase letter, we can use this math to 
		//map each character to the child node ptr array.
		return NodeChar - 97;
	}

	

	void createTrie(string Dictionary[], int numberOfWordsinDictionary)
	{
		
		
		for (int t = 0; t < numberOfWordsinDictionary; t++)
		{
			if (Dictionary[t].length() < 1) continue;//safety check for strings of length 0 so that an exception isnt called

			createArr(Dictionary[t]);
			
			bool Added = Append_word_to_Trie( root_Node, 0);
			if (Added)
			{
				numberOfTriewords++;
				numberOfTrieWordsAdded++;
			}
		}
	}
	//appends newly scanned character to trie
	bool Append_word_to_Trie(Trie_Node* root, short strpos)
	{
		

		if (!root) return false;

		//int t = 
		Trie_Node* t = root->ChildNode_ptr_arr[Assign_ptr_to_child_index(charArr[strpos])];

		if (strpos == charArrlen - 1)
		{
			//if (t == (int)0x12345678)//UNSAFE 
			if ( t == nullptr)
			{
				//Trie_Node* tn_Ptr = 
				
				//tn_Ptr->AtEndofWord = true;

			root->ChildNode_ptr_arr[Assign_ptr_to_child_index(charArr[strpos])] = new Trie_Node; //NewNode();

				root->ChildNode_ptr_arr[Assign_ptr_to_child_index(charArr[strpos])]->AtEndofWord = true;

				//add_pointer_to_vector(root->ChildNode_ptr_arr[Assign_ptr_to_child_index(charArr[strpos])]);
				return true;

			}

			//else if (t != (int)0x12345678)//if child pointer exists 
			else if (t != nullptr)
			{
				root->ChildNode_ptr_arr[Assign_ptr_to_child_index(charArr[strpos])]->AtEndofWord = true;
				return true;

			}

			else
			{
				cout << "error" << endl;
				return false;
			}
				

		}

		//if ( t == (int)0x12345678)
		if(t == NULL || t == nullptr)
		{
			//Trie_Node* tn_Ptr = NewNode(charArr[strpos]);
			
			
			root->ChildNode_ptr_arr[Assign_ptr_to_child_index(charArr[strpos])] =  NewNode();
			
			//add_pointer_to_vector(root->ChildNode_ptr_arr[Assign_ptr_to_child_index(charArr[strpos])]);

			Append_word_to_Trie(root->ChildNode_ptr_arr[Assign_ptr_to_child_index(charArr[strpos])], strpos+ 1);

			
		}

		//else if (t != (int)0x12345678)//if child pointer exists 
		else if ( t != nullptr)
		{
			Trie_Node* tempPtr = root->ChildNode_ptr_arr[Assign_ptr_to_child_index(charArr[strpos])];
			Append_word_to_Trie(tempPtr , strpos + 1);
		}

		
		
	}

	//1st element of pair: flag for whether original word to be deleted is found
	//2nd element of pair: flag for whether another word in the trie is found in original deleted word's node chain
	std::pair<bool,bool> delete_word(Trie_Node* root, short index )
	{
		bool isWordFound = false;
		bool exitRecursionFlag = false;


		if (index > charArrlen - 1)
		{
			if (root->AtEndofWord)
			{
				isWordFound = true;
			}

			root->AtEndofWord = false; //we set this variable to false since we are deleting this word, this letter will not be the end of a word
			return std::make_pair(isWordFound, false);

		}

		Trie_Node* t = root->ChildNode_ptr_arr[Assign_ptr_to_child_index(charArr[index])];

		//if ((int)t == (int)0x12345678)//stacic cast here???
		if ( t == nullptr)
		{
			isWordFound = false;
			return std::make_pair(isWordFound, false);
		}
		std::pair <bool, bool> retValues = delete_word(t, index + 1);
		if (retValues.first && retValues.second)
		{
			if (index == 0 && exitRecursionFlag  ) return std::make_pair(exitRecursionFlag, exitRecursionFlag);

			exitRecursionFlag = true;

			return std::make_pair(exitRecursionFlag, true);
		}
			
		

		  //a flag variable for if the node chain of the word we are trying to delete contains another word (ex. deleted trie word "catnip" also contains trie word "cat")
		
		if (root->AtEndofWord && retValues.first)
		{
			return std::make_pair(true, true);
		}
											   
		//if the flag is true, meaning that the word is indeed found to delete in trie, enter conditional block 
		if (retValues.first)
		{
			bool is_empty = true;

			//if( t->AtEndofWord && index != charArrlen - 1)
			for (int i = 0; i < ALPHABET_SIZE; i++)
			{
				//If a valid ptr is found, it means that this trie node t has a child node, meaning we can't delete this node because other nodes are linked to it 
				//if ((int)t->ChildNode_ptr_arr[i] != (int)0x12345678 )
				if( t->ChildNode_ptr_arr[i] != nullptr)
				{
					is_empty = false;

					if (index >= charArrlen - 1)//if at the last character of word to be deleted from trie..
						root->ChildNode_ptr_arr[Assign_ptr_to_child_index(charArr[index])]->AtEndofWord = false; //if one or more children exist, and we are at the end of the word to delete, set this variable to false
					return std::make_pair(true, false);
				}

				
			}

			if (is_empty)//if current trie node has no child nodes, then simply delete this node 
			{
				delete root->ChildNode_ptr_arr[Assign_ptr_to_child_index(charArr[index])];
				root->ChildNode_ptr_arr[Assign_ptr_to_child_index(charArr[index])] = nullptr; // reinterpret_cast <Trie_Node*> (0x12345678); //set pointer value to default "initalized" value

			}
			

			return std::make_pair(true, false);
		}

		
		return std::make_pair(isWordFound, false);
	}

	
	bool delete_from_trie(string word)
	{
		createArr(word);

		//if ((int)root_Node == (int)0x12345678)
		if( root_Node == nullptr)
			return false;

		bool Deleted = delete_word(root_Node, 0).first;

		//If word was sucessfully deleted from trie
		if (Deleted)
		{
			numberOfTriewords--;
			numberOfTriewordsDeleted++;
		}

		return Deleted;

	}

	
	 bool word_search( Trie_Node* root,  short index )
	{
		bool flag = true; 

		
		//Do a performance test against && if statements!!
		if (index > charArrlen - 1)
		{
			if (!root->AtEndofWord)
			{
				flag = false;
			}

			return flag;

		}

		Trie_Node* t = root->ChildNode_ptr_arr[Assign_ptr_to_child_index(charArr[index])];

		//if ((int)t == (int)0x12345678)//stacic cast here???
		if( t == nullptr)
		{
			flag = false; 
			return flag;
		}

		return word_search(t, index + 1);
	
	}

	bool search_for_word_in_trie(string word)
	{
		createArr(word); 

		bool Found = word_search(root_Node, 0);;

		if (Found)
		{
			numberOfsuccessfulSearches++;
		}
		numberofTrieSearches++;

		return Found;

	}

	//prints all words in trie in lexicographical order
	void getWords(Trie_Node* root, char* wordArr, short index)
	{
		if (!root) return;

		if (root->AtEndofWord)
		{
			//print all characters of word array
			print_dictionary_word(wordArr, index);
		}
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			//if ((int)root->ChildNode_ptr_arr[i] != (int)0x12345678)
			if ( root->ChildNode_ptr_arr[i] != nullptr)
			{
				if (index == 0)
				{
					wordArr = new char[1024];
				}
				wordArr[index] = getChar(i); 
				 getWords(root->ChildNode_ptr_arr[i], wordArr, index + 1);
				
				
			}
		}
	}

	inline void print_dictionary_word(char* charArr, short wordlength)//TEST THIS!!
	{
		string str(charArr);

		cout << str.substr(0, wordlength) << endl;
	}
	void Print_all_words_in_trie()
	{
		
		char dict_word[INT16_MAX]; 

		getWords(root_Node, dict_word, 0);
	}
	
	//USELESS FOR NOW!!
	inline Trie_Node* NewNode()
	{
		//Trie_Node* tn = new Trie_Node;
		//tn.AtEndofWord = true;
		//Trie_Node* tt = reinterpret_cast<Trie_Node*>(0x12345678);//set placement addr to determine if arr contains valid child ptr

		//for (int t = 0; t < ALPHABET_SIZE; t++)
		//{
		//	tn->ChildNode_ptr_arr[t] = tt;
		//}
		return new Trie_Node;
	}

	

	bool Insert(string word)
	{
		createArr(word);

		bool Inserted = Append_word_to_Trie(root_Node, 0);
		if (Inserted)
		{
			numberOfTrieWordsAdded++;
			numberOfsuccessfulSearches++;
		}

		return Inserted;
	}

	inline char getChar(unsigned char numericalValueofChar)
	{
		return numericalValueofChar + 97;
	}
	void print_words_in_alphabetical_order()
	{

	}
	
};

void outOfMemHandler()
{
	std::cerr << "Unable to satisfy request for memory\n";

	std::abort();
}

int main()
{
	//////////////////////////////////////////////////////////////////////////////////////////
	//		THIS SETS A HANDLER IN CASE THERE IS NOT ENOUGH MEMORY TO ALLOCATE ON THE HEAP
	//////////////////////////////////////////////////////////////////////////////////////////
	std::set_new_handler(outOfMemHandler);
	////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////

	Trie trie; 
	int Dictionarysize = 4;
	 
	string *Dict = new string[Dictionarysize]{ "hey", "hello", "at", "superbowl" };
	
	trie.createTrie(Dict, Dictionarysize);

	

	cout << "\n\n--------Words in Trie Currently-------------------" << endl;
	trie.Print_all_words_in_trie();
	
	cout <<"Number of words Added: "<< trie.getNumberofWordsAdded() << endl;
	cout <<"Number of Words Deleted: " <<  trie.getNumberofWordsDeleted() << endl;
	cout << "Number of words in Trie: "<< trie.getNumberofwordsinTrie() << endl;

	
	cout << "\n\n--------------------------" << endl;

		cout << "hey" << " Deleted: " << std::boolalpha << trie.delete_from_trie("hey") << endl;


		

		cout << "Number of words Added: " << trie.getNumberofWordsAdded() << endl;
		cout << "Number of Words Deleted: " << trie.getNumberofWordsDeleted() << endl;
		cout << "Number of words in Trie: " << trie.getNumberofwordsinTrie() << endl;
	//	trie.Print_all_words_in_trie();
		cout << "\n\n---------------------------" << endl;

		cout << "why" << " Deleted: " << std::boolalpha << trie.delete_from_trie("why") << endl;

		cout << endl;
		cout << "Number of words Added: " << trie.getNumberofWordsAdded() << endl;
		cout << "Number of Words Deleted: " << trie.getNumberofWordsDeleted() << endl;
		cout << " Number of words in Trie: " << trie.getNumberofwordsinTrie() << endl;
		//	trie.Print_all_words_in_trie();
		cout << "\n\n-----------------------------------" << endl;
	

		//returns true
		cout << "hello" << " Found: " << std::boolalpha << trie.search_for_word_in_trie("hello") << endl;
		cout << "number of word searches: " << trie.getNumberofWordsSearched() << endl;
		cout<<"\n\n-----------------------" << endl;

		//returns false
		cout << "hell" << " Found: " << std::boolalpha << trie.search_for_word_in_trie("hell") << endl;
		cout << "number of word searches: " << trie.getNumberofWordsSearched() << endl;

		cout << "\n\n--------------------------" << endl;

		trie.Insert("why");

		//cout << "\n\n" << endl;

		trie.Print_all_words_in_trie();

		cout << "why" << " Found: " << std::boolalpha << trie.search_for_word_in_trie("why") << endl;
		cout << "number of word searches: " << trie.getNumberofWordsSearched() << endl;

		cout << "\n\n--------------------------" << endl;

		delete[] Dict;

	system("pause");
    return 0;
}

