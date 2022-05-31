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
		ifstream messageFile;
		ofstream messageOutputFile;
		int positionInMessage;
		string sentMessagesPath = "usersmessages/" + to_string(this->userid) + "sent" + ".txt";
		string recievedMessagesPath = "usersmessages/" + to_string(this->userid) + "recieved" + ".txt";
		string favouriteMessagesPath = "favouritemessages/" + to_string(this->userid) + ".txt";
		string messageLine;
		messageFile.open(sentMessagesPath);

		while (getline(messageFile, messageLine)) {
			positionInMessage = messageLine.find(",");
			//string mycut = messageLine.substr(0, positionInMessage);
			string contenttemp = messageLine.substr(0, positionInMessage);
			messageLine = messageLine.substr(positionInMessage + 1);
			//first, 6437, 6421, May 15, 2022, 20:58 : 46
			positionInMessage = messageLine.find(",");
			int senderIDtemp = stoi(messageLine.substr(0,positionInMessage));
			messageLine = messageLine.substr(positionInMessage + 1);

			positionInMessage = messageLine.find(",");
			int recieverIDtemp = stoi(messageLine.substr(0, positionInMessage));
			messageLine = messageLine.substr(positionInMessage + 1);


			string datestringTemp = messageLine;

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
		messageFile.close();

		messageFile.open(recievedMessagesPath);
		//first, 6437, 6421, May 15, 2022, 20:58 : 46
		while (getline(messageFile, messageLine)) {
			positionInMessage = messageLine.find(",");
			//string mycut = messageLine.substr(0, positionInMessage);
			string contenttemp = messageLine.substr(0, positionInMessage);
			messageLine = messageLine.substr(positionInMessage + 1);
			//first, 6437, 6421, May 15, 2022, 20:58 : 46
			positionInMessage = messageLine.find(",");
			int senderIDtemp = stoi(messageLine.substr(0, positionInMessage));
			messageLine = messageLine.substr(positionInMessage + 1);

			positionInMessage = messageLine.find(",");
			int recieverIDtemp = stoi(messageLine.substr(0, positionInMessage));
			messageLine = messageLine.substr(positionInMessage + 1);


			string datestringTemp = messageLine;

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

		messageFile.close();


		/// retrieving favourites
		messageFile.open(favouriteMessagesPath);
		
		//first, 6437, 6421, May 15, 2022, 20:58 : 46
		while (getline(messageFile, messageLine)) {
			positionInMessage = messageLine.find(",");
			//string mycut = messageLine.substr(0, positionInMessage);
			string contenttemp = messageLine.substr(0, positionInMessage);
			messageLine = messageLine.substr(positionInMessage + 1);
			//first, 6437, 6421, May 15, 2022, 20:58 : 46
			positionInMessage = messageLine.find(",");
			int senderIDtemp = stoi(messageLine.substr(0, positionInMessage));
			messageLine = messageLine.substr(positionInMessage + 1);

			positionInMessage = messageLine.find(",");
			int recieverIDtemp = stoi(messageLine.substr(0, positionInMessage));
			messageLine = messageLine.substr(positionInMessage + 1);


			string datestringTemp = messageLine;

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

		messageFile.close();



}
/*
void User::goodmorning()
{
	ifstream mf;
	ofstream mofs;
	int mpos;
	string sentMessagesPath = "usersmessages/" + to_string(this->userid) + "sent" + ".txt";
	string recievedMessagesPath = "usersmessages/" + to_string(this->userid) + "recieved" + ".txt";
	string favouriteMessagesPath = "favouritemessages/" + to_string(this->userid) + ".txt";
	string mline;

	mf.open(recievedMessagesPath);

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
		//cout << messageTemp.content << endl;
		this->recivedmessages.push_back(messageTemp);
	}
	mf.close();






	// sent
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
		//cout << messageTemp.content << endl;
		this->sentmessages.push_back(messageTemp);
	}
	mf.close();




	// fav
	mf.open(favouriteMessagesPath);

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
		//cout << messageTemp.content << endl;
		this->myfavouritmessages.push_back(messageTemp);
	}
	mf.close();
}
*/
