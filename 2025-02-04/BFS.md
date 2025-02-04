Eg: Tree
        10   -> First Level
       /  \
      5    15  -> Second Level 
     / \  /  \
    4   6 16  20 -> Third Level

Here we have create the above BST where we want to traverse through the tree by the Breadth First Search(BFS) traversal technique.

In BFS all the levels of a tree are printed when the next level and so on.
So the output of the above tree would be 10,5,15,4,6,16,20

For to obtain this result we use Queue i.e(FIFO) principle 

Q.Why Use a Queue?
A queue is essential because it helps us:
✅ Process nodes in order (first-in, first-out) → ensuring level-wise traversal.
✅ Keep track of unvisited child nodes while processing the parent node.
✅ Expand nodes in the correct sequence → visiting all neighbors before moving deeper.

The steps to achieve the BFS is
1.Enqueue the root element to the queue
2.Since the root element is visited we dequeue it and enqueue it's child nodes.
3.And we continue this process until all the levels are traversed.