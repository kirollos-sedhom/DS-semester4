#pragma once
#include <list>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <iostream>
#include <string.h>
#include"User.h"
#include "Message.h"
using namespace std;
class Program
{
public:
	vector<User>users;
	User* usernow;
//	list<Message> sentmessages;
//	list<int> reciepientIDs;
//	int id_Of_Last_Recipient;

	void readdata();
	Program();
	~Program();
	void run();
	void login();
	void reg();
	int random();
	int chooseid();
	void programcontent();
	void addtoyourcontact(User n);
	void search();
	bool alreadyadded(User n);

	void sendmessage();
	void undosentmessage();
	void searchaboutcontact();
	void viewallmyrecievedmessages();
	void viewMessageFromaCertainContact();
	void viewmessagesihavesent();
	void viewallcontacts();
	void addtofavourites();
	void viewfavourites();
	void popoldestFavourite();
//	void checkRecipients();
	void writetofile(list<string> mylist, string filepath);
	void viewContactsOfSpecificUser();
	vector<Message> fetch(string mypath);
	list<string> returnmessages(string filepath);
};