#include <iostream>
#include <fstream> //File input and output
#include <string> //string input
#include <iomanip> // used for setprecision and fixed reserved words
#include <cmath> //used for power function in standard deviation calc

using namespace std;

//Function prototypes for Mean_Calc and StdDev_Calc
int Mean_Calc();
int StdDev_Calc();

//identifiers
int num1;
int num2;
int num3;
int num4;



int main()
{
	//Input identifiers
	
	ifstream inFile;
	ofstream outFile;

	char ans;
	cout << "Do you have a file you would like input from ? Y/N" << endl;
	cin >> ans;
	if (ans == 'Y')
	{
		inFile.open("inMeanStd.dat.txt");
		outFile.open("outMeanStd.dat.txt");
		inFile >> num1 >> num2 >> num3 >> num4; //Reads integers from inMeanStd.dat.txt into num input variables
		cout << "The mean of these four integers is: " << endl;
		outFile << fixed << showpoint << setprecision(2) 
			<< float(Mean_Calc()); //Type casts the return value as a float
		cout << "The standard deviation of these four integers is: " << endl;

	} 
	else
	{
		cout << "Enter four integers: " << endl;
		cin >> num1 >> num2 >> num3 >> num4; //Reads values into num variables from keyboard
		
		Mean_Calc();
		int mean = Mean_Calc();

		cout << "The mean of these four integers is: " << endl;
		cout << fixed << showpoint << setprecision(2)
			<< float(Mean_Calc()) << endl;;

		StdDev_Calc();

		cout << "The standard deviation of these four integers is: " << endl;
		cout << fixed << showpoint <<
			float(StdDev_Calc());
	}

	return 0;
}

//Mean_Calc definition: Calculates the mean of the four integers passed
int Mean_Calc()
{
	int mean;
	int sum = num1 + num2 + num3 + num4;
	mean = sum / 4;

	return mean;
}

//StdDev_Calc definition: Calculates standard deviation of four integers passed
int StdDev_Calc()
{
	float sum = num1 + num2 + num3 + num4;
	float mean = sum / float(4);
	float StdDev = sqrt(((pow(num1 - mean, 2) + pow(num2 - mean, 2) + pow(num3 - mean, 2) + pow(num4 - mean, 2)) / 4));
	
	return StdDev;
}