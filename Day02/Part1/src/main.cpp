#include <day2.hpp>

int	main( void )
{
	std::fstream	fd;
	std::string		s;
	long			total = 0;
	int				id = 1;
	size_t			aux1, aux2;
	std::map<std::string, int> max_colors;
	max_colors["red"] = 12;
	max_colors["green"] = 13;
	max_colors["blue"] = 14;
	int				num;
	std::string		color, line;
	bool			valid;
	fd.open("./input", std::fstream::in);
	while (std::getline(fd, s))
	{
		aux1 = 1;
		aux2 = s.find_first_of(":")+1;
		valid = true;
		while(42)
		{
			aux1 = s.find_first_of(";,", aux1) + 1;
			if (aux1 == std::string::npos || aux1 == 0 )
			{
				line = s.substr(aux2+1);
				aux2 = aux1;
				
				num = atoi(line.substr(0, line.find_first_of(" ")).c_str());
				color = line.substr(line.find_first_of(" ")+1);
				if (num > max_colors[color])
					valid = false;
				break ;
			}
			line = s.substr(aux2+1, aux1-aux2-2);
			aux2 = aux1;
			
			num = atoi(line.substr(0, line.find_first_of(" ")).c_str());
			color = line.substr(line.find_first_of(" ")+1);
			if (num > max_colors[color])
				valid = false;
		}
		if (valid)
			total += id;
		id++;
	}
	std::cout << "RESULT: " << total << std::endl;
}