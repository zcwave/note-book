export module BST;
import std;
using namespace std;

export template <typename KeyType, typename ValueType>
class BST {
private:
    struct Node {
        KeyType key;
        ValueType val;
        Node* left{};
        Node* right{};

        explicit Node(KeyType k, ValueType v) : key(k), val(v) {};
    };

    Node* root{};


    BST(const BST<KeyType, ValueType>& rhs) = delete;
    BST<KeyType, ValueType>& operator=(const BST<KeyType, ValueType>& src) = delete;
public:

    BST() = default;

    ~BST() {
        while (root != nullptr) {
            root = deleteMinNode(root);
        }
    }

    void deleteMinNode() {
        root = deleteMinNode(root);
    }

    Node* findMinNode() {
        return findMinNode(root);
    }


    void put(KeyType&& key, ValueType&& val) {
        insertNode(root, std::forward<KeyType>(key), std::forward<ValueType>(val));
    }

    ValueType get(KeyType&& key) {
        auto&& t = findNode(root, std::forward<KeyType&&>(key));
        if (t == nullptr) throw std::out_of_range("GET: NOT FOUND IT.");
        return t->val;
    }

    void show() {
        displayTree(root);
    }

    void deleteNode(KeyType&& key) {
        root = deleteNode(root, std::forward<KeyType>(key));
    }

private:

    Node* findMinNode(Node* t) {
        if (t->left == nullptr) {
            return t;
        }
        else {
            findMinNode(t->left);
        }
    }

    Node* deleteMinNode(Node* t) {
        if (t->left == nullptr) {
            Node* temp = t;
            t = t->right;
            delete temp;
        }
        else {
            t->left = deleteMinNode(t->left);
        }
        return t;
    }

    Node* deleteNode(Node* t, KeyType&& key) {

        Node* x = findNode(t, std::forward<KeyType>(key));
        Node* temp{};
        if (x->right == nullptr) {
            temp = x;
            x = x->left;
        }
        else if (x->left == nullptr) {
            temp = x;
            x = x->right;
        }
        else {
            temp = findMinNode(x->right);     // ����������С��������
            x->right = deleteMinNode(temp->right);  // ��temp����������ɾ��x��㱾����������x��������ָ��temp��������
            x->left = temp->left;                   // ���������䡣
        }
        delete temp;
        return x;
    }



    void insertNode(Node*& t, KeyType&& key, ValueType&& val) {
        if (t == nullptr) {
            t = new Node(key, val);
        }
        else {
            if (key != t->key) {
                if (key < t->key) {
                    insertNode(t->left, std::forward<KeyType>(key), std::forward<ValueType>(val));
                }
                else {
                    insertNode(t->right, std::forward<KeyType>(key), std::forward<ValueType>(val));
                }
            }
        }
    }

    Node* findNode(Node* t, KeyType&& key) {
        if (t == nullptr)   return nullptr;
        if (key == t->key)  return t;
        if (key < t->key) { return findNode(t->left, std::forward<KeyType&&>(key)); }
        else { return findNode(t->right, std::forward<KeyType&&>(key)); }
    }

    void displayTree(Node* t) {
        if (t != nullptr) {
            displayTree(t->left);
            cout << t->key << " : " << t->val << endl;
            displayTree(t->right);
        }
    }

};