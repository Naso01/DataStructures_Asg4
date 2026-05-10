# DataStructures_Asg4

A small C++ / Visual Studio 2022 console application that demonstrates classic
sorting algorithms operating on a list of `Student` records. The project was
built as Assignment 4 for a Data Structures course.

The program defines a simple `Student` class, populates a `std::vector` with a
handful of sample students, and exposes a static `SortingAlgorithms` utility
class that implements bubble, insertion, selection, merge, and quick sort.

---

## Project structure

```
DataStructuresAsg4/
├── DataStructures_Asg4.sln                  Visual Studio solution
├── .gitattributes
├── .gitignore                               Standard VS / C++ ignores
└── DataStructures_Asg4/
    ├── DataStructures_Asg4.vcxproj          MSBuild project file
    ├── DataStructures_Asg4.vcxproj.filters  VS source-tree filters
    ├── main.cpp                             Program entry point
    ├── Student.h                            Student class declaration
    ├── Student.cpp                          Student class implementation
    └── SortingAlgorithms.h                  Header-only sort utility class
```

| File | Purpose |
| --- | --- |
| [DataStructures_Asg4.sln](DataStructures_Asg4.sln) | Top-level Visual Studio 2022 solution. |
| [DataStructures_Asg4/main.cpp](DataStructures_Asg4/main.cpp) | Builds a `vector<Student>` of 8 sample students and prints them. |
| [DataStructures_Asg4/Student.h](DataStructures_Asg4/Student.h) | Declares the `Student` record (id, name, GPA, enrollment year). |
| [DataStructures_Asg4/Student.cpp](DataStructures_Asg4/Student.cpp) | Implements `Student`'s constructor and `Display()`. |
| [DataStructures_Asg4/SortingAlgorithms.h](DataStructures_Asg4/SortingAlgorithms.h) | Header-only `SortingAlgorithms` class containing all sort routines. |

---

## Build & run

Requirements: **Visual Studio 2022** with the *Desktop development with C++*
workload (any toolset that supports C++17 or later is fine). The project has
**no external dependencies** beyond the C++ Standard Library.

1. Open `DataStructures_Asg4.sln` in Visual Studio 2022.
2. Pick a configuration, e.g. `Debug | x64` or `Release | x64`.
3. Build the solution with `Ctrl+Shift+B`.
4. Run with `F5` (debug) or `Ctrl+F5` (run without debugging).

The program prints each student's id, name, GPA, and enrollment year to the
console.

---

## The `Student` class

Defined in [DataStructures_Asg4/Student.h](DataStructures_Asg4/Student.h) and
implemented in [DataStructures_Asg4/Student.cpp](DataStructures_Asg4/Student.cpp).

```cpp
class Student {
public:
    Student(int _id, string _name, double _gpa, int _enrollmentYear);
    virtual ~Student() {}

    int    GetId();
    string GetName();
    double GetGPA();
    int    GetEnrollmentYear();

    void Display();

private:
    int    m_id;
    string m_name;
    double m_gpa;
    int    m_enrollmentYear;
};
```

Project naming convention (used throughout):

- Method/function parameters are prefixed with `_` (e.g. `_id`, `_name`).
- Class member variables are prefixed with `m_` (e.g. `m_id`, `m_gpa`).

`Display()` prints the four fields surrounded by separator lines.

---

## `main.cpp` walkthrough

[DataStructures_Asg4/main.cpp](DataStructures_Asg4/main.cpp)

1. Creates a `std::vector<Student> studentList`.
2. Pushes 8 hard-coded sample students (intentionally out of id order so the
   list can be sorted later).
3. Calls `SortingAlgorithms::printArray(studentList)` which iterates the vector
   and invokes `Student::Display()` on each element.

> Note: the file currently only **prints** the list. The sort routines in
> `SortingAlgorithms` are defined but are not yet invoked from `main`; uncomment
> a call such as `SortingAlgorithms::bubbleSort(studentList);` before
> `printArray` to see the GPA-sorted output.

---

## Data structures used

| Data structure | Where | Notes |
| --- | --- | --- |
| `std::vector<Student>` | [main.cpp](DataStructures_Asg4/main.cpp), `bubbleSort`, `printArray` | Dynamic, contiguous-memory array of `Student` records. Provides O(1) random access and amortised O(1) `push_back`. |
| `std::vector<int>` | `insertionSort`, `selectionSort`, `mergeSort`, `merge`, `quickSort`, `quickSortHelper`, `partition` | Same dynamic array, used as the generic input for the integer sort routines. |
| `Student` (user-defined class) | Throughout | A record / aggregate bundling `int id`, `string name`, `double gpa`, `int enrollmentYear` with accessors. Acts as the element type sorted by `bubbleSort`. |
| Auxiliary `std::vector<int>` halves | Inside `mergeSort` | Out-of-place merge buffer: each recursive call allocates two halves (`left`, `right`), giving merge sort its O(n) extra-space requirement. |
| Recursion / call stack | `mergeSort`, `quickSortHelper` | Implicit data structure used to drive the divide-and-conquer recursion (O(log n) average depth for quick sort, O(log n) for merge sort). |

---

## Sorting algorithms

All algorithms live in
[DataStructures_Asg4/SortingAlgorithms.h](DataStructures_Asg4/SortingAlgorithms.h)
as `static` members of the `SortingAlgorithms` class.

| Algorithm | Container | Best | Average | Worst | Extra space | Stable | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `bubbleSort` | `vector<Student>` | O(n) | O(n^2) | O(n^2) | O(1) | yes | Sorts ascending **by GPA**. Uses a `swapped` flag for early exit when the vector becomes sorted. |
| `insertionSort` | `vector<int>` | O(n) | O(n^2) | O(n^2) | O(1) | yes | Builds the sorted prefix one element at a time by shifting larger items right. |
| `selectionSort` | `vector<int>` | O(n^2) | O(n^2) | O(n^2) | O(1) | no | Repeatedly selects the minimum element of the unsorted suffix and swaps it to the front. |
| `mergeSort` (+ `merge`) | `vector<int>` | O(n log n) | O(n log n) | O(n log n) | O(n) | yes | Classic divide-and-conquer. Splits the vector into two halves, recursively sorts each, and merges them with the helper `merge`. |
| `quickSort` (+ `quickSortHelper`, `partition`) | `vector<int>` | O(n log n) | O(n log n) | O(n^2) | O(log n) stack | no | In-place sort using **median-of-three pivot selection** and a two-pointer Hoare-style partition. |

The header keeps two earlier `partition` implementations in commented-out blocks
for reference:

1. A simple **last-element pivot** Lomuto-style partition.
2. A **median-of-three pivot** combined with a Lomuto-style partition.

The active version (used by `quickSort`) combines median-of-three pivot
selection with a two-pointer partition that better matches the paradigm
discussed in class.

`printArray(const vector<Student>&)` is a small utility that walks the vector
and calls `Student::Display()` on each element.

---

## Notes & known limitations

- The integer sort routines (`insertionSort`, `selectionSort`, `mergeSort`,
  `quickSort`) are written against `std::vector<int>` rather than the
  `Student` type. Only `bubbleSort` currently operates on `vector<Student>`
  (sorting by GPA).
- `main` does not yet call any sorting routine, it only prints the unsorted
  list.
- `SortingAlgorithms.h` places the `#endif` of its include guard above the
  `#include`s; functionally harmless because the file is only included once
  per translation unit here, but worth tightening if the file is reused.

### Possible extensions

- Templatise the sort routines on `T` (or accept a comparator) so all five
  algorithms can sort `vector<Student>` by any field.
- Add a small interactive menu in `main` to choose which algorithm to run.
- Add timing instrumentation to compare algorithms on larger generated
  datasets.

---

## Author

Project owner: [@Naso01](https://github.com/Naso01) -
[DataStructures_Asg4 on GitHub](https://github.com/Naso01/DataStructures_Asg4).
