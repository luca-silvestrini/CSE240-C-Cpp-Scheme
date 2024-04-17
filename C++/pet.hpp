/*
 * pet.hpp
 *
 *  Created on: Mar 19, 2024
 *      Author: Lucas
 */

#ifndef PET_HPP_
#define PET_HPP_

#include <iostream>
#include <string>

using namespace std;

class Pet
{
public:
	Pet(string nm, int bwt): name(nm), bodyweight(bwt){}
	virtual ~Pet(){}
	void setWeight(int lbs){bodyweight = lbs;}
	void setName(string nm){name = nm;}
	int getWeight(){return bodyweight;}
	string getName(){return name;}
	virtual int calculateFee() = 0;
	static float getLicensingRate(){return licensing_rate;};
private:
	string name;
	int bodyweight;
	static float licensing_rate;
};

float Pet::licensing_rate = 0;

#endif /* PET_HPP_ */
