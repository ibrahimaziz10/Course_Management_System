# **📘 Course Management System (C++ OOP Project)**
This is a C++ Course Management System that leverages Object-Oriented Programming (OOP) principles to model and manage academic courses, topics, and assessments. It is designed to run as a console-based interactive application, providing users a clean and structured interface to perform various course-related operations.
Main Menu Design to get An Idea:

[=== Course Management Menu ===]
1) Add Course  
2) Remove Course  
3) Show All Courses  
4) Show a Course  
5) Edit a Course  
6) Save Course Details  
7) Load Course Details  
8) Check Course Count  
9) Display Course-Topic Stats  
0) Exit

## **🎯 Program Functions**
- Add, remove, and edit courses

- View all courses or a specific course

- Assign faculty, topics, and tests to each course

- Track and display how many topics are covered per course

- Save and load course data to and from a file

- Maintain persistent records using JSON and file streams


## **🧠 Concepts Demonstrated**
1) Encapsulation: All data and behavior are grouped within classes like Course, Topic, Faculty, and Test using private, public, and protected access specifiers.

2) Inheritance: Quiz, Assignments, and Final classes inherit from the abstract class Test, promoting code reuse.

3)  Polymorphism: Virtual function display() in Test is overridden in child classes to implement different test display logic.

4) Abstraction: Abstract class Test enforces structure and hides implementation details, making the code more maintainable.

5) Constructor Overloading: Multiple constructors are used across classes (e.g., Topic, Test, Course) to provide flexible object initialization.

6) Operator Overloading: == operator is overloaded in Topic for comparison; assignment operator (=) is overloaded in Course for deep copy.

7) Friend Functions: Used in Test for custom ostream output using operator<<, accessing private data while keeping encapsulation intact.

8) Templates: Template functions like removeTopic<T>() and show_a_course<T>() handle different types (string, int) using generic programming.

9) Singleton Pattern: CourseManager uses a singleton design to ensure only one instance manages all courses.

10) STL Vectors: vector is used to store lists of topics and tests dynamically.

11) STL Maps: map is used to track course-topic statistics by mapping course names to topic counts.

12) File Handling: JSON and file streams are used to save/load course data to and from files.

13)  Namespace: All components are wrapped in the CMS namespace to organize code and prevent naming conflicts.

14) Const-Correctness: Getter methods and display functions are marked as const to protect data integrity.



 
Modular Code – All logic is split cleanly across functions and classes for readability.

