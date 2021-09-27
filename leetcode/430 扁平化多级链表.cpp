//�༶˫�������У�����ָ����һ���ڵ��ǰһ���ڵ�ָ��֮�⣬������һ��������ָ�룬����ָ�򵥶���˫��������Щ���б�Ҳ���ܻ���һ�������Լ�������������ƣ����ɶ༶���ݽṹ���������ʾ����ʾ��
//����λ���б��һ����ͷ�ڵ㣬�����ƽ���б�ʹ���н������ڵ���˫�����С�

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        function<Node* (Node*)> dfs = [&](Node* node) {
            Node* cur = node;
            // ��¼��������һ���ڵ�
            Node* last = nullptr;

            while (cur) {
                Node* next = cur->next;
                //  ������ӽڵ㣬��ô���ȴ����ӽڵ�
                if (cur->child) {
                    Node* child_last = dfs(cur->child);

                    next = cur->next;
                    //  �� node �� child ����
                    cur->next = cur->child;
                    cur->child->prev = cur;

                    //  ��� next ��Ϊ�գ��ͽ� last �� next ����
                    if (next) {
                        child_last->next = next;
                        next->prev = child_last;
                    }

                    // �� child ��Ϊ��
                    cur->child = nullptr;
                    last = child_last;
                }
                else {
                    last = cur;
                }
                cur = next;
            }
            return last;
        };

        dfs(head);
        return head;
    }
};