TEMPLATE = subdirs

SUBDIRS += \
    Student \
    Course \
    CourseTests \
    StudentTests

Student.depends = Course
CourseTests.depends = Course
CourseTests.depends = Student

StudentTests.depends = Student
