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
		string recievedMessagesPath = "usersmessages/" + to_string(this->userid) + "recieved" + ".txt";
		string favouriteMessagesPath = "favouritemessages/" + to_string(this->userid) + ".txt";
		string mline;
		mf.open(sentMessagesPath);

		while (getline(mf, mline)) {
			mpos = mline.find(",");
			string mycut = mline.substr(0, mpos);
			string contenttemp = mline.substr(0, mpos);
			mline = mline.substr(mpos + 1);


			int senderIDtemp = stoi(mline);


			int mylength = to_string(senderIDtemp).length() + 1;
			mline = mline.substr(mylength);

			int recieverIDtemp = stoi(mline);
			mline = mline.substr(mpos);
			string datestringTemp = mline;

		//	mline = mline.substr(mpos + 1);
		//	string timestringTemp = mline;

			Message messageTemp = Message(contenttemp, senderIDtemp, recieverIDtemp);
			string temp = datestringTemp;
			strncpy(messageTemp.date_string, temp.c_str(), sizeof(messageTemp.date_string));
		//	messageTemp.date_string[sizeof(messageTemp.date_string) - 1] = 0;
		//	string temp2 = timestringTemp;
		//	strncpy(messageTemp.time_string, temp2.c_str(), sizeof(messageTemp.time_string));
		//	messageTemp.time_string[sizeof(messageTemp.time_string) - 1] = 0;
			// sentmessagestemp.push_back(messageTemp);
			this->sentmessages.push_back(messageTemp);
		}
		mf.close();

		mf.open(recievedMessagesPath);
		//first, 6437, 6421, May 15, 2022, 20:58 : 46
		while (getline(mf, mline)) {
			mpos = mline.find(",");
			string mycut = mline.substr(0, mpos);
			string contenttemp = mline.substr(0, mpos);
			mline = mline.substr(mpos + 1);

			int senderIDtemp = stoi(mline);
			int mylength = to_string(senderIDtemp).length() + 1;
			mline = mline.substr(mylength);

			int recieverIDtemp = stoi(mline);

			///////////////////////////////check this fast
			mline = mline.substr(mpos);
			string datestringTemp = mline;

		//	mline = mline.substr(mpos + 1);
		//	string timestringTemp = mline;

			Message messageTemp = Message(contenttemp, senderIDtemp, recieverIDtemp);
			string temp = datestringTemp;
			strncpy(messageTemp.date_string, temp.c_str(), sizeof(messageTemp.date_string));
			messageTemp.date_string[sizeof(messageTemp.date_string) - 1] = 0;
		//	string temp2 = timestringTemp;
		//	strncpy(messageTemp.time_string, temp2.c_str(), sizeof(messageTemp.time_string));
		//	messageTemp.time_string[sizeof(messageTemp.time_string) - 1] = 0;

			this->recivedmessages.push_back(messageTemp);
		}

		mf.close();


		/// retrieving favourites
		mf.open(favouriteMessagesPath);
		
		//first, 6437, 6421, May 15, 2022, 20:58 : 46
		while (getline(mf, mline)) {
			mpos = mline.find(",");
			string mycut = mline.substr(0, mpos);
			string contenttemp = mline.substr(0, mpos);
			mline = mline.substr(mpos + 1);
			//error here
			int senderIDtemp = stoi(mline);
			int mylength = to_string(senderIDtemp).length() + 1;
			mline = mline.substr(mylength);

			int recieverIDtemp = stoi(mline);

			mline = mline.substr(mpos);
			string datestringTemp = mline;

		//	mline = mline.substr(mpos + 1);
		//	string timestringTemp = mline;

			Message messageTemp = Message(contenttemp, senderIDtemp, recieverIDtemp);
			string temp = datestringTemp;
			strncpy(messageTemp.date_string, temp.c_str(), sizeof(messageTemp.date_string));
			messageTemp.date_string[sizeof(messageTemp.date_string) - 1] = 0;
		//	string temp2 = timestringTemp;
		//	strncpy(messageTemp.time_string, temp2.c_str(), sizeof(messageTemp.time_string));
		//	messageTemp.time_string[sizeof(messageTemp.time_string) - 1] = 0;
			// recivedmessagestemp.push_back(messageTemp);
			this->myfavouritmessages.push_back(messageTemp);
		}

		mf.close();


}