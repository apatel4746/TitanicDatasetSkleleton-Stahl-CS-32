#include "Passenger.h"
	
	
#include "CSVFile.h"
#include "DataCollectorCallback.h"
#include "PassengerDatabase.h"
#include "PassengerOutputTable.h"
#include "OutputTableRow.h"
#include <iostream>
#include <sstream>
#include<vector>
#include<string>
#include<iomanip>

namespace cs32{
	OutputTableRow::OutputTableRow():mDescription(""), mTotal(0), mSurvived(0) {
	}
	void OutputTableRow::setDescription(std::string description){
		mDescription = description;

	}
	void OutputTableRow::setTotal(int total) {
		mTotal = total; //basic setters and getters for this class
	}
	void OutputTableRow::setSurvived(int survived) {
		mSurvived = survived;

	
	}
	std::string OutputTableRow::getDescription(){
		return mDescription;

	}
	int OutputTableRow::getSurvived() {
		return mSurvived;
	}
	int OutputTableRow::getTotal() {
		return mTotal;


	}
	double OutputTableRow::getPercentage() {
		double surv = static_cast<double>(mSurvived); //convert mSurvived and mTotal into double
		double tot = static_cast<double>(mTotal);
		double percentage = (surv / tot);// divide survived by total
		if (tot == 0) { return 0; } //edge case when total is 0 return 0

		return percentage;

	}
	std::string OutputTableRow::padToThreeCharacters(int value) {
		std::string str = std::to_string(value); //did not know how to pad so tried to do it from online suggetions
		std::ostringstream oss;
		oss << std::setw(3) << str; //thus part is what pads to three
		return oss.str();


	}
	void OutputTableRow::display() {
		std::cout << "Total: " << getTotal() << std::endl;
		std::cout << "TotalSurvived: " << getSurvived() << std::endl; 
		//print Description Survived and Total in that order then percentage times 100
		std::cout << getDescription() << padToThreeCharacters(mSurvived) << "    " << "/" << padToThreeCharacters(mTotal) << "     " << getPercentage() * 100 << std::endl;
	    }



	
	
	
}
