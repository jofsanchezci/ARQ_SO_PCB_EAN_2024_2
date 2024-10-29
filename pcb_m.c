#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef enum {
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
} ProcessState;

typedef struct PCB {
    int processID;
    ProcessState state;
    int programCounter;
    int cpuRegisters[8];
    int priority;
    int memoryBase;
    int memoryLimit;
    char resources[50];
    struct PCB* next;  // Pointer to next PCB in the list
} PCB;

// Head of the PCB list
PCB* head = NULL;

// Function to create a new PCB and add it to the list
PCB* createPCB(int processID, int priority, int memoryBase, int memoryLimit, const char* resources) {
    PCB* newPCB = (PCB*)malloc(sizeof(PCB));
    newPCB->processID = processID;
    newPCB->state = NEW;
    newPCB->programCounter = 0;
    memset(newPCB->cpuRegisters, 0, sizeof(newPCB->cpuRegisters));
    newPCB->priority = priority;
    newPCB->memoryBase = memoryBase;
    newPCB->memoryLimit = memoryLimit;
    strncpy(newPCB->resources, resources, sizeof(newPCB->resources) - 1);
    newPCB->resources[sizeof(newPCB->resources) - 1] = '\0';
    newPCB->next = NULL;

    // Add to the list of PCBs
    if (head == NULL) {
        head = newPCB;
    } else {
        PCB* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPCB;
    }
    return newPCB;
}

// Function to change the state of a PCB
void changePCBState(PCB* pcb, ProcessState newState) {
    if (pcb != NULL) {
        pcb->state = newState;
    }
}

// Function to simulate a process execution
void executePCB(PCB* pcb) {
    if (pcb->state == READY || pcb->state == NEW) {
        pcb->state = RUNNING;
        printf("Process %d is now RUNNING\n", pcb->processID);
        pcb->programCounter += 1; // Simulate some execution
        sleep(1);  // Simulate time taken by process
        pcb->state = READY;
    }
}

// Function to display information about all PCBs
void displayAllPCBs() {
    PCB* temp = head;
    printf("\n--- PCB List ---\n");
    while (temp != NULL) {
        printf("Process ID: %d, State: %d, Program Counter: %d, Priority: %d\n", 
               temp->processID, temp->state, temp->programCounter, temp->priority);
        temp = temp->next;
    }
    printf("----------------\n");
}

// Function to simulate process scheduling (Round Robin)
void scheduleProcesses() {
    PCB* temp = head;
    while (temp != NULL) {
        if (temp->state == READY || temp->state == NEW) {
            executePCB(temp);
        }
        temp = temp->next;
    }
}

int main() {
    // Create several processes
    createPCB(1, 5, 1000, 2000, "Disk");
    createPCB(2, 3, 2000, 3000, "Network");
    createPCB(3, 4, 3000, 4000, "I/O");
    createPCB(4, 2, 4000, 5000, "CPU");

    // Initialize all processes to READY state
    PCB* temp = head;
    while (temp != NULL) {
        changePCBState(temp, READY);
        temp = temp->next;
    }

    // Display initial states
    displayAllPCBs();

    // Simulate process scheduling and execution
    for (int i = 0; i < 3; i++) {  // Run 3 cycles
        printf("\n--- Scheduling Cycle %d ---\n", i + 1);
        scheduleProcesses();
        displayAllPCBs();
    }

    // Free all PCBs
    temp = head;
    while (temp != NULL) {
        PCB* nextPCB = temp->next;
        free(temp);
        temp = nextPCB;
    }

    return 0;
}
