#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    struct Status {
        int val;
        ListNode* ptr;
        bool operator < (const Status& rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue<Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto i : lists)
        {
            if (i) q.push({ i->val, i });
        }
        ListNode head, * tail = &head;
        while (!q.empty())
        {
            auto j = q.top();
            q.pop();
            tail->next = j.ptr;
            tail = tail->next;
            if (j.ptr->next) {
                q.push({j.ptr->next->val, j.ptr->next});
            }
        }
        return head.next;
    }
    
};

int main()
{
    int n;
    cin >> n;
    vector<ListNode*> lists;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        ListNode head, *p = &head;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            ListNode t;
            t.val = a;
            p->next = &t;
            p = p->next;
        }
        lists.push_back(&head);
    }
    Solution *sol = new Solution();
    ListNode* result = sol->mergeKLists(lists);
    
    while (result)
    {
        cout << result->val;
        result = result->next;
    }
    return 0;
}