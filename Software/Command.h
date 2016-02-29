#pragma once
class Command
{
public:
	Command();
	~Command();

	virtual bool executeCmd() = 0;
};