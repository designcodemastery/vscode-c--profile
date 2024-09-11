# vscode-cplusplus-profile

Repository for creating the VS Code Profile for C++ and testing it with a basic C++ application.

Here are the following steps I used to create thsi VSCode Profile.

Setting up a C++ development environment in VS Code with CMake and Ninja involves a few key extensions and configuration steps.

## Steps to Set Up the C++ Development Profile with CMake and Ninja:

### 1. Create a New Profile:
- Open the Command Palette (**Ctrl+Shift+P** or **Cmd+Shift+P**).
- Search for "***Profiles: Create Profile.***"
- Name the profile something like "***C++ Development with CMake & Ninja.***"

### 2. Install the Required Extensions:
You'll need a few extensions to work efficiently with C++, CMake, and Ninja in VS Code.

#### Key Extensions:

- C/C++: Provides rich C++ IntelliSense, debugging, and code navigation support.
  - Extension ID: **ms-vscode.cpptools**
- CMake Tools: Allows you to manage your CMake projects within VS Code. It helps in configuring, building, and debugging C++ projects using CMake.
  - Extension ID: **ms-vscode.cmake-tools**
- CMake: Adds syntax highlighting for CMake files (CMakeLists.txt).
  - Extension ID: **twxs.cmake**
- Ninja: This is not an extension but an external tool. Ensure Ninja is installed on your system and available in your system's PATH. Ninja is required for fast builds in combination with CMake.

#### Optional Extensions:

- CMake Formatter: Provides formatting support for CMake scripts.
  - Extension ID: **zheeeng.cmake-formatter**
- Clang-Format: Code formatting tool for C++.
  - Extension ID: **xaver.clang-format**

##### Installation Steps:

- Go to the Extensions view (**Ctrl+Shift+X** or **Cmd+Shift+X**).
- Search for and install the above extensions by name or using their extension ID.

### 3. Install CMake and Ninja:
You’ll need to install CMake and Ninja on your system:

- CMake: [CMake Download]()
- Ninja: [Ninja Build System]()

After installation, make sure both CMake and Ninja are accessible from your system’s terminal by running **cmake --version** and **ninja --version** to verify installation.

### 4. Configure CMake Tools Extension:
The CMake Tools extension integrates with CMake and allows you to configure, build, and debug C++ projects using various build systems, including Ninja.

#### Steps:

  - Open the Command Palette (**Ctrl+Shift+P**) and search for "***CMake: Quick Start***" to create a basic CMake project if you don’t already have one.
  - In your project folder, ensure you have a **CMakeLists.txt** file. This file contains the configuration instructions for CMake.
  - Open the Command Palette and run "***CMake: Configure***". The first time you run this, you’ll be prompted to choose a ***CMake generator***.
    - Choose Ninja as the generator.
  - You can now use the CMake Tools extension to build your project by running the "***CMake: Build***" command.
  - To configure the build directory, environment variables, and more, you can customize **.vscode/settings.json** in your project folder:
```json
{
    "cmake.generator": "Ninja",
    "cmake.buildDirectory": "${workspaceFolder}/build",
    "cmake.configureOnOpen": true,
    "cmake.buildArgs": ["--target", "all"]
}
```

### 5. Configure the Debugger:
The C++ extension provides integrated debugging support using ***gdb*** or ***lldb***.

#### Steps:

- After configuring CMake, you can set up a debugger by defining launch configurations in **.vscode/launch.json**:
```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "C++ Debug",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}/build/<your_executable>",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "build",
      "miDebuggerPath": "/usr/bin/gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "stopAtEntry": false,
      "miDebuggerArgs": "",
      "sourceFileMap": {
        "/build/glibc/glibc-2.31/": "/usr/src/glibc-2.31/"
      },
      "externalConsole": false,
      "pipeTransport": {
        "pipeCwd": "",
        "pipeProgram": "",
        "pipeArgs": []
      }
    }
  ]
}
```
- This will allow you to build and debug your C++ projects directly in VS Code.

### 6. Test the Profile:
-  a small C++ project with **CMakeLists.txt**.
- Use CMake and Ninja to configure and build the project.
- Test the build process by running the "***CMake: Build***" command.
- Set breakpoints and use the debugger to verify that debugging works properly.

### 7. Export and Save the Profile:
Once you have verified the configuration, you can export this profile and push it to your GitHub repository.

---