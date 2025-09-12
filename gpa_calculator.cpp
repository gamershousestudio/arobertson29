#include<iostream>

int main(){
    using std::cin, std::cout;

    float gpa, curve;

    cout << "Enter your GPA: ";
    cin >> gpa;

    cout << "How much do you want to scale your grade by? ";
    cin >> curve;

    gpa += curve;

    cout << "Your new and improved GPA is " << gpa;

    return 0;
}