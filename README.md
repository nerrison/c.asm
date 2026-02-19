# *C & Assembly Repo*

## Introduction
This repository contains a set of  *C* and  *Assembly* programs for various programming exercises, covering arrays, strings, structures, file handling, algorithms, and basic assembly operations.

### Folder structure

---

**\> /c - contains all c programs**

 1. arr_stats.c – Computes the smallest, largest, and average of an integer array.
 2. array_statistics.c – Similar array statistics program .
 3. book_records.c – Stores book details and saves each book to a separate file.
 4. double_linked_list.c – Implements a doubly linked list with basic operations.
 5. employee_record.c – Manages employee data and updates binary records.
 6. employee_salary.c – Computes and saves total salaries for multiple employees.
 7. hashtable.c – Implements a basic hash table (hashing and collision handling).
 8. linked_list.c – Implements a single linked list with insertion, deletion, and traversal.
 9. memory_inspection.c – Demonstrates stack vs heap memory, pointer behavior, and function scope.
 10. palindrome_checker.c – Checks if words in a string are palindromes.
 11. product_store.c – Stores and manages product details (name, price, quantity).
 12. ring_buffer.c – Implements a circular buffer (queue) using an array.
 13. running_sum.c – Continuously reads numbers and keeps a running sum.
 14. sensor_log.c – Dynamically logs sensor data and computes sum, average, max, and min.
 15. stack_demo.c – Demonstrates stack operations (push, pop, peek) using an array.
 16. student_records.c – Manages student details, sorting by age, and saving to file.
 17. temp_reading.c – Reads daily temperatures, computes average, and finds high/low values.
 18. two_sum.c – Finds two array elements that sum to a target number.
 19. vowel_counter.c – Counts vowels in a string and prints their position

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
