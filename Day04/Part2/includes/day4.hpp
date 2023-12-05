#ifndef	DAY4_HPP
# define DAY4_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <fstream>
# include <vector>
# include <algorithm>
# include <map>

class scratchcard
{
private:
	unsigned long					_instances;
	unsigned long					_winned;

	std::vector<int> 	_winning;
	std::vector<int> 	_possible;
public:
	scratchcard(std::vector<int> w, std::vector<int> p);
	~scratchcard();

	void	calculateWinned();

	void	addInstances(int i);

	unsigned long		getWinned();
	unsigned long		getInstances();
};

#endif