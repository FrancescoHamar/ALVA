#pragma once

class Self
{
public:
	std::string serialtag;
	std::string firstName;
	std::string lastName;
	// std::string selfName;

private:
	std::string m_series;
	std::string m_version;
	std::string m_status;
	bool m_born;
	std::string m_alvaBirthday;
	bool m_assigned;

	std::string m_birthYear;
	std::string m_birthMonth;
	std::string m_birthDate;

	const std::string m_tagURL;
	const std::string m_keeperURL;

public:
	void greet(bool newUser);
	void initializeAlva();
	void initializeKeeper();

	Self()
		: serialtag(""), firstName(""), lastName(""), m_series(""), m_version(""), m_status(""), m_born(false), m_alvaBirthday(""), m_assigned(false), 
		m_birthYear(""), m_birthMonth(""), m_birthDate(""), m_tagURL("../deephippo/tag.txt"), m_keeperURL("../deephippo/keeper.txt")
	{
		initializeAlva();
		initializeKeeper();
	}	
};
