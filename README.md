Citrine
Citrine is a C library that provides an interface for file and directory operations, including creation, reading, writing, removal, and manipulation of permissions and properties of files and directories. The library uses system calls directly to perform these operations, providing an efficient and straightforward way to handle files and directories on the system.

<br><br>

## Installation
To compile and install Citrine, you need to have CMake and NASM installed on your system. Follow the steps below:

- Clone the repository:
```bash
git clone https://github.com/Ismael-Moreira-Kt/Citrine
```

- If you want a preview of what the library can do:
```bash
cd Citrine
mkdir build
cd build
cmake ..
make
```

<br><br>

## Usage
To use the Citrine library in your project, include the citrine.h header and link with the library when compiling. For usage examples and information about the methods, visit the [documentation](./docs/English/C/README.md) and the [usage examples](./examples/).