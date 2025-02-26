#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    // Constructor
	Person(){}
    Person(const string& fname, const string& lname) : fname(fname), lname(lname) {}

    // Copy Constructor
    Person(const Person& person) : fname(person.fname), lname(person.lname) {}

    // Getters
    const string& getFname() const { return fname; }
    const string& getLname() const { return lname; }

    // Setters
    void setFname(const string& newFname) {
        cout << "Old Fname: " << fname << endl;
        fname = newFname;
        cout << "New Fname: " << fname << endl;
    }

    void setLname(const string& newLname) {
        cout << "Old Lname: " << lname << endl;
        lname = newLname;
        cout << "New Lname: " << lname << endl;
    }

    // Virtual info method (to be overridden)
    virtual void info() {
        cout << "Fname: " << fname << "\nLname: " << lname << endl;
    }

protected:
    string fname, lname;
};

// Derived class
class Employee : public Person {
public:
    // Constructor
	Employee(){}
    Employee(const Person& person, int salary) : Person(person), salary(salary) {}

    // Copy Constructor
    Employee(const Employee& emp) : Person(emp), salary(emp.salary) {}

    // Overridden info method
    void info() override {
        Person::info();
        cout << "Salary: " << salary << endl;
    }

    // Getter for salary
    int getSalary() const {
        return salary;
    }

    // Setter for salary
    void setSalary(int s) {
        cout << "Old Salary: " << salary << endl;
        salary = s;
        cout << "New Salary: " << salary << endl;
    }

protected:
    int salary;
};
class Manager:public Employee{
public:
	Manager(){}
	Manager(const Employee& emp, int salary,
			int meet_week, int vac_year):
		Employee(emp), meet_week(meet_week), vac_year(vac_year){}
	Manager(const Manager& man){
		this->meet_week = man.meet_week;
		this->vac_year = man.vac_year;
	}
	void info() override{
		Employee::info();
		cout<<"Meet_per_week: "<<meet_week<<"/n"<<"Vacation: "<<vac_year<<endl;
	}
	int getMeets() const{
		return this->meet_week;	
	}
	void setMeets(int m){
		cout<<"Old Meets per Week: "<<meet_week<<endl;
		this->meet_week = m;
		cout<<"New Meets per Week: "<<meet_week<<endl;
	}
	int getVacation() const{
		return this->vac_year;
	}

	void setVacation(int v){
		cout<<"Old Vacations: "<<vac_year<<endl;
		this->vac_year=v;
		cout<<"New Vacations: "<<vac_year<<endl;
	}
protected:
	int meet_week;
	int vac_year;
};

class Engineer:public Employee{
public:
	Engineer(){}
	Engineer(const Employee& emp,
			bool knows_cpp, int experience, string prof):
		Employee(emp), knows_cpp(knows_cpp),
		experience(experience), prof(prof){}
	
	void info() override{
		Employee::info();
		cout<<"C++: "<<knows_cpp<<"Experience: "<<experience<<"yrs/n"<<"Profession: "<<prof<<endl;
	}
	int getExperience() const{
		return this->experience;
	}
	void setExperience(int exp){
		cout<<"Old Experience: "<<experience<<endl;
		this->experience = exp;
		cout<<"New Experiene: "<<experience<<endl;
	}

	const string& getProf() const{
		return this->prof;
	}

	void setProf(const string& newProf){
		cout<<"Old Profession: "<<prof<<endl;
		this->prof = newProf;
		cout<<"Old Profession: "<<prof<<endl;
	}
	bool getKnowsCpp() const{
		return this->knows_cpp;
	}

	void setKnowsCpp(bool cpp){
		cout<<"C++: "<<knows_cpp<<endl;
		this->knows_cpp = cpp;
		cout<<"C++: "<<knows_cpp<<endl;
	}
protected:
	bool knows_cpp;
	int experience;
	string prof;
};
int main(){
	Person person1("John", "Anderson");
    Employee emp1(person1, 34000);
	Engineer eng1(emp1, true,
	3, "Java Developer");
	emp1.info();
	eng1.info();
	eng1.setSalary(50000);
	eng1.setKnowsCpp(false);
}
