template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    fake = new Node();
    fake->next = fake;
    fake->prev = fake;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
    delete fake;
}

template<class T>
bool DoublyLinkedList<T>::empty() const {
    return fake->next == fake;
}

template<class T>
void DoublyLinkedList<T>::push_front(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = fake->next;
    newNode->prev = fake;
    fake->next->prev = newNode;
    fake->next = newNode;
}

template<class T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node* newNode = new Node(value);
    newNode->prev = fake->prev;
    newNode->next = fake;
    fake->prev->next = newNode;
    fake->prev = newNode;
}

template<class T>
void DoublyLinkedList<T>::insert_after(Node* node, const T& value) {
    if (!node || node == fake) return;
    Node* newNode = new Node(value);
    newNode->next = node->next;
    newNode->prev = node;
    node->next->prev = newNode;
    node->next = newNode;
}

template<class T>
bool DoublyLinkedList<T>::remove(const T& value) {
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

template<class T>
void DoublyLinkedList<T>::remove(Node* node) {
    if (!node || node == fake) return;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}

template<class T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::find(const T& value) const {
    Node* current = fake->next;
    while (current != fake) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template<class T>
void DoublyLinkedList<T>::clear() {
    Node* current = fake->next;
    while (current != fake) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    fake->next = fake;
    fake->prev = fake;
}

template<class T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::begin() const {
    return fake->next;
}

template<class T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::end() const {
    return fake;
}
