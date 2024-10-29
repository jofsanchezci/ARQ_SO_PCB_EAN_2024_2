# Fisrt. Process Control Block (PCB) Implementation in C

This project provides a basic implementation of a **Process Control Block (PCB)** in C. The PCB is a critical data structure in operating systems, containing all necessary information about a process for it to be managed and scheduled by the OS.

### Overview

In this example, we create a simple PCB structure in C to represent and manage processes. The PCB structure includes essential fields such as process ID, state, priority, CPU registers, and memory allocation details. This code includes functions to initialize, change the state of, display, and free memory of a PCB.

### Components

- **`enum ProcessState`**: Represents the possible states of a process:
  - `NEW`: Newly created process.
  - `READY`: Process ready to execute.
  - `RUNNING`: Process currently executing.
  - `WAITING`: Process waiting for resources.
  - `TERMINATED`: Process completed or terminated.

- **`struct PCB`**: Defines the PCB structure with the following fields:
  - `processID`: Unique identifier for each process.
  - `state`: Current state of the process.
  - `programCounter`: Simulated program counter for tracking the process execution.
  - `cpuRegisters`: Array of integers simulating CPU registers (8 in this example).
  - `priority`: Process priority level.
  - `memoryBase` and `memoryLimit`: Base address and memory limit allocated to the process.
  - `resources`: A string representing resources used by the process, like disk or network.

### Functions

1. **`initializePCB`**:
   - Initializes a PCB with provided values for process ID, priority, memory base, memory limit, and resources.
   - Sets the initial state to `NEW`, resets the program counter to 0, and clears the CPU registers.
   - Returns a pointer to the created PCB.

2. **`changePCBState`**:
   - Changes the state of the PCB to a new specified state.
   - Takes a pointer to the PCB and the new state as parameters.

3. **`displayPCBInfo`**:
   - Displays all information about a PCB, including process ID, state, program counter, priority, memory boundaries, resources, and CPU registers.
   - Useful for debugging and monitoring.

4. **`freePCB`**:
   - Frees the allocated memory for a PCB to prevent memory leaks.
   - Takes a pointer to the PCB and releases its memory.

### Code Example

Here’s an example of how to use the functions in `main`:

```c
int main() {
    // Initialize a sample PCB with process ID 1, priority 5, memory base 1000, memory limit 2000, and resources
    PCB* pcb1 = initializePCB(1, 5, 1000, 2000, "Disk, Network");

    // Display initial PCB information
    printf("Initial PCB Information:\n");
    displayPCBInfo(pcb1);

    // Change the state of the process to READY
    changePCBState(pcb1, READY);
    printf("\nAfter changing state to READY:\n");
    displayPCBInfo(pcb1);

    // Free PCB memory
    freePCB(pcb1);

    return 0;
}
```

# Second. PCB (Process Control Block) Management in C

This project demonstrates a simple implementation of multiple **Process Control Blocks (PCBs)** in C to simulate process management within an operating system. Each PCB represents an individual process with attributes such as ID, state, priority, program counter, and resources. This program also includes a basic Round Robin scheduling mechanism to simulate context switching between processes.

## Features

1. **PCB Creation**: The program initializes multiple PCBs with predefined attributes.
2. **State Management**: Each PCB can change its state, simulating different stages in a process lifecycle (e.g., `NEW`, `READY`, `RUNNING`, `WAITING`, `TERMINATED`).
3. **Round Robin Scheduling**: A simple scheduling algorithm cycles through processes, executing each one sequentially and simulating context switching.
4. **Process Execution Simulation**: Each process "executes" by incrementing its program counter and briefly entering the `RUNNING` state before returning to `READY`.
5. **Memory Management**: The program frees all allocated memory for each PCB at the end of the execution to prevent memory leaks.

## Program Structure

### 1. `ProcessState` Enum

Defines the possible states of a process:
- `NEW`: Process has just been created.
- `READY`: Process is ready to be executed.
- `RUNNING`: Process is currently being executed.
- `WAITING`: Process is waiting for a resource.
- `TERMINATED`: Process has completed or been terminated.

### 2. `PCB` Structure

The `PCB` struct simulates a Process Control Block and contains:
- `processID`: Unique identifier for each process.
- `state`: Current state of the process.
- `programCounter`: Simulated program counter to track the process execution.
- `cpuRegisters`: Array of integers representing CPU registers (8 registers in this example).
- `priority`: The priority level of the process.
- `memoryBase` and `memoryLimit`: Base address and limit of memory allocated to the process.
- `resources`: String representing resources required by the process.
- `next`: Pointer to the next PCB, allowing multiple PCBs to be organized in a linked list.

### 3. Functions

- **`createPCB`**: Initializes a new PCB with specified values, sets its state to `NEW`, and adds it to the list of PCBs.
- **`changePCBState`**: Changes the state of a PCB, used to update process states during scheduling.
- **`executePCB`**: Simulates process execution. If the process is in `READY` or `NEW` state, it enters `RUNNING`, increments the program counter, and then returns to `READY`.
- **`displayAllPCBs`**: Prints details of each PCB, showing process information like ID, state, program counter, and priority.
- **`scheduleProcesses`**: Implements a Round Robin scheduler, executing each PCB in the list if it’s in the `READY` or `NEW` state.

### 4. Main Program Flow

1. **Initialize Processes**: Several PCBs are created with unique attributes for process ID, priority, memory allocation, and required resources.
2. **Set Initial State**: All PCBs are set to `READY`.
3. **Display PCB List**: The program displays details of all PCBs, including their initial states.
4. **Simulate Scheduling**: The program runs multiple scheduling cycles (3 in this example), executing each process in a Round Robin fashion.
5. **Display State Updates**: After each cycle, the program prints updated PCB details, showing the effect of the scheduler.
6. **Free Resources**: All allocated memory for PCBs is freed at the end of execution.

### Example Output

The output shows each process's state at each scheduling cycle:

```
--- PCB List ---
Process ID: 1, State: READY, Program Counter: 0, Priority: 5
Process ID: 2, State: READY, Program Counter: 0, Priority: 3
Process ID: 3, State: READY, Program Counter: 0, Priority: 4
Process ID: 4, State: READY, Program Counter: 0, Priority: 2
----------------

--- Scheduling Cycle 1 ---
Process 1 is now RUNNING
Process 2 is now RUNNING
Process 3 is now RUNNING
Process 4 is now RUNNING

--- PCB List ---
Process ID: 1, State: READY, Program Counter: 1, Priority: 5
Process ID: 2, State: READY, Program Counter: 1, Priority: 3
Process ID: 3, State: READY, Program Counter: 1, Priority: 4
Process ID: 4, State: READY, Program Counter: 1, Priority: 2
----------------

... (additional cycles) ...

```

### Compilation and Execution

To compile and run the program, use the following commands:

```bash
gcc pcb_simulation.c -o pcb_simulation
./pcb_simulation
```

## Notes

- **Round Robin Scheduling**: This is a simple form of scheduling where each process gets a turn. It cycles through all processes in the list, switching to the next one each time.
- **Memory Management**: The program frees each PCB after execution to avoid memory leaks, which is essential in long-running applications.
- **Simplified PCB**: This example provides a simplified PCB structure. A real-world operating system would use more complex data structures to store process information.

## Purpose

This code provides a foundational understanding of managing multiple processes through PCBs and simulates a basic OS scheduler. This implementation can be further extended with more complex scheduling algorithms or advanced PCB attributes.