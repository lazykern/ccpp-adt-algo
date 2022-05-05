# Binary Tree

## Table of Contents

- [Binary Tree](#binary-tree)
  - [Table of Contents](#table-of-contents)
  - [Types of Binary Trees](#types-of-binary-trees)
    - [Perfect Tree](#perfect-tree)
    - [Complete Tree](#complete-tree)
    - [Strict/Full Tree](#strictfull-tree)
    - [Balanced Tree](#balanced-tree)
  - [Traversal Methods](#traversal-methods)
  
---

## Types of Binary Trees

### Perfect Tree

Perfectly balanced.

```text
       x
     /   \
    /     \
   x       x
  / \     / \
 x   x   x   x
/ \ / \ / \ / \
x x x x x x x x
```

### Complete Tree

All the levels are completely filled except possibly the lowest one, which is **filled from the left**.

```tree
       x
     /   \
    /     \
   x       x
  / \     / \
 x   x   x   x
/ \ /
x x x

       x
     /   \
    /     \
   x       x
  / \     / \
 x   x   x   x
/ \ / \ / 
x x x x x
```

### Strict/Full Tree

Node can only have 2 or no child.

```text

       x
     /   \
    /     \
   x       x
  / \ 
 x   x 
    / \
    x x 
```

### Balanced Tree

* Difference between the left and the right subtree for any node is not more than one.
* The left and right subtree is balanced.

```text

       x
     /   \
    /     \
   x       x
  / \ 
 x   x 
```

---

## Traversal Methods
