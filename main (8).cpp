#include <iostream>

// Визначення структури вузла
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для розділення списку
ListNode* partition(ListNode* head, int x) {
    // Створюємо два віртуальні вузли для двох частин
    ListNode lessDummy(0);
    ListNode greaterDummy(0);
    
    ListNode* lessTail = &lessDummy; // Кінець списку з меншими вузлами
    ListNode* greaterTail = &greaterDummy; // Кінець списку з більшими вузлами

    // Проходимо через весь список
    while (head) {
        if (head->val < x) {
            lessTail->next = head; // Додаємо до списку з меншими вузлами
            lessTail = lessTail->next; // Рухаємось вперед
        } else {
            greaterTail->next = head; // Додаємо до списку з більшими вузлами
            greaterTail = greaterTail->next; // Рухаємось вперед
        }
        head = head->next; // Переходимо до наступного вузла
    }

    // Завершуємо списки
    greaterTail->next = nullptr; // Завершуємо список з більшими вузлами
    lessTail->next = greaterDummy.next; // Приєднуємо список з більшими вузлами до списку з меншими

    return lessDummy.next; // Повертаємо новий голова списку
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
    // Створюємо приклад: 1 -> 4 -> 3 -> 2 -> 5 -> 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    // Розділяємо список за x = 3
    ListNode* result = partition(head, 3);

    // Виводимо результат
    printList(result); // Виведе: 1 2 2 4 3 5

    // Вивільняємо пам'ять (необхідно реалізувати свою функцію для очищення пам'яті)
    // ...

    return 0;
}
