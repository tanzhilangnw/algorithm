//����һ��ͷ���Ϊ head �ĵ������һ������ k ���������һ���㷨������ָ�Ϊ k �������Ĳ��֡�
//
//ÿ���ֵĳ���Ӧ�þ����ܵ���ȣ����������ֵĳ��Ȳ�಻�ܳ��� 1 ������ܻᵼ����Щ����Ϊ null ��
//
//�� k ������Ӧ�ð����������г��ֵ�˳�����У���������ǰ��Ĳ��ֵĳ���Ӧ�ô��ڻ�������ں���ĳ��ȡ�
//
//����һ�������� k ������ɵ����顣
//
//�����нڵ����Ŀ�ڷ�Χ[0, 1000]
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