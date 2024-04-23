export module AVL;

export template<typename KeyType, typename ValueType>
class AVL {
    struct Node {
        KeyType key;
        ValueType val;
        Node* left{};
        Node* right{};
        int bf;

        explicit Node(KeyType k, ValueType v, int BF) : key(k), val(v), bf(BF) {};
    };

    Node* root{};
    static bool traceBST = false;

public:
    int insert(KeyType&& key, ValueType&& val) {
        insert(root, std::forward<KeyType>(key), std::forward<ValueType>(val));
    }
    
    void displayTree(BSTNode* t, const string& prefix) {
        /*
         * Function: displayTree
         * Usage: displayTree(t);
         *        displayTree(t, prefix);
         * ------------------------------
         * Displays the structure of the tree.  If prefix is supplied, it is
         * displayed before the line.
         */
        if (t != nullptr) {
            cout << prefix << t->key << " (" << bfString(t->bf) << ")" << endl;
            int len = prefix.length();
            string indent = (len == 0) ? "" : prefix.substr(0, len - 2);
            displayTree(t->left, indent + "  L:");
            displayTree(t->right, indent + "  R:");
        }
    }
private:

    string bfString(int bf) {
        if (bf == 0) return "0";
        if (bf < 0) return "-1";
        return "+1";
    }

    void fixLeftImbalance(Node*& t) {
        Node* child = t->left;
        if (child->bf != t->bf) {
            int oldBF = child->right->bf;
            rotateLeft(t->left);
            rotateRight(t);
            t->bf = 0;
            switch (oldBF) {
            case -1: t->left->bf = 0; t->right->bf = +1; break;
            case  0: t->left->bf = t->right->bf = 0; break;
            case +1: t->left->bf = -1; t->right->bf = 0; break;
            }
        }
        else {
            rotateRight(t);
            t->right->bf = t->bf = 0;
        }

    }
    void rotateLeft(Node*& t) {
        Node* child = t->right;
        if (traceBST) {
            cout << "rotateLeft(" << t->key << "-" << child->key << ")" << endl;
        }
        t->right = child->left;
        child->left = t;
        t = child;
    }

    void fixRightImbalance(Node*& t) {
        Node* child = t->right;
        if (child->bf != t->bf) {
            int oldBF = child->left->bf;
            rotateRight(t->right);
            rotateLeft(t);
            t->bf = 0;
            switch (oldBF) {
            case -1: t->left->bf = 0; t->right->bf = +1; break;
            case  0: t->left->bf = t->right->bf = 0; break;
            case +1: t->left->bf = -1; t->right->bf = 0; break;
            }
        }
        else {
            rotateLeft(t);
            t->left->bf = t->bf = 0;
        }
    }
    void rotateRight(Node*& t) {
        Node* child = t->left;
        if (traceBST) {
            cout << "rotateRight(" << t->key << "-" << child->key << ")" << endl;
        }
        t->left = child->right;
        child->right = t;
        t = child;
    }
    int insert(Node*& t, KeyType&& key, ValueType&& val) {
        if (t == nullptr) {
            t = new Node(key, val, 0);
            return +1;
        }
        
        if (key == t->key) return 0;
        else if (key < t->key) {
            int delta = insert(t->left, std::forward<KeyType>(key), std::forward<ValueType>(val));
            if (delta == 0) return 0;
            switch (t->bf){
                case +1: t->bf = 0; return 0;
                case 0: t->bf = -1; return +1;
                case -1: fixLeftImbalance(t); return 0;
            }
        }
        else {
            int delta = insert(t->right, std::forward<KeyType>(key), std::forward<ValueType>(val));
            if (delta == 0) return 0;
            switch (t->bf) {
                case -1: t->bf = 0; return 0;
                case 0: t->bf = +1; return +1;
                case +1: fixRightImbalance(t); return 0;
            }
        }
    }

};