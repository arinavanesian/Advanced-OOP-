#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>
#include "Headset.hpp"

class AccessFactory{
public:
	virtual ~AccessFactory() = default;
	virtual Headset* createHeadset() = 0;
};

class PlayStationFactory:public AccessFactory{
public:
	Headset* createHeadset() override{
		return new PlayStationHeadset();
	}
};

class XboxFactory:public AccessFactory{
public:
	Headset* createHeadset() override{
		return new XboxHeadset();
	}

};
