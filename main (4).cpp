#include <iostream>

// Визначення структури вузла
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для видалення вузла з однозв'язаного списку
void deleteNode(ListNode* node) {
    if (node == nullptr) return; // Перевірка на nullptr

    // Копіюємо значення з наступного вузла
    ListNode* nextNode = node->next; // Зберігаємо наступний вузол
    node->val = nextNode->val; // Копіюємо значення
    node->next = nextNode->next; // Пропускаємо наступний вузол

    delete nextNode; // Вивільняємо пам'ять
}

// Функція для виведення списку
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Приклад використання
int main() {
    // Створюємо список: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    // Вказуємо вузол, який потрібно видалити
    ListNode* nodeToDelete = head->next; // Вузол зі значенням 5

    // Видаляємо вузол
    deleteNode(nodeToDelete);

    // Виводимо результат
    printList(head); // Виведе: 4 1 9

    // Вивільняємо пам'ять (необхідно реалізувати свою функцію для очищення пам'яті)
    // ...

    return 0;
}
