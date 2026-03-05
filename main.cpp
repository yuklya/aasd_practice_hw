#include <iostream>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    DoublyLinkedList<int> list;
    for (int i = 0; i < size; i++) {
        list.push_back(arr[i]);
    }
    std::cout << "Список в прямом порядке: ";
    DoublyLinkedList<int>::Node* current = list.begin();
    while (current != list.end()) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
    std::cout << "Список в обратном порядке: ";
    current = list.end()->prev;
    while (current != list.end()) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
    DoublyLinkedList<int>::Node* found = list.find(30);
    if (found) {
        std::cout << "Найден элемент: " << found->data << std::endl;
        list.insert_after(found, 35);
    }
    list.remove(20);
    std::cout << "Изменённый список: ";
    current = list.begin();
    while (current != list.end()) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
    std::cout << "Список пуст? " << (list.empty() ? "Да" : "Нет") << std::endl;
    return 0;
}
