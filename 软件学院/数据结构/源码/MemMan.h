// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Memory Manager abstract class
class MemManager {
public:
  virtual ~MemManager() {} // Base destructor

  // Store a record and return a handle to it
  virtual MemHandle insert(void* info, int length) =0;

  // Get back a copy of a stored record
  virtual int get(void* info, MemHandle h) =0;

  // Release the space associated with a record
  virtual void release(MemHandle h) =0;
};
