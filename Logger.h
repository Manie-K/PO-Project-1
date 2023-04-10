#pragma once
#include <deque>
#include <string>
#include <iostream>
#include "Configuration.h"

using namespace std;

typedef enum {
	EMPTY,
	INFO,
	KILL,
	BIRTH
}Type;

typedef struct {
	string mess;
	Type type;
}LogString;

class Logger 
{
private:
	const static int max_messages = LOG_MAX_MESSAGES;
	const int startX, startY;
	bool added;
	deque<LogString> logs;
public:
	Logger(const int x, const int y);
	~Logger();
	void display();
	void addLog(const LogString& log);
};