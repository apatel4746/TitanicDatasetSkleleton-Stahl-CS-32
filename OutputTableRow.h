#ifndef OUTPUTTABLEROW_H
#define OUTPUTTABLEROW_H
#include "Settings.h"
#include "CSVFile.h"
#include "ExampleDataCollector.h"
#include <iostream>
#include <string>
#include "Enums.h"
#include "Passenger.h"
#include "PassengerDatabase.h"
#include "PassengerOutputTable.h"
#include "OutputTableRow.h"
#include "Settings.h"


namespace cs32 {
	class OutputTableRow {
	public:
		OutputTableRow();
		void setDescription(std::string description);
		void setSurvived(int survived);
		void setTotal(int total);
		std::string getDescription() ;
		int getSurvived();
		int getTotal();
		double getPercentage();
		void display();
	private:
		std::string mDescription;
		
		int mTotal;
		int mSurvived;
		std::string padToThreeCharacters(int value);
	};
}
#endif