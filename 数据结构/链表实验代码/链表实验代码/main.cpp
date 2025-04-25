#include <iostream>
#include "linkedList.h" 
using namespace std;

int main() {
    // 1) ����������е��������ż������ֽ⿪ 
    cout << "����1���ֽ�����ż����" << endl;
    cout << "��һ�����ݣ�" << endl;
    LinkedList L1; int data1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60 };
    for (int val : data1) {
        L1.insert(val);
    }
    LinkedList oddList1, evenList1;
    L1.splitOddEven(oddList1, evenList1);
    cout << "ԭ����: ";
    L1.print();
    cout << "��������: ";
    oddList1.print();
    cout << "ż������: ";
    evenList1.print();
    cout << endl;
    // 2) ������������������L1��L2�еĹ���Ԫ�أ������µĵ�����L3�� 
    cout << "����2���󹫹�Ԫ��" << endl;
    LinkedList L3, L4, L5;
    int data3[] = { 1, 3, 6, 10, 15, 16, 17, 18, 19, 20 };
    int data4[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 18, 20, 30 };
    for (int val : data3) {
        L3.insert(val);
    }
    for (int val : data4) {
        L4.insert(val);
    }
    LinkedList L6;
    LinkedList::findCommonElements(L3, L4, L6);
    cout << "��һ������: ";
    L3.print();
    cout << "�ڶ�������: ";
    L4.print();
    cout << "����Ԫ������: ";
    L6.print();
    // 3) ɾ���������������е��ظ�Ԫ�� 
    cout << "\n����3��ɾ���ظ�Ԫ��" << std::endl;
    LinkedList L7;
    int data5[] = { 1, 1, 2, 2, 2, 3, 4, 5, 5, 5, 6, 6, 7, 7, 8, 8, 9 };
    for (int val : data5) {
        L7.insert(val);
    }
    cout << "ԭ����: ";
    L7.print();
    L7.removeDuplicates();
    cout << "ɾ���ظ�Ԫ�غ������: ";
    L7.print();
    // 4) ������������L1��L2���������½�㣬����ԭ�����������кϲ� 
    cout << "\n����4���ϲ�����" << endl;
    LinkedList L8, L9;
    int data6[] = { 1, 3, 6, 10, 15, 16, 17, 18, 19, 20 };
    int data7[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 18, 20, 30 };
    for (int val : data6) {
        L8.insert(val);
    }
    for (int val : data7) {
        L9.insert(val);
    }
    LinkedList::mergeLists(L8, L9);
    cout << "�ϲ��������: ";
    L8.print();
    // 5) ���������е�����k��λ���ϵĽ�� 
    cout << "\n����5�����ҵ�����k�����" << endl;
    LinkedList L10;
    int data8[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int val : data8) {
        L10.insert(val);
    }
    int k = 3;
    int result = L10.findKthToLast(k);
    if (result == 0) {
        cout << "δ�ҵ�������" << k << "�����" << endl;
    }
    return 0;
}