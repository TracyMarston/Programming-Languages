#include <iostream>
#include <iomanip> 
#include <cmath>
#include <vector>
#include <bits/stdc++.h> 
#include "CompoundInterest.h"
#include "DataInput.h"

using namespace std;



int main() {
 double initialInvestAmt;    // Initial Investment Amount
 double monthlyDeposit;      // Monthly Deposit w/ Default 0
 double annualInterest;      // Annual Interest (Compounded)
 int numYears;               //Number of years

 CompoundInterest item1;        // Declare Item 1 Object - Interest Rate = user input
 CompoundInterest item2;        // Declare Item 2 Object - Interest Rate = 0

    t_dataInput(initialInvestAmt, monthlyDeposit, annualInterest, numYears); // Request Data Input from End user
    
    // Assign input into class  Item 1
    item1.SetInitialInvestAmt(initialInvestAmt);
    item1.SetMonthlyDeposit(monthlyDeposit); 
    item1.SetAnnualInterest(annualInterest);
    item1.SetNumYears(numYears);
    item1.t_compoundInterest();
    
    item2.SetInitialInvestAmt(initialInvestAmt);
    item2.SetMonthlyDeposit(0); 
    item2.SetAnnualInterest(annualInterest);
    item2.SetNumYears(numYears);
    item2.t_compoundInterest();
    
    return 0;    
}