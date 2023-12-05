#include <day4.hpp>

std::vector<int>	split(std::string s)
{
	std::vector<int>	result;
	std::string			aux;	

	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
			aux += s[i];
		else if (aux.size() != 0)
		{
			result.push_back(atoi(aux.c_str()));
			aux.clear();
		}
	}
	if (aux.size() != 0)
		result.push_back(atoi(aux.c_str()));
	return(result);
}

int	main( void )
{
	std::fstream	fd;
	std::string		s;
	fd.open("./input", std::fstream::in);
	std::vector<int>			winning, possible;
	std::string					sWinning, sPossible;
	std::vector<scratchcard>	scratchcards;
	int total = 0;
	while (std::getline(fd, s))
	{
		winning.clear();
		possible.clear();

		sWinning = s.substr(s.find_first_of(":")+1, s.find_first_of("|") - s.find_first_of(":")-1);
		sPossible = s.substr(s.find_first_of("|")+1);
		winning = split(sWinning);
		possible = split(sPossible);
		scratchcard sc = scratchcard(winning, possible);
		scratchcards.push_back(sc);
	}
	for (size_t i = 0; i < scratchcards.size(); i++)
	{
		scratchcards[i].calculateWinned();
		for (size_t j = 0; j < scratchcards[i].getWinned(); j++)
			scratchcards[i+j+1].addInstances(scratchcards[i].getInstances());
		total += scratchcards[i].getInstances();
	}
	std::cout << "RESULT: " << total << std::endl;
}