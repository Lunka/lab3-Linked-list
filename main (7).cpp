#include <iostream>

// Визначення структури вузла
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для розвертання вузлів у k-групі
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k <= 1) return head; // Якщо голова порожня або k <= 1, нічого не змінюємо

    ListNode* dummy = new ListNode(0); // Віртуальний вузол для полегшення обробки
    dummy->next = head;
    ListNode* prevGroupEnd = dummy; // Кінець попередньої групи

    while (true) {
        ListNode* groupStart = prevGroupEnd->next; // Початок групи
        ListNode* groupEnd = groupStart; // Кінець групи
        for (int i = 0; i < k - 1; ++i) {
            groupEnd = groupEnd->next; // Знаходимо кінець групи
            if (!groupEnd) return dummy->next; // Якщо менше ніж k вузлів, повертаємо
        }

        ListNode* nextGroupStart = groupEnd->next; // Зберігаємо початок наступної групи
        groupEnd->next = nullptr; // Завершуємо поточну групу

        // Розвертаємо вузли в групі
        ListNode* prev = nullptr;
        ListNode* current = groupStart;
        while (current) {
            ListNode* nextNode = current->next; // Зберігаємо наступний вузол
            current->next = prev; // Розвертаємо
            prev = current; // Переходимо вперед
            current = nextNode; // Переходимо вперед
        }

        // Підключаємо перевернуту групу до списку
        prevGroupEnd->next = prev; // Кінець попередньої групи вказує на новий початок
        groupStart->next = nextGroupStart; // З'єднуємо з наступною групою
        prevGroupEnd = groupStart; // Переходимо до кінця перевернутої групи
    }

    return dummy->next; // Повертаємо нову голову списку
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
    // Створюємо приклад: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Розвертаємо в групах по 2
    ListNode* result = reverseKGroup(head, 2);

    // Виводимо результат
    printList(result); // Виведе: 2 1 4 3 5

    // Вивільняємо пам'ять (необхідно реалізувати свою функцію для очищення пам'яті)
    // ...

    return 0;
}
