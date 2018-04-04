#include <iostream>
#include <string>
#include <list>
#include "ttree.cpp"
using namespace std;

int main(){
	ttree* myTree = new ttree();

	char command;
	string input;

	while(!cin.eof()){
		cin >> command;
		switch(command){
			case('I'):{
				cin >> input;
				// cout << "I: " << input << endl;
				myTree->insert(input);
				break;
			}
			case('S'):{
				cin >> input;
				cout << "Search: " << input << endl;
				break;
			}
			case('D'):{
				// cout << "D" << endl;
				cout << "----------------------" << endl;
				myTree->display();
				break;
			}
		}
	}

	// ttree* myTree = new ttree();
	// myTree->insert("XXXXX");
	// myTree->insert("XZZZZ");
	// myTree->insert("XYYYY");
	// myTree->insert("XBBBB");
	// myTree->insert("APPLE");


	// myTree->display();
}