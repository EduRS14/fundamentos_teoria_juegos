#include <iostream>
#include <string>

using namespace std;

void fatalError(string errorString)
{
	cout << errorString << endl;
	cout << "Presiona una tecla para salir..." << endl;
	int tmp;
	cin >> tmp;
	exit(1);
}
