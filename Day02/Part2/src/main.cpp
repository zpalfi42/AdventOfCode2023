#include <day2.hpp>

int	main( void )
{
	std::fstream	fd;
	std::string		s;
	long			total = 0;
	int				id = 1;
	size_t			aux1, aux2;

	std::map<std::string, int> min_colors;
	int				num;
	std::string		color, line;
	fd.open("./input", std::fstream::in);
	while (std::getline(fd, s))
	{
		aux1 = 1;
		aux2 = s.find_first_of(":")+1;
		min_colors["red"] = 0;
		min_colors["green"] = 0;
		min_colors["blue"] = 0;
		while(42)
		{
			aux1 = s.find_first_of(";,", aux1) + 1;
			if (aux1 == std::string::npos || aux1 == 0 )
			{
				line = s.substr(aux2+1);
				aux2 = aux1;
				
				num = atoi(line.substr(0, line.find_first_of(" ")).c_str());
				color = line.substr(line.find_first_of(" ")+1);
				if (num > min_colors[color])
					min_colors[color] = num;
				break ;
			}

			line = s.substr(aux2+1, aux1-aux2-2);
			aux2 = aux1;
			
			num = atoi(line.substr(0, line.find_first_of(" ")).c_str());
			color = line.substr(line.find_first_of(" ")+1);
			if (num > min_colors[color])
				min_colors[color] = num;
		}
		total += min_colors["red"]*min_colors["green"]*min_colors["blue"];
		id++;
	}
	std::cout << "RESULT: " << total << std::endl;
}