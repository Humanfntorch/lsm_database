Project will be a work-in-progress Log Structured Merge Tree database. 

## Initial Steps:
1.  Create Data Structure.
  ** Data structure will be represented as a node containing a buffer of generic key/value mapped pairs.
  ** Each node will have a predefined storage capacity (buffer array), allowing multiple key/value pairs (dependent on data size of KV-pairs).
  ** Buffer will remain sorted for each node.
  ** Once a buffer reaches max capacity, a new node will be created and a median value in the buffer will be chosen to represent the node (index node).
2. Create database structure.
  ** Database structure will be represented using a Binary Search Tree.
  ** Once tree reaches max size, tree will be flushed to disk and a new tree created.
  ** Tree will implment: Insertion, Deletion, Update, Search, and In-Order traversal for flushing to disk.


