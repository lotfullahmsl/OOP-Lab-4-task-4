#include <iostream>
#include <list>
#include <string>

using namespace std;

class ToDoList {
private:
    string taskName;
    list<ToDoList> subTasks;

public:
    ToDoList(const string& name) : taskName(name) {}

    void addSubTask(const string& subTaskName) {
        subTasks.push_back(ToDoList(subTaskName));
    }

    void addSubTask(const ToDoList& subTask) {
        subTasks.push_back(subTask);
    }

    void display(int level = 0) const {
        for (int i = 0; i < level; ++i)
            cout << "  ";
        cout << taskName << endl;
        for (const auto& subTask : subTasks) {
            subTask.display(level + 1);
        }
    }
};

int main() {
    ToDoList myToDoList("Main Task");

    ToDoList task1("Task 1");
    task1.addSubTask("Task 1.1");
    task1.addSubTask("Task 1.2");
    task1.addSubTask("Task 1.3");
    myToDoList.addSubTask(task1);

    ToDoList task2("Task 2");
    task2.addSubTask("Task 2.1");
    task2.addSubTask("Task 2.2");
    task2.addSubTask("Task 2.3");
    myToDoList.addSubTask(task2);

    ToDoList task3("Task 3");
    task3.addSubTask("Task 3.1");
    task3.addSubTask("Task 3.2");
    task3.addSubTask("Task 3.3");
    myToDoList.addSubTask(task3);

    myToDoList.display();

    return 0;
}
