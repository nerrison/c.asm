# *C & Assembly Repo*

## Introduction
This repository contains a set of  *C* and  *Assembly* programs for various programming exercises, covering arrays, strings, structures, file handling, algorithms, and basic assembly operations.

### Folder structure

---

**\> /c - contains all c programs**

 -arr_stats.c – Computes the smallest, largest, and average of an integer array.
 -array_statistics.c – Similar array statistics program .
 -book_records.c – Stores book details and saves each book to a separate file.
 -double_linked_list.c – Implements a doubly linked list with basic operations.
 -employee_record.c – Manages employee data and updates binary records.
 -employee_salary.c – Computes and saves total salaries for multiple employees.
 -hashtable.c – Implements a basic hash table (hashing and collision handling).
 -linked_list.c – Implements a single linked list with insertion, deletion, and traversal.
 -memory_inspection.c – Demonstrates stack vs heap memory, pointer behavior, and function scope.
 - palindrome_checker.c – Checks if words in a string are palindromes.
 - product_store.c – Stores and manages product details (name, price, quantity).
 - ring_buffer.c – Implements a circular buffer (queue) using an array.
 - running_sum.c – Continuously reads numbers and keeps a running sum.
 - sensor_log.c – Dynamically logs sensor data and computes sum, average, max, and min.
 - stack_demo.c – Demonstrates stack operations (push, pop, peek) using an array.
 - student_records.c – Manages student details, sorting by age, and saving to file.
 - temp_reading.c – Reads daily temperatures, computes average, and finds high/low values.
 - two_sum.c – Finds two array elements that sum to a target number.
 - vowel_counter.c – Counts vowels in a string and prints their position
 - debounce.c - simulation of debunce using rand() as mechanical input (0 1)
 - progress.c - simple progress bar
 - strdup_Implmnt.c - an implementation of strdup()

---

**\> assembly -  asm programs**

 1. boot_sum.asm - emphasizes that it’s a bootloader program that sums numbers.

---

### How to compile

***\> C Programs:***

- Compile

```bash
$ gcc program_name.c -o program_name
```
- Run

```bash
$ ./program_name
```

***\> Assembly Programs:***

- Assemble

```bash
$ nasm -f bin example.asm -o example.bin
```

- Run

```bash
$ qemu-system-x86_64 -fda boot_sum.bin
```

## Author
name : NERRISON
