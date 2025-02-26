#include <iostream>
#include <string>
using namespace std;

class Person{
public:
        Person(const string& fname, const string& lname):
                fname(fname), lname(lname){}
        virtual void info(){
                cout<<"Fname: "<<fname<<"/n"<<"Lname: "<<lname<<endl;
        }
        const string& getFname const(){
                return fname;
        }
        const string& getLname const(){
                return lname;
        }
        void setFname(const string& newFname){
                this->fname =newFname;
        }
        void setLname(const string& newLname){
                this->lname = newLname;
        }
protected:
        string fname;
        string lname;
};
int main(){
	Person p("Andrew", "Mathews");
	cout<<p.getFname();
}
