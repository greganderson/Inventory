/*
 This program asks the user for a month number, and then print out the name of the month that corresponds to the number.
 
 Jesus Zarate
 zarate
 September 5, 2012
 
 */

#include <iostream>

using namespace std;

int main ()
{
    int number;
    
    // Asks the user to enter the number of the month they want
    cout << "Please give the number of the month";
    cin >> number;
    
    // On the if statesments it will check each statement and if the number equals one of the statements it will execute that if statement, and it goes all the way down to the 12th number.
    if (number == 1)
    {
        // If the "if" statement is true it will display that month.
        cout << "Month " << number << " is January";
        
    
    }
    
    if (number == 2)
    {
        cout << "Month " << number << " is February";
        

    }
    
    if (number == 3)
    {
        cout << "Month " << number << " is March";
        
        
    }
    
    if (number == 4)
    {
        cout << "Month " << number << " is April";
        
        
    }
    
    if (number == 5)
    {
        cout << "Month " << number << " is May";
        
        
    }
    
    if (number == 6)
    {
        cout << "Month " << number << " is June";
        
        
    }
    
    if (number == 7)
    {
        cout << "Month " << number << " is July";
        
        
    }
    
    if (number == 8)
    {
        cout << "Month " << number << " is August";
        
        
    }
    
    if (number == 9)
    {
        cout << "Month " << number << " is September";
        
        
    }
    
    if (number == 10)
    {
        cout << "Month " << number << " is October";
        
        
    }
    
    if (number == 11)
    {
        cout << "Month " << number << " is November";
        
        
    }
    
    if (number == 12)
    {
        cout << "Month " << number << " is December";
        
        
    }
    
    // This if statement will check if the number the user entered is greater then 12, and if it is it then there is no month for that number, so it will display an error message.
    
    if (number > 12) 
    {
        cout << "Error, that is that is not a month number";
        cout << endl;
    
        
    }

}

