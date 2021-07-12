#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<vector>

using namespace std;


 
struct ListNode 
{  
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* root = nullptr;

    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    ListNode* temp;

    int mod = 0;
    int div = 0;

    while(temp1 != nullptr && temp2 != nullptr)
    {
        int val = temp1->val + temp2->val + div;

        mod = val%10;
        div = val/10;

        if(root == nullptr)
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

    while(temp1 != nullptr)
    {
        int val = temp1->val + div;

        mod = val%10;
        div = val/10;

        temp1 = temp1->next;

        temp->next = new ListNode(mod);
        temp = temp->next;
    }

    while(temp2 != nullptr)
    {
        int val = temp2->val + div;

        mod = val%10;
        div = val/10;

        temp2 = temp2->next;

        temp->next = new ListNode(mod);
        temp = temp->next;
    }

    if(div != 0)
    {
        temp->next = new ListNode(div);
    }

    return root;
}

ListNode* removeElements(ListNode* head, int val)
{
    ListNode* temp = head;
    ListNode* prev = temp;

    while(temp)
    {
        if(temp->val == val)
        {
            if(temp == prev)
            {
                prev = prev->next;

                head = head->next;

                temp = temp->next;
            }

            else if(temp->next == nullptr)
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

void deleteNode(ListNode* node)
{
    ListNode* temp = node;
    ListNode* prev;

    while(temp->next)
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
    ListNode* slow = head;
    ListNode* fast = head;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }

    return false;
}

ListNode *detectCycle(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    bool loop = false;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            loop = true;
            break;
        }
    }

    if(!loop)
        return nullptr;

    slow = head;

    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

bool isPalindrome(ListNode* head)
{
    vector<int> v;

    ListNode* temp = head;

    while(temp)
    {
        v.push_back(temp->val);

        temp = temp->next;
    }

    int len = v.size();

    for(int i=0;i<len;i++)
    {
        if(v[i] != v[len-i-1])
            return false;
    }

    return true;
}

ListNode* reverseList(ListNode* head)
{
    vector<int> v;

    ListNode* temp = head;

    while(temp)
    {
        v.push_back(temp->val);

        temp = temp->next;
    }

    int len = v.size();

    ListNode* reverse = nullptr;
    ListNode* current = nullptr;

    for(int i=len-1;i>=0;i--)
    {
        if(reverse == nullptr)
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

    unordered_map<ListNode*, int> map;

    ListNode* tempA = headA;
    ListNode* tempB = headB;

    while(tempA)
    {
        map[tempA] = tempA->val;

        tempA = tempA->next;
    }

    while(tempB)
    {
        if(map.find(tempB) != map.end())
            return tempB;

        map[tempB] = tempB->val;

        tempB = tempB->next;
    }

    return nullptr;
}

ListNode* deleteDuplicates2(ListNode* head)
{
    //keep one occurrence of repeating element

    ListNode* temp = head;
    ListNode* first = head;

    while(temp)
    {
        if(first->val != temp->val)
        {
            first->next = temp;
            first = temp;
        }
        
        temp = temp->next;
    }

    if(first != temp)
        first->next = nullptr;

    return head;
}


ListNode* deleteDuplicates(ListNode* head)
{
    //keep none of repeating elements
    //cant solve yet :(

    map<int, int> map;

    ListNode* temp = head;

    while(temp)
    {
        map[temp->val]++;
        temp = temp->next;
    }

    ListNode* dummy = new ListNode(0);
    temp = dummy;

    for(auto i : map)
    {
        if(i.second == 1)
        {
            temp->next = new ListNode(i.first);
            temp = temp->next;
        }
    }

    return dummy->next;
}



ListNode* swapPairs(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)
        return head;

    ListNode* temp = head;

    while(temp && temp->next)
    {
        int t = temp->val;
        temp->val = temp->next->val;
        temp->next->val = t;

        temp = temp->next->next;
    }


    return head;
}

ListNode* swapNodes(ListNode* head, int k)
{
    int len = 0;
    ListNode* temp = head;
    ListNode* k_from_begin = nullptr;

    while(temp)
    {
        len++;

        if(len == k)
        {
            k_from_begin = temp;
        }

        temp = temp->next;
    }

    temp = head;
    for(int i=0;i<len-k;i++)
    {
        temp = temp->next;
    }

    swap(k_from_begin->val, temp->val);

    return head;
}

int main()
{   
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(4);
    l1->next->next->next->next->next = new ListNode(6);


    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);

    //cout<<hasCycle(l1);


    //l2->next->next = new ListNode(4);

    //ListNode* ret = addTwoNumbers(l1, l2);

    //ListNode* ret = removeElements(l1, 1);

    //cout<<length(l2);
    ListNode * ret = deleteDuplicates(l1);

    // deleteNode(l1->next->next);

    while(ret)
    {
        cout<<ret->val<<" ";
        ret = ret->next;
    }
}