The above Binary_Tree.c program aims to implement a simple binary tree

Firstly we define a structure called Node
where it has a value and two pointers known left and right for the proper orientation of a binary tree.

The fucntion we encounter in the driver funcction is that initializeTree(rootData,leftData,rightData)

This fucntion aims to create a simple binary tree structure which is 
    10
   / \
  5   15
Firstly we have initailzed the root pointer to NULL and call the newNode() function which creates a new node which the value of the root node being rootData and we also part for the left and right 

After the basic structure of the tree is created we have the choice to add an element to the left hand side of the tree or to the right hand side of the tree
i.e we have an element the we which to add to the left side of the tree then the resulting tree would look like 

    10
   / \
  5   15
 / \
4   NULL

and if we wish to add the data 4 to the right hand side of the tree then the tree would look like

    10
   / \
  5   15
     /  \
    4    NULL

Here we can add element to the either left handside or the right handside of the tree but the added element should also follow the propery of the binary tree which is 
"If the value is lesser than the root node then add to the lefthand side else to right hand side "
"
Here since is lesser than both 5 and 15 so it gets added to the left handside w.r.to the 5 and  5 which are now considered to be the root node. 
