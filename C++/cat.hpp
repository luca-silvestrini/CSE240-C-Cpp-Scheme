/*
 * cat.hpp
 *
 *  Created on: Mar 19, 2024
 *      Author: Lucas
 */

#ifndef CAT_HPP_
#define CAT_HPP_

#include <iostream>
#include <string>
#include "pet.hpp"

using namespace std;

class Cat : public Pet
{
public:
	Cat(string nm, int bwt):Pet(nm, bwt){};
	virtual int calculateFee(){return licensing_rate*getWeight();};
private:
	static float licensing_rate;
};

float Cat::licensing_rate = 1.5;

#endif /* CAT_HPP_ */
