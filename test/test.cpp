#include <iostream>
#include<string>
#include<fstream>
#include<stdio.h>
using namespace std;

bool loggedIn()
{
	string username, password, u, p;
	cout << "insert username" << endl;
	cin >> username;
	cout << "insert password" << endl;
	cin >> password;
	ifstream show("DataOf" + username + ".txt");
	getline(show, u);
	getline(show, p);
	if (username == u && password == p) {
		return true;
	}
	else {
		return false;
	}

}
int main()
{
	int choice;
	cout << " please choose " << endl << "0.sign up " << endl << "1.login" << endl;
	cin >> choice;
	if (choice == 0) {
		string username,password;
		cout << " enter your username" << endl;
		cin >> username;
		cout << "enter your password" << endl;
		cin >> password;
	    ofstream file;
		file.open("DataOf" + username + ".txt");
		file << username << endl << password;
		file.close();
		main();
	}
	if (choice == 1) {
		bool attempt = loggedIn();
		if (!attempt)
		{
			cout << " you can not login because the information does not exist";
			return 0;
		}
		else 
		{
			cout << "you are logged in"; 
			return 1;
		}

	}
	
}