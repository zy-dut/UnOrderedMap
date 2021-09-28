#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Dispaly Map Contains
void displaymap(unordered_map<string, double> myMap, string str) {
	cout << str << endl;
	for (auto& x : myMap)
		cout << x.first << ":" << x.second << endl;
	cout << endl;
}

int main()
{
	unordered_map <string, double> myMap, mypantry = { {"milk",2.0},{"flour",1.5} };

	// Insert
	pair<string, double> myshopping("baking powder", 0.3);
	myMap.insert(myshopping);
	myMap.insert(pair<string, double>("eggs", 6.0));
	myMap.insert(mypantry.begin(), mypantry.end());
	myMap["coffee"] = 10.0;

	displaymap(myMap, "MyMap contains:");

	// Search
	unordered_map<string, double>::const_iterator got = myMap.find("coffee");
	if (got == myMap.end())
		cout << "not found";
	else
		cout << "found " << got->first << " is " << got->second << "\n";

	// Revise
	myMap.at("coffee") = 9.0;
	myMap["milk"] = 3.0;
	displaymap(myMap, "After modify MyMap contains:");

	// Erase
	myMap.erase(myMap.begin());
	myMap.erase("milk");
	displaymap(myMap, "After erase MyMap contains:");

	// Swap
	myMap.swap(mypantry);
	displaymap(myMap, "After swap MyMap contains:");

	// Clear
	myMap.clear();
	displaymap(myMap, "After clear MyMap contains:");


	return 0;
}