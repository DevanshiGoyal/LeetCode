/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        for(int i = 1 ; i<preorder.size() ; i++){
            TreeNode *node = new TreeNode(preorder[i]);
            insert(root, node);
        }
        return root;
            
    }

    TreeNode* insert(TreeNode*root , TreeNode* node){
        if(!root) return node ;
        if(node->val<root->val){
            root->left = insert(root->left , node);
        }
        if(node->val > root->val){
            root->right = insert(root->right, node);
        }
        return root;
    }

    
};
/*
Let's do a **detailed recursive dry run** of your code.

### Input

```cpp
preorder = [8,5,1,7,10,12]
```

---

# Step 1: Create Root

```cpp
TreeNode* root = new TreeNode(preorder[0]);
```

```text
root = 8
```

Tree:

```text
8
```

---

# i = 1

```cpp
node = new TreeNode(5);

insert(8, 5);
```

---

## insert(8,5)

Current call:

```cpp
insert(root=8, node=5)
```

Check:

```cpp
if(!root) return node;
```

False.

Check:

```cpp
if(5 < 8)
```

True.

Execute:

```cpp
root->left = insert(root->left, node);
```

Currently:

```cpp
root->left = NULL
```

So call:

```cpp
insert(NULL, 5)
```

---

## insert(NULL,5)

```cpp
if(!root) return node;
```

True.

Return node(5).

---

Back to previous call:

```cpp
8->left = 5
```

Return root(8).

Tree becomes:

```text
    8
   /
  5
```

---

# i = 2

```cpp
node = 1

insert(8,1)
```

---

## Call 1

```cpp
insert(8,1)
```

```cpp
1 < 8
```

Go left.

```cpp
insert(5,1)
```

---

## Call 2

```cpp
insert(5,1)
```

```cpp
1 < 5
```

Go left.

```cpp
insert(NULL,1)
```

---

## Call 3

```cpp
insert(NULL,1)
```

Return node(1).

---

Back to Call 2

```cpp
5->left = 1
```

Tree:

```text
  5
 /
1
```

Return 5.

---

Back to Call 1

```cpp
8->left = 5
```

Return 8.

Tree:

```text
      8
     /
    5
   /
  1
```

---

# i = 3

```cpp
node = 7

insert(8,7)
```

---

## Call 1

```cpp
insert(8,7)
```

```cpp
7 < 8
```

Go left.

```cpp
insert(5,7)
```

---

## Call 2

```cpp
insert(5,7)
```

```cpp
7 > 5
```

Go right.

```cpp
insert(NULL,7)
```

---

## Call 3

```cpp
insert(NULL,7)
```

Return node(7)

---

Back to Call 2

```cpp
5->right = 7
```

Tree:

```text
   5
  / \
 1   7
```

Return 5.

---

Back to Call 1

Return 8.

Tree:

```text
        8
       /
      5
     / \
    1   7
```

---

# i = 4

```cpp
node = 10

insert(8,10)
```

---

## Call 1

```cpp
insert(8,10)
```

```cpp
10 > 8
```

Go right.

```cpp
insert(NULL,10)
```

---

## Call 2

```cpp
insert(NULL,10)
```

Return node(10)

---

Back

```cpp
8->right = 10
```

Tree:

```text
        8
       / \
      5   10
     / \
    1   7
```

---

# i = 5

```cpp
node = 12

insert(8,12)
```

---

## Call 1

```cpp
insert(8,12)
```

```cpp
12 > 8
```

Go right.

```cpp
insert(10,12)
```

---

## Call 2

```cpp
insert(10,12)
```

```cpp
12 > 10
```

Go right.

```cpp
insert(NULL,12)
```

---

## Call 3

```cpp
insert(NULL,12)
```

Return node(12)

---

Back to Call 2

```cpp
10->right = 12
```

Tree:

```text
10
 \
 12
```

Return 10.

---

Back to Call 1

```cpp
8->right = 10
```

Return 8.

---

# Final Tree

```text
          8
        /   \
       5     10
      / \      \
     1   7      12
```

---

# Understanding the Recursion

When inserting `7`, the call stack looked like:

```cpp
insert(8,7)
    |
    ---> insert(5,7)
              |
              ---> insert(NULL,7)
                        return 7
```

Then returns happen **bottom-up**:

```cpp
insert(NULL,7) returns 7
```

↓

```cpp
5->right = 7
return 5
```

↓

```cpp
8->left = 5
return 8
```

This is why recursive tree insertion works: the recursive call finds the correct position, and while returning, each parent reconnects its child using:

```cpp
root->left = insert(...)
```

or

```cpp
root->right = insert(...)
```

---

### Complexity 

Best/Average Time:O(n log n)
Worst Time:O(n²) (when preorder is sorted)
Space:O(h) recursion stack

    Balanced BST: O(log n)
    Skewed BST: O(n)

*/