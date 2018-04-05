#include <iostream>
#include <string>
#include <list>
#include "ttree.cpp"
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
				cout << "Search: " << input << endl;
				cout << "S: " << input << endl;				
				break;
			}
			case('D'):{
				// cout << "D" << endl;
				// cout << "----------------------" << endl;
				myTree->display();
				break;
			}
		}
		cin >> command;
	}
	// myTree->insert("XXXXX");
	// myTree->insert("XYYYY");
	// myTree->insert("XZZZZ");
	// // myTree->insert("ARSENIC");

	// myTree->display();
}