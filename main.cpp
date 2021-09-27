#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;

class Person{
private:
    string fName;
    int y_o;
    int luck;

public:
    Person(string newFName="Unknown", int newYO=0, int newLuck=-1) : fName( newFName ), y_o( newYO ), luck( newLuck ){}

    //setters and getters of fName, y_o and luck
    void setName(string fName){
        this->fName = fName;
    }
    string getName(){
        return this->fName;
    }

    void setAge(int y_o){
        this->y_o = y_o;
    }
    int getAge(){
        return this->y_o;
    }

    void setLuck(int luck){
        this->luck = luck;
    }
    int getLuck(){
        return this->luck;
    }

};

void newLuck(Person &A, Person &B){
    int temp = A.getLuck();
    A.setLuck(B.getLuck());
    B.setLuck(temp);//function to find new Luck
}

const int N = 4; // constand number

int main(){
    srand(time(0));  // generating random numbers based on time

    vector<Person>character(1 + N);
    character[1] = Person("Todoroki", 16, rand());
    character[2] = Person("Naruto", 17, rand());
    character[3] = Person("Yagami", 22, rand());
    character[4] = Person("Jiraya", 44, rand());


    string luckiestPerson;//who is luckiest, we should figure it out
    int maxLuck = 0;//it will be equal to 0 at the begging and by comparing with others it will raise until
    //it will reach maxLuck
    for (Person person : character)
        if (maxLuck < person.getLuck())
            luckiestPerson = person.getName(), maxLuck = person.getLuck();
    cout << luckiestPerson << " is the luckiest person and his the luck coefficient is = " << maxLuck << "\n\n";

    cout << "Before using newLuck(Person A, Person B):\n";
    cout << character[3].getName();
    cout<< "'s luck is equal to " ;
    cout<< character[3].getLuck() << '\n';
    cout << character[4].getName() ;
    cout<< "'s luck is equal to ";
    cout<< character[4].getLuck() << "\n\n";

    newLuck(character[3], character[4]);

    cout << "After using newLuck(Person A, Person B):\n";
    cout << character[3].getName() << "'s luck is equal to " << character[3].getLuck() << '\n';
    cout << character[4].getName() << "'s luck is equal to " << character[4].getLuck() << "\n\n";

    //  Storing Person atributes inside an allocated heap memory
    cout << "New heap memory is\n";
    Person *peeps = new Person[N];
    *(peeps + 0) = Person("Todoroki", 16, rand());
    *(peeps + 1) = Person("Naruto", 17, rand());
    *(peeps + 2) = Person("Yagami", 22, rand());
    *(peeps + 3) = Person("Jiraya", 44, rand());


    for (; peeps->getAge(); peeps++)//outputing every member
        cout << peeps->getName();
    cout<< " is " << peeps->getAge() ;
    cout<< " years old and has a luck which is equal ";
    cout<< peeps->getLuck() << '\n';

    delete peeps; // free the memory

    cout << peeps->getName(); // this line doesn't ouput anything since the memory peeps(people) gets freed;
    return 0;
}