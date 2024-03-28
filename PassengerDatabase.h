#pragma once
#ifndef PASSENGERDATABASE_H
#define PASSENGERDATABASE_H
#include<string>
#include "Passenger.h"
#include<vector>
#include<string>
#include<map>
#include"DataCollectorCallback.h"
namespace cs32 {
	class PassengerDatabase:public DataCollectorCallback {
	public:
		PassengerDatabase();
		~PassengerDatabase();
		int load(std::string filePath);
		void clearAllPassengers();
		bool loaded();
		Passenger* getPassenger_byName(std::string);
		std::vector< Passenger* > getPassengers();
		std::vector<Passenger* > getPassengers_byClass(Class paidClass, bool survived, double minimumFare);
		std::vector<Passenger* > getPassengers_byEmbarcation(Embarcation embarked, bool Survived, double minimumFare);
		virtual void csvData(std::map<std::string, std::string> row);
	private:
		std::vector<Passenger*> passengers;
		bool isLoaded;

	};


}
#endif