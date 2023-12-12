# TED-Talks-Analyzer-
# TED Talks Information System

This C++ program reads TED Talks information from a file and provides an interactive interface for users to query talk entries.

## Functionalities

1. **Load Talks File**
   - Load talk entries from a specified file.
   - If the file doesn't exist, the program continues running, and users can choose other options.
   - The file format is assumed to be consistent (duration, talk title, overview, ---).
   - File format example: `duration talk_title overview ---`

2. **List Talks Sorted by Duration**
   - List talk entries from shortest to longest duration.
   - Talks with the same duration can appear in any order within that duration.

3. **List Talks Sorted by Title**
   - List talk entries sorted by title using `strcmp`.
   - Talks with the same title can appear in any order within that title.

4. **Lookup a Talk**
   - Prompt the user for a talk title (case-sensitive) and report all entries containing the input as a substring.
   - Print all information for the found entries.
   - If no entry is found, print "No such talk on record."

5. **Add a Talk**
   - Ask the user for duration, talk title, and overview to add a new talk entry.
   - Check for invalid duration (hours < 0, minutes/seconds < 0 or >= 60) and prompt for valid input.
   - Report "Entry added" after successful addition.

6. **Save Talks File**
   - Ask the user for the name of a file to save the current entries.
   - The existing file can be overwritten.
   - Report the number of entries saved.

7. **Terminate the Program**
   - Thank the user and end the program.

## Requirements

- Use the provided header files (`a4_talklib.hpp` and `a4_talkList.hpp`) and corresponding implementation files.
- Utilize the `Talk` struct defined in `a4_talklib` and the `vector` template in C++ to store talk information.
- No memory leaks; use `new` and `delete` for memory management.
- Follow C++ conventions for console I/O, file I/O, and text manipulation.

## Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/repo.git
   cd repo
   make
   ./test1


