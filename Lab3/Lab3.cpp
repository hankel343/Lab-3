#include <iostream>
#include <fstream> //File input and output
#include <string> //string input
#include <iomanip> // used for setprecision and fixed reserved words
#include <cmath> //used for power function in standard deviation calc

using namespace std;

//Function prototypes for Mean_Calc and StdDev_Calc
float Mean_Calc(float num1, float num2, float num3, float num4);
float StdDev_Calc(float num1, float num2, float num3, float num4, float mean);

int main()
{
	//Input identifiers
	ifstream inFile; // Input stream for files
	ofstream outFile; // Output stream for files
	//Filenum identifiers read data from input file inMeanStd.dat.txt for calculation independent from console input
	int fileNum1;
	int fileNum2;
	int fileNum3;
	int fileNum4;
	//Num identifiers read data that is input from the keyboard
	int num1;
	int num2;
	int num3;
	int num4;
	float fileMean; //mean calculated for integers stored in inMeanStd.dat.txt
	float mean; //mean calculated for integers entered from console

	//Opening input file inMeanStd.dat.txt and output file outMeanStd.dat.txt
	inFile.open("inMeanStd.dat.txt");
	outFile.open("outMeanStd.dat.txt");
	inFile >> fileNum1 >> fileNum2 >> fileNum3 >> fileNum4; //Reads integers from inMeanStd.dat.txt into num input variables

	outFile << "The four integers in inMeanStd.dat.txt are: "
		<< fileNum1 << ' ' << fileNum2 << ' ' << fileNum3 << ' ' << fileNum4;

	outFile << "\nThe mean of these four integers is: ";
	outFile << float(Mean_Calc(fileNum1, fileNum2, fileNum3, fileNum4)); //Function call returns the mean

	/*The fileMean assignment statement sets the value of the identifer mean to the return value of Mean_Calc,
	*which is the mean of the four integers passed to the function.*/
	fileMean = Mean_Calc(fileNum1, fileNum2, fileNum3, fileNum4); //This value is passed as an argument to the StdDev_Calc function

	outFile << "\nThe standard deviation of these four integers is: " 
		<< fixed << showpoint << setprecision(6)
		<< float(StdDev_Calc(fileNum1, fileNum2, fileNum3, fileNum4, fileMean)); //Return value is population standard deviation.

	//Closing input and output files
	inFile.close();
	outFile.close();

	//Portion of program that takes input directly from the keyboard
	cout << "Enter four integers: " << endl;
	cin >> num1 >> num2 >> num3 >> num4; //Reads values into num variables from keyboard

	cout << "You entered the following integers: "
		<< num1 << ' ' << num2 << ' ' << num3 << ' ' << num4;

	cout << "\nThe mean of these four integers is: " 
		<< float(Mean_Calc(num1, num2, num3, num4)); //Function call returns mean value

	/*This assignment statement sets the value of the identifer mean to the return value of Mean_Calc,
	 which is the mean of the four integers passed to the function.*/
	mean = Mean_Calc(num1, num2, num3, num4);

	cout << "\nThe standard deviation of these four integers is: " << fixed << setprecision(6)
		<< float(StdDev_Calc(num1, num2, num3, num4, mean));

	/*
	*Standard deviation function is passed the four integers along with their mean.
	*The return value is the standard deviation of the four integers,
	*and this is what is printed to the console via the output stream.
	*/

	return 0;
}

//Mean_Calc definition: Calculates the mean of the four integers passed
float Mean_Calc(float num1, float num2, float num3, float num4)
{
	float mean = (num1 + num2 + num3 + num4) / 4;
	return mean;
}

//StdDev_Calc definition: Calculates standard deviation of four integers passed
float StdDev_Calc(float num1, float num2, float num3, float num4, float mean)
{
	/*
	Calculation below:
	1. subtracts the mean from each integer entered
	2. squares this value
	3. adds deviations together
	4. divides deviations by four
	5. takes the square root of the quotient
	6. stores result in StdDev and the function returns this value to main()
	*/

	float StdDev = float(sqrt(((pow(num1 - mean, 2) + pow(num2 - mean, 2) + pow(num3 - mean, 2) + pow(num4 - mean, 2)) / 4)));

	return StdDev;
}