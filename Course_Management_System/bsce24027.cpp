// functions.cpp
#include <iostream>
#include <fstream>
#include <string>
#include "bsce24027.h"
#include "json.hpp"
using json = nlohmann::json;

int CMS::CourseManager::total_courses = 0;
// ----- Quiz -----
void CMS::Quiz::display() const {
    cout << "[Quiz] \n" << *this;
}

// ----- Assignments -----
void CMS::Assignments::display() const{
    cout << "[Assignment] \n" << *this;
}

// ----- Final -----
void CMS::Final::display() const {
    cout << "[Final Exam] \n" << *this;
 }

void CMS::CourseManager::save_a_course(string course_name) {
  try {
    json j;
    ofstream outFile("courses.json", ios::app);
    if (!outFile.is_open()) {
      throw runtime_error("Failed to open file for saving courses.");
    }
    bool courseFound = false;
    for (int i = 0; i < courses.size(); i++) {
      if (courses[i].getName() == course_name) {
        j["course_name"] = courses[i].getName();
        j["course_id"] = courses[i].getId();
        j["Faculty"] = courses[i].faculty.get_name();
        outFile << j.dump(4) << endl;
        cout << "Course Saved Successfully!" << endl;
        courseFound = true;
        break;
      }
    }
    if (!courseFound) {
      throw invalid_argument("Course not found in the system.");
    }
    outFile.close();
  }
  catch (const exception& e) {
    cout << "Error: " << e.what() << endl;
  }
}

void CMS::CourseManager::load_a_course(string course_name) {
  try {
    ifstream inFile("courses.json");
    if (!inFile.is_open()) throw runtime_error("Could not open courses.json");

    json j;
    inFile >> j;
    inFile.close();

    this->courses.clear();
    bool found = false;

    for (auto& item : j) {
      if (item["course_name"] == course_name) {
        int id = item["course_id"];
        string faculty = item["Faculty"];

        Faculty f(faculty);
        vector<Topic> topics;
        vector<Quiz> qz;
        vector<Assignments> asmt;
        vector<Final> fn;

        Course c(id, course_name, f, topics, qz, asmt, fn);
        this->courses.push_back(c);
        found = true;

        cout << "Course loaded:\n";
        cout << "Name: " << course_name << "\n";
        cout << "ID: " << id << "\n";
        cout << "Faculty: " << faculty << "\n";
        break;
      }
    }

    if (!found){throw invalid_argument("Course not found");}
  }
  catch (const exception& e) {
    cout << "Load Error: " << e.what() << endl;
  }
}


