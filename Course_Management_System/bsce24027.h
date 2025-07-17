#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

namespace CMS{
// Forward declaration
class Test;

// === Menu Function ===
inline void main_menu() {
    cout << "[=== Course Management Menu ===]" << endl;
    cout << "1) Add Course\n";
    cout << "2) Remove Course\n";
    cout << "3) Show All Courses\n";
    cout << "4) Show a Course\n";
    cout << "5) Edit A Course\n";
    cout << "6) Save Course Details\n";
    cout << "7) Load Course Details\n";
    cout << "8) Check Course Count\n";
    cout << "9) Display Course-Topic stats\n";
    cout << "0) Exit\n";
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    cout << "Select an option: ";
}

// === Faculty Class ===
class Faculty {
public:
    string name;
    Faculty() {}
    Faculty(string n) : name(n) {}
    void set_name(string n) { name = n; }
    string get_name() const { return name; }
};

// === Topic Class ===
class Topic {
    int id;
    string title;
    bool completed;
    string difficulty;
    string description;
public:
    Topic(int id = 0, string t = "", bool c = false, string d = "", string desc = "")
        : id(id), title(t), completed(c), difficulty(d), description(desc) {}

    // Getters
    int getId() const { return id; }
    string get_title() const { return title; }
    bool get_completed() const { return completed; }
    string get_difficulty() const { return difficulty; }
    string get_description() const { return description; }

    // Setters
    void set_Id(int i) { id = i; }
    void set_title(string t) { title = t; }
    void set_complete(bool c) { completed = c; }
    void set_difficulty(string d) { difficulty = d; }
    void set_description(string d) { description = d; }
    //===OTHER FUNCTIONS===

    // Display function
    void display() const {
        cout << "[Topic] ID: " << id
             << ", Title: " << title
             << ", Completed: " << (completed ? "Yes" : "No")
             << ", Difficulty: " << difficulty
             << ", Description: " << description << endl;
    }

    bool operator==(const Topic &other) const { //== OPERATOR
        return id == other.id && title == other.title &&
               completed == other.completed && difficulty == other.difficulty &&
               description == other.description;
    }
};

// === TopicManager ===
class TopicManager {//PRIVATE VARIABLES
    vector<Topic> topics;
public:
  // PUBLIC VARAIBLES
  //OTHER FUNCTIONS
    void addTopic() {
        int id; string title, difficulty, description; bool completed;
        cout << "Enter Topic ID: "; cin >> id; cin.ignore();
        cout << "Title: "; getline(cin, title);
        cout << "Completed (1/0): "; cin >> completed; cin.ignore();
        cout << "Difficulty: "; getline(cin, difficulty);
        cout << "Description: "; getline(cin, description);
        topics.push_back(Topic(id, title, completed, difficulty, description));
    }
    // TEMPLATE FUNCTION TO REMOVE TOPICS WITH EITHER ID OR NAME
    template <typename T>
    void removeTopic(T key) {
        for (int i = 0; i < topics.size(); ++i) {
            if (topics[i].get_title() == key || topics[i].getId() == key) {
                topics.erase(topics.begin() + i);
                --i;
            }
        }
    }
    // SHOWS ALL TOPICS
    void showAll() const {
        if (topics.empty()) {
            cout << "No topics available.\n";
            return;
        }
        for (const auto& t : topics)
            t.display();
    }
    // SHOWS A TOPIC
    template <typename T>
    void show_a_topic(T key) {
        for (const auto& t : topics)
            if (t.get_title() == key || t.getId() == key)
                t.display();
    }
      // RETURNS THE VECTOR LIST OF TOPICS
    const vector<Topic>& getAll() const { return topics; }
};

// === Test Abstract Class ===
class Test {
protected: //PROTECTED VARAIBLES DECLARED HERE
    string test_name;
    int component;
    int marks;
public:// CONSTRUCTORS AND DESTRUCTORS
    Test(string name = "", int c = 0, int m = 0)
        : test_name(name), component(c), marks(m) {}

    virtual ~Test() {}
   // OTHER FUNCTIONS
    virtual void display() const = 0; // PURE VIRTUAL FUNCTIONS , WHERE THE CHILD CLASS WOULD WRITE EACH SUBJECTIVE LOGIC

    friend ostream& operator<<(ostream& out, const Test& t) { // COUTS THE COMMON DETAILS BETWEEN EACH CHILD CLASS
        out << "Test Name: " << t.test_name << "\n"
            << "Component: " << t.component << "\n"
            << "Marks: " << t.marks << "\n";
        return out;
    }
};

// === Quiz Class ===
class Quiz : public Test { // DERIVES FROM TEST
public:
    Quiz(string name, int comp, int m) : Test(name, comp, m) {} // CUSTOM CONSTRUCTOR
    void display() const override; // FUNCTION OVERRIDE BUT LOGIC WRITTEN IN .CPP
};

// === Assignment Class ===
class Assignments : public Test { // DERIVES FROM TEST
public:
    Assignments(string name, int comp, int m) : Test(name, comp, m) {}// CUSTOM CONSTRUCTOR
    void display() const override;
};

// === Final Exam Class ===
class Final : public Test {
public:
    Final(string name, int comp, int m) : Test(name, comp, m) {}// CUSTOM CONSTRUCTOR
    void display() const override;// FUNCTION OVERRIDE BUT LOGIC WRITTEN IN .CPP
};

// === Course Class ===
class Course {
  // PRIVATES VARAIBLES DECLARED
    int id;
    string name;
    vector<Topic> topics;
    vector<Quiz> qz;
    vector<Assignments> asmt;
    vector<Final> fn;
public: //PUBLIC VARAIBLES & FUNCTIONS
  Faculty faculty;
  //DEEP COPY
  //CONSTRUCOR
    Course(int id, string n, Faculty f, vector<Topic> t, vector<Quiz> qz ,vector<Assignments> asmt , vector<Final> fn)
        : id(id), name(n), faculty(f), topics(t), qz(qz) , asmt(asmt) , fn(fn) {}
    //DESTRUCTOR
    ~Course() {
        cout <<"Tests Deleted"<< endl;
    }
    //SETTER & GETTERS
    int getId() const { return id; }
    string getName() const { return name; }
    Faculty getFaculty()const{return faculty;}

    void setId(int a){id = a;}
    void setName(string n){name = n;}
    void setFaculty(Faculty f){faculty = f;}
    //RETURNS THE VECTOR LIST OF TOPICS
    const vector<Topic>& getAllTopics() const{
    return topics;
    }
    // = CONSTRUCTOR
    Course& operator=(const Course& other) { //DEEP COPY THAT CREATES NEW COPIES OF NESTED DATA
    if (this != &other) {
        id = other.id;
        name = other.name;
        faculty = other.faculty;
        topics = other.topics;
        qz = other.qz;
        asmt = other.asmt;
        fn = other.fn;
    }
    return *this;
}
    // DISPLAY THE C0URSES INFO
    void display() const {
        cout << "\n[=== Course ID: " << id << " | Name: " << name << " ===]\n";
        cout << "Faculty: " << faculty.get_name() << endl;
        cout << "--- Topics ---\n";
        for (const auto& t : topics) t.display();
        cout <<"--- Tests ---"<< endl;
        for(int i = 0;i < qz.size();i++){
          qz[i].display();
        }
        for(int i = 0;i < asmt.size();i++){
          asmt[i].display();
        }
        for(int i = 0;i < fn.size();i++){
          fn[i].display();
        }
        cout << "===========================\n";
    }
};

// === CourseManager Singleton ===
class CourseManager {
    vector<Course> courses;
    static int total_courses;
    CourseManager() = default;
public:
  TopicManager tMgr;
    static CourseManager& getInstance() {
        static CourseManager instance;
        return instance;
    }

    CourseManager(const CourseManager&) = delete;
    CourseManager& operator=(const CourseManager&) = delete;

    Course addCourse() {
        int id; string name, facultyName;
        vector<Topic> topics;
        vector<Quiz> qz;
        vector<Assignments> asmt;
        vector<Final> fn;

        cout << "Enter Course ID: "; cin >> id; cin.ignore();
        cout << "Course Name: "; getline(cin, name);
        cout << "Faculty Name: "; getline(cin, facultyName);


        char more;
        do {
            tMgr.addTopic();
            cout << "Add another topic? (y/n): ";
            cin >> more;
        } while (tolower(more) == 'y');
        topics = tMgr.getAll();

        char option;
        do {
            cout << "\n--- Add Test ---\n";
            cout << "1) Quiz\n2) Assignment\n3) Final\n0) Done\nChoose: ";
            cin >> option;
            string testName;
            int comp, marks;
            switch (option) {
                case '1':
                    cin.ignore(); cout << "Quiz Name: "; getline(cin, testName);
                    cout << "Component: "; cin >> comp;
                    cout << "Marks: "; cin >> marks;
                    qz.push_back(Quiz(testName, comp, marks));
                    break;
                case '2':
                    cin.ignore(); cout << "Assignment Name: "; getline(cin, testName);
                    cout << "Component: "; cin >> comp;
                    cout << "Marks: "; cin >> marks;
                    asmt.push_back(Assignments(testName, comp, marks));
                    break;
                case '3':
                    cin.ignore(); cout << "Final Name: "; getline(cin, testName);
                    cout << "Component: "; cin >> comp;
                    cout << "Marks: "; cin >> marks;
                    fn.push_back(Final(testName, comp, marks));
                    break;
            }
        } while (option != '0');

        Course newCourse(id, name, Faculty(facultyName), topics, qz , asmt , fn);
        courses.push_back(newCourse);
        total_courses++;
        return newCourse;
    }
template <typename T>
    bool removeCourse(T id) {
    if constexpr (is_same<T, int>::value) {
        for (int i = 0; i < courses.size(); ++i) {
            if (courses[i].getId() == id) {
                courses.erase(courses.begin() + i);
                return true;
            }
        }
    } else if constexpr (std::is_same<T, std::string>::value) {
        for (int i = 0; i < courses.size(); ++i) {
            if (courses[i].getName() == id) {
                courses.erase(courses.begin() + i);
                return true;
            }
        }
    }
    total_courses--;
    return false;
}
template <typename T>
bool show_a_course(T id){
  if constexpr (is_same<T, int>::value) {
        for (int i = 0; i < courses.size(); ++i) {
            if (courses[i].getId() == id) {
                courses[i].display();
                return true;
            }
        }
    } else if constexpr (std::is_same<T, std::string>::value) {
        for (int i = 0; i < courses.size(); ++i) {
            if (courses[i].getName() == id) {
                 courses[i].display();
                return true;
            }
        }
    }
    return false;
}

    void displayAll() const {
        if (courses.empty()) {
            cout << "No courses available.\n";
            return;
        }
        for (const auto& c : courses)
            {c.display();}
    }

    bool edit_course(string name){
      string tname;
      int tid;
      Faculty f;
      for(int i =0 ; i < courses.size();++i){
        if(courses[i].getName() == name){
          cout << "[-- COURSE EDITOR --]" << endl;
          cout <<"Enter Course ID"<< endl;
          cin >> tid;
          cin.ignore();
          cout <<"Enter Course Name"<< endl;
          getline(cin,tname);
          cout <<"Enter Course Faculty"<< endl;
          getline(cin,f.name);
          cout <<"-----------------------"<< endl;
          courses[i].setName(tname);
          courses[i].setId(tid);
          courses[i].setFaculty(f);
          return true;
        }
      }
      return false;
    }

    void displayCourseTopicStats() const{
      map<string,int> courseTopicCount;
      for(const auto& course:courses){
         courseTopicCount[course.getName()] = course.getAllTopics().size();
      }
      cout <<"[-- Course Topic Stats --]"<< endl;
      for (const auto& [name, count] : courseTopicCount){
        cout << "Course: " << name << " has " << count << " topics.\n";
        }
      cout <<"--------------------------"<< endl;
    }

void save_a_course(string course_name);
void load_a_course(string course_name);
int course_count(){return total_courses;}
};
}
