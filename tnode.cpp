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
	void find(string key, list<string>* results);

	void put(string key);
	bool insert(string key, int level);
	void setNext(ttree* nextLevel);
	void setWords(list<string>* words);

	void operator=(tnode& tn);
	string operator[](int index);





	//MY SHIT
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

ttree* tnode::getNext(){
	return _nextLevel;
}

list<string>* tnode::getWords(){
	return _words;
}

void tnode::find(string key, list<string>* results){

}

void tnode::put(string key){
	if(_words == NULL){
		_words = new list<string>();
	}
	_words->push_back(key);
}

bool tnode::insert(string key, int level){
	if(_words == NULL){
		_words = new list<string>();
		_words->push_back(key);
		return true;
	}





	// string compWord = _words->front();
	string pre1 = key.substr(0, level);
	string pre2 = _words->front().substr(0, level);

	// for(int i = 0; i < level; ++i){
	// 	cout << "key @ " << i << ": " << key[i] << endl;
	// 			cout << "compWord @ " << i << ": " << compWord[i] << endl;

 // 		pre1[i] = key[i];
	// 	pre2[i] = compWord[i];
	// }

	// cout << "pre1: " << pre1 << endl;
	// cout << "pre2: " << pre2 << endl;


	if(pre1 == pre2){
		return false;
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

// int main(){
// 	tnode* myNode = new tnode();

// 	myNode->insert("BLACK", 5);
// 	myNode->insert("BLACKIRON", 5);
// 	myNode->insert("BLACKSMITH", 5);
// 	myNode->insert("BLA", 5);
// 	myNode->display();
// }



