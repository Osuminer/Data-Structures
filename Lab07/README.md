# Lab07

## Objective
The objective of this Lab is to create an implementation of a Heap and a Priority Queue.

## Task 1  Define Interface for PriorityQueue

1.	Make an interface for the PriorityQueue that will be inherited by the classes generated in Task 1 and Task 2.
2.	The following Methods should be on the class.  And make them pure virtual
*.	Insert – This will add an item to the priority queue
*.	DeQueue – This will remove the highest\lowest priority item from the queue 
*.	PrintPriorityQueue – This will print the items in the queue in priority order and return a string representation as well (so it can be used for testing).  

You can add more items if you desire - an IsEmpty seems like a good addition :)

## Task 2  Implement an ArrayBased PriorityQueue
1.	Create an implementation of a Priority Queue using a ArrayBasedQueue that uses brute force sorting.  Include the following members:
*.	Insert – 
*.	DeQueue – 
*.	PrintPriorityQueue –
1.	Create unit Tests for testing the array based implementation, at least 2 per method.
1.	In the lab report, discuss the advantages and disadvantages of this implementation 

## Task 3  Implement an HeapBased PriorityQueue
1.	Create an implementation of Priority Queue using a Heap.  Include the following members:
*.	Insert – 
*.	DeQueue – 
*.	PrintPriorityQueue –
1.	Create a unit Tests for testing the Heap based implementation at least 2 per method.
1.	In the lab report, discuss the advantages and disadvantages of this structure over a standard binary search tree.

## Task 4  Evaluate implementations
1.	Evaluate the performance of adding 500, 1,000, 2,000, and 5,000 random items to each of the ADT  built in this using the same techniques as the sorting lab.  Make sure the items being added are the same for each of the structures.  In the lab report, graph the results and discuss which structure performs which.
2.	Evaluate the performance of removing all of the items from step 1 for each of the 4 sets of data (remove 1 at a time, not all at once).  Make sure the items being added are the same for each of the structures.  In the lab report, graph the results and discuss which structure performs which.
3.	Graph the total time as well for a third graph, and discuss the performance.


# Task 5 Participation Rubric And Lab Report


Participation rubric of teammates.  List out for your all team members how much they participated.  This will go into your Lab report.
```
	             Member1	Member2	Member3
Member1 (opinion)	33	     33	     33
Member2 (opinion)	33	     33	     33
Member3 (opinion)	33	     33	     33
```			
			
Example 			
```
	             Member1	Member2	Member3
Member1 (opinion)	33	     33	     33
Member2 (opinion)	20	     40	     40
Member3 (opinion)	20	     40	     40
```

## Lab Submission

1.	Write a lab report including the requested information from the Tasks above.
2.	Include all source code and CMake file into a tar file

Lab Grading:
1.	25% - Task 1 has been correctly implemented. 
2.	25% - Task 2 has been correctly implemented. 
2.	25% - Task 3 has been correctly implemented. 
3.	25% - Task 4,5 has been correctly implemented.
If program fails to compile, 0% will be given for that Task.

