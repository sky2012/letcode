struct startIncreasing
{
	bool operator() (const Interval &a, const Interval &b)
	{
		return (a.start < b.start);
	}
} start_increase;

class Solution 
{
	public:
		vector<Interval> merge(vector<Interval> &intervals) 
		{
			int N = intervals.size();
			if (N <= 1) return intervals;
			sort(intervals.begin(), intervals.end(), mycompare);
			vector<Interval> res;
			Interval last = intervals[0];
			for (int i = 1; i < N; ++i)
			{
				if (intervals[i].start > last.end) 
				{
					res.push_back(last);
					last = intervals[i];
				} 
				else 
				{
					last.end = max(last.end, intervals[i].end);
				}
			}
			res.push_back(last);
			return res;
		}
};

vector<Interval> merge(vector<Interval> &intervals) 
{
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (intervals.size() < 2) return intervals;
	sort(intervals.begin(), intervals.end(), start_increase);
	vector<Interval> result;
	vector<Interval>::iterator it = intervals.begin();
	Interval current;
	
	while (it != intervals.end())
	{
		if (it == intervals.begin())
		{
			current = *it;
		}
		else if ((current.start <= it->end) && (current.end >= it->start))
		{
			if (current.start > it->start)
			{
				current.start = it->start;
			}
			if (current.end < it->end)
			{
				current.end = it->end;
			}
		}
		else if (it->start > current.end)
		{
			result.push_back(current);
			current = *it;
		}
		it++;
	}
	result.push_back(current);
	return result;
	
}
