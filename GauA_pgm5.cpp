//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: Input data about states and their populations, budgets and revenue from a file and outputs 
// the data onto a different file in a sorted manner and with calculations declaring the average state
// budget, the state with the highest budget and surplus, and the state with the lowest population. 
// Process: This program uses an initial sentinel loop that stops when it reaches the end of the input
// file. Within the loop is a for loop that sets an array with the inputted values. Once the loop is closed
// due to the file, it outputs the beginning of the receipt to the new file. A new for loop starts, 
// which outputs the data into the new file in the sorted mannter. The loop ends, and a new for loop begins to
// calculate the extra calculations using if else statements. After this, all data is finished outputting
// and the files close. 
// Results: The average budget amongst all 50 states, as well as the states with the the highest budget,
// revenue, and lowest population/
//
// Class: CS2010
// Section: 100x
// Term: Fall 2024
// Author: Anya Gau
//
// Reflection: This project was very straightforward, and honestly the hardest part was getting it to
// output the way I wanted it to. Other than that, it was not horribly difficult to get things to work
// as intended, especially with the videos that were posted on canvas.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {

    // all the variables, starting with arrays, then files, i, and the calculated data and saved states
    string stateArr[50];
    int populationArr[50];
    double budgetArr[50];
    double revenueArr[50];
    ifstream infile;
    ofstream outfile;
    int i;
    double avgBudget = 0;
    double highestBudget;
    double highestSurplus;
    int lowestPop;
    string stateSurplus;
    string stateBudget;
    string statePop;
    
    // opening the files
    infile.open("pgm5.txt");
    outfile.open("report5.txt");


    // while loop operating with eof(), this will input the data from the file into the array
    while (!infile.eof()) {
        for(i = 0; i <= 50; ++i) {
            getline(infile, stateArr[i]);
            infile >> populationArr[i];
            infile >> budgetArr[i];
            infile >> revenueArr[i];
            infile.ignore();
        }
    }


    // setting up the beginning of the receipt that lists each section/catagory
    outfile << setw(55) << setfill('=') << "" << "\n";
    outfile << setfill(' ');
    outfile << setw(4) << left << "#" << "Name";
    outfile << right << setw(25) << "Population";
    outfile << right << setw(10) << "Budget";
    outfile << setw(10) << right << "Revenue" << "\n";
    outfile << setw(4) << left << "-" << "----";
    outfile << right << setw(25) << "----------";
    outfile << right << setw(10) << "------";
    outfile << setw(10) << right << "-------" << "\n";

    // declaring calculated data numbers 
    lowestPop = populationArr[0];
    highestBudget = budgetArr[0];
    highestSurplus = revenueArr[0] - budgetArr[0];
    

    // this outputs the inital data, the state names/populations/revenue/budgets
    for(i = 0; i < 50; ++i) {
        outfile << fixed << setprecision(2);
        outfile << setw(4) << left << i + 1;
        outfile << setw(15) << left << stateArr[i];
        outfile << setw(14) << right << populationArr[i];
        outfile << setw(10) << right << budgetArr[i];
        outfile << setw(10) << right << revenueArr[i];
        outfile << "\n";

        avgBudget = avgBudget + budgetArr[i];
    }

    // calculates the calculated data (lowest population, revenues & highest revenue, highest budget)
    for (i = 0; i < 50; ++i) {
        if (populationArr[i] < lowestPop) {
            lowestPop = populationArr[i];
            statePop = stateArr[i];
        }
        if (budgetArr[i] > highestBudget) {
            highestBudget = budgetArr[i];
            stateBudget = stateArr[i];
        }

        if ((revenueArr[i] - budgetArr[i]) > highestSurplus) {
            highestSurplus = revenueArr[i] - budgetArr[i];
            stateSurplus = stateArr[i];
        }
    }

    // final avg budget calculation
    avgBudget = avgBudget / 50;

    outfile << "\n" << "\n";

    // final output of the calculated data
    outfile << "The average state budget is $" << avgBudget << " billion." << "\n";
    outfile << stateBudget << " has the highest budget : $" << highestBudget << " billion." << "\n";
    outfile << stateSurplus << " has the highest surplus: $" << highestSurplus << " billion." << "\n";
    outfile << statePop << " has the lowest population : " << lowestPop << " people." << "\n";

    // closing files
    infile.close();
    outfile.close();

    return 0;
}