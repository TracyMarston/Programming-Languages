#ifndef COMPOUNDINTEREST_H
#define COMPOUNDINTEREST_H

using namespace std;
class CompoundInterest {
   public:
      CompoundInterest(); // Set up Default Values
      int months;
      
      void SetInitialInvestAmt(double InvestAmt);  // Set Initial Investment Amount
      double GetInitialInvestAmt();                // Get Initial Investment Amount
      
      void SetMonthlyDeposit(double MonthlyDeposit);  // Set Monthy Deposit Amount
      double GetMonthlyDeposit();                     // Get Monthy Deposit Amount
      
      void SetAnnualInterest(double AnnualInterest);  // Set Annual Interest
      double GetAnnualInterest();                     // Get Annual Interest
     
      void SetNumYears(int NumYears);  // Set Number of Years
      int GetNumYears();                     // Set Number of Years
      
      void SetClosingBalance(double ClosingBalance);  // Set Closing Balance
      double GetClosingBalance();                     // Set Closing Balance
      
      void SetAccruedInt(double AccruedInt);  // Set Acc. Interest
      double GetAccruedInt();                     // Get Acc. Interest
      
      void SetCompoundInterest(double CompoundInterest);  // Set Componded interest
      double GetCompoundInterest();                     // Get Componded interest
      
      // Functions
      int t_calcMonths();  // Convert Years into Months
      void t_compoundInterest(); // Compound interest Function

   private:
      double m_initialInvestAmt;    // Initial Investment Amount
      double m_monthlyDeposit;  // Monthly Deposit w/ Default 0
      double m_annualInterest;      // Annual Interest (Compounded)
      int m_numYears;               // Number of Years
      double m_closingBalance;      //Closing balance
      double m_accruedInt;          // Accrued Interest
      double m_compoundInterest;    /// Componded Interest
};

#endif