#ifndef HEADSET_H
#define HEADSET_H

#include <iostream>
#include <string>

class Headset{
public:
	virtual ~Headset() = default;
	virtual void connect = 0;
};

class PlayStationHeadset:public Headset{
public:
	void connect() override{
		cout<<"Headset PlayStation is Connecting..."<<endl;
	}
};

class XboxHeadset:public Headset{
public:
	void connect() override{
		cout<<"Headset Xbox is Connecting..."<<endl;
	}
};

#endif //HEADSET_H
