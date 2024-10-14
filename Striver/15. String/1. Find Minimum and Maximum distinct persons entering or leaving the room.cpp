// Link: https://www.geeksforgeeks.org/find-minimum-and-maximum-distinct-persons-entering-or-leaving-the-room/

// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum and
// maximum number of possible persons
// entering or leaving the room
pair<int,int> minDistPersons(string& persons)
{
int N=persons.length(),entered=0;
pair<int,int>result={0,N};
	
for(int i=0;i<N;i++)
{
	if(persons[i]=='1')
	entered++;
	else entered--;
		
	result.first=max(result.first,entered);
		
	if(entered<0)
	{
		entered=0;
		result.first++;
	}
}
	
return result;
}

// Driver code
int main()
{
	string persons = "10101";

	// Function call
	pair<int, int> ans = minDistPersons(persons);
	cout << "Minimum Persons: " << ans.first
		<< "\n";
	cout << "Maximum Persons: " << ans.second;
	return 0;
}
// this code is contributed by prophet1999

// Output
// Minimum Persons: 1
// Maximum Persons: 5
// Time Complexity: O(N), where N is the length of the string persons.
// Auxiliary Space: O(1)

/*
Why Maximum = N?

In the context of the problem, N is the length of the binary string persons. This value is used to represent the maximum number of distinct persons based on the following rationale:

Unique Events Interpretation: Each character in the string represents an event (either entering or leaving). For the maximum distinct count, you can assume each event involves a unique person.

Total Events: The maximum possible number of distinct persons that can enter or leave the room is the total number of events. Since every event could involve a different person, the maximum number of distinct persons can be at most N.

Example:

For the string "10101", there are 5 events ('1' and '0'), which means, in the worst case, you could have 5 distinct persons, each contributing to these events.
Minimum Number of Distinct Persons
Why Adjust for Negative Values?

To find the minimum number of distinct persons, you need to ensure that the current count of persons in the room never goes negative. Here's why we adjust for negative values:

Tracking Room Occupancy: The variable entered tracks the number of people currently in the room. As you process each character:

'1' increases the count (a person enters).
'0' decreases the count (a person leaves).
Handling Negative Values:

If the count of persons in the room (entered) becomes negative, it implies that more people have left than were present, which is not feasible without additional persons having entered at some point. This scenario suggests that more distinct persons must have been involved than what entered currently reflects.
Correction: When entered goes negative, reset entered to 0 (since you can't have a negative count of people). Also, increase the minimum distinct persons (result.first) by the absolute value of the deficit to account for this discrepancy.
Example:

For the string "110011", the count of entered might go negative if more people leave than are present, meaning the minimum number of distinct persons must be adjusted to account for this imbalance.	
*/