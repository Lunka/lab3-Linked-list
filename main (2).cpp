#include <iostream>

// Визначення структури вузла
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для перевірки наявності циклу в пов’язаному списку
bool hasCycle(ListNode* head) {
    if (head == nullptr) return false; // Якщо список порожній, немає циклу

    ListNode* slow = head; // Повільний вказівник
    ListNode* fast = head; // Швидкий вказівник

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next; // Рухаємо повільний вказівник на один вузол
        fast = fast->next->next; // Рухаємо швидкий вказівник на два вузли

        // Якщо вказівники зустрічаються, є цикл
        if (slow == fast) {
            return true;
        }
    }

    return false; // Якщо швидкий вказівник досягне кінця списку, немає циклу
}

// Функція для виведення списку (для тестування)
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Приклад використання
int main() {
    // Створюємо список: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Створюємо цикл для тестування
    head->next->next->next->next = head->next; // -4 вказує на 2

    // Перевіряємо наявність циклу
    if (hasCycle(head)) {
        std::cout << "The linked list has a cycle." << std::endl; // Виведе: The linked list has a cycle.
    } else {
        std::cout << "The linked list does not have a cycle." << std::endl;
    }

    // Вивільняємо пам'ять (необхідно реалізувати свою функцію для очищення пам'яті)
    // ...

    return 0;
}
