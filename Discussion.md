The main issues are speed and memory efficiency because the log file is 1TB in size.  The many methods taken into consideration are listed below:

 1. The naïve (ineffective) approach
 Method: Fill memory with the entire file.
 Use list or std::vector<std::string> (C++). To save lines, use Python's add() function.
 Filter logs with the date of the search.
 Why Is It Ineffective?
  Memory-intensive:  RAM cannot accommodate a 1TB file.
 Slow:  Large volumes of data are inefficient to read, filter, and store.
  Unscalable:  would crash because to a memory overflow while dealing with huge files.

2. Efficient Line-by-Line Processing  Method:
 Use readline() (Python) or std::getline() (C++) to read the file line by line.
 Verify that the line begins with the specified date.
 Directly write the corresponding lines to an output file.
 Why Does It Work So Well?
 One line is kept in memory at a time, making it memory-efficient.
  Quick filtering: Avoids additional storage by writing matching logs straight to output.
  Scalable: Performs admirably with files larger than 1TB.
 This is the method used in the Python and C++ solutions.
3. A file that is memory-mapped (mmap)
 Method:
 To handle the file as an array in memory, use memory-mapped files.
 Use quick substring search (memchr or std::search) to scan and extract logs.
 Advantages:
  faster for huge files than standard file I/O.
  eliminates the need for system calls (such as fread and ifstream).

 Cons: Needs a lot of virtual address space, which 32-bit computers cannot provide.
  Partial file mappings have more difficult error handling.
  Unsuitable for all file systems and operating systems.
 Predictable search patterns and well-structured logs would be advantageous.



Line-by-Line Processing is the best option for this use case.
 The line-by-line method offers the optimum balance of simplicity, efficiency, and scalability given the limitations (big file, single machine, effective filtering).

 Additional Optimisations Potential:

 For small speedups, use buffered reading (std::ifstream::readsome()).
 For quicker lookups, combine with binary search (if logs are sorted).
 If you are reading from more than one disc, use parallel processing.




 How to Use the Log Extraction Solution in C++
 To efficiently compile and run the log extraction application, follow these steps.

 1 Prerequisites 
 Make sure you have the following C++ compilers before running the solution: MSVC, MinGW (Windows), or GCC (Linux/macOS).
 .  Log File: A sizable log file that is kept on your disc, such as large_log.txt.
 . Sufficient Storage: The output/directory will house the output file.

2 Compile the C++ application.
 Locate logs_extraction.cpp in the directory by opening a terminal (Linux/macOS) or Command Prompt (Windows).


3 Launch the Basic Usage Program by running sh Copy Edit./logs_extraction.cpp <log_file_path>. <YYYY-MM-DD>
All logs for the specified date are extracted and saved to output/output_YYYY-MM-DD.txt.

4.Check the Output
 Examine the created file by navigating to the output/directory:

 edit cat output/output_2024-12-01.txt, copying and editing
 Or use any text editor to open it.







