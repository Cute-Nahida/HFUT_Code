#include <iostream>
using namespace std;
// ���嵥����ڵ�ṹ 
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};
// ���嵥������ 
class LinkedList {
public:
    ListNode* head;
    LinkedList() {
        head = new ListNode(0); // ͷ��� 
    }
    // ����Ԫ�ص�����β�� 
    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
    // ��ӡ���� 
    void print() {
        ListNode* cur = head->next;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    // 1) ����������е��������ż������ֽ⿪ 
    void splitOddEven(LinkedList& oddList, LinkedList& evenList) {
        ListNode* cur = head->next;
        while (cur) {
            if (cur->data % 2 == 1) {
                oddList.insert(cur->data);
            }
            else {
                evenList.insert(cur->data);
            }
            cur = cur->next;
        }
    }
    // 2) ������������������L1��L2�еĹ���Ԫ�أ������µĵ�����L3�� 
    static void findCommonElements(LinkedList& L1, LinkedList& L2, LinkedList& L3) {
        ListNode* p1 = L1.head->next;
        ListNode* p2 = L2.head->next;
        while (p1 && p2) {
            if (p1->data < p2->data) {
                p1 = p1->next;
            }
            else if (p1->data > p2->data) {
                p2 = p2->next;
            }
            else {
                L3.insert(p1->data);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
    }
    // 3) ɾ���������������е��ظ�Ԫ�� 
    void removeDuplicates() {
        ListNode* cur = head->next;
        while (cur && cur->next) {
            if (cur->data == cur->next->data) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else {
                cur = cur->next;
            }
        }
    }
    // 4) ������������L1��L2���������½�㣬����ԭ�����������кϲ� 
    static void mergeLists(LinkedList& L1, LinkedList& L2) {
        ListNode* p1 = L1.head->next;
        ListNode* p2 = L2.head->next;
        ListNode* prev = L1.head;
        while (p1 && p2) {
            if (p1->data < p2->data) {
                prev = p1;
                p1 = p1->next;
            }
            else if (p1->data > p2->data) {
                ListNode* temp = p2;
                p2 = p2->next;
                prev->next = temp;
                temp->next = p1;
                prev = temp;
            }
            else {
                ListNode* temp = p2;
                p2 = p2->next;
                delete temp;
                prev = p1;
                p1 = p1->next;
            }
        }
        if (p2) {
            prev->next = p2;
        }
        delete L2.head;
    }
    // 5) ���������е�����k��λ���ϵĽ�� 
    int findKthToLast(int k) {
        ListNode* fast = head->next;
        ListNode* slow = head->next;
        // ��ָ������k�� 
        for (int i = 0; i < k; ++i) {
            if (!fast) {
                return 0;
            }
            fast = fast->next;
        }
        // ����ָ��ͬʱ�� 
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        if (slow) {
            cout << "������" << k << "��λ�õĽ��ֵΪ: " << slow->data << endl;
            return 1;
        }
        return 0;
    }
};