/*
You are given the head of a linked list. You have to replace all the values of the nodes with the nearest prime number. If more than one prime number exists at an equal distance, choose the smallest one. Return the head of the modified linked list.
Input: head = 2 → 6 → 10
Output: 2 → 5 → 11
Solution:
1. Create a function to check if a number is prime.
2. Create a function to find the nearest prime number to a given number.
3. Iterate through the linked list and replace each node's value with the nearest prime number.
4. Return the modified linked list.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;
class Node{
    public:
        int val;
        Node* next;
        Node(int x) : val(x), next(NULL) {}
};
class PrimeList{
    /*
    here the logic for the prime number is 
    1.Primes are ≥ 2, so return false for numbers like 0 or 1.
    2.2 and 3 are the first two prime numbers — return true early.
    3.If divisible by 2 or 3, it's not prime (except for 2 and 3, which were already handled).
    Why start at 5 and increment by 6?
    After 2 and 3, all primes are of the form 6k ± 1 (e.g. 5, 7, 11, 13, 17, 19...)
    So we only check numbers of the form i = 6k - 1 and i + 2 = 6k + 1
    Why i * i <= n?
    You only need to check up to √n to determine if n is prime.
    If n has a factor greater than √n, it must also have a smaller factor (e.g., if 100 = 10 × 10, or 4 × 25).
    */
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
    int nearestPrime(int n) {
        if (isPrime(n)) return n;
        int k = 1;
        while (true) {
            if (n - k >= 2 && isPrime(n - k)) return n - k;
            if (isPrime(n + k)) return n + k;
            k++;
        }
    }
    Node* PrimeListCheck(Node * head) {
        Node* current = head;
        while (current != NULL) {
            current->val = nearestPrime(current->val);
            current = current->next;
        }
        return head;
    }
    int main(){
        int n;
        cin>>n;
        Node* head = new Node(0);
        Node* current = head;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            current->next = new Node(val);
            current = current->next;
        }
        current = head->next; // Skip the dummy head node
        head = PrimeListCheck(current);
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};