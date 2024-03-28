#pragma once
#ifndef PASSENGEROUTPUTTABLE_H
#define PASSENGEROUTPUTTABLE_H
#include<vector>
#include "Passenger.h"
#include "PassengerDatabase.h"
#include<string>
#include "OutputTableRow.h"

namespace cs32 {
	class PassengerOutputTable {
	public:
		PassengerOutputTable(std::vector<Passenger*> passengers);
			void setOutputField(Field f) ;
			void setDescription(std::string description);
			Field getOutputField(); 
			std::string getDescription();
			void display();
			size_t rowCount();
			OutputTableRow getRow(int index);
	private:
		std::vector<Passenger* > mPassengerList;
		
		Field mField;
		std::string mDescription;
		std::vector<OutputTableRow> mRows;

	};
}
#endif