//Leonardo Garcia
//Project 1: Blood Sugar Readings

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	double data[1000][14];
	double dailyTotal[14], dailyMin[14], dailyMax[14];
	double weeklyTotal1 = 0, weeklyMax1 = 0, weeklyMin1 = 0, maxd1 = 0;
	double weeklyTotal2 = 0, weeklyMax2 = 0, weeklyMin2 = 0, maxd2 = 0;
	double checkMax = 999999, negative = 0, squared = 0, root = 0;
	int day = 0, reading = 0, week = 0, weeklyCount1 = 0, weeklyCount2 = 0, sciNotation1 = 0, sciNotation2 = 0, delta1 = 0, delta2 = 0;
	int dailyCount[14];
	string input;

	cout << "Enter Values For Blood Sugar as a Positive Number\n\nEnter n to input for next day\nEnter d for daily summary\nEnter w for weekly summary\n\nDay 1" << endl;

	//populate arrays with 0 values
	for (int i = 0; i < 14; i++) {
		dailyMin[i] = 0;
		dailyMax[i] = 0;
		dailyTotal[i] = 0;
		dailyCount[i] = 0;
	}

	while (day < 14)
	{
		//get input values
		cout << "Enter Value: ";
		cin >> input;

		//daily summary output
		if (input == "d"){
			cout << "\nDay Summary\nSum: " << dailyTotal[day] << "\nMax: " << dailyMax[day] << "\nMin: " << dailyMin[day] << "\nCount: " << dailyCount[day] << "\n" << endl;
		}

		//weekly summary output
		else if (input == "w"){
			weeklyTotal1 = 0;
			weeklyTotal2 = 0;
			weeklyCount1 = 0;
			weeklyCount2 = 0;
			sciNotation1 = 0;
			sciNotation2 = 0;
			delta1 = 0;
			delta2 = 0;
			//week 1 summary
			if (day < 7) {
				for (int i = 0; i < day + 1; i++) {
					//sum of daily totals
					if (checkMax - dailyTotal[i] > 0) {
						weeklyTotal1 += dailyTotal[i];
					}
					//use a form of scientific notation to make sure a 1 million value is never reached.
					else {
						negative = checkMax - dailyTotal[i];
						squared = negative * negative;
						root = sqrt(squared);
						weeklyTotal1 = root;
						sciNotation1++;
						checkMax = 999999 - weeklyTotal1;
						root = 0;
					}
					//sum of weekly count
					weeklyCount1 += dailyCount[i];
					//find weekly max
					if (dailyMax[i] >= weeklyMax1 || weeklyMax1 == 0) {
						weeklyMax1 = dailyMax[i];
					}
					//find weekly min
					if (dailyMin[i] <= weeklyMin1 || weeklyMin1 == 0) {
						weeklyMin1 = dailyMin[i];
					}
					//find biggest weekly delta
					double delta = dailyMax[i] - dailyMin[i];
					if (delta >= maxd1) {
						maxd1 = delta;
						delta1 = i + 1;
					}
		
				}
			}
			//week 2 summary
			else {
				for (int i = 7; i < day + 1; i++) {
					//sum of daily totals
					if (checkMax - dailyTotal[i] > 0) {
						weeklyTotal2 += dailyTotal[i];
					}
					//use a form of scientific notation to avoid numbers greater than 1 million
					else {
						negative = checkMax - dailyTotal[i];
						squared = negative * negative;
						root = sqrt(squared);
						weeklyTotal2 = root;
						sciNotation2++;
						checkMax = 999999 - weeklyTotal2;
						root = 0;
					}
					//sum of weekly count
					weeklyCount2 += dailyCount[i];
					//find weekly max
					if (dailyMax[i] >= weeklyMax2 || weeklyMax2 == 0) {
						weeklyMax2 = dailyMax[i];
					}
					//find weekly min
					if (dailyMin[i] <= weeklyMin2 || weeklyMin2 == 0) {
						weeklyMin2 = dailyMin[i];
					}
					//find biggest weekly delta
					double delta3 = dailyMax[i] - dailyMin[i];
					if (delta3 >= maxd2) {
						maxd2 = delta3;
						delta2 = i + 1;
					}
				}
			}
			//weekly output if nothing overflowed
			if (sciNotation1 == 0 && sciNotation2 == 0) {
				if (day < 7) {
					cout << "\nWeek 1 Summary\n\nTotal: " << weeklyTotal1 << "\nMax: " << weeklyMax1 << "\nMin: " << weeklyMin1 << "\nCount: " << weeklyCount1 << "\nDelta: Day " << delta1 << "\n" << endl;
				}
				else {
					cout << "\nWeek 2 Summary\n\nTotal: " << weeklyTotal2 << "\nMax: " << weeklyMax2 << "\nMin: " << weeklyMin2 << "\nCount: " << weeklyCount2 << "\nDelta: Day " << delta2 << "\n" << endl;
				}
			}
			//weekly output if there was overflow
			else {
				if (day < 7) {
					cout << "\nWeek 1 Summary\n\nTotal: " << weeklyTotal1 << " + " << sciNotation1 << " * 999999" << "\nMax: " << weeklyMax1 << "\nMin: " << weeklyMin1 << "\nCount: " << weeklyCount1 << "\nDelta: Day " << delta1 << "\n" << endl;
				}
				else {
					cout << "\nWeek 2 Summary\n\nTotal: " << weeklyTotal2 << " + " << sciNotation2 << " * 999999" << "\nMax: " << weeklyMax2 << "\nMin: " << weeklyMin2 << "\nCount: " << weeklyCount2 << "\nDelta: Day " << delta2 << "\n" << endl;
				}
			}
		}
		//move to next day
		else if (input == "n") {
			day++;
			if (day < 14) {
				cout << "\nDay " << day + 1 << endl;
			}
			else {
				cout << "\nEnd of 2 weeks. No More Data Entry Permitted" << endl;
			}
			reading = 0;
		}
		//insert value into arrays
		else if (stod(input) > 0){
			//turn input into a double variable
			double num = stod(input);
			//increment count per each input
			dailyCount[day]++;
			//insert input into data array
			data[reading][day] = num;
			//find total of all inputs for the day
			dailyTotal[day] += data[reading][day];
			//check for min of the day
			if (dailyMin[day] >= num || dailyMin[day] == 0) {
				dailyMin[day] = num;
			}
			//check for max of the day
			if (dailyMax[day] <= num || dailyMax[day] == 0) {
				dailyMax[day] = num;
			}
		}
		else
		{
			//do nothing
		}
		reading++;
	}
	system("pause");
	return 0;
}