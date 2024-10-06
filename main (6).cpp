#include <iostream>
#include <vector>
#include <queue>

// Визначення структури вузла
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Порівняння для пріоритетної черги
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Менший елемент буде мати вищий пріоритет
    }
};

// Функція для об'єднання k відсортованих списків
ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> minHeap;

    // Додаємо перший елемент кожного списку в пріоритетну чергу
    for (auto list : lists) {
        if (list) {
            minHeap.push(list);
        }
    }

    ListNode* dummy = new ListNode(0); // Віртуальний вузол для полегшення обробки
    ListNode* current = dummy;

    // Поки пріоритетна черга не пуста
    while (!minHeap.empty()) {
        ListNode* node = minHeap.top(); // Отримуємо найменший елемент
        minHeap.pop();

        current->next = node; // Додаємо його до результату
        current = current->next; // Переходимо до наступного вузла

        // Додаємо наступний елемент цього списку до пріоритетної черги
        if (node->next) {
            minHeap.push(node->next);
        }
    }

    return dummy->next; // Повертаємо перший реальний вузол
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
    // Створюємо приклад списків
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    std::vector<ListNode*> lists = {list1, list2, list3};

    // Об'єднуємо списки
    ListNode* result = mergeKLists(lists);

    // Виводимо результат
    printList(result); // Виведе: 1 1 2 3 4 4 5 6

    // Вивільняємо пам'ять (необхідно реалізувати свою функцію для очищення пам'яті)
    // ...

    return 0;
}
