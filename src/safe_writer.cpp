#include <iostream>
#include <fstream>
#include <memory>
#include <thread>
#include <mutex>
#include <vector>
#include "Student.hpp"

std::mutex fileMutex;

void studentWriteSafe(
    std::shared_ptr<std::ofstream> file,
    std::unique_ptr<Student> student)
{
    std::lock_guard<std::mutex> lock(fileMutex);
    (*file) << student->name() << ": " << student->message() << "\n";
}

int main() {
    auto file = std::make_shared<std::ofstream>("res/safe_file.txt");

    if (!file->is_open()) {
        std::cerr << "Failed to open file\n";
        return 1;
    }
    auto student1 = std::make_unique<Student>("Alice", "Hello from Alice, I just wanted to say that blah I like flowers but roses are ugly.");
    auto student2 = std::make_unique<Student>("Bob", "I can't wait for christmas. I like looking at the lights, it is the only thing that brings me joy");
    auto student3 = std::make_unique<Student>("Charlie", "Bob scares me sometimes");

    std::vector<std::thread> threads;
    threads.emplace_back(studentWriteSafe, file, std::move(student1));
    threads.emplace_back(studentWriteSafe, file, std::move(student2));
    threads.emplace_back(studentWriteSafe, file, std::move(student3));
        
    for (auto& t : threads)
        t.join();

    return 0;
}