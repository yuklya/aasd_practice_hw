template<class T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& val = T(), Node* n = nullptr, Node* p = nullptr)
            : data(val), next(n), prev(p) {}
    };
    Node* fake;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void push_front(const T& value);
    void push_back(const T& value);
    void insert_after(Node* node, const T& value);
    bool remove(const T& value);
    void remove(Node* node);
    Node* find(const T& value) const;
    bool empty() const;
    void clear();
    Node* begin() const;
    Node* end() const;
};
