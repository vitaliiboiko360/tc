#include <vector>
#include <algorithm>

using std::vector;

class BigBurger
{
	public:
	int maxWait(vector<int> arrival, vector<int> service)
	{
		int ret = 0;
		int tmp = 0;

		for (int i=1; i<arrival.size(); ++i)
		{
			tmp = (arrival[i-1] + service[i-1] + tmp) - arrival[i];

			if (tmp <= 0)
			{
				tmp = 0;
				continue;
			}

			ret = std::max(ret, tmp);
		}

		return ret;
	}	
};
