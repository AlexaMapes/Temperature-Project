// Alexa Mapes 5/30/2021

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream cityFS;
	ofstream tempFS;
	string cityName;
	int tempInF;
	int tempInC;

	cityFS.open("FahrenheitTemperature.txt");
	tempFS.open("CelsiusTemperature.txt");

	if (!cityFS.is_open()) {
		cout << "Could not open file FarenheightTemperature.txt." << endl;
		return 1;
	}

	if (!tempFS.is_open()) {
		cout << "Could not open file CelsiusTemperature.txt." << endl;
		return 1;
	}

	cout << "Reading file, converting temperatures, and writing to new file." << endl << endl;

	cityFS >> cityName;
	while (!cityFS.fail()) {
		cityFS >> tempInF;
		cout << "City: " << cityName << endl << "Temp in F: " << tempInF << endl;
		tempInC = (5.0 / 9.0) * (tempInF - 32);
		cout << "Temp in C: " << tempInC << endl << endl;
		tempFS << cityName << " " << tempInC << endl;
		cityFS >> cityName;
	}

	if (!cityFS.eof()) {
		cout << "Input error before reaching end of file." << endl;
	}

	cout << "Closing files." << endl;

	cityFS.close();
	tempFS.close();

	return 0;
}