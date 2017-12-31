// Beta Distribution (2011-B1-Q2)

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

//Declaring the variables
const double h = 0.01;

// Declaring the functions
double B(double p, double q){
	double sum = 0;
	for(double t=0 ; t <= 1 ; t += h){
		sum += pow(t, p-1) * pow((1-t),q-1) * h;
	}
	return sum;
}

double betadist(double x, double p, double q){
//Checking if the arguments are right.
	if(x < 0 || x > 1){
		cout << "Error! \nFirst argument must me within the range [0,1]" << endl;
	}
	if(p <=0 || q<=0){
		cout << "Error!! \nSecond and third argument cannot be negative!" << endl;
	}
	return pow(x,p-1) * pow(1-x, q-1) / B(p, q);
}

int main(){
//Writing data to the file.
	cout << "Program Initiated. Writing to file. \n\nPlease Wait...\n\n";
	ofstream fout("pqdata.dat");
	fout <<"# x \t f(x, 2, 2) \t f(x, 3, 3) \t f(x, 2, 3) \t f(x, 3, 2)" << endl;
	for(double x=0; x <=1 ; x += h){
		fout  << x  << "\t" << betadist(x, 2, 2)
					<< "\t" << betadist(x, 3, 3)
					<< "\t" << betadist(x, 2, 3)
					<< "\t" << betadist(x, 3, 2) << endl;
	}
	fout.close();
	cout << "Done! Check the data file \"pqdata.dat\"";
}
