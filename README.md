# add-two-numbers-leet-code-
question is-
            You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and               each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

            You may assume the two numbers do not contain any leading zero, except the number 0 itself.
            
This question is based on basic Linked List opreation with some Logic that how you extract the values from Linked List 
and than how to store the result to the new resultant Linked List.

The brute force for this is -
  1. Take first List and then extract each element.
  2. Make it a fully number.
  3. Do it for second list.
  4. Add that two numbers.
  5. Spilt the added numbers and store it to resultant List.
  
  The Time Complexity is O(m+n+l) 
 as it uses 3 loop. 
 check in ADDTWONUMBER.CPP
 
The Best Solution is-
  1. To take first node and extract the data part and plus that part .
  2. If it is greater than 10 than store 1 to carry for next calculation.
  3. Then Store the sum to the end of the List.
  4. Doit until both reach their ends.
  
  The Time Complexity is O(n);
  Only 1 loop is used.
