#include <iostream>
#include <list>
#include <string>
using namespace std;

class ttree;

class tnode{
private:
	ttree* _nextLevel; //Pointer to the ttree at the next level
	list<string>* _words; //Stores keywords
public:
	tnode();
	tnode(tnode& tn);
	~tnode();

	//ostream operator and other methods

	friend ostream& operator<<(ostream& os, ttree& tt);
	ttree* getNext();
	list<string>* getWords();
	void find(string key, int depth);

	void put(string key);
	bool insert(string key, int level);
	void setNext(ttree* nextLevel);
	void setWords(list<string>* words);

	void operator=(tnode& tn);
	string operator[](int index);

	void display();

};


tnode::tnode(){
	_nextLevel = NULL;
	_words = NULL;
}

tnode::tnode(tnode& tn){
	_nextLevel = tn.getNext();
	_words = tn.getWords();
}

tnode::~tnode(){
	if(_nextLevel != NULL){
		_nextLevel = NULL;
	}
	if(_words != NULL){
		_words = NULL;
	}
}

ttree* tnode::getNext(){
	return _nextLevel;
}

list<string>* tnode::getWords(){
	return _words;
}

//Finds and prints out words at node if it matches key up to certain depth
void tnode::find(string key, int depth){
	list<string>* results;
	list<string>::iterator it;

	//If the node contains a word or words that match the key up to a certain depth,
	//then that word is added to the results list 
	if(key.size() > 0){
		results = new list<string>();
		if(_words != NULL){
			for(it = _words->begin(); it != _words->end(); ++it){
				if(key == (*it).substr(depth, key.size())){
					results->push_back(*it);
				}
			}			
		}
	}
	//if there is no key, then all words in the node are added to results
	else{
		results = _words;
	}
	//if results is empty
	if(results->size() == 0){
		cout << "not found";
	}
	//Prints out all words in results
	else{
		for(it = results->begin(); it != results->end(); ++it){
			cout << *it << " ";
		}
	}	
}

void tnode::put(string key){
	//If _words is empty, then _words is initialized and key is placed in it
	if(_words == NULL){
		_words = new list<string>();
		_words->push_back(key);
	}

	//This chunk places the key in _words while keeping everything in alphabetical order,
	//using a binary search algorithm if necessary
	if(key < _words->front()){
		_words->push_front(key);
	}
	else if(key > _words->back()){
		_words->push_back(key);
	}
	else{
		list<string>::iterator it = _words->begin();
		while(it != _words->end()){
			string low = (*it);
			++it;
			string high = (*it);
			if(key > low && key < high){
				_words->insert(it, key);
				return;
			}
		}
	}	
}

//Same thing as put, except checks to see if key belongs in the node
bool tnode::insert(string key, int level){
	if(_words == NULL){
		_words = new list<string>();
		_words->push_back(key);
		return true;
	}

	//if the key does not match the words in the node up to the current level,
	//it returns false
	list<string>::iterator it;
	for(it = _words->begin(); it != _words->end(); ++it){
		string compWord = (*it);
		if(compWord[level] == key[level]){			
			return false;
		}
	}

	if(key < _words->front()){
		_words->push_front(key);
	}
	else if(key > _words->back()){
		_words->push_back(key);
	}
	else{
		list<string>::iterator it = _words->begin();
		while(it != _words->end()){
			string low = (*it);
			++it;
			string high = (*it);
			if(key > low && key < high){
				_words->insert(it, key);
				return true;
			}
		}
	}
	return true;
}

void tnode::setNext(ttree* nextLevel){
	_nextLevel = nextLevel;
}

void tnode::setWords(list<string>* words){
	_words = words;
}

void tnode::operator=(tnode& tn){

}

string tnode::operator[](int index){
	list<string>::iterator it = _words->begin();
	advance(it, index);
	return (*it);
}

//Prints out the words in the node
void tnode::display(){
	if(_words == NULL){
		cout << "NULL" << endl;
		return;
	}

	list<string>::iterator it;
	int i = 0;

	for(it = _words->begin(); it != _words->end(); ++it, ++i){
		cout << (*it) << " ";
	}
}



