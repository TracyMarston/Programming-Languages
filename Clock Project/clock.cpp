#include <iostream>
#include <iomanip> 
#include <cmath>
#include <ctime>
using namespace std;

// FIND CURRENT TIME
void currentTime(int& clock12Hours, int& clock24Hours, int& clockMinutes, int& clockSeconds){
    // current date/time based on current system
    time_t now = time(0);
    tm *ltm = localtime(&now);
   
   clock12Hours = ltm->tm_hour; //  Assign Current Hours (12 Clock)
   clock24Hours = ltm->tm_hour; // Assign Current Hours (24 Clock)
   clockMinutes = ltm->tm_min; // Assign Current Minutes
   clockSeconds = ltm->tm_sec; // Assign Current Seconds
 
}



// DETERMINE PERIOD / MERIDIAN of Day
void timePeriod(string& period, int& clock12Hours){
    if ((clock12Hours >= 13) && (clock12Hours < 24)){  // 12pm -11pm
        period = "PM";
    }
    else if (clock12Hours == 12){
        period = "PM";
    }
    else{
        period = "AM";
    }   
}



// PRESS 1 - Increment Hours by 1, depending on 12 or 24 hour Clock
void add24Hour (int& clock24Hours){

  clock24Hours = clock24Hours + 1; // Add one to Hours (24-Clock)
  
    if (clock24Hours >= 24){ // When clock reaches 24, change Hours to 0. 
        clock24Hours = 0;
    }
}


// PRESS 1 - Increment Hours by 1, depending on 12 or 24 hour Clock
void add12Hour (int& clock12Hours){

    clock12Hours = clock12Hours + 1;  // Add one to Hours (12-Clock)
    
    // Prevent Hours from exceeding 24 Hours
    if (clock12Hours > 24){ // When clock reaches 24, change Hours to 1. 
       clock12Hours = 1;
   }
}



 // PRESS 2 - Increment Minutes by 1
void addMinute (int& clockMinutes){

  clockMinutes = clockMinutes + 1;  // Add 1 minute

  if (clockMinutes == 60){ //Revert minutes to 0 after 59    
      clockMinutes = 0;  
    }
}


// PRESS 3 - Increment Seconds by 1
void addSecond (int& clockSeconds){

  clockSeconds = clockSeconds + 1;  // Add 1 second

  if (clockSeconds == 60){  //Revert seconds to 0 after 59 
      clockSeconds = 0;
    }
}




// PRINT 12 HOUR CLOCK
void print12Clock (int clock12Hours, int clockMinutes, int clockSeconds, string period){
   
   // FORMAT Hours to be 1-12 only
   if ((clock12Hours > 12) && (clock12Hours < 25)){  // Between the hours of 13 - 24 Hours, subtract 12 to equal actual time.
       clock12Hours = clock12Hours - 12;
   }
   
    // START PRINTING OUT 12-Clock
    cout << "*" << setfill(' ') << setw(7);
        if(clock12Hours < 10){ // If clock12Hours is less than 10 then display 0.
            cout << "0";
            
        }
    cout << clock12Hours << ":";
    if(clockMinutes < 10){ //If Minutes is less than 10 then display 0.
            cout << "0";
        }
    cout << clockMinutes << ":"; 
    if(clockSeconds < 10){  //If Seconds is less than 10 then display 0.
            cout << "0";
        }
    cout << clockSeconds << " " << period << setfill(' ') << setw(8) << "*\t";
}



// PRINT 24 HOUR CLOCK 
void print24Clock (int clock24Hours, int clockMinutes, int clockSeconds){
    
     // START PRINTING OUT 24-Clock
     cout << "*"<< setfill(' ') << setw(9);
     if(clock24Hours < 10){ // Add 0 to front of int if single digit.
            cout << "0";
            
     }
     cout << clock24Hours << ":";
     if(clockMinutes < 10){// Add 0 to front of int if single digit.
            cout << "0";
            
        }
     cout << clockMinutes << ":";
      if(clockSeconds < 10){// Add 0 to front of int if single digit.
            cout << "0";
            
        }
     cout << clockSeconds << setfill(' ') << setw(8) << "*" << endl;
}



// Print Menu 
void printMenu(){
    cout << setfill('*') << setw(26) << "\n";
    cout << "* 1 - Add One Hour" << setfill(' ') << setw(7) << "*" << endl;
    cout << "* 2 - Add One Minute" << setfill(' ') << setw(5) << "*" <<  endl;
    cout << "* 3 - Add One Second" << setfill(' ') << setw(5) << "*" << endl;
    cout << "* 4 - Exit Program" << setfill(' ') << setw(7) << "*" << endl;
    cout << setfill('*') << setw(26) << "\n";
}

int main (){
  
  int clock12Hours; // Clock 12 Hours 
  int clock24Hours; // Clock 24 Hours 
  int clockMinutes; // Clock Minutes 
  int clockSeconds; // Clock Seconds 
  string period; // Declare time of day AM/PM
  bool clearScreen = true; // Continue display clear screen.
  int menuChoice; // Menu Choice 1,2,3,4. No need for default

  
  currentTime(clock12Hours, clock24Hours, clockMinutes, clockSeconds); // Pull initial Current time
  timePeriod(period, clock12Hours);  // Pull intial time of day - Must follow after pulling current time.

 while ((clearScreen = true)) // Keep providing clearScreen with Menu Options until user presses Option 4
    {
        
         cout << setfill('*') << setw(26) << "\t" << setw(26) << "\n";
         cout << "*"  << setfill(' ') << setw(18) <<  "12-Hour Clock"<< setw(8) << "*\t*";
         cout << setfill(' ') << setw(18) << "24-Hour Clock" << setw(6) << "*" << endl;
         print12Clock (clock12Hours, clockMinutes, clockSeconds, period);
         print24Clock (clock24Hours, clockMinutes, clockSeconds);
         cout << setfill('*') << setw(26) << "\t" << setw(27) << "\n\n";
     
      printMenu ();
      cin >> menuChoice;

      if (menuChoice == 1){ // Trigger Add Hour to time Function
        add12Hour (clock12Hours);
        add24Hour (clock24Hours);
        timePeriod(period, clock12Hours); // Update Time of Day AM/PM depending on new 12-Clock Hours
      }
      else if (menuChoice == 2){ // Trigger Add Minute to time Function
        addMinute (clockMinutes);
      }
      else if (menuChoice == 3){ // Trigger Add Second to time Function
        addSecond (clockSeconds);
      }
      else if (menuChoice == 4){ // Exit Program - Update parameter on while loop to stop.
        clearScreen = false;
      }
      else{
      cout << "Enter a item from the menu or press 4 to Exit program." << endl << endl << endl;
    }
} 

cout << "Program Finished" << endl; // End Statement once while loop stops


  return 0;

}
