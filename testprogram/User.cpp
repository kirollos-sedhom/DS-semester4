#include "User.h"
#include "Program.h"
#include<stack>
# include<string>
# include "User.h"
# include<Stack>
# include <cstdlib>
# include <ctime>
# include <fstream>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>
#include <string>
#include <iostream>
using namespace std;
User::User(string name, string pass) {
	username = name;
	password = pass;
}

User::User() {
	username = "";
	password = "";

}
void User::setuserpass(string pass) {
	password = pass;
}
string User::getuserpass() {
	return password;
}
void User::readfromfile() {

		///////////////////////////////////////////////////////karlo's code
		ifstream mf;
		ofstream mofs;
		int mpos;
		string sentMessagesPath = "usersmessages/" + to_string(this->userid) + "sent" + ".txt";
		// string path = "usersmessages/" + usernow->userid + "sent" + ".txt";
		string recievedMessagesPath = "usersmessages/" + to_string(this->userid) + "recieved" + ".txt";
		string mline;
		mf.open(sentMessagesPath);
		// list<Message>sentmessagestemp;
		// list<Message>recivedmessagestemp;
		while (getline(mf, mline)) {
			mpos = mline.find("|");
			string mycut = mline.substr(0, mpos);
			string contenttemp = mline.substr(0, mpos);
			mline = mline.substr(mpos + 1);
			//stringstream geeki(mline);

			int senderIDtemp = stoi(mline);

			// geeki >> senderIDtemp;
			mline = mline.substr(mpos + 2);
			// stringstream geeki(mline);
			//geeki >> recieverIDtemp;
			int recieverIDtemp = stoi(mline);
			mline = mline.substr(mpos + 3);
			string datestringTemp = mline;

			mline = mline.substr(mpos + 4);
			string timestringTemp = mline;

			Message messageTemp = Message(contenttemp, senderIDtemp, recieverIDtemp);
			string temp = datestringTemp;
			strncpy(messageTemp.date_string, temp.c_str(), sizeof(messageTemp.date_string));
			messageTemp.date_string[sizeof(messageTemp.date_string) - 1] = 0;
			string temp2 = timestringTemp;
			strncpy(messageTemp.time_string, temp2.c_str(), sizeof(messageTemp.time_string));
			messageTemp.time_string[sizeof(messageTemp.time_string) - 1] = 0;
			// sentmessagestemp.push_back(messageTemp);
			this->sentmessages.push_back(messageTemp);
		}
		mf.close();

		mf.open(recievedMessagesPath);

		while (getline(mf, mline)) {
			mpos = mline.find("|");
			string mycut = mline.substr(0, mpos);
			string contenttemp = mline.substr(0, mpos);
			mline = mline.substr(mpos + 1);
			// stringstream geeki(mline);
			int senderIDtemp = stoi(mline);

			// geeki >> senderIDtemp;
			mline = mline.substr(mpos + 2);
			int recieverIDtemp = stoi(mline);
			// stringstream geeki(mline);
			//geeki >> recieverIDtemp;
			mline = mline.substr(mpos + 3);
			string datestringTemp = mline;

			mline = mline.substr(mpos + 4);
			string timestringTemp = mline;

			Message messageTemp = Message(contenttemp, senderIDtemp, recieverIDtemp);
			string temp = datestringTemp;
			strncpy(messageTemp.date_string, temp.c_str(), sizeof(messageTemp.date_string));
			messageTemp.date_string[sizeof(messageTemp.date_string) - 1] = 0;
			string temp2 = timestringTemp;
			strncpy(messageTemp.time_string, temp2.c_str(), sizeof(messageTemp.time_string));
			messageTemp.time_string[sizeof(messageTemp.time_string) - 1] = 0;
			// recivedmessagestemp.push_back(messageTemp);
			this->recivedmessages.push_back(messageTemp);
		}
		mf.close();



}