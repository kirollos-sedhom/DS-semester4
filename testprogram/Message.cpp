#include "Message.h"
//message::message() {
	//this->content = "empty message";
	// this->messageCount++;
//}

Message::Message(string content, int senderid, int recieverid)
{

	time(&curr_time);
	curr_tm = localtime(&curr_time);

	strftime(date_string, 50, "%B %d, %Y", curr_tm);
	strftime(time_string, 50, "%T", curr_tm);
	//this->content = content + " " + date_string + " " + time_string;
	this->content = content;
	this->senderID = senderid;
	this->recieverID = recieverid;
	// this->messageCount++;



}