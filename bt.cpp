#include <iostream>
#include <vector>

using namespace std;

class treeNode {

private:
public:
  char data;

  treeNode(char d)
  {
    data = d;
  }
  treeNode *leftChild;
  treeNode *rightChild;
};

void printTree(treeNode *root)
{ // start can also be called "root"
  if (root == NULL)
  {
    return;
  }

  cout << root->data << " "; // print the data of the node for fun

  printTree(root->leftChild);  // recurse on the left subtree
  printTree(root->rightChild); // recurse on the right subtree
}

treeNode* build2(vector<char> v, int &i)
{
  if (i == v.size())
  { // base condition
    return NULL;
  }
  i++;
  treeNode *root = new treeNode(v[i]);

  if (v[i] == '*' || v[i] == '-' || v[i] == '+' || v[i] == '/')
  {
    root->leftChild = build2(v, i);
    root->rightChild = build2(v, i);
  }
  else
  {
    return root;
  }
}

int main()
{

  cout << "Code works" << endl;

  vector<char> v = {'*', '+', '3', '4', '/', '7', '6'};

  int i = 0;

  treeNode *root = build2(v, i);
  // printTree(root); // need to fix

  return 0;
}
