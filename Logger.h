#pragma once
#include <deque>
#include <string>
#include <iostream>
#include "Configuration.h"
#include "InputManager.h"

using namespace std;

typedef enum {
	EMPTY,
	INFO,
	KILL,
	BIRTH,
	SOW,
	EAT,
	POISON
} Type;

typedef struct {
	string mess;
	Type type;
} LogString;

class Logger
{
private:
	const static int max_messages = LOG_MAX_MESSAGES;
	const int startX, startY;
	bool added;
	InputManager& input;
	deque<LogString> logs;
public:
	Logger(const int x, const int y, InputManager& in);
	Logger(const int x, const int y, InputManager& in, deque<LogString> log, bool add);
	~Logger();
	void display();
	void textMenu() const;
	void addLog(const LogString& log);
};