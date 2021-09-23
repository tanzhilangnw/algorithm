//给你一个头结点为 head 的单链表和一个整数 k ，请你设计一个算法将链表分隔为 k 个连续的部分。
//
//每部分的长度应该尽可能的相等：任意两部分的长度差距不能超过 1 。这可能会导致有些部分为 null 。
//
//这 k 个部分应该按照在链表中出现的顺序排列，并且排在前面的部分的长度应该大于或等于排在后面的长度。
//
//返回一个由上述 k 部分组成的数组。
//
//链表中节点的数目在范围[0, 1000]
//0 <= Node.val <= 1000
//1 <= k <= 50


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* tmp = head;
        while (tmp != nullptr) {
            tmp = tmp->next;
            len++;
        }
        int seplen = len / k, remain = len % k;
        vector <ListNode*> res(k, nullptr);
        ListNode* cur = head;
        for (int i = 0; i < k && cur != nullptr; i++)
        {
            res[i] = cur;
            int lsize = seplen + (i < remain ? 1 : 0);
            for (int j = 1; j < lsize; j++)
            {
                cur = cur->next;
            }
            ListNode* next = cur->next;
            cur->next = nullptr;
            cur = next;
        }
        return res;
    }
};