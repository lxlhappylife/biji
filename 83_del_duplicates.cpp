/*
  给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

*/
/*
	给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

	注意是给定的排序链表。所以不用每次都遍历整个链表。
*/
#include <iostream>

using namespace std;

struct listnode {
	int val;
	struct listnode * next;
};

class Solution {
public:
	listnode * del_dump(listnode * head) {   //返回链表的头节点。
		listnode * p = head;

		while (p && p->next) {
			if (p->val == p->next->val) { //需要进行删除
				p->next = p->next->next;   //???这个地方需要对节点进行free吗？貌似存在内存泄漏哈
			} else { //不相同了，往后遍历
				p = p->next;
			}
		}
		return head;
	}
};

int main()
{
	struct listnode *head, *p, *temp;
	int number = 1;
	head = new (struct listnode);
	p = head;
	for (int index = 0; index < 10; index++) {
		
		p->next = new (struct listnode);
		p->next->val = 10;
		p = p->next;
		//p = p->next;
		//p->next = NULL;
		p->next = NULL;
	}
	//p->next - NULL;
	p = head->next;
	while (p) { 
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	class Solution SL;
	struct listnode *result = SL.del_dump(head);

	p = result->next;

	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}
