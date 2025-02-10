# 🚀 Mini-libc: A Minimalist Standard C Library Implementation

## 🌟 Overview
Welcome to **mini-libc**, a lightweight and freestanding implementation of the **standard C library** for Linux systems! This project is built from the ground up to replace the default system libc, relying solely on Linux system calls. By crafting a minimal yet functional libc, you'll dive deep into **string manipulation, memory management, and low-level file I/O** operations.

## 🎯 Objectives
- 🔍 Understand the structure and purpose of the **C standard library**
- 🏗️ Develop a **freestanding** implementation using only **syscalls**
- 📝 Implement fundamental **string and memory functions**
- 📂 Provide essential **file I/O and process utilities**
- ⚙️ Gain insights into **Linux syscall interfaces**

## 🔧 Core Features

### 📜 String Manipulation (`<string.h>`)  
Efficient string-handling functions:
- `strcpy()` / `strncpy()` ✅
- `strcat()` / `strncat()` ✅
- `strlen()` ✅
- `strcmp()` / `strncmp()` ✅
- `strstr()` / `strrstr()` ✅
- `memcpy()` / `memmove()` ✅
- `memset()` / `memcmp()` ✅

### 📝 Input/Output (`<stdio.h>`)
- `puts()` – Simple **string printing** via `syscall(__NR_write)` 📢

### 📂 File & Process Control (`<unistd.h>`, `<sys/fcntl.h>`, `<sys/stat.h>`)
Essential **POSIX-compliant file operations**:
- `open()` / `close()` 🔑
- `lseek()` 🔄
- `stat()` / `fstat()` 📊
- `truncate()` / `ftruncate()` ✂️

### ⏳ Time Utilities (`<time.h>`)  
- `nanosleep()` / `sleep()` 💤

### 🧠 Memory Management (`<stdlib.h>`, `<sys/mman.h>`)  
Lightweight **dynamic memory allocation**:
- `malloc()` / `free()` 🔄
- `calloc()` ✅
- `realloc()` / `reallocarray()` 🔧
- `mmap()` / `mremap()` / `munmap()` 🗂️

### 🚨 Error Handling (`<errno.h>`)  
- `errno` variable management for **system call failures** ❌

## 🏗️ Build & Installation
### 🔨 Compiling mini-libc
```bash
cd src/
make
```
### 📌 Compiling & Running Samples
```bash
cd samples/
make
./test_sample
```
### 🛠 Running Tests & Grading
```bash
cd tests/
./grade.sh
```
A successful run yields:
```bash
Checker: 90/90  🎯
Style: 10/10    ✅
Total: 100/100  🏆
```

## 🔍 Debugging & Validation
- Run **all tests**:
  ```bash
  ./run_all_tests.sh
  ```
- Test **individual components**:
  ```bash
  ./test_malloc_free.sh
  ./test_nanosleep.sh
  ```
- Run **static analysis & linters**:
  ```bash
  make lint
  ```

## 📚 Resources & References
- 🔗 [GNU libc manual](https://www.gnu.org/software/libc/manual/html_mono/libc.html)
- 🔗 [musl libc source](https://elixir.bootlin.com/musl/latest/source)
- 🔗 [Linux man pages](https://man7.org/linux/man-pages/index.html)

🚀 **Ready to build your own libc? Let's go!** 🛠️
