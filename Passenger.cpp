#include"Passenger.h"
#include<iostream>
#include<string>
#include"Enums.h"
namespace cs32 {
	Passenger::Passenger() :mClass(Class::NOTKNOWN), mEmbarked(Embarcation::NOTKNOWN), mName(""), mSurvived(false), mFare(0.00) {

	}
	void Passenger::setName(std::string name) {
		mName = name;
	}

	std::string Passenger::getName() {
		return mName;
	}

	void Passenger::setEmbarcation(std::string embarked){
		if (embarked == "C")
			mEmbarked = Embarcation::CHERBOURG;
		else if (embarked == "Q")
			mEmbarked = Embarcation::QUEENSTOWN;
		else if (embarked == "S")
			mEmbarked = Embarcation::SOUTHHAMPTON;
		else
			mEmbarked = Embarcation::NOTKNOWN;
		//need to convert string into enum
		//use if else statements
	}

	void Passenger::setClass(std::string classofFare) {
		if (classofFare == "1")
			mClass = Class::FIRST;
		else if (classofFare == "2")
			mClass = Class::SECOND;
		else if (classofFare == "3")
			mClass = Class::THIRD;
		else
			mClass = Class::NOTKNOWN;
		//convert string into class enum with if else statements
	}

	void Passenger::setSurvived(std::string survived) {//if else statements for converting survived
		if (survived == "1")
			mSurvived = true;
		else
			mSurvived = false;
	}
	void Passenger::setFare(std::string fare) {
		if (fare >= "0") {
			mFare = std::stof(fare);
			
		}
		else {
			mFare = 0.0;// if empty string set it to 0.0
		}
	}
	Embarcation Passenger::getEmbarcation() {
		return mEmbarked;
	}
	Class Passenger::getClass() {
		return mClass;
	}
	bool Passenger::getSurvived() {
		return mSurvived;

	}
	double Passenger::getFare() {
		return mFare;
	}

}