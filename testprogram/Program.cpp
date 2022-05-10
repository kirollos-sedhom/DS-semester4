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

using namespace std;
string usernamenow;
int useridnow;


void Program::run() {
	int choose;
	cout << "\n\t\t\t      ---------Hello to sarah program----------\n " << endl;
	cout << "\t\t_______________________________________________________________\n" << endl;
	cout << "\t\t**please press 1 for register , 2 for login and 3 for Exit ** :    " ;
	cin >> choose;
	if (choose == 1) {
		reg();
	}
	else if (choose == 2) {
		login();


	}
	else if (choose == 3)
	{
		cout << "\n\t\t\t  Thanks For Using Saraha ^_^ ... " << endl;;
		cout << "\t\t\t\tEXIt PROGRAM ";
		exit;	exit;

	}
	else {
		cout << "\t\twrong choose !!!!!  please try again " << endl;
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
	std::cin >> std::ws;
	getline(cin, s.username);
	cout << "\t\t!!!!!!! wow it is a beautiful  name  ^_^ : " << endl;
	cout << "\t\t-----please enter a sutiable password----- : " << endl;
	cout << "\t\t";
	std::cin >> std::ws;
	getline(cin, pass);
	s.setuserpass(pass);
	for (int i = 0; i < users.size(); i++) {
		int k = users[i].username.compare(s.username);
		int j = users[i].getuserpass().compare(s.getuserpass());
		if (j == 0 && k == 0) {
			cout << "\t\t** you are already have an account on saraha** " << endl;
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
	cout << "\t\tyour id now is : " << s.userid << endl;
	users.push_back(s);
	cout << "\t\t^^^^^^^ Congratulations you now have account on sarah please login^^^^^^^ :" << endl;
	cout << "______________________________________________________________________________" << endl;
	int choose;
	cout << "\t\t**press 1 for reg again , 2 for login and 3 for Exit ** :" << endl;
	cout << "\t\t";
	cin >> choose;
	if (choose == 1) {
		reg();
	}
	else if (choose == 2) {
		login();
	}
	else if (choose == 3)
	{
		cout << "\n\t\t\t  Thanks For Using Saraha ^_^ ... " << endl;;
		cout << "\t\t\t\tEXIt PROGRAM ";
		exit;	exit;

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
			// replacement for the above code
			usernow = &users[i];
			break;

		}

	}
	if (found == true) {
		cout << "\t\t //////  you successfully login /////// " << endl;
		cout << "\t\t_________________________________________" << endl;
		programcontent();
	}
	else {
		cout << "\t\t Something's wrong!" << endl;
		cout << "\t\t To try again press 1 , to Register press 2\n\n";
		int myinput = 0;
		while (myinput == 0)
		{
			cin >> myinput;
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
}
void Program::programcontent() {
	cout << "\n\n\n\t\t\t\t modified app \n\n\n";
	cout << "\t\tpress 1 for Add a user in your contacts.\n ";
	cout << "\t\tpress 2 for send a message to a contact.\n ";
	cout << "\t\tpress 3 for undo the last sent message.\n ";
	cout << "\t\tpress 4 for search about contact in my contacts(report NOT FOUND if he doesn’t exist).\n ";
	cout << "\t\tpress 5 for view all contacts of specific user.\n ";
	cout << "\t\tpress 6 for view all the sent messages from latest to oldest.\n ";
	cout << "\t\tpress 7 for view all the received messages from specific contact.\n ";
	cout << "\t\tpress 8 for put a message in favorites.\n ";
	cout << "\t\tpress 9 for remove the oldest message from favorites.\n ";
	cout << "\t\tpress 10 for view all favorites messages\n ";
	cout << "\t\tpress 11 for logout\n ";

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
		run();
		break;
	default:
		int choice;
		cout << "\t\t--- if you want to use program  again press 1 and if you want to exit press 2 --- :" << endl;
		cout << "\t\t";
		cin >> choice;
		if (choice == 1) {
			programcontent();
		}
		else if (choice == 2) {
			cout << "\t\tThanks For Using Saraha ^_^ ... " << endl;;
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
	ifstream f;
	ofstream ofs;
	string size;
	f.open("sizeOfusers.txt");
	getline(f, size);
	int k = stoi(size);
	f.close();
	if (stoi(size) != 0) {
		ofs.open("sizeOfusers.txt", std::ofstream::out | std::ofstream::trunc);
		ofs.close();
	}

	string fname;
	string line;
	User us;
	User uc;
	int pos;
	for (int i = 0; i < stoi(size); i++) {
		stringstream convert;
		convert << i;
		convert >> fname;
		f.open("data/user" + fname + "info " + ".txt");
		getline(f, line);
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
		users.push_back(us);
		f.clear();
		f.close();
		f.open("data/user" + fname + "mycontacts " + ".txt");
		while (getline(f, line)) {
			pos = line.find("|");
			mycut = line.substr(0, pos);
			uc.username = mycut;
			line = line.substr(pos + 1);
			stringstream geeki(line);
			geeki >> uc.userid;
			users[i].mycontact.push_back(uc);

		}
		f.close();


	}
	for (int i = 0; i < stoi(size); i++) {
		stringstream converti;
		converti << i;
		converti >> fname;
		ofs.open("data/user" + fname + "info " + ".txt", std::ofstream::out | std::ofstream::trunc);
		ofs.close();
		ofs.open("data/user" + fname + "mycontacts " + ".txt", std::ofstream::out | std::ofstream::trunc);
		ofs.close();
	}
}
void  Program::addtoyourcontact(User n) {
	int hi;
	bool l = alreadyadded(n);
	if (l == true) {
		cout << " _you add this contact before_ : " << endl;
		cout << " press 1 to back to home and 2 for add another contact : " << endl;
		cin >> hi;
		if (hi == 1) {
			programcontent();

		}
		else if (hi == 2) {
			search();


		}

	}
	else if (l == false) {
		for (int j = 0; j < users.size(); j++) {
			int l = users[j].username.compare(usernamenow);
			if (l == 0 && users[j].userid == useridnow) {
				users[j].mycontact.push_back(n);
				cout << "contact is added" << endl;
				break;

			}
		}
	}

}
void Program::search() {
	string name;
	string choose;
	int choose1;
	bool found;
	found = false;
	cout << "**enter the user name of contect you want to add** : " << endl;
	std::cin >> std::ws;
	getline(cin, name);
	for (int i = 0; i < users.size(); i++) {
		int k = users[i].username.compare(name);
		if (k == 0 && users[i].userid != useridnow) {
			cout << "is this the contact you want to add : (y/n)" << endl;
			cout << users[i].username << endl;
			cout << users[i].userid << endl;
			cin >> choose;
			if (choose == "y") {
				found = true;
				addtoyourcontact(users[i]);
				break;
			}
			else if (choose == "n") {
				cout << " it is okay we will search more : " << endl;
				continue;
			}
		}
	}
	if (found == false) {
		cout << "__ No contact of this username ___" << endl;
		cout << " * enter 1 for another try and 2 for home * : " << endl;
		cin >> choose1;
		if (choose1 == 1) {
			search();
		}
		else if ((choose1 == 2)) {
			programcontent();
		}
	}

}
bool Program::alreadyadded(User n) {
	bool alreadyadded = false;
	for (int l = 0; l < users.size(); l++) {
		int m = users[l].username.compare(usernamenow);
		if (m == 0 && users[l].userid == useridnow) {
			for (int k = 0; k < users[l].mycontact.size(); k++) {
				int test = users[l].mycontact[k].username.compare(n.username);
				if (test == 0 && users[l].mycontact[k].userid == n.userid) {

					alreadyadded = true;

				}
				else {
					continue;
				}
			}

		}
		else {
			continue;
		}
	}
	return alreadyadded;

}

void Program::sendmessage()
{
	int recieverid;
	// checking if recipient is a registered user
	bool found = false;
	while (found == false)
	{
		cout << "enter reciever id: \n";
		//cin >> recieverid;

		int x = 0;
		while (!(cin >> x)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";
		}




		for (auto i : users)
		{
			if (i.userid == x)
			{
				found = true;
			}
		}
		recieverid = x;
		
	}
	

	
	//this->reciepientIDs.push(recieverid);
	reciepientIDs.push_back(recieverid);
	id_Of_Last_Recipient = recieverid;
	this->reciepientIDs.pop_back();
	string messageToBeSent;
	cout << "write your message: \n make it supportive and nice :)\n";
	cin >> ws;
	getline(cin, messageToBeSent);

	//test
	//cout << " confirming sending message : \" " << messageToBeSent << "\" \n";
	Message newmessage = Message(messageToBeSent, useridnow, recieverid);
	this->sentmessages.push_back(newmessage);
	
	for (int i = 0; i < users.size(); i++)
	{
		

	if (users[i].userid == recieverid)
		{
		
			users[i].recivedmessages.push_back(newmessage);

			this->reciepientIDs.push_back(recieverid);
			// testing
			//cout << "recipient IDs now contain:\n";
			//checkRecipients();
		}


	}
		
/////// file addition
	//string id = s;
	//id_Of_Last_Recipient = s;
	string fname = "usersmessages/" +to_string(recieverid) + "recieved" + ".txt";
	//   string fname = s + "recieved" + ".txt";
	ofstream filei;
	filei.open(fname, ios::out | ios::app);

	//    fname = usn + ".txt";

	if (!filei.is_open() && filei.fail())
	{
		cout << "\nerror sending message!\n";
		filei.close();
	}
	string finalmessagecontent = newmessage.content + "\n";
	filei << finalmessagecontent;
	cout << "message sent successfully!\n";
	filei.close();

	// add to my sent messages
	fname = "usersmessages/" +to_string(usernow->userid) + "sent" + ".txt";
	filei.open(fname, ios::out | ios::app);
	if (!filei.is_open() && filei.fail())
	{
		cout << "\nerror sending message!\n";
		filei.close();
	}

	filei << finalmessagecontent;
	filei.close();
}
void Program::undosentmessage()
{
	//usernow->sentmessages.pop_back();
	string path = "usersmessages/" + to_string(usernow->userid)  + "sent" + ".txt";
	//string path = "usersmessages/" + usernow->userid + "sent" + ".txt";
	string fname = "usersmessages/" + to_string(id_Of_Last_Recipient) + "recieved" + ".txt";
	list<string> mymessages = returnmessages(path);
	list<string> yourmessages = returnmessages(fname);
	mymessages.pop_back();
	yourmessages.pop_back();
	writetofile(mymessages, path);
	writetofile(yourmessages, fname);

	
	// under testing
	/*
	* 			for (auto i : usernow->mycontact)
	{
		if (i.userid == reciepientIDs.back())
		{
			//cout << "found the user to pop his messages"<<endl;
			//i.recievedmessages.pop_back();
			i.recivedmessages.pop_back();
			//cout << "message popped" << endl;
			this->reciepientIDs.pop_back();

		}
	}
	*/
	


	




	
}
void Program::searchaboutcontact()
{
	int n,f=0;
	cout << "enter the id \n";
	cin >> n;
	if (n == useridnow) {
		cout << "this your id ";
	}
	else {

		for (int l = 0; l < users.size(); l++) {


			for (int k = 0; k < users[l].mycontact.size(); k++) {
				if (users[l].mycontact[k].userid == n) { f = 1; }
				else { f = 0; }
			}
		}
			if (f==1)
				cout << "user found \n";
			else 
				cout << "user not found \n";
			
		
	}
}
void Program::viewmessagesihavesent()
{

	list<Message> reversedsentmessages = sentmessages;
	reversedsentmessages.reverse();
	for (auto const& i : reversedsentmessages) {
		cout << i.content << " ---sent to user: " << i.recieverID << " " << i.date_string << " " << i.time_string << endl;
	}
}
void Program::viewallcontacts()
{
//	for (int i = 0; i < users.size(); i++) {
//		int k = users[i].username.compare(usernamenow);
//		if (k == 0 && users[i].userid == useridnow) {
	
			for (int j = 0; j < this->usernow->mycontact.size(); j++) {
				cout << "contact " << (j + 1) << ":" << endl;
				cout << usernow->mycontact[j].username << endl;
				cout << usernow->mycontact[j].userid << endl;
				cout << "_______________" << endl;
			}
//		}
//		else {
//			continue;
//		}

//	}
}
void Program::viewallmyrecievedmessages()
{

	for (int i = 0; i < users.size(); i++)
	{
		

		if (users[i].userid == useridnow)
		{

			if (users[i].recivedmessages.empty())
			{
				cout << "empty messages :C";
			}
			else
			{
				for (auto const& i : users[i].recivedmessages) {
					cout << i.content << endl;
				}
			}
		}

	}
}

void Program::addtofavourites()
{
	vector<Message> messagesPlaceholder;
	int i = 0;
	// currently using sentmessages , but will switch to recieved messages

	for (auto temp : usernow->recivedmessages)
	{

		messagesPlaceholder.push_back(temp);

		cout << (i + 1) << "- " << temp.content << endl;
		i++;

	}


	cout << "type the number of your favourited message :D\n";
	int tempnumber;
	cin >> tempnumber;

	

	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].userid == useridnow)
		{
			users[i].myfavouritmessages.push_back(messagesPlaceholder[(tempnumber - 1)]);
			
		}

	}
}
void Program::viewfavourites()
{
	/*
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].userid == useridnow)
		{
			for (auto i : users[i].myfavouritmessages)
			{
				cout << i.content << endl;
			}

		}

	}
	*/
	for (auto i : usernow->myfavouritmessages)
	{
		cout << i.content<<"   " << i.date_string << " " << i.time_string << endl;
	}
	
	
	
}
void Program::popoldestFavourite()
{
	/*
		for (int i = 0; i < users.size(); i++)
	{
		if (users[i].userid == useridnow)
		{
			users[i].myfavouritmessages.pop_front();
		}

	}
	*/
	usernow->myfavouritmessages.pop_front();


}

void Program::checkRecipients()
{
	list<int> temp = reciepientIDs;
	while (!temp.empty())
	{
		int x = temp.back();
		cout << x<<endl;
		temp.pop_back();
	}

}


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
		cout << "their is an standerd exception " << e.what() << endl;
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