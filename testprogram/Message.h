#pragma once
#pragma warning(disable : 4996)
using namespace std;
#include <string>
#include <chrono>
#include <ctime>
class Message
{



public:
	int messageid;
	string content;
	int senderID;
	int recieverID;


	//date
	time_t curr_time;
	tm* curr_tm;
	char date_string[100];
	char time_string[100];


	Message();
	Message(string content, int senderid, int recieverid);

};