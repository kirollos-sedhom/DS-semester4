#include "Message.h"

Message::Message(string content, int senderid, int recieverid)
{

	time(&curr_time);
	curr_tm = localtime(&curr_time);

	strftime(date_string, 50, "%B %d, %Y", curr_tm);
	this->content = content;
	this->senderID = senderid;
	this->recieverID = recieverid;
	



}