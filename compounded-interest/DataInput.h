void t_dataInput(double& initialInvestAmt, double& monthlyDeposit, double& annualInterest, int& numYears){
    cout << setfill('=') << setw(100) << "\n Investment - Compounded Interest Calculator\n";
    cout << setfill('-') << setw(84);
    // Input Initial Deposit, Monthly Deposit, Annual Interest rate and Number of Years.
    cout << "\n Initial Investment Amount: $";
    cin >> initialInvestAmt; // 
    cout << " Monthly Deposit: $";
    cin >> monthlyDeposit;
    cout << " Annual Interest: %";
    cin >> annualInterest;
    cout << " Number of Years: ";
    cin >> numYears;
   
    
}

