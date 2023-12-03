#include <day3.hpp>

int	main( void )
{
	std::fstream	fd;
	std::string		s, line;
	int 			total = 0;
	std::vector<int>	nums;
	fd.open("./input", std::fstream::in);
	std::vector<std::string>		map;
	unsigned long	aux1, aux2, aux3, aux4;
	while (std::getline(fd, s))
	{
		map.push_back(s);
	}
	for (int i = 0; i < (int)map.size(); i++)
	{
		aux1 = 0;
		aux2 = 0;
		std::cout << i << ": " << std::endl;
		while (42)
		{
			nums.clear();
			if (map[i].find_first_of("*", aux2) == std::string::npos)
				break ;
			aux1 = map[i].find_first_of("*", aux2) - 1;
			aux2 = aux1+3;
			line = map[i].substr(aux1, aux2-aux1);
			if (line.find_first_of("1234567890") != std::string::npos)
			{
				if (isdigit(line[0]))
				{
					aux3 = aux1;
					while (aux3 >= 0)
					{
						if (isdigit(map[i][aux3]) == false)
							break ;
						aux3--;
					}
					if (aux1 - aux3 != 0)
					{
						// std::cout << "-->1.1 " << map[i].substr(aux3+1, aux1-aux3) << std::endl;
						nums.push_back(atoi(map[i].substr(aux3+1, aux1-aux3).c_str()));
					}
				}
				if (isdigit(line[2]))
				{
					aux3 = aux2;
					while (aux3 < map[i].size())
					{
						if (isdigit(map[i][aux3]) == false)
							break ;
						aux3++;
					}
					if (aux3 - aux2 != 0)
					{
						// std::cout << "-->1.2 " << map[i].substr(aux2-1, aux3-aux2+1) << std::endl;
						nums.push_back(atoi(map[i].substr(aux2-1, aux3-aux2+1).c_str()));
					}
				}
			}
			if (i != 0)
			{
				line = map[i-1].substr(aux1, aux2-aux1);
				if (line.find_first_of("1234567890") != std::string::npos)
				{
					if (isdigit(line[1]))
					{
						aux3 = aux1;
						if (isdigit(map[i-1][aux3]))
						{
							while (aux3 >= 0)
							{
								if (isdigit(map[i-1][aux3]) == false)
									break ;
								aux3--;
							}
						}
						aux4 = aux3+1;
						aux3 = aux2-1;
						if (isdigit(map[i-1][aux3]))
						{
							while (aux3 < map[i-1].size())
							{
								if (isdigit(map[i-1][aux3]) == false)
									break ;
								aux3++;
							}
						}
						if (aux3 - aux4 != 0)
						{
							// std::cout << "-->4.2 " << map[i-1].substr(aux4, aux3-aux4) << std::endl;
							nums.push_back(atoi(map[i-1].substr(aux4, aux3-aux4).c_str()));
						}
					}
					else
					{
						if (isdigit(line[0]))
						{
							aux3 = aux1;
							while (aux3 >= 0)
							{
								if (isdigit(map[i-1][aux3]) == false)
									break ;
								aux3--;
							}
							if (aux1 - aux3 != 0)
							{
								// std::cout << "-->1.1 " << map[i-1].substr(aux3+1, aux1-aux3) << std::endl;
								nums.push_back(atoi(map[i-1].substr(aux3+1, aux1-aux3).c_str()));
							}
						}
						if (isdigit(line[2]))
						{
							aux3 = aux2-1;
							std::cout << "---> " << map[i-1][aux2-1] << std::endl;
							while (aux3 < map[i-1].size())
							{
								if (isdigit(map[i-1][aux3]) == false)
									break ;
								aux3++;
							}
							if (aux3 - aux2+1 != 0)
							{
								// std::cout << "-->1.2 " << map[i-1].substr(aux2-1, aux3-aux2+1) << std::endl;
								nums.push_back(atoi(map[i-1].substr(aux2-1, aux3-aux2+1).c_str()));
							}
						}
					}
				}
			}
			if (i != (int)map.size()-1)
			{
				line = map[i+1].substr(aux1, aux2-aux1);
				if (line.find_first_of("1234567890") != std::string::npos)
				{
					if (isdigit(line[1]))
					{
						aux3 = aux1;
						if (isdigit(map[i+1][aux3]))
						{
							while (aux3 >= 0)
							{
								if (isdigit(map[i+1][aux3]) == false)
									break ;
								aux3--;
							}
						}
						aux4 = aux3+1;
						aux3 = aux2-1;
						if (isdigit(map[i+1][aux3]))
						{
							while (aux3 < map[i+1].size())
							{
								if (isdigit(map[i+1][aux3]) == false)
									break ;
								aux3++;
							}
						}
						if (aux3 - aux4 != 0)
						{
							// std::cout << "-->4.2 " << map[i+1].substr(aux4, aux3-aux4) << std::endl;
							nums.push_back(atoi(map[i+1].substr(aux4, aux3-aux4).c_str()));
						}
					}
					else
					{
						if (isdigit(line[0]))
						{
							aux3 = aux1+1;
							while (aux3 >= 0)
							{
								if (isdigit(map[i+1][aux3]) == false)
									break ;
								aux3--;
							}
							if (aux1 - aux3 != 0)
							{
								// std::cout << "-->1.1 " << map[i+1].substr(aux3+1, aux1-aux3) << std::endl;
								nums.push_back(atoi(map[i+1].substr(aux3+1, aux1-aux3).c_str()));
							}
						}
						if (isdigit(line[2]))
						{
							aux3 = aux2-1;
							while (aux3 < map[i+1].size())
							{
								if (isdigit(map[i+1][aux3]) == false)
									break ;
								aux3++;
							}
							if (aux3 - aux2+1 != 0)
							{
								// std::cout << "-->1.2 " << map[i+1].substr(aux2-1, aux3-aux2+1) << std::endl;
								nums.push_back(atoi(map[i+1].substr(aux2-1, aux3-aux2+1).c_str()));
							}
						}
					}
				}
			}
			if (nums.size() == 2)
			{
				std::cout << nums[0] << " * " << nums[1] << std::endl;
				total += nums[0]*nums[1];
			}
		}
	}
	
	std::cout << "RESULT: " << total << std::endl;
}