/*
 * main.cpp
 *
 *  Created on: Mar 19, 2024
 *      Author: Lucas
 */

#include <iostream>
#include <vector>
#include "pet.hpp"
#include "dog.hpp"
#include "cat.hpp"

using namespace std;


int main()
{
	Dog* dog1 = new Dog("Bob", 65);
	Dog* dog2 = new Dog("Stan", 37);
	Cat* cat = new Cat("Tom", 12);


	vector<Pet*> pvec;
	pvec.push_back(dog1);
	pvec.push_back(dog2);
	pvec.push_back(cat);

	float total_fee = 0.0;
	for (int i = 0; i < pvec.size(); i++)
	{
		cout << pvec[i]->getName() << ' ' << pvec[i]->calculateFee() << endl;
		total_fee = total_fee + pvec[i]->calculateFee();
	}
	cout << "total licensing fee = " << total_fee << endl;
}


