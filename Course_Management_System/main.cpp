// main.cpp
#include <iostream>
#include <string>
#include <vector>
#include "bsce24027.h"
using namespace std;
//TODO: ADD THE REMAINING FINCTIONS LIKE SHOW A COURSE AND EDIT A COURSE. MAKE A SAVE TO COURSE AND A LOAD TO COURSE AND REMOVE THE SAVE FILES
int main() {
    CMS::CourseManager& cmgr = CMS::CourseManager::getInstance();
    CMS::TopicManager tMgr;
    bool running = true;
    while (running) {
        CMS::main_menu();
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: { // TO ADD A COURSE
                cmgr.addCourse();
                break;
            }
            case 2:{ // TO REMOVE A COURSES
              char choice_3;
              cout <<"Enter 1 to enter Course Name "<< endl;
              cout <<"Enter 2 to enter Course ID "<< endl;
              cin >> choice_3;
            if(choice_3 == '1'){
             string data;
              cout <<"Enter Course's Name: "<< endl;
              cin >> data;
              if(cmgr.removeCourse<string>(data)){
                cout<<"Course With the Name "<< data <<" is removed."<< endl;
              }
              else{
                cout <<"Error"<< endl;
                main();
              }
            }
            else if(choice_3 == '2'){
            int id;
            cout <<"Enter Course's ID: "<< endl;
            cin >> id;
            if(cmgr.removeCourse<int>(id)){
            cout<<"Course With the ID "<< id <<" is removed."<< endl;
            }
            else{
            cout <<"Error"<< endl;
            main();
            }
        }
        else{
          cout <<"Please Enter A Valid Option"<< endl;
          main();
        }
                break;
            }
            case 3: { // TO DISPLAY ALL COURSES
              cmgr.displayAll();
                break;
            }
            case 4:
              //  TO SHOW A COURSE
              char choice_4;
            cout <<"Enter 1 to enter Course Name "<< endl;
            cout <<"Enter 2 to enter Course ID "<< endl;
            cin >> choice_4;
            if(choice_4 == '1'){
                string data;
                cout <<"Enter Course's Name: "<< endl;
                cin >> data;
                if(cmgr.show_a_course<string>(data)){
                main();
                }
                else{
                    cout <<"Error"<< endl;
                    main();
                }
            }
            else if(choice_4 == '2'){
                int id;
                cout <<"Enter Course's ID: "<< endl;
                cin >> id;
                if(cmgr.show_a_course<int>(id)){
                   main();
                }
                else{
                    cout <<"Error"<< endl;
                    main();
                }
            }
            else{
                cout <<"Please Enter A Valid Option"<< endl;
                main();
            }
                break;
            case 5: { // TO EDIT A COURSE
                string name;
                cout <<"Enter the Course Name to Edit"<< endl;
                cin >> name;
                if(cmgr.edit_course(name)){
                  cout <<"Course With the Name " << name << " is successfully Edited!"<< endl;
                }
                else{
                  cout <<"Sorry Course Not Found."<< endl;
                  main();
                }
                break;
            }
            case 6:{ //TO SAVE A SPECIFIC COURSE TO FILE
              string course_name;
              cout <<"Enter Course Name"<< endl;
              cin >> course_name;
              cmgr.save_a_course( course_name);
              main();
              break;
            }
            case 7:{//TO LOAD A SPECIFIC COURSE
                string course_name;
                cout <<"Enter Course Name"<< endl;
                cin >> course_name;
                cmgr.load_a_course(course_name);
                main();
                break;
            }
            case 8:{// TO RETURN A COURSE COUNT
             cout <<"The total Count of Courses are: "<< cmgr.course_count() << endl;
            main();
            }
            case 9:{
                cmgr.displayCourseTopicStats();
                break;
            }
            case 0:
                running = false;
                break;
            default:
                cout << "Invalid option.\n";
        }
    }

    return 0;
}
