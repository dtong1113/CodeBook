/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <bits/stdc++.h>

 using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 int main(){

 }
 static bool compare(ListNode* a, ListNode* b) {
    return a->val > b-> val;
 }
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq(&compare);
    ListNode* first = new ListNode(0);
    ListNode* last = first;
    for(ListNode* node : lists) {
        if(node != NULL) {
            pq.push(node);
        }
    }
    while(!pq.empty()) {
        ListNode* newNode = pq.top();
        pq.pop();
        if(newNode != NULL) {
            if(newNode -> next != NULL) {
                pq.push(newNode -> next);
            }
            last -> next = newNode;
            last = newNode;
        }
    }
    return first -> next;
}
