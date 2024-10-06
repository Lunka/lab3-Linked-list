#include <iostream>

// Визначення структури вузла
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для видалення дублікатів з відсортованого списку
ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return head; // Якщо список порожній, повертаємо nullptr

    ListNode* current = head; // Вказівник на поточний вузол

    // Перебираємо список
    while (current->next != nullptr) {
        if (current->val == current->next->val) {
            // Якщо значення поточного вузла дорівнює значенню наступного, пропускаємо наступний вузол
            ListNode* temp = current->next; // Зберігаємо вузол для видалення
            current->next = current->next->next; // Пропускаємо дублікат
            delete temp; // Вивільняємо пам'ять
        } else {
            current = current->next; // Переходимо до наступного вузла
        }
    }

    return head; // Повертаємо голову відсортованого списку без дублікатів
}

// Функція для виведення списку
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Приклад використання
int main() {
    // Створюємо список: 1 -> 1 -> 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);

    // Видаляємо дублікати
    head = deleteDuplicates(head);

    // Виводимо результат
    printList(head); // Виведе: 1 2

    // Вивільняємо пам'ять (можете реалізувати свою функцію для очищення пам'яті)
    // ...

    return 0;
}
