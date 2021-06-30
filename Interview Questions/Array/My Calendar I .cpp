/*
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendar class:

MyCalendar() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 

Example 1:

Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]

Explanation
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.
 

Constraints:

0 <= start < end <= 109
At most 1000 calls will be made to book.
Hide Hint #1  
Store the events as a sorted list of intervals. If none of the events conflict, then the new event can be added.*/
/*
Complexity Analysis

Time Complexity: O(N^2) where N is the number of events booked. For each new event, we process every previous event to decide whether the new event can be booked. This leads to  O(N^2)


Space Complexity: O(N)O(N), the size of the calendar.*/
1.
class MyCalendar
{
	public:
		vector<pair<int, int>> v;
	MyCalendar() {}

	bool book(int start, int end)
	{

		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].second > start && v[i].first < end)
			{
				//v[i].fisrt< end condition is necesssary. Consider a case["MyCalendar","book","book","book","book","book","book","book","book","book","book"]
				//[[], [47,50], [33,41], [39,45], [33,42], [25,32], [26,35], [19,25], [3,8], [8,13], [18,27]]

				return false;
			}
		}
		v.push_back(make_pair(start, end));
		return true;
	}
};

/**
 *Your MyCalendar object will be instantiated and called as such:
 *MyCalendar* obj = new MyCalendar();
 *bool param_1 = obj->book(start,end);
 */
