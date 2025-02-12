### Red Black Tree

Red black trees are special case of Binary Trees where the construction and constitution of the tree 
follows several rules:
1) Each node has a color - red or black
2) Root node is always of color black
3) Two red nodes cannot be in a parent/child relationship
4) When inserting new node the color is always red
5) nullptrs are treated as nodes of color black
6) Number of black colored nodes is the same on each path in the tree

After inserting, if parent/child are both of color red actions need to be taken to form the tree
as per mentioned rules:
1) If the uncle of the inserted node is red:

    - change the color of uncle and parent to black
    - change the color of the grandparent to red (if grandparent is root, keep it black)

2) If the uncle is black, apply one of the rotations:

    - Left-left rotation
    - Right-right rotation
    - Left-right rotation
    - Right-left rotation 

Resources::
* Red Black Tree: https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
* For rotations: https://en.wikipedia.org/wiki/AVL_tree#Rebalancing

**Note**: Red black trees relate to the 2-3-4 trees.
