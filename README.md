# PPP

My coursework and practice for **PPP (Princípios de Programação Procedimental / Procedural Programming Principles)**. This repository brings together C exercises organized by assignment and topic, along with a larger student-management project.

## Repository structure

- `Problemas/Problemas1`–`Problemas5`: assignment sheets and exercise solutions, grouped by topic and difficulty.
- `Problemas/Problemas2`: vectors.
- `Problemas/Problemas3`: pointers and examples of linked data structures.
- `Problemas/Problemas4`: queues, stacks, and linked lists.
- `Problemas/Problemas5`: text and binary file handling.
- `Problemas/Projeto2025-2026`: the course project, a menu-driven student and expense manager.

Most exercises are small, standalone C programs. The assignment PDFs are kept alongside the corresponding solutions.

## Course project

The project stores student records and their expenses using linked lists. Its menu supports adding and removing students, listing students, recording expenses, topping up a student's balance, viewing a student's expenses, and saving or loading records from binary files.

### Build and run

You need GCC and GNU Make. From the project directory:

```sh
cd Problemas/Projeto2025-2026
make
./Projeto2025-2026
```

The program reads and writes `dados.bin` and `despesas.bin` in its current working directory. Run it from `Problemas/Projeto2025-2026` so these files are created there. To remove the compiled executable and object files, run:

```sh
make clean
```
