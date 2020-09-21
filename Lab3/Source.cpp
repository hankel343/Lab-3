#include <iostream>
#include <fstream> //File input and output
#include <string> //string input
#include <iomanip> // used for setprecision and fixed reserved words
#include <cmath> //used for power function in standard deviation calc

using namespace std;

//Function prototypes for Mean_Calc and StdDev_Calc
int Mean_Calc(int num1, int num2, int num3, int num4);
float StdDev_Calc(float num1, float num2, float num3, float num4, float mean);

int main()
{
	//Input identifiers
	ifstream inFile; // Input stream for files
	ofstream outFile; // Output stream for files
	int num1;
	int num2;
	int num3;
	int num4;

	char ans;
	cout << "Do you have a file you would like input from ? Y/N" << endl;
	cin >> ans;
	if (ans == 'Y')
	{
		inFile.open("inMeanStd.dat.txt");
		outFile.open("outMeanStd.dat.txt");
		inFile >> num1 >> num2 >> num3 >> num4; //Reads integers from inMeanStd.dat.txt into num input variables
		
		outFile << "The mean of these four integers is: " << endl;
		outFile << Mean_Calc(num1, num2, num3, num4) << endl;

		float mean = Mean_Calc(num1, num2, num3, num4);

		outFile << "The standard deviation of these four integers is: " << endl;
		outFile << fixed << setprecision(6)
			<< float(StdDev_Calc(num1, num2, num3, num4, mean));

	} 
	else
	{
		cout << "Enter four integers: " << endl;
		cin >> num1 >> num2 >> num3 >> num4; //Reads values into num variables from keyboard

		cout << "The mean of these four integers is: " << endl;
		cout << Mean_Calc(num1, num2, num3, num4) << endl;

		/*This assignment statement sets the value of the identifer mean to the return value of Mean_Calc,
		  which is the mean of the four integers passed to the function.*/
		float mean = Mean_Calc(num1, num2, num3, num4);

		cout << "The standard deviation of these four integers is: " << endl;
		cout << fixed << setprecision(6)
			<< float(StdDev_Calc(num1, num2, num3, num4, mean)); /*********************************************************************************
																  *Standard deviation function is passed the four integers along with their mean. *
																  *The return value is the standard deviation of the four integers,				  *
																  *and this is what is printed to the console via the output stream.			  *
																  *********************************************************************************/
	}

	return 0;
}

//Mean_Calc definition: Calculates the mean of the four integers passed
int Mean_Calc(int num1, int num2, int num3, int num4)
{
	int mean = (num1 + num2 + num3 + num4) / 4;
	return mean;
}

//StdDev_Calc definition: Calculates standard deviation of four integers passed
float StdDev_Calc(float num1, float num2, float num3, float num4, float mean)
{
	float StdDev = float(sqrt(((pow(num1 - mean, 2) + pow(num2 - mean, 2) + pow(num3 - mean, 2) + pow(num4 - mean, 2)) / 4)));
	
	return StdDev;
}