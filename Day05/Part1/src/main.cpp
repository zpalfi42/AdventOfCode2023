#include <day3.hpp>

class Dictionary
{
private:
	unsigned long	_sourceStart;
	unsigned long	_destStart;
	unsigned long	_range;
public:
	Dictionary(unsigned long s, unsigned long d, unsigned long r);
	~Dictionary();

	unsigned long getSource();
	unsigned long getDestination();
	unsigned long getRange();
};

Dictionary::Dictionary(unsigned long s, unsigned long d, unsigned long r): _sourceStart(s), _destStart(d), _range(r)
{
}

Dictionary::~Dictionary()
{
}

unsigned long Dictionary::getSource()
{
	return(this->_sourceStart);
}

unsigned long Dictionary::getDestination()
{
	return(this->_destStart);
}

unsigned long Dictionary::getRange()
{
	return(this->_range);
}


std::vector<unsigned long long>	split(std::string s)
{
	std::vector<unsigned long long>	result;
	std::string			aux;

	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
			aux += s[i];
		else if (aux.size() != 0)
		{
			result.push_back(strtoul(aux.c_str(), nullptr, 0));
			std::cout << aux << " = " << strtoul(aux.c_str(), nullptr, 0) << std::endl;
			aux.clear();
		}
	}
	result.push_back(strtoul(aux.c_str(), nullptr, 0));
	return(result);
}

int	main( void )
{
	std::fstream	fd;
	std::string		s, line, subline;
	fd.open("./input", std::fstream::in);
	unsigned long long 			total = 18446744073709551615;
	bool			first = true;

	std::vector<unsigned long long>				values, newValues, aux;
	std::vector<Dictionary>	dict;

	while (std::getline(fd, s))
	{
		if (first == true)
		{
			values = split(s.substr(s.find_first_of(":")+1));
			first = false;
		}
		else if (s.find_first_of(":") != std::string::npos)
		{
			dict.clear();
			while (std::getline(fd, s))
			{
				if (s.size() == 0)
					break ;
				aux = split(s);
				Dictionary	d(aux[1], aux[0], aux[2]);
				dict.push_back(d);
			}
			newValues.clear();
			for (size_t i = 0; i < values.size(); i++)
			{
				for (size_t j = 0; j < dict.size(); j++)
				{
					if (values[i] >= dict[j].getSource() && values[i] < dict[j].getSource() + dict[j].getRange())
					{
						newValues.push_back(dict[j].getDestination()+(values[i] - dict[j].getSource()));
						std::cout << values[i] << "= " << dict[j].getDestination()+(values[i] - dict[j].getSource()) << std::endl;
						break ;
					}
				}
				if (newValues.size() != i+1)
				{
					newValues.push_back(values[i]);
					std::cout << values[i] << "= " << values[i] << std::endl;
				}
			}
			values.clear();
			values = newValues;
			std::cout << std::endl << std::endl;
		}
	}
	for (size_t i = 0; i < values.size(); i++)
	{
		std::cout << values[i] << std::endl;
		if (values[i] < total)
			total = values[i];
	}
	
	std::cout << "RESULT: " << total << std::endl;
}