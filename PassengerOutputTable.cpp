
#include "Settings.h"
#include "CSVFile.h"
#include "Enums.h"
#include <iostream>
#include <string>
#include <cassert>
#include "Passenger.h"
#include "PassengerDatabase.h"
#include "PassengerOutputTable.h"
#include "OutputTableRow.h"
#include "Settings.h"
#include<iostream>
#include <vector>

namespace cs32 {
	PassengerOutputTable::PassengerOutputTable(std::vector<Passenger*> passengers) : mPassengerList(passengers),mField(Field::NOVALUE), mDescription(""),  mRows() {
	
		// used intializer list to set member variables with parameters
	}

	void PassengerOutputTable::setDescription(std::string description) {
		mDescription = description; //basic setters and getters
	}		
	Field PassengerOutputTable::getOutputField() {
		return mField;
	}
	std::string PassengerOutputTable::getDescription() {
		return mDescription;
	}

	size_t PassengerOutputTable::rowCount() {
		return ( mRows.size()); //row Count is basically how many rows of outputtable row in mRows should usually be 4 maybe edge case not throught of

	}

	void PassengerOutputTable::setOutputField(Field f) {
		mField = f;
	}


	OutputTableRow PassengerOutputTable::getRow(int index) {
		return mRows.at(index); //get the specifc row in mRows
	}

	void PassengerOutputTable::display() {
		
		//std::cout << "     Survived/Total " <<  <<"%" << std::endl;
		//getOutputField();
		//set two types of variables for each outputtablerow row one survive one total
		
		size_t byclassfirsttotal = 0;
		size_t byclasssecondtotal = 0;
		size_t byclassthirdtotal = 0;
		size_t byclassnotknowntotal = 0;

		size_t byembarcationcherbourgtotal = 0;
		size_t byembarcationqueenstowntotal = 0;
		size_t byembarcationsouthhamptontotal = 0;
		size_t byembarcationnotknowntotal = 0;

		
		size_t byfarenotknowntotal = 0;
		size_t byfare1to10total = 0;
		size_t byfare10to25total = 0;
		size_t byfare25to50total = 0;
		size_t byfaregt50total = 0;



		size_t bynovaluetotal = 0;

		int    byclassfirstsurvived = 0;
		int    byclasssecondsurvived = 0;
		int    byclassthirdsurvived = 0;
		int    byclassnotknownsurvived = 0;

		int    byembarcationcherbourgsurvived = 0;
		int    byembarcationqueenstownsurvived = 0;
		int    byembarcationsouthhamptonsurvived = 0;
		int    byembarcationnotknownsurvived = 0;

		int    byfarenotknownsurvived = 0;
		int    byfare1to10survived = 0;
		int    byfare10to25survived = 0;
		int    byfare25to50survived = 0;
		int    byfaregt50survived = 0;

		int    bynovaluesurvived = 0;

		//for (int i = 0; i < this->rowCount(); i++) {
		if (getOutputField() == Field::BYCLASS) {
				//if field is byclass then use for loop go through vector using this pointer create Passenger pointer object access what kind of class check survive increment accordingly
				//byclasssurvived = 0;
			    for (int i = 0; i < this->mPassengerList.size(); i++) {
				Passenger* cp = mPassengerList.at(i);
				// Calculate total for each Class member
				if (cp->getClass() == Class::FIRST) byclassfirsttotal++;				
				if (cp->getClass() == Class::SECOND) byclasssecondtotal++;
				if (cp->getClass() == Class::THIRD)  byclassthirdtotal++;
				if (cp->getClass() == Class::NOTKNOWN) byclassnotknowntotal++;

				if ((cp->getSurvived() == true) && (cp->getClass() == Class::FIRST))  byclassfirstsurvived++;
				if ((cp->getSurvived() == true) && (cp->getClass() == Class::SECOND)) byclasssecondsurvived++;
				if ((cp->getSurvived() == true) && (cp->getClass() == Class::THIRD))  byclassthirdsurvived++;
				if ((cp->getSurvived() == true) && (cp->getClass() == Class::NOTKNOWN)) byclassnotknownsurvived++;
			    }
/*
				// Print attributes as required
				
				std::cout << "List of all passengers by class" << std::endl;
				std::cout << "             %" << std::endl;
				rowbyclassfirst.setDescription("First Class - ");
				rowbyclassfirst.setSurvived(byclassfirstsurvived);
				rowbyclassfirst.setTotal(byclassfirsttotal);
				//mRows.push_back(rowbyclassfirst);
				rowbyclassfirst.display();
				//mRows.clear();
				std::cout << mRows.size()<<": 

				
				rowbyclasssecond.setDescription("Second Class - ");
				rowbyclasssecond.setSurvived( byclasssecondsurvived);
				rowbyclasssecond.setTotal(byclasssecondtotal);
				//mRows.push_back(rowbyclasssecond);
				rowbyclasssecond.display();
				//mRows.clear();

				std::cout << mRows.size() << ":
				
				rowbyclassthird.setDescription("Third Class - ");
				rowbyclassthird.setSurvived( byclassthirdsurvived);
				rowbyclassthird.setTotal(byclassthirdtotal);
				//mRows.push_back(rowbyclassthird);
				rowbyclassthird.display();
				//mRows.clear();
				std::cout << mRows.size() << 
				
				rowbyclassnotknown.setDescription("Notknown Class - ");
				rowbyclassnotknown.setSurvived(byclassnotknownsurvived);
				rowbyclassnotknown.setTotal(byclassnotknowntotal);
				//mRows.push_back(rowbyclassnotknown);
				rowbyclassnotknown.display();
				//mRows.clear();
				std::cout << mRows.size() 
*/				
				//OutputTableRow rowbyclasssecond;
				//create output table row objects
				OutputTableRow rowbyclassfirst;
				OutputTableRow rowbyclasssecond;
				OutputTableRow rowbyclassthird;
				OutputTableRow rowbyclassnotknown;

				std::cout << mDescription << std::endl;
				std::cout << "Survived/Total %" << std::endl;
				rowbyclassfirst.setDescription("First Class");
				//std::cout << "-";
				rowbyclassfirst.setSurvived(byclassfirstsurvived); //set description for row 0, then for survived, then total then push into mRows
				rowbyclassfirst.setTotal(byclassfirsttotal); //quick fix come ba
				mRows.push_back(rowbyclassfirst);
				rowbyclassfirst.display();
				//mRows.clear();
				//std::cout << mRows.size() << 
				rowbyclasssecond.setDescription("Second Class");
				//std::cout << "-";
				rowbyclasssecond.setSurvived(byclasssecondsurvived);
				rowbyclasssecond.setTotal(byclasssecondtotal);
				mRows.push_back(rowbyclasssecond);
				rowbyclasssecond.display();
				//mRows.clear();
				//std::cout << mRows.size() 
				rowbyclassthird.setDescription("Third Class");
				//std::cout << "-";
				rowbyclassthird.setSurvived(byclassthirdsurvived);
				rowbyclassthird.setTotal(byclassthirdtotal);
				mRows.push_back(rowbyclassthird);
				rowbyclassthird.display();
				//mRows.clear();
				//std::cout << mRows.size() 
				rowbyclassnotknown.setDescription("Not known");
				//std::cout << "-";
				rowbyclassnotknown.setSurvived(byclassnotknownsurvived);
				rowbyclassnotknown.setTotal(byclassnotknowntotal);
				mRows.push_back(rowbyclassnotknown);
				rowbyclassnotknown.display();
				//mRows.clear();
				
			//}
		}
		else if (getOutputField() == Field::BYEMBARCATION) {
			//same process as BYCLASS except this time checking for locations of embaraction
			for (int j = 0; j < this->mPassengerList.size(); j++) {
				Passenger* ep = mPassengerList.at(j);
				if (ep->getEmbarcation() == Embarcation::CHERBOURG) byembarcationcherbourgtotal++;
				if (ep->getEmbarcation() == Embarcation::QUEENSTOWN) byembarcationqueenstowntotal++;
				if (ep->getEmbarcation() == Embarcation::SOUTHHAMPTON) byembarcationsouthhamptontotal++;
				if (ep->getEmbarcation() == Embarcation::NOTKNOWN) byembarcationnotknowntotal++;


				if ((ep->getEmbarcation() == Embarcation::CHERBOURG) && (ep->getSurvived() == true)) byembarcationcherbourgsurvived++;
				if ((ep->getEmbarcation() == Embarcation::QUEENSTOWN) && (ep->getSurvived() == true)) byembarcationqueenstownsurvived++;
				if ((ep->getEmbarcation() == Embarcation::SOUTHHAMPTON) && (ep->getSurvived() == true)) byembarcationsouthhamptonsurvived++;
				if ((ep->getEmbarcation() == Embarcation::NOTKNOWN) && (ep->getSurvived() == true)) byembarcationnotknownsurvived++;
					
			}
			//create outputtable row objects that represent each row set description toal and survived and push into mRows
			
				OutputTableRow rowbyembarcationcherbourg;
				std::cout << mDescription << std::endl;
				std::cout << "Survived/Total %" << std::endl;
				rowbyembarcationcherbourg.setDescription("Cherbourg");
				//std::cout << "-";
				rowbyembarcationcherbourg.setSurvived(byembarcationcherbourgsurvived);
				rowbyembarcationcherbourg.setTotal(byembarcationcherbourgtotal);
				mRows.push_back(rowbyembarcationcherbourg);
				rowbyembarcationcherbourg.display();
				

				OutputTableRow rowbyembarcationqueenstown;
				rowbyembarcationqueenstown.setDescription("Queenstown");
				//std::cout << "-";
				rowbyembarcationqueenstown.setSurvived(byembarcationqueenstownsurvived);
				rowbyembarcationqueenstown.setTotal(byembarcationqueenstowntotal);
				mRows.push_back(rowbyembarcationqueenstown);
				rowbyembarcationqueenstown.display();
				

				OutputTableRow rowbyembarcationsouthhampton;
				rowbyembarcationsouthhampton.setDescription("South Hampton");
				//std::cout << "-";
				rowbyembarcationsouthhampton.setSurvived(byembarcationsouthhamptonsurvived);
				rowbyembarcationsouthhampton.setTotal(byembarcationsouthhamptontotal);
				mRows.push_back(rowbyembarcationsouthhampton);
				rowbyembarcationsouthhampton.display();
				

				OutputTableRow rowbyembarcationnotknown;
				rowbyembarcationnotknown.setDescription("Not known");
				//std::cout << "-";
				rowbyembarcationnotknown.setSurvived(byembarcationnotknownsurvived);
				rowbyembarcationnotknown.setTotal(byembarcationnotknowntotal);
				mRows.push_back(rowbyembarcationnotknown);
				rowbyembarcationnotknown.display();
				


			//}
		}
		else if (getOutputField() == Field::BYFARE) {
			//same process continued just specific ranges specified for fare
			for (int k = 0; k < this->mPassengerList.size(); k++) {
				Passenger* fp = mPassengerList.at(k);
				if (fp->getFare() <=0 )  byfarenotknowntotal++;
				if ((fp->getFare() >0) && (fp->getFare() <= 10)) byfare1to10total++;
				if ((fp->getFare() > 10) && (fp->getFare() <= 25)) byfare10to25total++;
				if ((fp->getFare() > 25) && (fp->getFare() <= 50)) byfare25to50total++;
				if (fp->getFare() > 50)  byfaregt50total++;

				if ((fp->getFare() < 1) && (fp->getSurvived() == true)) byfarenotknownsurvived++;
				if (((fp->getFare() > 1) && (fp->getFare() <= 10)) && (fp->getSurvived() == true)) byfare1to10survived++;
				if (((fp->getFare() > 10) && (fp->getFare() <= 25)) && (fp->getSurvived() == true)) byfare10to25survived++;
				if (((fp->getFare() > 25) && (fp->getFare() <= 50)) && (fp->getSurvived() == true)) byfare25to50survived++;
				if ((fp->getFare() > 50) && (fp->getSurvived() == true)) byfaregt50survived++;
				
			}
			//create outputtable row object then do same things as we did for byclass and then push into mRows
				OutputTableRow rowbyfarenotknown;
				std::cout << mDescription << std::endl;
				std::cout << "Survived/Total %" << std::endl;
				rowbyfarenotknown.setDescription("Not Known");
				//std::cout << "-";
				rowbyfarenotknown.setSurvived(byfarenotknownsurvived);
				rowbyfarenotknown.setTotal(byfarenotknowntotal);
				mRows.push_back(rowbyfarenotknown);
				rowbyfarenotknown.display();

				OutputTableRow rowbyfare1to10;
				rowbyfare1to10.setDescription("$ 1-$10");
				//std::cout << "-";
				rowbyfare1to10.setSurvived(byfare1to10survived);
				rowbyfare1to10.setTotal(byfare1to10total);
				mRows.push_back(rowbyfare1to10);
				rowbyfare1to10.display();

				OutputTableRow rowbyfare10to25;
				rowbyfare10to25.setDescription("$10-$25");
				//std::cout << "-";
				rowbyfare10to25.setSurvived(byfare10to25survived);
				rowbyfare10to25.setTotal(byfare10to25total);
				mRows.push_back(rowbyfare10to25);
				rowbyfare10to25.display();

				OutputTableRow rowbyfare25to50;
				rowbyfare25to50.setDescription("$25-$50");
				//std::cout << "-";
				rowbyfare25to50.setSurvived(byfare25to50survived);
				rowbyfare25to50.setTotal(byfare25to50total);
				mRows.push_back(rowbyfare25to50);
				rowbyfare25to50.display();

				OutputTableRow rowbyfaregt50;
				rowbyfaregt50.setDescription(">$50");
				//std::cout << "-";
				rowbyfaregt50.setSurvived(byfaregt50survived);
				rowbyfaregt50.setTotal(byfaregt50total);
				mRows.push_back(rowbyfaregt50);
				rowbyfaregt50.display();

			//}


		}
		/*else if (getOutputField() == Field::NOVALUE) {
			std::cout << "Calling OutputTableRow.display() by NoValue:" << std::endl;
			for (int l = 0; l < this->mPassengerList.size(); l++) {
				Passenger* np = mPassengerList.at(l);
				bynovaluetotal++;
				if (np->getSurvived() == true) {
					bynovaluesurvived++;
				}
			}
			
			OutputTableRow rowbynovalue;
			rowbynovalue.setDescription("Testing byNoValue display");
			rowbynovalue.setSurvived(bynovaluesurvived);
			rowbynovalue.setTotal(bynovaluetotal);
			mRows.push_back(rowbynovalue);
			std::cout << "Calling OutputTableRow.display() by NoValue:" << std::endl;*/
			//rowbynovalue.display();
		//} 
		std::cout << "" << std::endl;
		
		}
		
	}

