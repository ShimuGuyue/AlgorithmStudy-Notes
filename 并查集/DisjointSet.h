#include <vector>
using std::vector;
#include <set>
using std::set;

struct DisjointSet
{
	vector<int> sets;
	vector<int> ranks;

	DisjointSet()
	{}
	DisjointSet(const int &n) : sets(n), ranks(n, 1)
	{
		for (int i = 0; i < n; ++i)
		{
			sets[i] = i;
		}
	}

	int Find_Set(const int &x)
	{
		return sets[x] == x ? x : sets[x] = Find_Set(sets[x]);
	}

	void Merge_Set(const int &x, const int &y)
	{
		int setX = Find_Set(x);
		int setY = Find_Set(y);
		if (ranks[setX] < ranks[setY])
		{
			sets[setX] = setY;
		}
		else
		{
			sets[setY] = setX;
			if (ranks[setX] == ranks[setY])
				++ranks[setX];
		}
	}

	bool In_Same_Set(const int &x, const int &y)
	{
		return Find_Set(x) == Find_Set(y);
	}

	int Count_Sets(void)
	{
		set<int> sets;
		for (const int &node : sets)
		{
			sets.insert(Find_Set(node));
		}
		return sets.size();
	}
};