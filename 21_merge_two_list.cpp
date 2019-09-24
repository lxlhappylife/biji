/*
  将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
  
*/

/*
	将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
*/
#include <iostream>

using namespace std;

struct listnode {
	int val;
	struct listnode * next;
}; 

/*递归解法怎么弄*/
listnode * merge_list(listnode * listtable1, listnode* listtable2){
	if (listtable1 == NULL) {
		return listtable2;
	} else if (listtable2 == NULL) {
		return listtable1;
	} else if (listtable1->val < listtable2->val) {
		merge_list(listtable1->next, listtable2);
		return listtable1;
	} else {
		merge_list(listtable1, listtable2->next);
		return listtable2;
	}
}

struct listnode* mergeTwoLists(struct listnode* l1, struct listnode* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    struct listnode newhead, *p1, *p2;
    newhead.next = l1;
    l1 = &newhead;
    
    while(l2 != NULL) {
        p1 = l1->next;
        p2 = l2->next;
        if(p1 == NULL) {
            l1->next = l2;
            break;
        }
        if(l2->val <= p1->val) {
            l2->next = l1->next;
            l1->next = l2;
            l2 = p2;
        }
        l1 = l1->next;
    }
    return newhead.next;
}


int main()
{
	struct listnode *head, *p, *temp, *p1, *head1;
	int number = 1;
	head = new (struct listnode);
	p = head;
	for (int index = 0; index < 10; index++) {
		
		p->next = new (struct listnode);
		p->next->val = index;
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


	head1 = new (struct listnode);
	p1 = head1;
	for (int index = 0; index < 10; index++) {
		
		p1->next = new (struct listnode);
		p1->next->val = index;
		p1 = p1->next;
		//p = p->next;
		//p->next = NULL;
		p1->next = NULL;
	}
	//p->next - NULL;
	p1 = head1->next;
	while (p1) { 
		cout << p1->val << " ";
		p1 = p1->next;
	}
	cout << endl;

	temp = mergeTwoLists(head, head1);

	while (temp->next) {
		cout << temp->next->val << "  ";
		temp = temp->next;
	}


	return 0;
}
