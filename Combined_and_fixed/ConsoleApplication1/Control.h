#pragma once
#include "Command.h"

class Control :public Command
{
	public:
	void setCommand(Command *cmd) {
		mCmd = cmd;
	}

	void buttonPressed() {
		mCmd->executeCmd();
	}
	void executeCmd(){}
private:
	Command *mCmd;
};