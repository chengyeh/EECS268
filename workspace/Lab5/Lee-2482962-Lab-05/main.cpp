/*
 * File Name: main.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab5
 * Description: This is the main class. It is where we give the user a set of options to interact with AnimalPen.
 * Created on: Oct 17, 2015
 *
 */

#include <iostream>
#include "FarmAnimal.h"
#include "Cow.h"
#include "Chicken.h"
#include "CyberChicken.h"
#include "AnimalPen.h"

void goodbyeMessage(const FarmAnimal& animal)
{
        std::cout << "Upon release the " << animal.getName() << " said " << animal.getSound() << "." << std::endl;
}

int main()
{
        AnimalPen* pen = new AnimalPen();
	FarmAnimal* fa;
        Cow* c = nullptr;
        Chicken* chick = nullptr;
        CyberChicken* cyber = nullptr;

	int userChoice;
	int numEggs;
	int totalEggs = 0;
	double totalGallons = 0;
        double gallons = 0.0;
	char quitAdding;
	bool end = false;

	while(end == false)
	{
		std::cout << "Select an animal to add to the pen:\n"
				<< "1.) Cow (produces milk)\n"
				<< "2.) Chicken (cannot lay eggs)\n"
				<< "3.) Cyber Chicken (seems dangerous, but lays eggs)\n"
				<< "---------------------------------------------------\n"
				<< "choice: ";
		std::cin >> userChoice;

		if(userChoice == 1)
		{
			c = new Cow();
			std::cout << "How many gallons of milk did this cow produce?: ";
			std::cin >> gallons;
			c->setMilkProduced(gallons);
			pen->addAnimal(c);
		}
		if(userChoice == 2)
		{
			chick = new Chicken();
			std::cout << "Add an eggless chicken to the pen? OK. You're the boss.\n";
			pen->addAnimal(chick);
		}
		if(userChoice == 3)
		{
			cyber = new CyberChicken();
			std::cout << "How many eggs did this cyber chicken produce?: ";
			std::cin >> numEggs;
			cyber->setCyberEggs(numEggs);
			pen->addAnimal(cyber);
		}

		do
		{
			std::cout << "Done adding animals? (y/n): ";
			std::cin >> quitAdding;

		}while(quitAdding != 'Y' && quitAdding != 'y' && quitAdding != 'N' && quitAdding != 'n');

		if(quitAdding == 'Y' || quitAdding == 'y')
		{
			std::cout << "\n";
			end = true;
		}
		if(quitAdding == 'N' || quitAdding == 'n')
		{
			std::cout << "\n";
			end = false;
		}
	}

	std::cout << "Releasing all animals!\n"
			<< "-------------------------" << std::endl;

	while(!pen->isPenEmpty())
	{
		fa = static_cast<FarmAnimal*>(pen->peakAtNextAnimal());

		if(fa->getName().compare("Cow") == 0)
		{
                        c = static_cast<Cow*>(pen->peakAtNextAnimal());
			totalGallons = totalGallons + c->getMilkProduced();
                        std::cout << "This cow produced " << c->getMilkProduced() << " gallons of milk" << std::endl;
			goodbyeMessage(*(fa));
			pen->releaseAnimal();
                        delete c;
                        c = nullptr;
		}
		else if(fa->getName().compare("Chicken") == 0)
		{
                        chick = static_cast<Chicken*>(pen->peakAtNextAnimal());
			std::cout << "Chicken unable to lay eggs. Perhaps cybornetic implants will help?" << std::endl;
			goodbyeMessage(*(fa));
			pen->releaseAnimal();
                        std::cout << "Chicken Destructor called\n";
                        delete chick;
                        chick = nullptr;
		}
		else if(fa->getName().compare("Cyber Chicken") == 0)
		{
                        cyber = static_cast<CyberChicken*>(pen->peakAtNextAnimal());
			totalEggs = totalEggs + cyber->getCyberEggs();
			std::cout << "This Cyber Chicken laid " << cyber->getCyberEggs() << " cyber eggs. Humanity is in trouble." << std::endl;
			goodbyeMessage(*(fa));
			pen->releaseAnimal();
                        std::cout << "CyberChicken Destructor called\n"
                                        << "Chicken Destructor called\n";
                        delete cyber;
                        cyber = nullptr;
		}
	}

	std::cout << "Your farm produced " << totalGallons << " of milk and " << totalEggs << " eggs." << std::endl;
        delete pen;
        pen = nullptr;

	return(0);
}


