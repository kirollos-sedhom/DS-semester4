#include "User.h"
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