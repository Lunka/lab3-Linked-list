#include <iostream>

// Визначення структури вузла
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для об'єднання двох відсортованих списків
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // Створюємо віртуальний початок нового списку
    ListNode dummy(0);
    ListNode* tail = &dummy;

    // Об’єднуємо списки поки один з них не стане порожнім
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            tail->next = list1; // Додаємо вузол з list1
            list1 = list1->next; // Переходимо до наступного вузла в list1
        } else {
            tail->next = list2; // Додаємо вузол з list2
            list2 = list2->next; // Переходимо до наступного вузла в list2
        }
        tail = tail->next; // Переходимо до останнього вузла в новому списку
    }

    // Додаємо залишки з непорожнього списку
    if (list1 != nullptr) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next; // Повертаємо початок об’єднаного списку
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
    // Створюємо перший список: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // Створюємо другий список: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // Об’єднуємо списки
    ListNode* mergedList = mergeTwoLists(list1, list2);

    // Виводимо об’єднаний список
    printList(mergedList);

    // Вивільняємо пам'ять (можете реалізувати свою функцію для очищення пам'яті)
    // ...

    return 0;
}
