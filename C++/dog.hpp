/*
 * dog.hpp
 *
 *  Created on: Mar 19, 2024
 *      Author: Lucas
 */

#ifndef DOG_HPP_
#define DOG_HPP_

#include <iostream>
#include <string>
#include "pet.hpp"

using namespace std;

class Dog : public Pet
{
public:
	Dog(string nm, int bwt):Pet(nm, bwt){};
	virtual int calculateFee(){return licensing_rate*getWeight();};
private:
	static float licensing_rate;
};

float Dog::licensing_rate = 2;

#endif /* DOG_HPP_ */
