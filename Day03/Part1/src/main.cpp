#include <day3.hpp>

int	main( void )
{
	std::fstream	fd;
	std::string		s, line, subline;
	int 			total = 0;
	fd.open("./input", std::fstream::in);
	std::vector<std::string>		map;
	unsigned long	aux, aux2, dist;
	while (std::getline(fd, s))
	{
		map.push_back(s);
	}
	for (int i = 0; i < (int)map.size(); i++)
	{
		aux = 0;
		aux2 = 0;
		dist = 0;
		while (42)
		{
			subline = "";
			if (map[i].find_first_of("0123456789", aux2) == std::string::npos)
				break ;
			aux = map[i].find_first_of("0123456789", aux2);
			aux2 = map[i].find_first_not_of("0123456789", aux);
			dist = aux2-aux+2;
			if (aux == 0)
				dist--;
			else
				aux--;
			line = map[i].substr(aux, dist);
			if (line.find_first_not_of("1234567890.") != std::string::npos)
				total += atoi(line.substr(line.find_first_of("1234567890"), line.find_first_not_of("1234567890")-line.find_first_of("1234567890")).c_str());
			else 
			{
				if (i != 0)
					subline = map[i-1].substr(aux, dist);
				if (subline.find_first_not_of("1234567890.") != std::string::npos)
					total += atoi(line.substr(line.find_first_of("1234567890"), line.find_first_not_of("1234567890")-line.find_first_of("1234567890")).c_str());
				else
				{
					if (i != (int)map.size()-1)
						subline = map[i+1].substr(aux, dist);
					if (subline.find_first_not_of("1234567890.") != std::string::npos)
						total += atoi(line.substr(line.find_first_of("1234567890"), line.find_first_not_of("1234567890")-line.find_first_of("1234567890")).c_str());
				}
			}
		}

	}
	
	std::cout << "RESULT: " << total << std::endl;
}