# Tree 

```text
       x
     /   \
    /     \
   x       x
  / \     / \
 x   x   x   x
/ \ / \ / 
x x x x x
```

## Terminology

| Root                                        | The first node. There must be only one root node.            |
| ------------------------------------------- | ------------------------------------------------------------ |
| Edge                                        | The connecting link between any two nodes. Max = **N-1**.    |
| Parent                                      | The node which has a branch from it to any other node.       |
| Child                                       | The node which is descendant of any node is called as.       |
| Siblings                                    | The nodes with the same parent are called Sibling nodes.     |
| Leaf / External / Terminal Node             | The node with no child.                                      |
| Internal / Non-External / Non-Terminal Node | The node with at least one child.                            |
| Degree                                      | The total number of children of a node.                      |
| Level                                       | Starts form 0 at root node and increases by 1 for each node. |
| Depth                                       | Root -> Node.                                                |
| Height                                      | Leaf -> Node.                                                |

>**Depth vs Height** 
>Simply speaking, the depth of a node is the number of edges you have to traverse starting from the root to reach that node. Height of a node is the number of edges you have to traverse downwards starting from that node to reach the farthest node. The height of a tree is the height of its root.

