#include <iostream>
#include <list>
#include <string>
// #include "ttree.cpp"
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
	// void find(string key, list<string>* results);
	void find(string key, int depth);

	void put(string key);
	bool insert(string key, int level);
	void setNext(ttree* nextLevel);
	void setWords(list<string>* words);

	void operator=(tnode& tn);
	string operator[](int index);





	//MY SHIT
	void display();
	string* getWordsAsArray();

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
	
}

ttree* tnode::getNext(){
	return _nextLevel;
}

list<string>* tnode::getWords(){
	return _words;
}

void tnode::find(string key, int depth){
	list<string>* results;
	list<string>::iterator it;

	//_nextLevel == NULL
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
	else{
		results = _words;
	}
	if(results->size() == 0){
		cout << "not found";
	}
	else{
		for(it = results->begin(); it != results->end(); ++it){
			cout << *it << " ";
		}
	}	
}

void tnode::put(string key){
	if(_words == NULL){
		_words = new list<string>();
		_words->push_back(key);
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
				return;
			}
		}
	}	
}

bool tnode::insert(string key, int level){
	if(_words == NULL){
		_words = new list<string>();
		_words->push_back(key);
		return true;
	}

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
	// if(words == NULL){
	// 	return;
	// }
	// list<string>::iterator it;
	// for(it = words.begin(); it != words.end(); ++it){
	// 	_words->push_back((*it));
	// }
}

void tnode::operator=(tnode& tn){

}

string tnode::operator[](int index){
	list<string>::iterator it = _words->begin();
	advance(it, index);
	return (*it);
}

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

string* tnode::getWordsAsArray(){
	string* wordsArr = new string[_words->size()];
	list<string>::iterator it;
	int i = 0;
	for(it = _words->begin(); it != _words->end(); ++it, ++i){
		wordsArr[i] = (*it);
	}
}

// int main(){
// 	tnode* myNode = new tnode();

// 	myNode->insert("BLACK", 5);
// 	myNode->insert("BLACKIRON", 5);
// 	myNode->insert("BLACKSMITH", 5);
// 	myNode->insert("BLA", 5);
// 	myNode->display();
// }



