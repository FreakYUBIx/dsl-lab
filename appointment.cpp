#include <iostream>
using namespace std;


struct Appointment {
    int start_time;   
    int end_time;     
    Appointment* next;
};


Appointment* createAppointment(int start, int end) {
    Appointment* newAppt = new Appointment();
    newAppt->start_time = start;
    newAppt->end_time = end;
    newAppt->next = nullptr;
    return newAppt;
}


void displayFreeSlots(Appointment* head, int day_start, int day_end, int min_duration) {
    Appointment* current = head;
    int previous_end = day_start;
    
    while (current != nullptr) {
        if (current->start_time - previous_end >= min_duration) {
            cout << "Free Slot: " << previous_end << " to " << current->start_time << endl;
        }
        previous_end = current->end_time;
        current = current->next;
    }
    
    if (day_end - previous_end >= min_duration) {
        cout << "Free Slot: " << previous_end << " to " << day_end << endl;
    }
}


void bookAppointment(Appointment*& head, int start, int end, int min_duration, int day_start, int day_end) {
    
    if (start < day_start || end > day_end || end - start < min_duration) {
        cout << "Invalid appointment time!" << endl;
        return;
    }
    
    
    Appointment* newAppt = createAppointment(start, end);

    
    if (head == nullptr || head->start_time > start) {
        newAppt->next = head;
        head = newAppt;
    } else {
        Appointment* current = head;
        while (current->next != nullptr && current->next->start_time < start) {
            current = current->next;
        }
        newAppt->next = current->next;
        current->next = newAppt;
    }
    cout << "Appointment booked from " << start << " to " << end << endl;
}


void cancelAppointment(Appointment*& head, int start, int end) {
    if (head == nullptr) {
        cout << "No appointments to cancel!" << endl;
        return;
    }

    Appointment* current = head;
    Appointment* previous = nullptr;

    while (current != nullptr) {
        if (current->start_time == start && current->end_time == end) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            cout << "Appointment canceled from " << start << " to " << end << endl;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "No matching appointment found to cancel!" << endl;
}


void sortAppointments(Appointment*& head) {
    if (head == nullptr) return;

    bool swapped;
    Appointment* ptr1;
    Appointment* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->start_time > ptr1->next->start_time) {
                
                swap(ptr1->start_time, ptr1->next->start_time);
                swap(ptr1->end_time, ptr1->next->end_time);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}


void sortAppointmentsPointerManipulation(Appointment*& head) {
    if (!head) return;

    Appointment* sorted = nullptr; 

    Appointment* current = head;
    while (current != nullptr) {
        Appointment* next = current->next;

        if (sorted == nullptr || sorted->start_time > current->start_time) {
            current->next = sorted;
            sorted = current;
        } else {
            Appointment* temp = sorted;
            while (temp->next != nullptr && temp->next->start_time < current->start_time) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    head = sorted;
}


void displayAppointments(Appointment* head) {
    if (head == nullptr) {
        cout << "No appointments booked." << endl;
        return;
    }
    Appointment* current = head;
    while (current != nullptr) {
        cout << "Appointment: " << current->start_time << " to " << current->end_time << endl;
        current = current->next;
    }
}


int main() {
    Appointment* schedule = nullptr;
    int day_start = 900; 
    int day_end = 1700;   
    int min_duration = 30; 

    int choice, start, end;

    do {
        cout << "\nMenu:\n";
        cout << "1. Display Free Slots\n";
        cout << "2. Book Appointment\n";
        cout << "3. Cancel Appointment\n";
        cout << "4. Display Appointments\n";
        cout << "5. Sort Appointments by Time (Simple Sort)\n";
        cout << "6. Sort Appointments by Time (Pointer Manipulation)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayFreeSlots(schedule, day_start, day_end, min_duration);
                break;
            case 2:
                cout << "Enter start time and end time (in 24-hour format): ";
                cin >> start >> end;
                bookAppointment(schedule, start, end, min_duration, day_start, day_end);
                break;
            case 3:
                cout << "Enter start time and end time (in 24-hour format) to cancel: ";
                cin >> start >> end;
                cancelAppointment(schedule, start, end);
                break;
            case 4:
                displayAppointments(schedule);
                break;
            case 5:
                sortAppointments(schedule);
                cout << "Appointments sorted by time (simple sort)." << endl;
                break;
            case 6:
                sortAppointmentsPointerManipulation(schedule);
                cout << "Appointments sorted by time (pointer manipulation)." << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}