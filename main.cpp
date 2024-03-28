//
//  main.cpp
//  Titanic
//
//  Created by Howard Stahl on 7/1/23.
//


#include "Settings.h"
#include "CSVFile.h"
#include "ExampleDataCollector.h"
#include <iostream>
#include <string>
#include <cassert>
#include "Passenger.h"
#include "PassengerDatabase.h"
#include "PassengerOutputTable.h"
#include "OutputTableRow.h"
#include "Settings.h"

// once you get things working...
// #include "Passenger.h"
// #include "PassengerDatabase.h"
// #include "PassengerOutputTable.h"

int example()
{
    using namespace cs32;
    using namespace std;
    
    // work with the ExampleDataCollector do I still need to work with ExampleDataCollector?
   /* ExampleDataCollector* collector = new ExampleDataCollector();
    CSVFile file( collector );
    file.readFile(PATH_TO_BIGGER_DATA_G32);*/
    
    return( 0 );

}
int example2()
{
    using namespace cs32;
    using namespace std;


    return(0);
}


int sample( ) {
  
    
    return 0;
 
   
}

int main()
{
    example();
    sample();

    
    using namespace std;
    using namespace cs32;


    Passenger passenger;
    passenger.setName("Jack Dawson");
    passenger.setEmbarcation("S");
    passenger.setClass("3");
    
    passenger.setSurvived("0");
    passenger.setFare("12.50");
    assert(passenger.getName() == "Jack Dawson");
    assert(passenger.getClass() == Class::THIRD);
    assert(passenger.getEmbarcation() == Embarcation::SOUTHHAMPTON);
    assert(std::to_string(passenger.getFare()) == "12.500000");
    assert(passenger.getSurvived() == false);
    
    OutputTableRow row;
    row.setDescription("testing");
    row.setSurvived(5);
    row.setTotal(10);
    assert(row.getDescription() == "testing");
    assert(row.getSurvived() == 5);
    assert(row.getTotal() == 10);
    assert(std::to_string(row.getPercentage()) == "0.500000");
    
    
    PassengerDatabase database;
    database.load(PATH_TO_SAMPLE_DATA_WINDOWS);
    if (database.loaded())
    {
        vector< Passenger* > byclass = database.getPassengers_byClass(Class::FIRST, true, -10.00);
        vector< Passenger* > byembark = database.getPassengers_byEmbarcation(Embarcation::SOUTHHAMPTON, true, 0.00);

        Passenger* p = database.getPassenger_byName("Howard");
        if (p)
            p->setEmbarcation("S");


        PassengerOutputTable t(byclass);
        t.setDescription("List of First Class Survivors With Fare > 0");
        t.setOutputField(Field::BYCLASS);
        assert(t.getDescription() == "List of First Class Survivors With Fare > 0");
        assert(t.getOutputField() == Field::BYCLASS);
        t.display();
        
        vector< Passenger* > byclassdied = database.getPassengers_byClass(Class::FIRST, false, -10.00);
        PassengerOutputTable t1(byclassdied);
        t1.setDescription("List of First Class Died With Fare > 0");
        t1.setOutputField(Field::BYCLASS);
        t1.display();

        /*vector< Passenger* > byclassdead = database.getPassengers_byEmbarcation(Embarcation::SOUTHHAMPTON, false, -10.00);
        PassengerOutputTable t3(byclassdead);
        t3.setDescription("List of First Class Died With Fare > 0");
        t3.setOutputField(Field::BYCLASS);
        t3.display();*/

        vector< Passenger* > all = database.getPassengers();
        PassengerOutputTable t2(all);
        t2.setDescription("List of all passengers by class");
        t2.setOutputField(Field::BYCLASS);
        t2.display();
               assert(t2.rowCount() == 4);
               
        // first class
        row = t2.getRow(0);
        //std::cout << row.getSurvived() << std::endl;
       // std::cout << row.getTotal() << std::endl;
  //  assert(row.getSurvived() == 200);
    //  assert(row.getTotal() == 200);
       //cout << row.getPercentage() << endl;
     //  assert(std::to_string(row.getPercentage()) == "0.800000");
       /*
        
      assert(std::to_string(row.getPercentage()) == "0.555556");
      row = t2.getRow(1);
      assert(row.getSurvived() == 1);
      assert(row.getTotal() == 1);
      row = t2.getRow(2);
      assert(row.getSurvived() == 1);
      assert(row.getTotal() == 1);
      row = t2.getRow(3);
      assert(row.getSurvived() == 0);
      assert(row.getTotal() == 0);
      */

        t2.setDescription("List of all passengers by embarcation");
        t2.setOutputField(Field::BYEMBARCATION);
        t2.display();

        t2.setDescription("List of all passengers by fare");
        t2.setOutputField(Field::BYFARE);
        t2.display();

        t2.setDescription("What is shown by NOVALUE??");
        t2.setOutputField(Field::NOVALUE);
        t2.display();

        
        /*vector< Passenger* > byclassembarked = database.getPassengers_byEmbarcation(Embarcation::SOUTHHAMPTON, true, 47.00);
        PassengerOutputTable t3(byclassembarked);
        t3.setDescription("List of all passengers by embarcation");
        t3.setOutputField(Field::BYCLASS);
        t3.display();
        */


        cout << "all tests passed" << endl;
        return(0);
        
        
    }

    else
    {
        cout << "database was not loaded correctly" << endl;
        cout << PATH_TO_SAMPLE_DATA_WINDOWS << " is not working!" << endl;
    }


   

    
    
    //cout << "all tests passed!" << endl;
    return(0);
    

}
