#pragma once
#include <string>

class Student {
public:
    Student(std::string name, std::string message)
        : name_(std::move(name)),
          message_(std::move(message)) {}
    
    Student(Student&&) = default;
    Student& operator=(Student&&) = default;
    
    const std::string& name() const { return name_; }
    const std::string& message() const { return message_; }
    
    private:
        std::string name_;
        std::string message_;
        Student(const Student&);
        Student& operator=(const Student&);
};