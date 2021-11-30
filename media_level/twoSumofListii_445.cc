ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* head = nullptr;
        
        int t = 0;
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                t += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                t += s2.top();
                s2.pop();
            }
            auto newNode = new ListNode(t%10);
            t = t / 10;
            newNode->next = head;
            head = newNode;

        }
        if (t) {
            auto newNode = new ListNode(t);
            newNode->next = head;
            head = newNode;
        }   
        return head;
    }