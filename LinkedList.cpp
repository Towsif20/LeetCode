#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2)
{
    ListNode *root = nullptr;

    ListNode *temp1 = l1;
    ListNode *temp2 = l2;
    ListNode *temp;

    int mod = 0;
    int div = 0;

    while (temp1 != nullptr && temp2 != nullptr)
    {
        int val = temp1->val + temp2->val + div;

        mod = val % 10;
        div = val / 10;

        if (root == nullptr)
        {
            root = new ListNode(mod);
            temp1 = temp1->next;
            temp2 = temp2->next;
            temp = root;
            continue;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;

        temp->next = new ListNode(mod);
        temp = temp->next;
    }

    while (temp1 != nullptr)
    {
        int val = temp1->val + div;

        mod = val % 10;
        div = val / 10;

        temp1 = temp1->next;

        temp->next = new ListNode(mod);
        temp = temp->next;
    }

    while (temp2 != nullptr)
    {
        int val = temp2->val + div;

        mod = val % 10;
        div = val / 10;

        temp2 = temp2->next;

        temp->next = new ListNode(mod);
        temp = temp->next;
    }

    if (div != 0)
    {
        temp->next = new ListNode(div);
    }

    return root;
}

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *temp = head;
    ListNode *prev = temp;

    while (temp)
    {
        if (temp->val == val)
        {
            if (temp == prev)
            {
                prev = prev->next;

                head = head->next;

                temp = temp->next;
            }

            else if (temp->next == nullptr)
            {
                prev->next = nullptr;
                temp = temp->next;
            }

            else
            {
                prev->next = temp->next;
                temp = temp->next;
            }
        }

        else
        {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

void deleteNode(ListNode *node)
{
    ListNode *temp = node;
    ListNode *prev;

    while (temp->next)
    {
        temp->val = temp->next->val;

        prev = temp;
        temp = temp->next;
    }

    //delete temp;

    prev->next = nullptr;
}

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    bool loop = false;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            loop = true;
            break;
        }
    }

    if (!loop)
        return nullptr;

    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

bool isPalindrome(ListNode *head)
{
    vector<int> v;

    ListNode *temp = head;

    while (temp)
    {
        v.push_back(temp->val);

        temp = temp->next;
    }

    int len = v.size();

    for (int i = 0; i < len; i++)
    {
        if (v[i] != v[len - i - 1])
            return false;
    }

    return true;
}

ListNode *reverseList(ListNode *head)
{
    vector<int> v;

    ListNode *temp = head;

    while (temp)
    {
        v.push_back(temp->val);

        temp = temp->next;
    }

    int len = v.size();

    ListNode *reverse = nullptr;
    ListNode *current = nullptr;

    for (int i = len - 1; i >= 0; i--)
    {
        if (reverse == nullptr)
        {
            reverse = new ListNode(v[i]);
            current = reverse;
            continue;
        }

        current->next = new ListNode(v[i]);
        current = current->next;
    }

    return reverse;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // ListNode* tempA = headA;

    // while(tempA)
    // {
    //     ListNode* tempB = headB;

    //     while(tempB)
    //     {
    //         if(tempA == tempB)
    //             return tempA;

    //         tempB = tempB->next;
    //     }

    //     tempA = tempA->next;
    // }

    // return nullptr;

    unordered_map<ListNode *, int> map;

    ListNode *tempA = headA;
    ListNode *tempB = headB;

    while (tempA)
    {
        map[tempA] = tempA->val;

        tempA = tempA->next;
    }

    while (tempB)
    {
        if (map.find(tempB) != map.end())
            return tempB;

        map[tempB] = tempB->val;

        tempB = tempB->next;
    }

    return nullptr;
}

ListNode *deleteDuplicates2(ListNode *head)
{
    //keep one occurrence of repeating element

    ListNode *temp = head;
    ListNode *first = head;

    while (temp)
    {
        if (first->val != temp->val)
        {
            first->next = temp;
            first = temp;
        }

        temp = temp->next;
    }

    if (first != temp)
        first->next = nullptr;

    return head;
}

ListNode *deleteDuplicates(ListNode *head)
{
    //keep none of repeating elements
    //cant solve yet :(

    map<int, int> map;

    ListNode *temp = head;

    while (temp)
    {
        map[temp->val]++;
        temp = temp->next;
    }

    ListNode *dummy = new ListNode(0);
    temp = dummy;

    for (auto i : map)
    {
        if (i.second == 1)
        {
            temp->next = new ListNode(i.first);
            temp = temp->next;
        }
    }

    return dummy->next;
}

ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *temp = head;

    while (temp && temp->next)
    {
        int t = temp->val;
        temp->val = temp->next->val;
        temp->next->val = t;

        temp = temp->next->next;
    }

    return head;
}

ListNode *swapNodes(ListNode *head, int k)
{
    int len = 0;
    ListNode *temp = head;
    ListNode *k_from_begin = nullptr;

    while (temp)
    {
        len++;

        if (len == k)
        {
            k_from_begin = temp;
        }

        temp = temp->next;
    }

    temp = head;
    for (int i = 0; i < len - k; i++)
    {
        temp = temp->next;
    }

    swap(k_from_begin->val, temp->val);

    return head;
}

int getDecimalValue(ListNode *head)
{
    int len = 0;

    ListNode *temp = head;

    while (temp)
    {
        len++;

        temp = temp->next;
    }

    int sum = 0;

    int local = pow(2, len - 1);

    temp = head;

    for (int i = 0; i < len; i++)
    {
        if (temp->val == 1)
            sum += local;

        local /= 2;

        temp = temp->next;
    }

    return sum;
}

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
{
    ListNode *temp = list1;

    for (int i = 0; i < a - 1; i++)
    {
        temp = temp->next;
    }

    ListNode *first = temp;

    temp = temp->next;

    for (int i = a; i <= b; i++)
    {
        ListNode *t = temp;
        temp = temp->next;
        delete t;
    }

    ListNode *last = temp;

    first->next = list2;

    temp = list2;

    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = last;

    return list1;
}

class BrowserHistory
{
    int current;
    int total;
    vector<string> urls;

public:
    BrowserHistory(string homepage)
    {
        current = 0;
        total = 1;

        urls.clear();

        for (int i = 0; i < 500000; i++)
        {
            urls.push_back("");
        }

        urls[current] = homepage;
    }

    void visit(string url)
    {
        current++;
        total = current + 1;

        urls[current] = url;
    }

    string back(int steps)
    {
        if (current - steps < 0)
            current = 0;

        else
            current -= steps;

        return urls[current];
    }

    string forward(int steps)
    {
        if (current + steps > total)
            current = total - 1;

        else
            current += steps;

        return urls[current];
    }
};

ListNode *oddEvenList(ListNode *head)
{
    int parity = 0;

    ListNode *even = nullptr;

    ListNode *odd = nullptr;

    ListNode *temp = head;

    ListNode *t1, *t2;

    while (temp)
    {
        if (parity == 0)
        {
            if (even == nullptr)
            {
                even = new ListNode(temp->val);
                t1 = even;
            }
            else
            {
                t1->next = new ListNode(temp->val);
                t1 = t1->next;
            }
        }
        else
        {
            if (odd == nullptr)
            {
                odd = new ListNode(temp->val);
                t2 = odd;
            }
            else
            {
                t2->next = new ListNode(temp->val);
                t2 = t2->next;
            }
        }
        parity = 1 - parity;

        temp = temp->next;
    }

    if (t1 != nullptr)
        t1->next = odd;

    return even;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;

    int len1 = 0, len2 = 0;

    vector<int> v1;
    vector<int> v2;

    int dif = 0;

    while (temp1)
    {
        len1++;

        temp1 = temp1->next;
    }

    while (temp2)
    {
        len2++;

        temp2 = temp2->next;
    }

    if (len1 < len2)
    {
        dif = len2 - len1;

        for (int i = 0; i < dif; i++)
        {
            v1.push_back(0);
        }
    }
    else
    {
        dif = len1 - len2;

        for (int i = 0; i < dif; i++)
        {
            v2.push_back(0);
        }
    }

    temp1 = l1, temp2 = l2;

    while (temp1)
    {
        v1.push_back(temp1->val);

        temp1 = temp1->next;
    }

    while (temp2)
    {
        v2.push_back(temp2->val);

        temp2 = temp2->next;
    }

    int sum = 0;
    int carry = 0;

    stack<int> add;

    int len = v1.size();

    for (int i = len - 1; i >= 0; i--)
    {
        sum = v1[i] + v2[i] + carry;

        carry = sum / 10;

        sum = sum % 10;

        add.push(sum);
    }

    if (carry > 0)
        add.push(carry);

    ListNode *result = nullptr;
    ListNode *t;

    while (!add.empty())
    {
        int v = add.top();

        if (result == nullptr)
        {
            result = new ListNode(v);
            t = result;
        }
        else
        {
            t->next = new ListNode(v);
            t = t->next;
        }

        add.pop();
    }

    return result;
}

ListNode *middleNode(ListNode *head)
{
    ListNode *temp = head;
    int count = 0;

    while (temp)
    {
        count++;

        temp = temp->next;
    }

    int mid = count / 2;

    temp = head;

    for (int i = 0; i < mid; i++)
    {
        temp = temp->next;
    }

    return temp;
}

int main()
{
    ListNode *l1 = new ListNode(9);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);
    //l1->next->next->next->next = new ListNode(5);
    //l1->next->next->next->next->next = new ListNode(6);

    ListNode *l2 = new ListNode(9);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    //cout<<hasCycle(l1);

    //l2->next->next = new ListNode(4);

    //ListNode* ret = addTwoNumbers(l1, l2);

    //ListNode* ret = removeElements(l1, 1);

    //cout<<length(l2);
    // ListNode *ret = deleteDuplicates(l1);

    ListNode *ret = oddEvenList(l1);

    ret = addTwoNumbers(l1, l2);

    // deleteNode(l1->next->next);

    while (ret)
    {
        cout << ret->val;
        ret = ret->next;
    }
}