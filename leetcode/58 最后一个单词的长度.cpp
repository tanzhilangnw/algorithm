//����һ���ַ��� s�������ɵ�����ɣ�����ǰ����һЩ�ո��ַ������������ַ��������һ�����ʵĳ��ȡ�
//
//���� ��ָ������ĸ��ɡ��������κοո��ַ���������ַ�����
//1 <= s.length <= 104
//s ����Ӣ����ĸ�Ϳո� ' ' ���
//s �����ٴ���һ������

class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.size() - 1;

        while (s[index] == ' ') {
            index--;
        }
        int wordLength = 0;
        while (index >= 0 && s[index] != ' ') {
            wordLength++;
            index--;
        }

        return wordLength;
    }
};
