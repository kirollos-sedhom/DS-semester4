#pragma once
#include <iostream>
#include<stack>
#include<queue>
#include<list>
#include <vector>
#include<string>

# include "Message.h"
using namespace std;
#include<list>


class User
{
private:
	string password;
public:
	string username;
	int userid;
	int ActiveSession = 0;
	list<Message>sentmessages;
	list<Message>recivedmessages;
	list<Message>myfavouritmessages;
//	list<int>recipientIds;
	vector< User>mycontact;





public:
	User(string name, string pass);
	User();
	string getuserpass();
	void setuserpass(string pass);
	void readfromfile();
	void goodmorning();
};