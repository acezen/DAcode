typedef int ElementType;

#ifndef _Cursor_tree_h
#define _Cursor_tree_h

struct TreeNode;
typedef struct int Position;
typedef struct int SearchTree;


struct TreeNode
{
    ElementType Element;
    Position Left;
    Position Right;
};

#endif
