#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//mohamed babiker
//southern new hampshire university
//cs 300
//06/16/2023

//project two

//course structure
struct Course {
    string courseNumber;
    string courseTitle;
   vector<string> prerequisites;
};


//function to load course data from a file into the data strcutres we created tree, hash, vector
void LoadDataStructure(vector<Course>& courses, const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error opening the file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        Course course;
        stringstream ss(line);
        getline(ss, course.courseNumber, ',');
        getline(ss, course.courseTitle, ',');

        string prereq;
        while (getline(ss, prereq, ',')) {
            course.prerequisites.push_back(prereq);
        }

        courses.push_back(course);
    }

    file.close();
    cout << "Data loaded successfully." << endl;
}


//function to print the course list in alphanumeric order
void PrintCourseList(const vector<Course>& courses) {
    //making the vector list that holds that courses.
    vector<Course> sortedCourses = courses;

    //sort the courses 
    for(int i = 0; i < courses.size(); i++){
        for(int j = 0; j < courses.size(); j++){
        if(courses[j].courseNumber > courses[j+1].courseNumber){
            swap(courses[j+1],courses[j]);
        }
        }
        }

    //print the sorted courses list
    for(int i = 0; i < courses.size(); i++){
        PrintCourseList(courses[i]);
    }
}

//funciton to print the course information like example privided
void PrintCourse(const vector<Course>& courses, const string& courseNumber) {
    for (const Course& course : courses) {
        if (course.courseNumber == courseNumber) {
            cout << course.courseTitle << ", " << endl;
            if (course.prerequisites.empty()) {
                break;
            } else {
                cout << "Prerequisites: ";
                for (const string& prereq : course.prerequisites) {
                    cout << prereq << ", ";
                }
                cout << endl;
            }
            return;
        }
    }
    cout << "Course not found." << endl;
}



int main(){
        //making the vector list that holds that courses.
    vector<Course> courses;

        cout << "Welcome to course planneer.\n";
        cout << "1. Load Data Structure.\n";
        cout << "2. Print Course List.\n";
        cout << "3. Print Course.\n";
        cout << "4. Exit\n";
        int choice;

        do{
        cout << "What would you like to do? ";
        cin >> choice;


        switch(choice){
            case 1: courses= LoadDataStructure();
            break;
            
            case 2: {
          cout << "Here is a sample schedule. " << endl;

                PrintCourseList(courses);
            }
            break;
              case 3:{
              string courseNumber;
                cout << "what course do you want to know about? " << endl;
                cin >> courseNumber;
                         PrintCourse(courses, courseNumber);
             break;

              }
            case 4: cout<<"Thank you for using the course planner!" << endl;
            break;
            default: cout << to_string(choice) + " is not a valid option." << endl;
        }
        }while(choice != 4);
        return 0;
        }