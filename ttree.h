#include <iostream>
#include <list>
#include <string>
#include "tnode.h"
using namespace std;

class tnode;

class ttree{
private:
	tnode* _tnodes; //Pointer to _tnodes, a tnode array of size 26 will be created in the constructor
	int _maxDepth; //Max depth allowance
	int _currentDepth; //Depth of the current node(root is depth 1)
public:
	ttree(); //Set the maxDepth to 5 in the empty constructor
	ttree(int maxDepth); //Constructor with given maxDepth value
	ttree(int maxDepth, int currentDepth);
	~ttree();
	void insert(string key); //Insert 'key' into the tree
	void search(string key); //Search for 'key' in the tree and print out all matches

	//ostream operator and other methods

	void display();
};

ttree::ttree(){
	_tnodes = new tnode[26];
	_maxDepth = 5;
	_currentDepth = 1;
}

ttree::ttree(int maxDepth, int currentDepth){
	_tnodes = new tnode[26];
	_maxDepth = maxDepth;
	_currentDepth = currentDepth;
}

ttree::~ttree(){
	if (_tnodes != NULL){
		_tnodes = NULL;
	}
}

void ttree::insert(string key){
	ttree* newLevel;
	int index = key[_currentDepth - 1] - 'A'; //find which tnode we are concerned with, based on _currentDepth and key

	// if((*_tnodes)[index].getNext() != NULL){ //if the node in question has a next level
	if(_tnodes[index].getNext() != NULL){
		//ttree obj
		_tnodes[index].getNext()->insert(key); //Pass insert call to next level
	}
	else{
			//tnode obj
		if(_tnodes[index].insert(key, _currentDepth) == false){ //Try to insert, if false then common pre > depth
			if((_currentDepth + 1) > _maxDepth){
				_tnodes[index].put(key); //put() into _words if we hit the max depth
			}
			else{ //We need a new level
				newLevel = new ttree(_maxDepth, _currentDepth + 1);
				//Store words from current tnode in temp list
				list<string>* oldWords = _tnodes[index].getWords();

				//INSERT CODE HERE TO INSERT EACH WORD IN OLDWORDS IN NEWLEVEL RECURSIVLEY
				while(!oldWords->empty()){
					//Set temp variable to first element in oldWords
					string tempWord = oldWords->front();
					//Delete first element in oldWords
					oldWords->pop_front();
					//After popping element, set current tnode's words to oldWords
					_tnodes[index].setWords(oldWords);
					//Insert the tempWord into the newLevel
					newLevel->insert(tempWord);
				}

				newLevel->insert(key); //try again to insert key now that we have more levels; this makes sure multiple new levels will be created if necessary
				_tnodes[index].setNext(newLevel);
				_tnodes[index].setWords(NULL);
			}

		}
	}
}

void ttree::search(string key){
	if(key.size() != 0){
		int index = key[0] - 'A';
		//If current tnode does not have a next level
		if(_tnodes[index].getNext() == NULL){
			//We will call find on the current tnode
			_tnodes[index].find(key, _currentDepth - 1);
			return;
		}
		//If current tnode does have a next level 
		//Then we erase the first letter and call search again
		key = key.erase(0, 1);
		_tnodes[index].getNext()->search(key);
	}
	//key size == 0
	else{
		//Step through each node in _tnodes
		for(int i = 0; i < 26; ++i){
			//If words are present in that node, then call find on the node
			if(_tnodes[i].getWords() != NULL){
				_tnodes[i].find(key, _currentDepth - 1);
			}
			//If the current node has a next level, call search on that level
			else if(_tnodes[i].getNext() != NULL){
				_tnodes[i].getNext()->search(key);
			}
		}
	}
}

void ttree::display(){
	//Step through each node in _tnodes
	for(int i = 0; i < 26; ++i){
		//if current node has words in it, add 3 * currentDepth - 1 spaces
		if(_tnodes[i].getWords() != NULL){
			for(int j = 0; j < 3 * (_currentDepth - 1); ++j){
				cout << " ";
			}
			//Print out the letter corresponding to the current node
			cout << (char)('A' + i) << " ";
			//Print out words at that node
			_tnodes[i].display();
			cout << endl;

		}
		//if the current node has a next level
		else if(_tnodes[i].getNext() != NULL){
			//Add 3 * currentDepth - 1 spaces for formatting
			for(int j = 0; j < 3 * (_currentDepth - 1); ++j){
				cout << " ";
			}
			//Print out corresponding letter
			cout << (char)('A' + i) << endl;
			//Call display on the nextLevel
			_tnodes[i].getNext()->display();
		}
	}
}