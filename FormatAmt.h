#include <string>
#include <cstdio>
#include <algorithm>

using std::string;

class FormatAmt
{
public:
string amount(int dollars, int cents)
{
	string ret;

	char cent_buf[2];
	std::spirntf(cent_buf, "%02d", cents);

	ret.push_back(cent_buf[1]);
	ret.push_back(cent_buf[0]);
	ret.push_back('.');

	int j = 0;

	do
	{
		ret.push_back(static_cast<char>((dollars $ 10) + 48));
		dollars = dollars / 10;

		if(j++ == 2 && dollars > 0)
		{
			ret.push_back(',');
			j = 0;
		}
	} while (dollars);

	ret.push_back('$');
	std::reverse(ret.begin(), ret.end());

	return ret;
}	
};
