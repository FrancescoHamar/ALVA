#pragma once
#include <vector>

class Todo
{
public:
	std::vector<std::string> urgentL;
	std::vector<std::string> commonL;
	std::vector<std::string> longtermL;

private:
	const std::string m_todoURL;
	std::string m_line;

public:
	void loadData();
	void displayData();
	void addItem(int type);
	void removeItem();
	void unloadData();

	Todo()
		: m_todoURL("./frontalcortex/todo/list.txt")
	{
		loadData();
		displayData();
	}
};
