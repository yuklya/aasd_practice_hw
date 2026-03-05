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
    DoublyLinkedList() {
        fake = new Node();
        fake->next = fake;
        fake->prev = fake;
    }
    ~DoublyLinkedList() {
        clear();
        delete fake;
    }
    DoublyLinkedList(const DoublyLinkedList& other) {
        fake = new Node();
        fake->next = fake;
        fake->prev = fake;
        Node* current = other.fake->next;
        while (current != other.fake) {
            push_back(current->data);
            current = current->next;
        }
    }
    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this != &other) {
            clear();
            Node* current = other.fake->next;
            while (current != other.fake) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }
    bool empty() const {
        return fake->next == fake;
    }
    size_t size() const {
        size_t count = 0;
        Node* current = fake->next;
        while (current != fake) {
            count++;
            current = current->next;
        }
        return count;
    }
    void push_front(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = fake->next;
        newNode->prev = fake;
        fake->next->prev = newNode;
        fake->next = newNode;
    }
    void push_back(const T& value) {
        Node* newNode = new Node(value);
        newNode->prev = fake->prev;
        newNode->next = fake;
        fake->prev->next = newNode;
        fake->prev = newNode;
    }
    void insert_after(Node* node, const T& value) {
        if (!node || node == fake) return;
        Node* newNode = new Node(value);
        newNode->next = node->next;
        newNode->prev = node;
        node->next->prev = newNode;
        node->next = newNode;
    }
    void insert_before(Node* node, const T& value) {
        if (!node || node == fake) return;
        Node* newNode = new Node(value);
        newNode->prev = node->prev;
        newNode->next = node;
        node->prev->next = newNode;
        node->prev = newNode;
    }
    bool remove(const T& value) {
        Node* current = fake->next;
        while (current != fake) {
            if (current->data == value) {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void remove(Node* node) {
        if (!node || node == fake) return;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
    Node* find(const T& value) const {
        Node* current = fake->next;
        while (current != fake) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
    Node* begin() const {
        return fake->next;
    }
    Node* end() const {
        return fake;
    }
    Node* rbegin() const {
        return fake->prev;
    }
    void clear() {
        Node* current = fake->next;
        while (current != fake) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        fake->next = fake;
        fake->prev = fake;
    }
    void from_array(const T* arr, size_t size) {
        clear();
        for (size_t i = 0; i < size; i++) {
            push_back(arr[i]);
        }
    }
    void to_array(T* arr, size_t max_size) const {
        Node* current = fake->next;
        size_t i = 0;
        while (current != fake && i < max_size) {
            arr[i++] = current->data;
            current = current->next;
        }
    }
};
/*
1. Конструктор по умолчанию T() — используется при создании фиктивного узла
2. Конструктор копирования T(const T&) — используется при создании новых узлов с переданными значениями
3. Деструктор — вызывается при удалении узлов
4. Оператор присваивания operator= — используется при копировании между списками
5. Оператор сравнения operator== — используется в методах remove(const T&) и find()
*/
