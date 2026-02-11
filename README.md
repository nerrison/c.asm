# Programming Concepts Repository

## Overview

This repository contains multiple projects demonstrating core programming concepts, data structures, memory management, file handling, and low-level assembly programming.

Included projects:

- **Linked Lists** – Singly and doubly linked lists with insert, delete, search, and traversal operations.
- **Stack & Queue** – Fixed-size stack and circular buffer (queue) implementations.
- **File Handling** – Binary file operations for structured data (`Employee` records).
- **Array Statistics** – Heap memory allocation, pointer arithmetic, and array analytics (sum, average, max, min).
- **Memory Inspection** – Stack vs heap memory, pointers, and function-local variable scope.
- **Assembly Boot Sector** – Minimal x86 bootloader computing and displaying `5 + 10`.

---

## Project Details

### 1. Linked Lists

- **Singly Linked List**: Supports insertion at head/tail, deletion, search, and traversal.
- **Doubly Linked List**: Supports bidirectional traversal and deletion.
- Interactive menus allow testing all operations.

**Key Concepts:** `struct`, dynamic memory allocation, pointers, list traversal.

---

### 2. Stack & Queue

- **Stack**: Array-based stack with `push`, `pop`, `peek`, and `print`.
- **Circular Queue (Ring Buffer)**: Supports `enqueue`, `dequeue`, `peek`, and `print` using modular arithmetic.

**Key Concepts:** LIFO/FIFO principles, overflow/underflow handling, array indexing, modular arithmetic.

---

### 3. File Handling

- Reads and writes an array of `Employee` structs to a binary file.
- Updates a specific record using `fseek` and `fwrite`.
- Demonstrates reading and writing structured data in binary mode.

**Key Concepts:** `FILE` pointers, `fopen`, `fwrite`, `fread`, `fseek`, binary files, structs.

---

### 4. Array Statistics

- Allocates an integer array on the heap based on user input.
- Calculates sum, average, maximum, and minimum.
- Demonstrates pointer arithmetic for array access.

**Key Concepts:** Dynamic memory allocation (`malloc`/`free`), pointer arithmetic, array traversal, input validation.

---

### 5. Memory Inspection

- Demonstrates stack vs heap allocation.
- Uses pointers to reference stack and heap variables.
- Shows memory addresses and function-local variable scope.

**Key Concepts:** Stack vs heap, pointers, memory addresses, function-local variables.

---

### 6. Assembly Boot Sector (`main.asm`)

- Minimal x86 bootloader computing `5 + 10` and printing the result.
- Converts numeric result to ASCII for display using BIOS interrupt `0x10`.
- Includes proper boot sector padding and signature.

**Key Concepts:** x86 assembly, registers, division, ASCII conversion, BIOS interrupts, bootloader structure.

---

