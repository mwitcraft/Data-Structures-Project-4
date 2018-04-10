#include <iostream>
#include <string>
#include <list>
#include "ttree.h"
using namespace std;

int main(){
	ttree* myTree = new ttree();

	char command;
	string input;

	cin >> command;
	while(!cin.eof()){
		switch(command){
			case('I'):{
				cin >> input;
				// cout << "I: " << input << endl;
				myTree->insert(input);
				break;
			}
			case('S'):{
				cin >> input;
				myTree->search(input);
				cout << '\n' << endl;
				// cout << "Search: " << input << endl;
				// cout << "S: " << input << endl;				
				break;
			}
			case('D'):{
				// cout << "D" << endl;
				// cout << "----------------------" << endl;
				myTree->display();
				cout << endl;
				break;
			}
		}
		cin >> command;
	}

	// myTree->insert("STILLWHISPER");
	// myTree->insert("STILLPINE");
	// // myTree->display();
	// myTree->insert("STILLWATER");
	// myTree->display();
}