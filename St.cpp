#include <iostream>
#include <ctime>
 
using namespace std;

 
class slotMachine 
{

private:
	
    int wheelA;
    int wheelB;
    int wheelC;
    double payOut;         //amount of $ won during the current turn
    double moneyInMachine; //total amount of $ in the machine
    double gameCost;       //the cost of one pull
    double moneyPaid;      //the money put in by user
public:
    //prototypes
    slotMachine();
    bool displayMenu(void);
    bool pullHandle(void);
    void spinWheel(int &);
    double calculatePayout();
    void insertCoin(double );
    void displaySpinResults();
    
	int Random(int, int);
    void displayTotals();

};
 

int main(void)
 {

    //create a slot machine object

    slotMachine mySlot;

 

    //Start the slot machine game

    //Keep running until the user

    //decides to quit

 

    bool ok = true;

    while (ok){

        ok = mySlot.displayMenu();

    };

 

    return 0;

 

} //end main

 

slotMachine::slotMachine () 
{

    //constructor, set the initial state

    //of all the properties



    moneyInMachine = 100;

    moneyPaid = 0;

    payOut = 0;

    wheelA = 0;

    wheelB = 0;

    wheelC = 0;

    gameCost = 1;

}

 

bool slotMachine::displayMenu(void)

{

    //main menu, executes the command selected by the

    //user or returns a value to terminate game execution
 
    char choice = 'Z';
 
    bool continueGame = true;  
 
    cout << "\n\n(E)nd, (P)ull, P(A)Y, (T)otals :";
    cin >> choice;
 
    switch (choice) {

case 'e':

case 'E':  //stop game

    continueGame = false;

    break;

case 'a':

case 'A': //pay

    double money;

    cout << "\nIt's a dollar a pull!\n"

        << "Put money into the machine $";
    cin >> money;

    insertCoin(money);

    break;

case 'p':

case 'P': //pull

    if (pullHandle())
	{
    	
    	

        cout << endl << endl << endl;

        displaySpinResults();

        cout << "Payout: $" << calculatePayout();

    }
    break;
case 't':
case 'T': //display totals
    displayTotals();
    break;
    }

    return continueGame;

}

 

bool slotMachine::pullHandle(void)

{

    //checks to see if there is enough user money

    //for a spin. If so, assigns a random value

    //to each wheel. Deducts the cost of one

    //pull from the users money.

    if (moneyPaid > gameCost)
    {
        spinWheel(wheelA);
        spinWheel(wheelB);
        spinWheel(wheelC);
 
        moneyPaid -= gameCost;
 
        //returns true if the handle was pulled.
        return true;
    } //end if

 
    //returns false if the handle could not be pulled  

    else

    {

        return false;

 

    } //end else if

 

}

 

void slotMachine::spinWheel(int &theWheel)

{

    //assign a random value to a wheel 

    theWheel = Random(1,3);

}


double slotMachine::calculatePayout()

{
    //decides if the current wheel values merit a

    //payout and how much that payout should be.

    //deducts the total payout from the total

    //amount of money in the machine
 
    if (wheelA == wheelB  && wheelA == wheelC)
    {
        //Use case statement
        switch(wheelA)
        {
            //For case 1 (when all wheels equal 1)

        case 1:
            //calculate the payout.
            payOut = (moneyInMachine * 0.10);
             //reduce money in machine by 10%

            moneyInMachine -= payOut;

 

            //return 10% of money in machine

            cout << "You win!" << endl;
 

            return payOut;

            break;


            //For case 2 (when all wheels equal 2)

        case 2:

            //calculate the payout.

            payOut = (moneyInMachine * 0.20);

 

            //reduce money in machine by 20%

            moneyInMachine -= payOut;

 

            //return 20% of money in machine

            cout << "You win!" << endl;

 

            return payOut;
            break;
 
            //For case 3 (when all wheels equal 3)
        case 3:

            //calculate the payout.

            payOut = (moneyInMachine * 0.30);

 

            //reduce money in machine by 30%

            moneyInMachine -= payOut;
 
            //return 30% of money in machine
            cout << "You win!" << endl;
 
            return payOut;
            break;

 

            //otherwise return zero

        default:

            return 0;

            break;
 
        } //end switch case
 
    } //end if

 

    else

    {
        //Otherwise return zero
        cout << "No payout. Try again?\n" << endl;
        return 0;

    } //end else
 
}
 
void slotMachine::insertCoin(double amount)
{

    //adds to the amount of money paid by the user

    moneyPaid += amount;

 

    //adds to the total money in the machine

    moneyInMachine += amount;

}

 

void slotMachine::displaySpinResults()

{

    //displays the value of the three wheels

    cout << "[" << wheelA << "] "

        << "[" << wheelB << "] "
        << "[" << wheelC << "] \n\n" ;
}

 

void slotMachine::displayTotals()

{

    //displays the amount of money and number

    // of pulls the player has left

    cout << "\nMoney in Machine $" << slotMachine::moneyInMachine << endl;

    cout << "Pulls Left: " <<   slotMachine::moneyPaid / slotMachine::gameCost  << endl << endl;

 

}          

 

int slotMachine::Random(int lowerLimit, int upperLimit)

{

    //returns a random number within the given boundary


}

