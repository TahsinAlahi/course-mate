# **CourseMate - Course Management System**

## Title Page

- **Project Title:** CourseMate - Course Management System
- **Group Members:**
  1. Tahsin Alahi Prodhan
  2. Farhan Khan
  3. Prithwi Chakraborty
- **Course Code and Title:** CSE115 - Introduction to Programming Language

---

## Introduction

The main goal of this project, **CourseMate**, was to develop a simple Course Management System using the C programming language.  
The system allows two types of users — **students** and **instructors** — to interact with courses.  
Students can **view available courses**, **enroll in courses**, and **view their own enrollments**, while instructors can **create courses** and **view all created courses**.  
All user, course, and enrollment information is saved in and loaded from text files, allowing persistence across sessions.

---

## Implementation

The project was implemented in **C** using a structured and modular approach.  
It uses `structs` to define **User**, **Course**, and **Enrollment** entities, and manages them using **dynamic memory allocation** (`malloc`) and **file I/O** (`fopen`, `fscanf`, `fprintf`).  

### Key Features Implemented:
- **User Registration:** Users can register with their name, email, password, and role (student or instructor).
- **User Login:** Users can login with their email and password.
- **Role-Based Access:**
  - Students can:
    - View all available courses.
    - Enroll in a course.
    - View their enrolled courses.
  - Instructors can:
    - Create new courses.
    - View all courses.
- **Persistence:**
  - Registered users are saved to `users.txt`.
  - Courses are saved to `courses.txt`.
  - Enrollments are saved to `enrollments.txt`.
- **Utility Functions:** Screen clearing (`clearScreen`), pausing (`pause`), and menu navigation.

### Code Organization:

- **Data Structures:**  
  - `User`, `Course`, and `Enrollment` structs.
- **Global Variables:**  
  - Arrays for users, courses, and enrollments.
  - Current logged-in user pointer.
- **File Handling:**  
  - Functions to load and save users, courses, and enrollments.
- **Menu System:**  
  - Separate menus for students and instructors.

---

## Results

When the program runs, the following behaviors are observed:

1. **User Registration:**  
   Users can successfully register and their information is appended to `users.txt`.

2. **User Login:**  
   Users can login if their credentials match the data in `users.txt`.

3. **Instructor Flow:**
   - Create new courses by providing course titles.
   - Courses are listed properly with their IDs and the instructor's email.

4. **Student Flow:**
   - Students can view a list of available courses.
   - Students can enroll in a course by selecting its ID.
   - Students can view a list of courses they are enrolled in.

5. **Data Persistence:**  
   Data is retained across multiple runs through the use of external files.

---

## Conclusion

The **CourseMate** project successfully implements a basic course management system in C. It allows students to enroll in courses and instructors to create them, with data stored in external files.  
The project helped practice key concepts like **structs**, **dynamic memory**, and **file handling**.  
In the future, improvements like better input validation and fixing minor bugs could make the system even more reliable.

