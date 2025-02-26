#include <iostream>
#include <cstdio>
#include <string>


class Logger{
public:
	static Logger& getInstance(){
		static Logger& instance{};
		return instance;
	}
	void log(const std::string& message){
		std::cout<<"Logged!"<<message;
	}
private:
	Logger(){};
	Logger(Logger& copy)=delete;
	void operator=(const Logger&)=delete;
	int logCount;
};
int main(){
	Logger::getInstance().log("Did it log?");
}
