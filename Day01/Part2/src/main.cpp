#include <day1.hpp>

int	main( void )
{
	std::fstream	fd;
	std::string		s;
	long			total, single;
	std::string		nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	std::size_t		n;
	int 			aux, aux2, aux3, aux4;
	fd.open("./input", std::fstream::in);
	total = 0;
	while (std::getline(fd, s))
	{
		single = 0;
		aux = 10000;
		aux2 = -1;
		for (int i = 0; i < 10; i++)
		{
			n = s.find(nums[i]);
			if (n != std::string::npos && (int)n < aux)
			{
				aux = n;
				aux3 = i;
			}
			n = s.rfind(nums[i]);
			if (n != std::string::npos && (int)n > aux2)
			{
				aux2 = n;
				aux4 = i;
			}
		}
		
		n = s.find_first_of("1234567890");
		if (n != std::string::npos && (int)n < aux)
			single += (s[n]-'0')*10;
		else
			single += aux3*10;

		n = s.find_last_of("1234567890");
		if (n != std::string::npos && (int)n > aux2)
			single += (s[n]-'0');
		else
			single += aux4;
		total += single;
	}
	std::cout << "RESULT: " << total << std::endl;
}