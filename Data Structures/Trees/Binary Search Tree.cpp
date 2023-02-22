template <typename type>
class BinarySearchTree {
    struct BinaryNode {
        type data;
        BinaryNode *left {};
        BinaryNode *right{};

        BinaryNode(type data) : data(data) { }
    };
    BinaryNode* root {};

    void insert_node(BinaryNode* node, type target) {
        if (target < node->data) {
            if (node->left)
                insert_node(node->left, target);
            else node->left = new BinaryNode(target);
        }
        else {
            if (node->right)
                insert_node(node->right, target);
            else node->right = new BinaryNode(target);
        }
    }

    bool search_node(BinaryNode* node, type target) {
        if (target < node->data)
            return node->left and search_node(node->left, target);
        else if (target > node->data)
            return node->right and search_node(node->right, target);

        return true;
    }

    void print_inorder_node(BinaryNode* node) {
        if (node->left)
            print_inorder_node(node->left);
        cout << node->data << ' ';
        if (node->right)
            print_inorder_node(node->right);
    }

    void level_order_trav_node() {
        queue<BinaryNode*> levels;
        levels.push(root);

        int l = 0;
        while (!levels.empty()) {
            cout << "Level " << l << ": ";

            int siz = levels.size();
            while (siz--) {
                BinaryNode* it = levels.front();
                cout << it->data << ' ';

                if (it->left)
                    levels.push(it->left);
                if (it->right)
                    levels.push(it->right);

                levels.pop();
            }

            cout << endl;
            ++l;
        }
    }

    BinaryNode* min_node(BinaryNode* node) {
        BinaryNode* cur = node;
        while (cur->left)
            cur = cur->left;
        return cur;
    }
    BinaryNode* delete_node(BinaryNode* node, type target) {
        if (!node)
            return nullptr;

        if (target < node->data)
            node->left = delete_node(node->left, target); // update left
        else if (target > node->data)
            node->right = delete_node(node->right, target);
        else { // found the node to be deleted !
            BinaryNode* tmp = node;

            if (!node->left and !node->right) // case 1: no children
                node = nullptr;
            else if (!node->right) // case 2: one left child
                node = node->left;
            else if (!node->left) // case 2: one right child
                node = node->right;
            else { // case 3: 2 children => use Successor
                BinaryNode* suc = min_node(node->right);
                node->data = suc->data; // copy suc data
                node->right = delete_node(node->right, node->data); // remove the original suc
                tmp = nullptr; // don't delete me
            }

            if (tmp)
                delete tmp;
        }

        return node;
    }

public:
    void insert(type val) {
        if (!root) root = new BinaryNode(val);
        else insert_node(root, val);
    }

    bool search(type target) {
        if (root)
            return search_node(root, target);
        return false;
    }

    void print_inorder() {
        if (root)
            print_inorder_node(root);
    }
    void level_order_traversal() {
        if (root)
            level_order_trav_node();
    }

    void delete_value(type target) {
        if (root)
            root = delete_node(root, target);
    }
};