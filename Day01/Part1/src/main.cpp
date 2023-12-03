#include <day1.hpp>

int	main( void )
{
	std::fstream	fd;
	std::string		s;
	long			total, single;

	fd.open("./input", std::fstream::in);
	total = 0;
	while (std::getline(fd, s))
	{
		single = 0;
		std::cout << s[s.find_first_of("1234567890")]-'0' << " + " << s[s.find_last_of("1234567890")]-'0' << std::endl;
		single += (s[s.find_first_of("1234567890")]-'0')*10 +(s[s.find_last_of("1234567890")]-'0');
		std::cout << single << std::endl;
		total += single;
	}
	std::cout << "RESULT: " << total << std::endl;
}