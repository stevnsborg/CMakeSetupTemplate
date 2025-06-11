# Documentation

The documentation is automatically generated using the "doxygen" tool.


## Literature

Following that the majority of **CERE** and **KTC** software tools are based on scientific research, it is important to ensure 


## Doxygen v.1.9.6

This project uses **Doxygen**, a powerful and widely adopted tool for generating API documentation from annotated C++ source code. The documentation system is tightly integrated with the CMake build process and is designed to produce clear, navigable, and maintainable documentation for the public interface of this shared library (DLL).

---

### How Documentation is Generated

The documentation is generated automatically via a CMake target. Both the `include/` and `src/` directories are scanned by Doxygen, which extracts documentation from structured comments in the source code and generates HTML output in the `docs/` directory in the binary after compiling the source code.

Doxygen is fetched from GitHub and executed as part of the build process — there is **no need for a local installation** of Doxygen on your system.

To generate the documentation, run the following code in the compiled binary folder:

```bash
cmake --build . --target doc
```

### Why Use Doxygen?

Doxygen is a powerful documentation tool tailored for C++ and ideal for shared libraries (.dll or .so). It provides significant benefits in terms of clarity, maintainability, and developer productivity.

#### 1. Public API Clarity

Doxygen helps communicate the structure and intent of the public API:

- Lists and documents public classes, methods, functions, and constants
- Describes parameters, return types, and usage
- Supports grouping related functionality into modules
- Automatically generates documentation indexes

This makes it easier for users of the library to understand how to use it without digging through the code.

---

#### 2. Documentation That Stays in Sync with Code

Unlike separate documentation systems (e.g., wikis or PDFs), Doxygen extracts comments directly from source files:

- Changes in code are automatically reflected in the documentation
- Minimizes risk of outdated or inconsistent documentation
- Build warnings notify you of undocumented functions or parameters

This ensures that documentation evolves along with the codebase.

---

#### 3. Clean, Structured, Navigable Output

Doxygen generates static HTML files that are:

- Fully navigable via sidebar, indexes, and cross-links
- Organized by files, classes, namespaces, and modules
- Enhanced with diagrams (class hierarchies, call graphs, etc.)
- Customizable and themeable

This results in a more professional and maintainable documentation set.

---

#### 4. Seamless Integration with CMake

In this project, Doxygen is fully integrated with the CMake build system:

- Automatically downloads Doxygen if not installed locally
- Can be built via a single command (`cmake --build . --target doc`)
- Ensures consistent output across platforms and developer machines
- Enables CI/CD deployment of updated documentation

No manual steps or tools are required beyond the build system.

---

#### 5. Improved Developer Productivity

Good documentation helps:

- Onboard new developers faster
- Reduce time spent answering common usage questions
- Avoid misuse of APIs or misunderstanding of behavior
- Accelerate debugging and integration with other systems

Even for internal teams, clear documentation leads to reduced friction and better collaboration.

---

#### 6. Designed for Libraries and DLLs

For shared libraries, Doxygen can:

- Focus only on public headers (hiding internal implementation)
- Create API documentation suitable for SDKs and external use
- Flag missing or incomplete documentation
- Support stable, versioned documentation output

This is particularly important for maintainers of reusable components or libraries intended for distribution.

---

### Summary

Using Doxygen to document this C++ shared library offers a number of long-term benefits for both internal development and external usage:

- **Clear, accurate API documentation** that reflects the current state of the codebase
- **Automation via CMake**, eliminating the need for manual steps or local installations
- **Professional, navigable output** in HTML format, ideal for distribution or hosting
- **Improved collaboration and onboarding**, thanks to consistent and accessible reference material
- **Reduced maintenance overhead**, by keeping documentation and code in sync
- **Better library usability**, especially when the API is consumed across teams, systems, or languages

In short, Doxygen turns structured source comments into a powerful, scalable documentation system — an essential part of building reliable and maintainable software libraries.

