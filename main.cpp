#include <iostream>
#include <string>
#include <list>
#include "ttree.h"
using namespace std;

int main(){
	ttree* myTree = new ttree();

	char command;
	string input;

	//Reads commands from text file and executes it
	cin >> command;
	while(!cin.eof()){
		switch(command){
			case('I'):{
				cin >> input;
				myTree->insert(input);
				break;
			}
			case('S'):{
				cin >> input;
				myTree->search(input);
				//Here for correct formatting
				cout << '\n' << endl;			
				break;
			}
			case('D'):{
				myTree->display();
				//Correct formatting
				cout << endl;
				break;
			}
		}
		cin >> command;
	}
}