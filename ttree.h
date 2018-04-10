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
	list<string>* getSubsequent(list<string>* results);


	//MY SHIT
	void display();
	tnode* getTnodes(){
		return _tnodes;
	}
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
				//This right here may cause problems, idk how this is updated throughout
				list<string>* oldWords = _tnodes[index].getWords();

				// list<string>::iterator it;
				// for(it = oldWords->begin(); it != oldWords->end(); ++it){
				// 	cout << (*it) << endl;
				// }
				// cout << "-------------------" << endl;

				//NEED TO WRITE THIS PORTION OF CODE
				//INSERT CODE HERE TO INSERT EACH WORD IN OLDWORDS IN NEWLEVEL RECURSIVLEY
				while(!oldWords->empty()){
					string tempWord = oldWords->front();
					oldWords->pop_front();

				// for(it = oldWords->begin(); it != oldWords->end(); ++it){
				// 	cout << (*it) << endl;
				// }

					_tnodes[index].setWords(oldWords);
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
	// cout << "KEY: " << key << endl;
	if(key.size() != 0){
		int index = key[0] - 'A';
		if(_tnodes[index].getNext() == NULL){
			// cout << "DEPTH: " << _currentDepth << endl;
			_tnodes[index].find(key, _currentDepth - 1);
			return;
		}
		key = key.erase(0, 1);
		_tnodes[index].getNext()->search(key);
//		tnode node = _tnodes[index];
	}
	else{
		for(int i = 0; i < 26; ++i){
			if(_tnodes[i].getWords() != NULL){
				_tnodes[i].find(key, _currentDepth - 1);
			}
			else if(_tnodes[i].getNext() != NULL){
				_tnodes[i].getNext()->search(key);
			}
		}
	}
}

list<string>* getSubsequent(list<string>* results){

}

void ttree::display(){
	for(int i = 0; i < 26; ++i){
		if(_tnodes[i].getWords() != NULL){
			for(int j = 0; j < 3 * (_currentDepth - 1); ++j){
				cout << " ";
			}
			cout << (char)('A' + i) << " ";
			_tnodes[i].display();
			cout << endl;

		}
		else if(_tnodes[i].getNext() != NULL){
			for(int j = 0; j < 3 * (_currentDepth - 1); ++j){
				cout << " ";
			}
			cout << (char)('A' + i) << endl;
			_tnodes[i].getNext()->display();
		}
	}




	// for(int i = 0; i < 26; ++i){
	// 	char c = i + 'A';
	// 	if(_tnodes[i].getWords() == NULL){
	// 		if(_tnodes[i].getNext() != NULL){
	// 			_tnodes[i].getNext()->display();
	// 		}
	// 		else{
	// 			cout << c << ": NULL" << endl;
	// 		}
	// 	}
	// 	else{
	// 		cout << c << ": ";
	// 		_tnodes[i].display();
	// 	}
	// }
}