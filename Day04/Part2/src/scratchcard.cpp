#include <day4.hpp>

scratchcard::scratchcard(std::vector<int> w, std::vector<int> p): _instances(1), _winning(w), _possible(p)
{
}

scratchcard::~scratchcard()
{
}

void scratchcard::calculateWinned( void )
{
	for (size_t i = 0; i < this->_possible.size(); i++)
		if (std::find(this->_winning.begin(), this->_winning.end(), this->_possible[i]) != this->_winning.end())
			this->_winned++;
}

void scratchcard::addInstances( int i )
{
	this->_instances += i;
}

unsigned long	scratchcard::getWinned( void )
{
	return (this->_winned);
}

unsigned long scratchcard::getInstances( void )
{
	return (this->_instances);
}