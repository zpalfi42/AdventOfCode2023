#include <day3.hpp>

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
	result.push_back(atoi(aux.c_str()));
	return(result);
}

int	main( void )
{
	std::fstream	fd;
	std::string		s;
	fd.open("./input", std::fstream::in);
	std::vector<int>	winning, possible;
	std::string			sWinning, sPossible;
	int total = 0, winned;
	while (std::getline(fd, s))
	{
		winned = 0;
		winning.clear();
		possible.clear();

		sWinning = s.substr(s.find_first_of(":")+1, s.find_first_of("|") - s.find_first_of(":")-1);
		sPossible = s.substr(s.find_first_of("|")+1);
		winning = split(sWinning);
		possible = split(sPossible);
		for (size_t i = 0; i < possible.size(); i++)
			if (std::find(winning.begin(), winning.end(), possible[i]) != winning.end())
				winned++;
		if (winned != 0)
			total += pow(2, winned-1);
	}
	
	std::cout << "RESULT: " << total << std::endl;
}