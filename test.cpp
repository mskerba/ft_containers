// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> g1(std::begin(arr), std::end(arr));

	// vector<int> g1(19);


	cout << g1.size() << endl;cout << g1.capacity();
	// cout << g1.size();

	// for (int i = 1; i <= 5; i++)
	// 	g1.push_back(i);

	// cout << "Output of begin and end: ";
	// for (int i = 0; i != g1.size(); ++i)
	// 	cout << g1[i] << " ";

	// cout << "\nOutput of cbegin and cend: ";
	// for (int i = 0; i != g1.size(); ++i)
	// 	cout << g1[i] << " ";

	// cout << "\nOutput of rbegin and rend: ";
	// for (int i = 0; i != g1.size(); ++i)
	// 	cout << g1[i] << " ";

	// cout << "\nOutput of crbegin and crend : ";
	// for (int i = 0; i != g1.size(); ++i)
	// 	cout << g1[i] << " ";

	return 0;
}

