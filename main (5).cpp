#include <iostream>
#include <vector>
#include <algorithm>

// Визначення структури вузла
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для подвоєння числа, представленого у вигляді зв’язаного списку
ListNode* doubleNumber(ListNode* head) {
    std::vector<int> digits;

    // Збираємо цифри в вектор
    while (head) {
        digits.push_back(head->val);
        head = head->next;
    }

    // Перетворюємо вектор в число
    int carry = 0; // Для переносу
    for (int i = digits.size() - 1; i >= 0; --i) {
        int current = digits[i] * 2 + carry; // Подвоюємо цифру та додаємо перенесення
        digits[i] = current % 10; // Оновлюємо цифру
        carry = current / 10; // Обчислюємо нове перенесення
    }

    // Якщо після проходження залишилось перенесення, додаємо його
    if (carry > 0) {
        digits.insert(digits.begin(), carry); // Додаємо перенесення на початку
    }

    // Створюємо новий зв’язаний список
    ListNode* newHead = new ListNode(digits[0]);
    ListNode* current = newHead;
    for (int i = 1; i < digits.size(); ++i) {
        current->next = new ListNode(digits[i]);
        current = current->next;
    }

    return newHead; // Повертаємо голову нового списку
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
    // Створюємо список: 1 -> 8 -> 9 (189)
    ListNode* head = new ListNode(1);
    head->next = new ListNode(8);
    head->next->next = new ListNode(9);

    // Подвоюємо число
    ListNode* result = doubleNumber(head);

    // Виводимо результат
    printList(result); // Виведе: 3 7 8 (378)

    // Вивільняємо пам'ять (необхідно реалізувати свою функцію для очищення пам'яті)
    // ...

    return 0;
}
