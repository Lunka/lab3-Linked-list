#include <iostream>
#include <stack>

// Визначення структури вузла
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для перевпорядкування списку
void reorderList(ListNode* head) {
    if (!head || !head->next) return;

    // Знаходимо середину списку за допомогою повільного і швидкого вказівників
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Розділяємо список на дві частини і перевертаємо другу половину
    ListNode* second = slow->next;
    slow->next = nullptr;
    
    ListNode* prev = nullptr;
    while (second) {
        ListNode* tmp = second->next;
        second->next = prev;
        prev = second;
        second = tmp;
    }

    // Об'єднуємо обидві половини
    ListNode* first = head;
    second = prev;
    while (second) {
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = second->next;

        first->next = second;
        second->next = tmp1;

        first = tmp1;
        second = tmp2;
    }
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
    // Створюємо список: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Перевпорядковуємо список
    reorderList(head);

    // Виводимо результат
    printList(head); // Виведе: 1 4 2 3

    return 0;
}
