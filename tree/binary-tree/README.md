# Binary Tree

## Table of Contents

- [Binary Tree](#binary-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Types of Binary Trees](#types-of-binary-trees)
    - [Perfect Tree](#perfect-tree)
    - [Complete Tree](#complete-tree)
    - [Strict/Full Tree](#strictfull-tree)
    - [Balanced Tree](#balanced-tree)
  - [Traversal Methods](#traversal-methods)
    - [Pre-Order](#pre-order)
    - [In-Order](#in-order)
    - [Post-Order](#post-order)
    - [Level Order](#level-order)
    - [Example](#example)
  
---

## Introduction

Binary Tree is a data structure in which each node can have at most 2 children.



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

- Difference between the left and the right subtree for any node is not more than one.
- The left and right subtree is balanced.

```text

       x
     /   \
    /     \
   x       x
  / \ 
 x   x 
```

## Traversal Methods

### Pre-Order

   1. Visit the root.
   2. Traverse the left subtree, i.e., call Preorder(left-subtree)
   3. Traverse the right subtree, i.e., call Preorder(right-subtree)

### In-Order

   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Visit the root.
   3. Traverse the right subtree, i.e., call Inorder(right-subtree)

### Post-Order

   1. Traverse the left subtree, i.e., call Postorder(left-subtree)
   2. Traverse the right subtree, i.e., call Postorder(right-subtree)
   3. Visit the root.

### Level Order

Breadth-first traversal for the tree.

### Example

```text
       a
     /   \
    /     \
   b       c
  / \     / \
 d   e   f   g

PRE: a, (b,d,e), (c,f,g)
IN: (d,b,e), a, (f,c,g)
POST: (d,e,b), (f,g,c), a
LEVEL: a,b,c,d,e,f,g
```
