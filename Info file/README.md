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

Class file created for storing file and its details

compare_file_older_months

comparison

Manan 

# File Class

## Attributes:
- `path`: string
- `dateModified`: string
- `noOfTimeOpened`: integer

## Methods:
- `print()`: Prints the `path`, `dateModified`, and `noOfTimeOpened` attributes of the file.

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

