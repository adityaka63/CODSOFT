#include <iostream>
#include <vector>

using namespace std;

class ToDoList {
public:
    void addTask(const string& task) {
        tasks.push_back({task, false}); // Initialize tasks as not completed
        cout << "Task '" << task << "' added successfully!" << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks found." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". ";
                if (tasks[i].second) {
                    cout << "[X] ";
                } else {
                    cout << "[ ] ";
                }
                cout << tasks[i].first << endl;
            }
        }
    }

    void deleteTask(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
            string deletedTask = tasks[taskIndex - 1].first;
            tasks.erase(tasks.begin() + taskIndex - 1);
            cout << "Task '" << deletedTask << "' deleted successfully!" << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void markAsCompleted(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
            tasks[taskIndex - 1].second = true;
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

private:
    vector<pair<string, bool>> tasks; // Use a pair to store tasks and their completion status
};

int main() {
    ToDoList todoList;

    while (true) {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Mark Task as Completed" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter the task: ";
                cin.ignore();
                getline(cin, task);
                todoList.addTask(task);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                todoList.viewTasks();
                int taskIndex;
                cout << "Enter the task index to delete: ";
                cin >> taskIndex;
                todoList.deleteTask(taskIndex);
                break;
            }
            case 4: {
                todoList.viewTasks();
                int taskIndex;
                cout << "Enter the task index to mark as completed: ";
                cin >> taskIndex;
                todoList.markAsCompleted(taskIndex);
                break;
            }
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
