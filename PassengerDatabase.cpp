#include"PassengerDatabase.h"
#include "Passenger.h"
#include "Enums.h"
#include"CSVFile.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>

namespace cs32 {

	PassengerDatabase::PassengerDatabase():isLoaded(false){	
		
	/*Passenger p; //call default constructor
	p.setClass("1");
	p.setEmbarcation("C");
	p.setSurvived("1");
	p.setName(" ");
	p.setFare("10.25");
	Passenger* pg = new Passenger(p);
	 //assign passsenger pointer Pg address of p
		passengers.push_back(pg); //insert the value into the passengers vector
		for (int i = 0; i < passengers.size(); i++) { //if any problems come back here
			delete passengers.at(i); //delete each individual pointer object to Passenger
		}
		passengers.clear();*/
		
	}
	void PassengerDatabase::clearAllPassengers() {

		for (int i = 0; i < passengers.size(); i++) {
			delete passengers.at(i); //delete each individual pointer object to Passenger
		}
		passengers.clear();

	}
	PassengerDatabase::~PassengerDatabase(){
	
	
	clearAllPassengers();//call clearall function
     


	}
	bool PassengerDatabase::loaded() {
		return isLoaded; //return whether or not is loaded
	}

	Passenger* PassengerDatabase:: getPassenger_byName(std::string name) {
		if (passengers.at(0) == nullptr) { //if the vector is empty return nullptr
			return nullptr;
		}
		if (passengers.size() > 0) { //make sure not accessing an empty vector
			for (int i = 0; i < passengers.size(); i++) { 
				if (passengers.at(i)->getName() == name) { //if we traverse vector and find an element Passenger ptr that has a name that matches parameter
					return (passengers.at(i)); //return that element 
				}

			}
		}
		return nullptr;// if traverse entire vector and cannot find it return nullptr
	}
	std::vector< Passenger* >PassengerDatabase::getPassengers() {
		return passengers;
	}

	

	std::vector<Passenger* > PassengerDatabase::getPassengers_byClass(Class paidClass, bool survived, double minimumFare) {
		std::vector<Passenger*> tempVec;
		//create tempvec traverse vector check if all the parameter condition met then push into new vector
		//*std::vector<Passenger*>::iterator it = passengers.begin(); /
		//if (passengers.empty()) {
			//return tempVec;
		//}
	//	for (int i = 0; i < tempVec.size(); i++) {
		for (int i = 0; i < passengers.size(); i++) {
			if (passengers.at(i)->getClass() == paidClass && passengers.at(i)->getSurvived() == survived && passengers.at(i)-> getFare()>minimumFare) {
				tempVec.push_back(passengers.at(i));
				//
			}
		}
		return tempVec;
	}


	std::vector<Passenger* > PassengerDatabase::getPassengers_byEmbarcation(Embarcation embarked, bool Survived, double minimumFare) {
		std::vector<Passenger*> tempVec;
		//create tempvec traverse vector check if all the parameter condition met then push into new vector
	//	std::vector<Passenger*>::iterator it = passengers.begin();
		//if (passengers.empty()) {
		//	return tempVec;
	//	}
		for (int i = 0; i < passengers.size(); i++) {
			if (passengers.at(i)->getEmbarcation() == embarked && passengers.at(i)->getSurvived() == Survived && passengers.at(i)->getFare() > minimumFare) {
				tempVec.push_back(passengers.at(i));
				// && passengers.at(i)->getSurvived() == Survived
				
			
			}
		}

		return tempVec;
	}
	


	int PassengerDatabase::load(std::string filePath) {
		CSVFile file(this);
		int recordCount = file.readFile(filePath);
		isLoaded = true;
		return (recordCount);
	}
	void PassengerDatabase::csvData(std::map<std::string, std::string>row){
	//	clearAllPassengers();
		Passenger* pointr = new Passenger();// create pointer object to Passenger
		//push into the map each individual part in csv file
		
		pointr->setClass(row["pclass"]);
		pointr->setName(row["name"]);
		pointr->setEmbarcation(row["embarked"]);
		pointr->setSurvived(row["survived"]);
		pointr->setFare(row["fare"]);
		
		passengers.push_back(pointr);// push pointr object into vector
		
		
		

		

	}


	





}