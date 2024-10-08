/*
	request.h - header file for the Request class.
	
	Revision 0
	
	Notes:
			- 
			
	2016/11/19, Maya Posch
	(c) Nyanko.ws
*/


#pragma once
#ifndef REQUEST_H
#define REQUEST_H

#include "abstract_request.h"
#include <functional>
#include <string>

using namespace std;

using logFunction = std::function<void(std::string)>;


class Request : public AbstractRequest {
	int value;
	logFunction outFnc;
	
public:
	void setValue(int value) { this->value = value; }
	void setOutput(logFunction fnc) { outFnc = fnc; }
	void process();
	void finish();
};

#endif
