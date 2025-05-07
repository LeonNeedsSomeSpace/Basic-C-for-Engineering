//Create a task queue for a machine that fulfills simple tasks
//It can operate the stored tasks in a normal mode where it carries out the tasks in the order that is given
//In reverse mode, however, the tasks are carried out in the opposite of the listed order

//This code is written in C++ instead of C as C++ is better for complex programs due to its object-oriented features 
#include <iostream>
#include <string>

//Set up the node structure
struct TaskNode { 
    std::string task;
    TaskNode* next;

    TaskNode(const std::string& t) : task(t), next(nullptr) {}
};

class TaskQueue {
private:
    TaskNode* head;

public:
    TaskQueue() : head(nullptr) {}

    void addTask(const std::string& task) {
        TaskNode* New = new TaskNode(task);
        New->next = head;
        head = New; 
    }

    void reverseList() {
        TaskNode* prev = nullptr;
        TaskNode* curr = head;
        TaskNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;   
            curr->next = prev;   
            prev = curr;        
            curr = next;        
        }

        head = prev;
    }

    void executeTasks() const {
        TaskNode* current = head;
        while (current != nullptr) {
            std::cout << "Executing: " << current->task << std::endl;
            current = current->next;
        }
    }

    ~TaskQueue() {
        while (head) {
            TaskNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    TaskQueue queue;

    //Create some tasks for the machine 
    queue.addTask("Move Forward");
    queue.addTask("Lower Arm");
    queue.addTask("Pick Object");

    //Make sure to write in the correct order
    std::cout << "=== FORWARD MODE ===" << std::endl;
    queue.reverseList(); 
    queue.executeTasks();

    //Reverse the list. Tasks get carried out in reverse order
    std::cout << "\n=== REVERSE MODE ===" << std::endl;
    queue.reverseList(); 
    queue.executeTasks();

    return 0;
}
