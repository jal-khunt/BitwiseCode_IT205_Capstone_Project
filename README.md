# BitwiseCode_IT205_Capstone_Project
This is our Capstone Project of course IT205 
<br>
BitwiseCode
<br>
manan
<br> 
jenish
shreyas
jal

## Work Distribution

### Jenish:
- **Responsibility:** Input file handling, returning an array wih all interpreted data from input file.

### Manan:
- **Responsibility:** Compares data in files to deterine which is deleted and which files are empty.

### Jal:
- **Responsibility:** Deleting files older than a certain date & file not accessed atleast M number of times.
  
### Shreyas:
- **Responsibility:**  CLI, redundancy of files with same name.



Class file created for storing file and its details

compare_file_older_months

comparison




# Class File

## Attributes:
- `path`: string
- `dateModified`: string
- `noOfTimeOpened`: integer

## Methods:
- `print()`: Prints the `path`, `dateModified`, and `noOfTimeOpened` attributes of the file.

# Class Date

## Attributes:
- `date`: integer
- `month`: integer
- `year`: integer

## Constructor:
- `Date(DateConvert)`: Parses `DateConvert` string to extract date, month, and year, and assigns parsed values to `date`, `month`, and `year` attributes.

# Pseudocode for Comparing Text Files

## Function `compareFiles(filePath1, filePath2)`:

- Open `file1` and `file2` for reading
- If either `file1` or `file2` cannot be opened:
  - Output error message
  - Return `false`
- Read content of `file1` into string `content1`
- Read content of `file2` into string `content2`
- Close `file1` and `file2`
- Return `true` if `content1` is equal to `content2`, otherwise `false`

## Function `compareAndDelete(files)`:

- Initialize an empty list `index`
- Initialize `count` as 0
- For each `file1` in `files`:
  - For each `file2` in `files` starting from next to `file1`:
    - If `compareFiles(file1.path, file2.path)` returns `true`:
      - Call `delete_file(files[j].path, j, files)` and store result in `del`
      - If `del` is 0, continue to the next iteration
      - Increment `count` by 1
      - Decrement `j` by 1 (to handle the case when a file is deleted)
- Return `count`

# Pseudocode for Deleting Empty Files

## Function `deleteEmptyFiles(files)`:

- Initialize `count` as 0
- For each `file` in `files`:
  - Open the file for reading
  - Read a string from the file
  - Close the file
  - If the size of the string is 0:
    - Call `delete_file(file.path, index, files)` and store result in `in`
    - Increment `count` by 1
    - If `in` is 0, continue to the next iteration
    - Decrement `index` by 1 (to handle the case when a file is deleted)
- Return `count`

# Pseudocode for Deleting Function

## Function `delete_file(file_to_be_deleted, index, F)`:

- Create a character array `f` with size equal to the length of `file_to_be_deleted` + 1
- Copy the characters of `file_to_be_deleted` into the character array `f`
- Set the last character of `f` as '\0' to terminate the string
- Open the `file_to_be_deleted` for reading
- If the file is successfully opened:
  - Close the file
  - If `index` is less than 0 or greater than or equal to the size of `F`:
    - Output "Invalid index"
  - Else:
    - Remove the File object at the specified index from vector `F`
    - Delete the file from the filesystem
    - Return 1 indicating successful deletion
- Else:
  - Output "File doesn't exist"
  - Return 0 indicating failure
- Return 0

# Pseudocode for Mtimes Function

## Function `lessThanMTimes(v, m)`:

- Initialize count as 0
- For each file f in vector v:
  - If f.noOfTimeOpened < m:
    - Call delete_file(f.path, index, v) and store result in del
    - Increment count by 1
    - Decrement index by 1
- Return count

# Pseudocode for Month Comparison 

## Function `dateComparison(dM, dT)`:

- If `dM.month` equals `dT.month` and `dM.year` equals `dT.year`:
  - Return 0
- Else if `dM.year` equals `dT.year`:
  - If `dT.date` is greater than `dM.date`:
    - Return `dT.month - dM.month`
  - Else if `dT.date` is less than `dM.date`:
    - Return `dT.month - dM.month - 1`
- Else:
  - If `dT.month` is greater than `dM.month`:
    - Calculate `yearMonth` as `(dT.year - dM.year) * 12`
    - Calculate `monthMonth` based on `dT.date` and `dM.date`
    - Return `yearMonth + monthMonth`
  - Else if `dT.month` is less than `dM.month`:
    - Calculate `yearMonth` as `(dT.year - dM.year - 1) * 12`
    - Calculate `monthMonth` based on `dT.date` and `dM.date`
    - Return `yearMonth + monthMonth`

## Function `compare_month(v, month, todaysDate)`:

- Initialize count as 0
- Create `todayDateObj` using `todaysDate`
- For each file `f` in vector `v`:
  - Create `lastModifiedDateObj` using `f.dateModified`
  - Calculate `diffMonth` using `dateComparison(lastModifiedDateObj, todayDateObj)`

# Main Function

## Steps:
1. Declare variables `s` (string), `testing` (integer), and `v` (vector of File objects).
2. Prompt the user with "testing?[1/0] " and read the input into variable `testing`.
3. If `testing` is true (non-zero):
   - Set `s` to "/home/shreyas/Desktop/testinput.txt".
4. Else:
   - Prompt the user with "Input file location: " and read the input into variable `s`.
5. Call `input_parser(v, s)` to parse the input file and set the vector `v`.
6. If the size of `v` is 0, output "Empty file provided." and end the program.
7. Output "File cleaner starting...".
8. Prompt the user with "Removing Old Files..\n\tRemove files older than (in months): " and read the input into variable `month`.
9. Prompt the user with "\tToday's date: " and read the input into variable `date`.
10. Output "\tRemoving files older than <month> months.".
11. Call `compare_month(v, month, date)` to remove files older than the specified month.
12. Output the number of files removed.
13. If `v` is empty, output "Folder is empty" and end the program.
14. Prompt the user with "Deleting unused/obsolete files:\n\tMinimum number of times a file should have been opened: " and read the input into variable `m`.
15. Call `lessThanMTimes(v, m)` to remove files that have been opened fewer than `m` times.
16. Output the number of files removed.
17. If `v` is empty, output "Folder is empty" and end the program.
18. Output "Checking for empty files and deleting them...".
19. Call `deleteEmptyFiles(v)` to delete any empty files in the vector `v`.
20. Output the number of empty files removed.
21. If `v` is empty, output "Folder is empty" and end the program.
22. Output "Removing duplicates...".
23. Call `compareAndDelete(v)` to remove duplicate files.
24. Output the number of duplicate files removed.
25. If `v` is empty, output "Folder is empty" and end the program.
26. Output "Program end".
27. End the program.


