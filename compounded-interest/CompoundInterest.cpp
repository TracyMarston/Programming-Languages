#include <iostream>
#include <iomanip> 
#include <cmath>
#include <vector>
#include "CompoundInterest.h"

using namespace std;

// Set Default
CompoundInterest::CompoundInterest () {
    m_initialInvestAmt = 1;    // Initial Investment Amount
    m_monthlyDeposit = 50;  // Monthly Deposit w/ Default 0
    m_annualInterest = 5;      // Annual Interest (Compounded)
    m_numYears = 5;               // Number of Years
};
  
  
/* SET:
   - Initial Investment
   - Monthly Deposit
   - Annual Interest
   - Number of Years */

void CompoundInterest::SetInitialInvestAmt(double InvestAmt) {
   m_initialInvestAmt = InvestAmt;
}

void CompoundInterest::SetMonthlyDeposit(double MonthlyDeposit) {
   m_monthlyDeposit = MonthlyDeposit;
}

void CompoundInterest::SetAnnualInterest(double AnnualInterest) {
   m_annualInterest = AnnualInterest;
}

void CompoundInterest::SetNumYears(int NumYears) {
   m_numYears = NumYears;
}

void CompoundInterest::SetClosingBalance(double ClosingBalance) {
   m_closingBalance = ClosingBalance;
}

void CompoundInterest::SetAccruedInt(double AccruedInt) {
   m_accruedInt = AccruedInt;
}

void CompoundInterest::SetCompoundInterest(double CompoundInterest) {
   m_compoundInterest = CompoundInterest;
}

/* GET:
   - Initial Investment
   - Monthly Deposit
   - Annual Interest
   - Number of Years 
   - Closing Balance 
   - Accrued Interest */

double CompoundInterest::GetInitialInvestAmt() {
    return m_initialInvestAmt;
}

double CompoundInterest::GetMonthlyDeposit() {
    return m_monthlyDeposit;
}

double CompoundInterest::GetAnnualInterest() {
    return m_annualInterest;
}

int CompoundInterest::GetNumYears() {
    return m_numYears;
}

double CompoundInterest::GetClosingBalance() {
    return m_closingBalance;
}

double CompoundInterest::GetAccruedInt() {
    return m_accruedInt;
}
double CompoundInterest::GetCompoundInterest() {
    return m_compoundInterest;
}

/* FUNCTIONS */

// Convert Years into months
int CompoundInterest::t_calcMonths(){
    return GetNumYears()*12;
}

void CompoundInterest::t_compoundInterest(){
        SetClosingBalance(GetInitialInvestAmt()); // Set Initial Investment as Balance before loop kicks off.
        cout << fixed << setprecision(2); // Ensure that outputs only displays 2 places after decimal
        cout << setfill('=') << setw(91) << endl;
        cout << "\n Balance and Interest with";
        if (GetMonthlyDeposit() == 0){
           cout <<  " No ";
        } 
        else { 
            cout << " Additional ";
        }
        cout << "Monthly Deposits" << endl;
        cout << setfill('-') << setw(65) << "\n";
        cout << right << " Year" << setfill(' ') << setw(20) << right << "Year End Balance" << setw(30) << right << "Year End Earned Interest" << endl;
        
        
    for(int i = 1; i <= GetNumYears(); i++){ // Run outer loop equal to number of years
        for (int j = 1; j <=12; j++){ // Run inner loop equal to 12 months
            
            // Find Monthly Compound Interest
            SetCompoundInterest((GetClosingBalance()+GetMonthlyDeposit())*((GetAnnualInterest()/100)/12));
            
            // Calculate Accured Interest by adding on to previous month.
            SetAccruedInt(GetCompoundInterest()+GetAccruedInt());
            
            // Calculate Closing monthly Balance by Adding prevous months CB, Monthly Deposit and Compound Interest the month.
            SetClosingBalance(GetClosingBalance()+GetMonthlyDeposit()+GetCompoundInterest());
            
            if(j == 12){ // When inner loop is equal to 12 or the last month of the year print out year end statements.
                cout << right << setfill(' ') << setw(2) << i << setw(15) << "$" << right << GetClosingBalance() << setw(19) << "$" <<  GetAccruedInt() << "\n";
            } 
            
        } // CLose inner Loop
    }  //Close outer Loop
     
}


