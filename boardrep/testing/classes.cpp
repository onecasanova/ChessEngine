#include <iostream>
#include <string>

using namespace std;

class Car {
    //the members in this private part cannot be accessed by code outside of the class, they are hidden
    //can only be accessed by the class's member functions
    private:
        //define variables
        int mpg;
        double height;
        string color;

    
    public:

        void setMpg(int);
        void setHeight(double);
        void setColor(string);
        void DisplayContent();
    
    
};

void Car::setMpg(int n){
        mpg = n;
    }

void Car::setHeight(double h){
    height = h;
}

void Car::setColor(string c){
    color = c;
}

void Car::DisplayContent() {
    cout << "\nmpg: " << mpg << endl;
    cout << "car height: " << height << " feet" << endl;
    cout << "car color: " << color << endl;

}

int main() {
    
    Car Corvette; 

    int m;
    double h;
    string c;

    cout << "Enter car color: ";
    cin >> c;
    Corvette.setColor(c);
    cout << "Enter car height: ";
    cin >> h;
    Corvette.setHeight(h);
    cout << "Enter car mpg: ";
    cin >> m;
    Corvette.setMpg(m);


    Corvette.DisplayContent();

    return 0;
}

