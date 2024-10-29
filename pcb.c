#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de constantes para el estado del proceso
typedef enum {
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
} ProcessState;

// Estructura del Process Control Block (PCB)
typedef struct {
    int processID;           // Identificador único del proceso
    ProcessState state;      // Estado actual del proceso
    int programCounter;      // Contador de programa
    int cpuRegisters[8];     // Registros simulados de la CPU (8 en este ejemplo)
    int priority;            // Prioridad del proceso
    int memoryBase;          // Dirección base de memoria
    int memoryLimit;         // Límite de memoria
    char resources[50];      // Recursos utilizados (ejemplo)
} PCB;

// Función para inicializar un PCB
PCB* initializePCB(int processID, int priority, int memoryBase, int memoryLimit, const char* resources) {
    PCB* pcb = (PCB*)malloc(sizeof(PCB));
    pcb->processID = processID;
    pcb->state = NEW;
    pcb->programCounter = 0;
    memset(pcb->cpuRegisters, 0, sizeof(pcb->cpuRegisters)); // Inicializa registros en 0
    pcb->priority = priority;
    pcb->memoryBase = memoryBase;
    pcb->memoryLimit = memoryLimit;
    strncpy(pcb->resources, resources, sizeof(pcb->resources) - 1);
    pcb->resources[sizeof(pcb->resources) - 1] = '\0'; // Asegura terminación de cadena
    return pcb;
}

// Función para cambiar el estado de un PCB
void changePCBState(PCB* pcb, ProcessState newState) {
    if (pcb == NULL) return;
    pcb->state = newState;
}

// Función para mostrar la información del PCB
void displayPCBInfo(const PCB* pcb) {
    if (pcb == NULL) return;
    printf("Process ID: %d\n", pcb->processID);
    printf("State: %d\n", pcb->state);
    printf("Program Counter: %d\n", pcb->programCounter);
    printf("Priority: %d\n", pcb->priority);
    printf("Memory Base: %d\n", pcb->memoryBase);
    printf("Memory Limit: %d\n", pcb->memoryLimit);
    printf("Resources: %s\n", pcb->resources);
    printf("CPU Registers: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", pcb->cpuRegisters[i]);
    }
    printf("\n");
}

// Función para liberar el PCB
void freePCB(PCB* pcb) {
    if (pcb != NULL) {
        free(pcb);
    }
}

int main() {
    // Inicialización de un PCB de ejemplo
    PCB* pcb1 = initializePCB(1, 5, 1000, 2000, "Disk, Network");

    // Mostrar información del PCB
    printf("Initial PCB Information:\n");
    displayPCBInfo(pcb1);

    // Cambiar el estado del proceso a READY
    changePCBState(pcb1, READY);
    printf("\nAfter changing state to READY:\n");
    displayPCBInfo(pcb1);

    // Liberar memoria del PCB
    freePCB(pcb1);

    return 0;
}
