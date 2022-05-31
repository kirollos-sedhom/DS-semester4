#define NOMINMAX
#include "Program.h"
# include<string>
# include "User.h"
# include <cstdlib>
# include <ctime>
# include <fstream>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
using namespace std;


string usernamenow;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int useridnow;


void Program::run() {
	int choose = 0;
	SetConsoleTextAttribute(h, 5);
	cout << "\n\t\t\t      ---------Hello to saraha program----------\n " << endl;
	SetConsoleTextAttribute(h, 15);

	cout << "\t\t_______________________________________________________________\n" << endl;
	cout << "\t\t**please press 1 for register , 2 for login and 3 for Exit ** :    ";

	while (!(cin >> choose)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		printf("\x1B[31m\t\tInvalid input.  Try again:\033[0m\t\t");
	}
	if (choose == 1) {
		reg();
	}
	else if (choose == 2) {
		login();
	}
	else if (choose == 3)
	{
		SetConsoleTextAttribute(h, 10);
		cout << "\n\t\t\t  Thanks For Using Saraha ^_^ ... " << endl;
		SetConsoleTextAttribute(h, 15);
		cout << "\t\t\t\tEXIt PROGRAM ";
		exit;
	}
	else {
		SetConsoleTextAttribute(h, 12);
		cout << "\t\twrong choose !!!!!  please try again " << endl;
		SetConsoleTextAttribute(h, 15);
		run();
	}
}
int Program::random() {
	int randid = rand() % 10000;
	return randid;
}
int Program::chooseid() {
	srand(time(0));
	while (true) {
		bool alreadyexists = false;
		int randid = random();
		for (int i = 0; i < users.size(); i++) {
			if (users[i].userid != randid) {
				continue;
			}
			else if (users[i].userid == randid) {
				alreadyexists = true;
				break;
			}
		}

		if (alreadyexists == false) {
			return randid;
			break;
		}
	}

}
void Program::reg() {
	string pass;
	User s;
	cout << "\t\t----- enter your username please----- : " << endl;
	cout << "\t\t";
	cin >> ws;
	getline(cin, s.username);
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t!!!!!!! wow it is a beautiful  name  ^_^ : " << endl;
	SetConsoleTextAttribute(h, 15);
	cout << "\t\t-----please enter a sutiable password----- : " << endl;
	cout << "\t\t";
	cin >> ws;
	getline(cin, pass);
	s.setuserpass(pass);
	for (int i = 0; i < users.size(); i++) {
		int k = users[i].username.compare(s.username);
		int j = users[i].getuserpass().compare(s.getuserpass());
		if (j == 0 && k == 0) {
			SetConsoleTextAttribute(h, 5);
			cout << "\t\t** you are already have an account on saraha** " << endl;
			SetConsoleTextAttribute(h, 15);
			cout << " \t\t\t\t///please login/// : " << endl;
			cout << "\t\t_______________________________________________" << endl;
			login();
			break;

		}
		else {
			continue;
		}

	}
	cout << "\t\t-----now we will choose for you  an id----- : " << endl;
	s.userid = chooseid();
	SetConsoleTextAttribute(h, 14);
	cout << "\t\tyour id now is : " << s.userid << endl;
	SetConsoleTextAttribute(h, 15);
	users.push_back(s);
	sort(users.begin(), users.end(), [](const auto& a, const auto& b) { return a.userid < b.userid; });
	cout << "\t\t^^^^^^^ Congratulations you now have account on sarah please login^^^^^^^ :" << endl;
	cout << "______________________________________________________________________________" << endl;
	int choose;
	cout << "\t\t**press 1 for reg again , 2 for login and 3 for Exit ** :" << endl;
	cout << "\t\t";

	int x = 0;
	while (!(cin >> x)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		SetConsoleTextAttribute(h, 12);
		cout << "Invalid input.  Try again: ";
		SetConsoleTextAttribute(h, 15);
	}

	choose = x;
	if (choose == 1) {
		reg();
	}
	else if (choose == 2) {
		login();
	}
	else if (choose == 3)
	{
		SetConsoleTextAttribute(h, 10);
		cout << "\n\t\t\t  Thanks For Using Saraha ^_^ ... " << endl;
		SetConsoleTextAttribute(h, 15);
		cout << "\t\t\t\tEXIt PROGRAM ";
		exit;

	}

}
void Program::login() {
	string pass;
	User s;
	cout << " \t\t----- enter your username please ----- : " << endl;
	cout << "\t\t";
	std::cin >> std::ws;
	getline(cin, s.username);
	cout << "\t\t ----- enter your password ----- : " << endl;
	cout << "\t\t";
	std::cin >> std::ws;
	getline(cin, pass);
	s.setuserpass(pass);

	bool found = false;
	for (int i = 0; i < users.size(); i++) {
		int k = users[i].username.compare(s.username);
		int j = users[i].getuserpass().compare(s.getuserpass());
		if (j == 0 && k == 0) {

			found = true;
			usernamenow = users[i].username;
			useridnow = users[i].userid;

			usernow = &users[i];

			break;

		}

	}
	if (found == true) {
		SetConsoleTextAttribute(h, 10);
		cout << "\t\t //////  you successfully login /////// " << endl;
		SetConsoleTextAttribute(h, 15);
		cout << "\t\t_________________________________________" << endl;
		programcontent();
	}
	else {
		SetConsoleTextAttribute(h, 12);
		cout << "\t\t Something's wrong!" << endl;
		SetConsoleTextAttribute(h, 15);
		cout << "\t\t To try again press 1 , to Register press any number \n\n";
		int myinput = 0;

		while (!(cin >> myinput)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			SetConsoleTextAttribute(h, 12);
			cout << "\t\tInvalid input.  Try again: ";
			SetConsoleTextAttribute(h, 15);
		}
		if (myinput == 1)
		{
			login();
		}
		else
		{
			reg();
		}

	}

}
void Program::programcontent() {
	cout << "\n\n\n\t\t\t\t modified app \n\n\n";
	cout << "\t\tpress 1 for Add a user in your contacts.\n ";
	cout << "\t\tpress 2 for send a message to a contact.\n ";
	cout << "\t\tpress 3 for undo the last sent message.\n ";
	cout << "\t\tpress 4 for search about contact in my contacts(report NOT FOUND if he doesn’t exist).\n ";
	cout << "\t\tpress 5 for view your contacts.\n ";
	cout << "\t\tpress 6 for view all the sent messages from latest to oldest.\n ";
	cout << "\t\tpress 7 for view all the received messages.\n ";
	cout << "\t\tpress 8 for put a message in favorites.\n ";
	cout << "\t\tpress 9 for remove the oldest message from favorites.\n ";
	cout << "\t\tpress 10 for view all favorites messages\n ";
	cout << "\t\tpress 11 for to view messages from a cerain contact\n ";
	cout << "\t\tpress 12 for to view the contacts of a specific user\n ";
	cout << "\t\tpress 13 to logout\n ";

	int c;
	cin >> c;
	string s;
	switch (c) {
	case 1:
		search();
		programcontent();
		break;
	case 2:
		sendmessage();
		programcontent();
		break;
	case 3:
		undosentmessage();
		programcontent();
		break;
	case 4:
		searchaboutcontact();
		programcontent();
		break;
	case 5:
		viewallcontacts();
		programcontent();
		break;
	case 6:
		viewmessagesihavesent();
		programcontent();
		break;
	case 7:
		viewallmyrecievedmessages();
		programcontent();
		break;
	case 8:
		addtofavourites();
		programcontent();
		break;
	case 9:
		popoldestFavourite();
		programcontent();
		break;
	case 10:
		viewfavourites();
		programcontent();
		break;
	case 11:
		viewMessageFromaCertainContact();
		programcontent();
		break;
	case 12:
		viewContactsOfSpecificUser();
		programcontent();
		break;
	case 13:
		run();
		break;
	default:
		int choice;
		SetConsoleTextAttribute(h, 14);
		cout << "\t\t--- if you want to use program  again press 1 and if you want to exit press 2 --- :" << endl;
		SetConsoleTextAttribute(h, 15);
		cout << "\t\t";
		cin >> choice;
		if (choice == 1) {
			programcontent();
		}
		else if (choice == 2) {
			SetConsoleTextAttribute(h, 10);
			cout << "\t\tThanks For Using Saraha ^_^ ... " << endl;
			SetConsoleTextAttribute(h, 15);
			cout << "\t\t\tEXIt PROGRAM ";
			exit;
		}
	}
}
Program::~Program() {

	ofstream file_obj;
	string fname;

	file_obj.open("sizeOfusers.txt", ios::out | ios::app);
	file_obj << users.size() << endl;
	file_obj.close();
	for (int i = 0; i < users.size(); i++) {
		stringstream convert;
		convert << i;
		convert >> fname;
		file_obj.open("data/user" + fname + "info " + ".txt", ios::app);
		file_obj << users[i].username << "," << users[i].userid << "," << users[i].getuserpass() << endl;
		file_obj.close();
		for (int j = 0; j < users[i].mycontact.size(); j++) {

			file_obj.open("data/user" + fname + "mycontacts " + ".txt", ios::app);
			file_obj << users[i].mycontact[j].username << "|" << users[i].mycontact[j].userid << endl;
			file_obj.close();

		}

	}

}
Program::Program() {

}
void Program::readdata() {
	ifstream file;
	ofstream outputfile;
	string size;
	file.open("sizeOfusers.txt");
	getline(file, size);
	int k = stoi(size);
	file.close();
	outputfile.open("sizeOfusers.txt", std::ofstream::out | std::ofstream::trunc);
	outputfile.close();

	string fname;
	string line;
	User us;
	User uc;
	int pos;
	for (int i = 0; i < stoi(size); i++) {
		stringstream convert;
		convert << i;
		convert >> fname;
		file.open("data/user" + fname + "info " + ".txt");
		getline(file, line);
		pos = line.find(",");
		string mycut = line.substr(0, pos);
		us.username = mycut;
		line = line.substr(pos + 1);
		pos = line.find(",");
		mycut = line.substr(0, pos);
		stringstream geek(mycut);
		geek >> us.userid;
		line = line.substr(pos + 1);
		us.setuserpass(line);
		// was here
		us.readfromfile();

		users.push_back(us);


		file.clear();
		file.close();
		file.open("data/user" + fname + "mycontacts " + ".txt");
		while (getline(file, line)) {
			pos = line.find("|");
			mycut = line.substr(0, pos);
			uc.username = mycut;
			line = line.substr(pos + 1);
			stringstream geeki(line);
			geeki >> uc.userid;
			users[i].mycontact.push_back(uc);

		}
		file.close();

	}
	for (int i = 0; i < stoi(size); i++) {
		stringstream converti;
		converti << i;
		converti >> fname;
		outputfile.open("data/user" + fname + "info " + ".txt", std::ofstream::out | std::ofstream::trunc);
		outputfile.close();
		outputfile.open("data/user" + fname + "mycontacts " + ".txt", std::ofstream::out | std::ofstream::trunc);
		outputfile.close();
	}
}
void  Program::addtoyourcontact(User n) {
	int check = 0;
	bool isAdded = alreadyadded(n);
	if (isAdded == true) {
		SetConsoleTextAttribute(h, 5);
		cout << " _you added this contact before_ : " << endl;
		SetConsoleTextAttribute(h, 15);
		cout << " press 1 to back to home and 2 for add another contact : " << endl;
		while (!(cin >> check)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			SetConsoleTextAttribute(h, 12);
			cout << "\t\tInvalid input.  Try again: ";
			SetConsoleTextAttribute(h, 15);
		}
		if (check == 1) {
			programcontent();

		}
		else if (check == 2) {
			search();


		}

	}
	else if (isAdded == false) {
		int start = 0;
		int end = users.size() - 1;


		for (int i = 0; i < users.size(); i++) {
			int middle = (end - start) / 2;
			if (users[i].userid == useridnow) {
				users[i].mycontact.push_back(n);
				SetConsoleTextAttribute(h, 10);
				cout << " ***contact is added*** " << endl;
				SetConsoleTextAttribute(h, 15);
				break;
			}
			else if (users[middle].userid > useridnow) {
				end = middle - 1;
			}
			else {
				start = middle + 1;
			}
		}
	}

}
void Program::search() {

	int start = 0;
	int end = users.size() - 1;
	int id;
	cout << "enter id of user you want to add : " << endl;
	int myinput = 0;

	while (!(cin >> myinput)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		SetConsoleTextAttribute(h, 12);
		cout << "\t\tInvalid input.  Try again: ";
		SetConsoleTextAttribute(h, 15);
	}
	id = myinput;

	User us;
	bool found = false;

	for (int i = 0; i < users.size(); i++) {
		int middle = (end - start) / 2;
		if (users[i].userid == id) {
			found = true;
			addtoyourcontact(users[i]);
			break;
		}
		else if (users[middle].userid > id) {
			end = middle - 1;
		}
		else {
			start = middle + 1;
		}
	}

	if (found == false) {
		int choose = 0;
		SetConsoleTextAttribute(h, 8);
		cout << " ___ No contact of this username ___" << endl;
		SetConsoleTextAttribute(h, 15);
		cout << " enter 1 for try again and 2 for go home" << endl;

		while (!(cin >> choose)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			SetConsoleTextAttribute(h, 12);
			cout << "\t\tInvalid input.  Try again: ";
			SetConsoleTextAttribute(h, 15);
		}
		if (choose == 1) {
			search();
		}

	}

}
bool Program::alreadyadded(User n) {
	bool alreadyadded = false;
	int start = 0;
	int end = users.size() - 1;

	for (int i = 0; i < users.size(); i++) {
		int middle = (end - start) / 2;
		if (users[i].userid == useridnow) {
			for (int k = 0; k < users[i].mycontact.size(); k++) {

				if (users[i].mycontact[k].userid == n.userid) {

					alreadyadded = true;

				}
				else {
					continue;
				}
			}

			break;
		}
		else if (users[middle].userid > useridnow) {
			end = middle - 1;
		}
		else {
			start = middle + 1;
		}
	}
	return alreadyadded;

}

void Program::sendmessage()
{
	int recieverid;
	// checking if recipient is a registered user 
	// using binary search

	bool found = false;





	while (found == false)
	{
		cout << "enter reciever ID: \n";

		int x = 0;
		while (!(cin >> x)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			SetConsoleTextAttribute(h, 12);
			cout << "Invalid input. please try again: ";
			SetConsoleTextAttribute(h, 15);


		}

		int start = 0;
		int end = users.size() - 1;
		recieverid = x;
		for (int i = 0; i < users.size(); i++) {
			int middle = (end - start) / 2;
			if (users[i].userid == recieverid) {

				found = true;
				string messageToBeSent;
				SetConsoleTextAttribute(h, 14);
				cout << "write your message: \n make it supportive and nice :)\n";
				SetConsoleTextAttribute(h, 15);
				cin >> ws;
				getline(cin, messageToBeSent);

				Message newmessage = Message(messageToBeSent, useridnow, recieverid);
				newmessage.messageid = chooseid();
				usernow->sentmessages.push_back(newmessage);
				usernow->ActiveSession++;
				users[i].recivedmessages.push_back(newmessage);
				/////// file addition 

				string fname = "usersmessages/" + to_string(recieverid) + "recieved" + ".txt";
				ofstream filei;
				filei.open(fname, ios::out | ios::app);

				if (!filei.is_open() && filei.fail())
				{
					SetConsoleTextAttribute(h, 12);
					cout << "\nerror sending message!\n";
					SetConsoleTextAttribute(h, 15);
					filei.close();
				}

				filei << newmessage.content << "," << newmessage.senderID << "," << newmessage.recieverID << "," << newmessage.date_string << "," << newmessage.time_string << endl;
				SetConsoleTextAttribute(h, 10);
				cout << "message sent successfully!\n";
				SetConsoleTextAttribute(h, 15);
				filei.close();

				// add to my sent messages 
				fname = "usersmessages/" + to_string(usernow->userid) + "sent" + ".txt";
				filei.open(fname, ios::out | ios::app);
				if (!filei.is_open() && filei.fail())
				{
					SetConsoleTextAttribute(h, 12);
					cout << "\nerror sending message!\n";
					SetConsoleTextAttribute(h, 15);
					filei.close();
				}

				filei << newmessage.content << "," << newmessage.senderID << "," << newmessage.recieverID << "," << newmessage.date_string << "," << newmessage.time_string << endl;
				filei.close();
				break;
			}
			else if (users[middle].userid > useridnow) {
				end = middle - 1;
			}
			else {
				start = middle + 1;
			}
		}
	}






}
void Program::undosentmessage()
{
	if (usernow->ActiveSession == 0)
	{
		SetConsoleTextAttribute(h, 12);
		cout << "You haven't sent messages during this session Yet";
		SetConsoleTextAttribute(h, 15);
	}
	else
	{
		int tempid;
		string fname;
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].userid == usernow->userid)
			{
				tempid = users[i].sentmessages.back().recieverID;
				users[i].sentmessages.pop_back();
				users[i].ActiveSession--;
				break;
			}
		}
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].userid == tempid)
			{

				users[i].recivedmessages.pop_back();
				fname = "usersmessages/" + to_string(users[i].userid) + "recieved" + ".txt";
				break;
			}
		}

		string path = "usersmessages/" + to_string(usernow->userid) + "sent" + ".txt";

		list<string> mymessages = returnmessages(path);
		list<string> yourmessages = returnmessages(fname);
		mymessages.pop_back();
		yourmessages.pop_back();
		writetofile(mymessages, path);
		writetofile(yourmessages, fname);
		SetConsoleTextAttribute(h, 10);
		cout << "Message undo succesfully ^_^ :" << endl;
		SetConsoleTextAttribute(h, 15);


	}

}
void Program::searchaboutcontact()
{
	int n, f = 0;
	cout << "enter the id \n";
	cin >> n;
	if (n == useridnow) {
		SetConsoleTextAttribute(h, 12);
		cout << "this your id ";
		SetConsoleTextAttribute(h, 15);
	}
	else {
		int f = 0;
		for (auto x : usernow->mycontact) {
			if (x.userid == n)
				f = 1;
			else
				f = 0;
		}
		if (f == 1)
		{
			SetConsoleTextAttribute(h, 10);
			cout << "user found \n";
			SetConsoleTextAttribute(h, 15);
		}

		else
		{
			SetConsoleTextAttribute(h, 5);
			cout << "user not found \n";
			SetConsoleTextAttribute(h, 15);
		}

	}
}
void Program::viewmessagesihavesent()
{


	///////////////////////////////////////////////////////karlo's code
	list<Message>tempmessages;
	ifstream mf;
	ofstream mofs;
	int mpos;
	string sentMessagesPath = "usersmessages/" + to_string(usernow->userid) + "sent" + ".txt";
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
		tempmessages.push_back(messageTemp);
		//cout << messageTemp.content << endl;
	}
	mf.close();
	//list<Message> reversedmessages = 
	tempmessages.reverse();
	for (auto i : tempmessages)
	{
		cout << i.content<<endl;
	}

	/**list<Message> reversedsentmessages = usernow->sentmessages;
	reversedsentmessages.reverse();
	for (auto const& i : reversedsentmessages) {
		cout << i.content << " ---sent to user: " << i.recieverID << " " << i.date_string << " " << i.time_string << endl;
	}**/

}
void Program::viewallcontacts()
{
	if (usernow->mycontact.empty())
	{
		SetConsoleTextAttribute(h, 14);
		cout << "Looks like you don't have friends yet!\n";
		SetConsoleTextAttribute(h, 15);
	}
	else
	{
		for (int j = 0; j < this->usernow->mycontact.size(); j++) {
			cout << "contact " << (j + 1) << ":" << endl;
			//cout << usernow->mycontact[j].username << endl;  // removed the username because it defeats the point of Saraha's anonymity
			cout << usernow->mycontact[j].userid << endl;
			cout << "_______________" << endl;
		}
	}

}
void Program::viewallmyrecievedmessages()
{
	list<Message>tempmessages;
	/**list<Message> reversedmessages = usernow->recivedmessages;
	reversedmessages.reverse();
	if (usernow->recivedmessages.empty())
	{
		SetConsoleTextAttribute(h, 14);
		cout << "empty messages :C\n";
		SetConsoleTextAttribute(h, 15);
	}
	else
	{
		for (auto i : reversedmessages)
		{
			cout << i.content << " ---recieved from user: " << i.senderID << " " << i.date_string << " " << i.time_string << endl;
		}
	}**/
	ifstream mf;
	ofstream mofs;
	int mpos;
	string recievedMessagesPath = "usersmessages/" + to_string(usernow->userid) + "recieved" + ".txt";
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
		tempmessages.push_back(messageTemp);
	}
	mf.close();
	tempmessages.reverse();
	for (auto i : tempmessages)
	{
		cout << i.content<< "--- from user "<<i.senderID << "at time: "<<i.date_string<<endl;
	}
}

void Program::addtofavourites()
{
	string sentMessagesPath = "usersmessages/" + to_string(usernow->userid) + "sent" + ".txt";
	string recievedMessagesPath = "usersmessages/" + to_string(usernow->userid) + "recieved" + ".txt";
	string favouriteMessagesPath = "favouritemessages/" + to_string(usernow->userid) + ".txt";
	vector<Message> messagesPlaceholder = fetch(recievedMessagesPath);

	/// <summary>
	/// /////////////////
	/// </summary>


	
	int i = 0;
	int tempnumber;

	for (auto temp : messagesPlaceholder)
	{

		

		cout << (i + 1) << "- " << temp.content << endl;
		i++;

	}

	if (messagesPlaceholder.empty())
	{
		SetConsoleTextAttribute(h, 14);
		cout << "but... your messages are empty !";
		SetConsoleTextAttribute(h, 15);
	}
	else
	{
		cout << "type the number of your favourited message :D\n";

		cin >> tempnumber;
		bool alreadyadded = false;
		for (auto message : usernow->myfavouritmessages)
		{
			if (message.messageid == messagesPlaceholder[(tempnumber - 1)].messageid)
			{
				cout << "this message is already in your favourites!";
				alreadyadded = true;
			}

		}
		if (alreadyadded == false)
		{
			for (int i = 0; i < users.size(); i++)
			{
				if (users[i].userid == useridnow)
				{
					users[i].myfavouritmessages.push_back(messagesPlaceholder[(tempnumber - 1)]);

				}

			}
			/////// file addition

			string fname = "favouritemessages/" + to_string(usernow->userid) + ".txt";
			ofstream filei;
			filei.open(fname, ios::out | ios::app);

			if (!filei.is_open() && filei.fail())
			{
				SetConsoleTextAttribute(h, 12);
				cout << "\nerror saving message to favourites!\n";
				SetConsoleTextAttribute(h, 15);
				filei.close();
			}

			filei << messagesPlaceholder[(tempnumber - 1)].content << "," << messagesPlaceholder[(tempnumber - 1)].senderID << "," << messagesPlaceholder[(tempnumber - 1)].recieverID << "," << messagesPlaceholder[(tempnumber - 1)].date_string << endl;
			SetConsoleTextAttribute(h, 10);
			cout << "message added to favourites successfully!\n";
			SetConsoleTextAttribute(h, 15);
			filei.close();


		}

	}

}
void Program::viewfavourites()
{
	if (usernow->myfavouritmessages.empty())
	{
		SetConsoleTextAttribute(h, 14);
		cout << "but... your favourite messages are empty !";
		SetConsoleTextAttribute(h, 15);
	}
	else
	{
		for (auto i : usernow->myfavouritmessages)
		{
			cout << i.content << " ---recieved from user: " << i.senderID << " " << i.date_string << " " << i.time_string << endl;
		}

	}



}
void Program::popoldestFavourite()
{
	if (usernow->myfavouritmessages.empty())
	{
		SetConsoleTextAttribute(h, 14);
		cout << "but... your favourite messages are empty !";
		SetConsoleTextAttribute(h, 15);
	}
	else
	{
		string favouriteMessagesPath = "favouritemessages/" + to_string(usernow->userid) + ".txt";
		usernow->myfavouritmessages.pop_front();
		ofstream newfile;
		newfile.open(favouriteMessagesPath, ios::out);
		if (newfile.is_open())
		{
			for (auto const& i : usernow->myfavouritmessages)
			{
				newfile << i.content << "," << i.senderID << "," << i.recieverID << "," << i.date_string << endl;
			}
			newfile.close();
		}

	}

}
/*
void Program::checkRecipients()
{
	list<int> temp = reciepientIDs;
	while (!temp.empty())
	{
		int x = temp.back();
		cout << x << endl;
		temp.pop_back();
	}

}

*/


list<string> Program::returnmessages(string filepath)
{
	list<string> messages;
	string lines;
	try
	{
		fstream newfile;
		newfile.open(filepath, ios::in); // open a file to perform read operation using file object
		if (newfile.is_open())
		{ // checking whether the file is open
			string tp;
			while (getline(newfile, tp))
			{                           // read data from file object and put it into string.
				messages.push_back(tp); // print the data of the string
			}
			newfile.close(); // close the file object.
		}
	}
	catch (exception& e)
	{
		SetConsoleTextAttribute(h, 12);
		cout << "there is a standerd exception " << e.what() << endl;
		SetConsoleTextAttribute(h, 15);
	}
	return messages;
}
void Program::writetofile(list<string> mylist, string filepath)
{
	ofstream newfile;
	newfile.open(filepath, ios::out);
	if (newfile.is_open())
	{
		/* code */
		for (auto const& i : mylist)
		{
			newfile << i << std::endl;
		}
		newfile.close();
	}
}

void Program::viewMessageFromaCertainContact()
{
	cout << "Please enter the user ID:-\n";
	bool found = false;
	int tempid;
	cin >> tempid;
	if (tempid == usernow->userid)
	{
		SetConsoleTextAttribute(h, 14);
		cout << "but... this is your ID :/\n";
		SetConsoleTextAttribute(h, 15);

	}
	else
	{
		for (Message i : usernow->recivedmessages)
		{
			if (i.senderID == tempid)
			{
				cout << i.content << "," << i.senderID << "," << i.recieverID << "," << i.date_string << endl;

				found = true;
			}
		}
		if (found == false)
		{
			SetConsoleTextAttribute(h, 14);
			cout << "You haven't recieved messages from this user yet, or the user might not exist :C";
			SetConsoleTextAttribute(h, 15);
		}

	}

}
void Program::viewContactsOfSpecificUser()
{
	cout << "Please enter the user ID:-\n";
	int tempid;
	cin >> tempid;

	int start = 0;
	int end = users.size() - 1;
	bool found = false;
	for (int i = 0; i < users.size(); i++) {
		int middle = (end - start) / 2;
		if (users[i].userid == tempid) {

			found = true;
			if (users[i].mycontact.empty())
			{
				SetConsoleTextAttribute(h, 14);
				cout << "this user has no friends :c\n";
			}
			else
			{
				cout << "For anonymity, you can only see this user's friends' IDs\n";
				cout << "__________________" << endl;
				int count = 0;
				for (auto contact : users[i].mycontact)
				{
					cout << "contact " << (count + 1) << ":" << endl;
					//cout << usernow->mycontact[j].username << endl;  // removed the username because it defeats the point of Saraha's anonymity
					cout << contact.userid << endl;
					cout << "_______________" << endl;
				}

			}


			break;
		}
		else if (users[middle].userid > useridnow) {
			end = middle - 1;
		}
		else {
			start = middle + 1;
		}
	}

	if (found == false)
	{
		SetConsoleTextAttribute(h, 14);
		cout << "This user does not exist :C";
		SetConsoleTextAttribute(h, 15);

	}



}

vector<Message> Program::fetch(string mypath)
{
	vector<Message> tempvector;

	
		ifstream messageFile;
		ofstream messageOutputFile;
		int positionInMessage;

		string messageLine;
		messageFile.open(mypath);

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
			//	messageTemp.date_string[sizeof(messageTemp.date_string) - 1] = 0;
			//	string temp2 = timestringTemp;
			//	strncpy(messageTemp.time_string, temp2.c_str(), sizeof(messageTemp.time_string));
			//	messageTemp.time_string[sizeof(messageTemp.time_string) - 1] = 0;
				// sentmessagestemp.push_back(messageTemp);
			//usernow->myfavouritmessages.push_back(messageTemp);
			tempvector.push_back(messageTemp);
		}
		messageFile.close();
		return tempvector;

	
	
}