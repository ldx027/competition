#include <iostream>
using namespace std;

struct TreeNode
{
    int key;
    TreeNode *left;
    TreeNode *right;
    // 维护其他信息，如高度，节点数量等
    int size;  // 当前节点为根的子树大小
    int count; // 当前节点的重复数量

    TreeNode(int value)
        : key(value), size(1), count(1), left(nullptr), right(nullptr) {}
};

// 遍历
void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    std::cout << root->key << " ";
    inorderTraversal(root->right);
}

// 最值
int findMin(TreeNode *root)
{
    if (root == nullptr)
        return -1;
    while (root->left != nullptr)
        root = root->left;
    return root->key;
}

int findMax(TreeNode *root)
{
    if (root == nullptr)
        return -1;
    while (root->right != nullptr)
        root = root->right;
    return root->key;
}

// 此处以右子树的最小值为例
TreeNode *findMinNode(TreeNode *root)
{
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// 搜索
bool search(TreeNode *root, int target)
{
    if (root == nullptr)
        return false;
    if (root->key == target)
        return true;
    else if (target < root->key)
        return search(root->left, target);
    else
        return search(root->right, target);
}

// 插入
TreeNode *insert(TreeNode *root, int value)
{
    if (root == nullptr)
        return new TreeNode(value);
    if (value < root->key)
        root->left = insert(root->left, value);
    else if (value > root->key)
        root->right = insert(root->right, value);
    else
        root->count++; // 节点值相等，增加重复数量
    root->size = root->count + (root->left ? root->left->size : 0) +
                 (root->right ? root->right->size : 0); // 更新节点的子树大小
    return root;
}

// 删除
TreeNode *remove(TreeNode *root, int value)
{
    if (root == nullptr)
        return root;
    if (value < root->key)
        root->left = remove(root->left, value);
    else if (value > root->key)
        root->right = remove(root->right, value);
    else
    {
        if (root->count > 1)
            root->count--; // 节点重复数量大于1，减少重复数量
        else
        {
            if (root->left == nullptr)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                TreeNode *successor = findMinNode(root->right);
                root->key = successor->key;
                root->count = successor->count; // 更新重复数量
                root->right = remove(root->right, successor->key);
            }
        }
    }
    return root;
}

// 求排名
int queryRank(TreeNode *root, int v)
{
    if (root == nullptr)
        return 0;
    if (root->key == v)
        return (root->left ? root->left->size : 0) + 1;
    if (root->key > v)
        return queryRank(root->left, v);
    return queryRank(root->right, v) + (root->left ? root->left->size : 0) +
           root->count;
}

// 找排名对应节点
int querykth(TreeNode *root, int k)
{
    if (root == nullptr)
        return -1; // 或者根据需求返回其他合适的值
    if (root->left)
    {
        if (root->left->size >= k)
            return querykth(root->left, k);
        if (root->left->size + root->count >= k)
            return root->key;
    }
    else
    {
        if (k == 1)
            return root->key;
    }
    return querykth(root->right,
                    k - (root->left ? root->left->size : 0) - root->count);
}

int main()
{
    return 0;
}