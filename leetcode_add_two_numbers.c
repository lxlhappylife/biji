/*
  问题：
  两个数据，用list逆序存储单个位数，最后想加后，依然以list输出。
 
  输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
  输出：7 -> 0 -> 8
  原因：342 + 465 = 807
*/

/*
  思路：
  定义两个数据结构list；从最低位开始遍历想加，注意进位和结束判断。
*/
// Source : https://oj.leetcode.com/problems/add-two-numbers/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 
* You are given two linked lists representing two non-negative numbers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
* 
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*               
**********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}    //结构体构造函数
};

class Solution {
    
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int x=0, y=0, carry=0, sum=0;
        ListNode *h=NULL, **t=&h;
        
        while (l1!=NULL || l2!=NULL){
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);
            
            sum = carry + x + y;
            
            ListNode *node = new ListNode(sum%10);
            *t = node;
            t = (&node->next);
            
            carry = sum/10;
        }
        
        if (carry > 0) {
            ListNode *node = new ListNode(carry%10);
            *t = node;
        }
        
        return h;
    }
private:
    int getValueAndMoveNext(ListNode* &l){
        int x = 0;
        if (l != NULL){
            x = l->val;
            l = l->next;
        }
        return x;
    }
};

int main()
{
	struct ListNode Node1 = ListNode(2);
	struct ListNode Node2 = ListNode(4);
	struct ListNode Node3 = ListNode(3);

	Node1.next = &Node2;
	Node2.next = &Node3;
	
	struct ListNode *list = &Node1;
	/*
	while (list) {
		cout << list->val << " ";
		if(list->next)
			list = list->next;
		else
			break;
	}
	cout << endl;
	*/
	struct ListNode Node4 = ListNode(5);
	struct ListNode Node5 = ListNode(6);
	struct ListNode Node6 = ListNode(4);

	Node4.next = &Node5;
	Node5.next = &Node6;

	struct ListNode *list2 = &Node4;
	/*
	while (list2) {
		cout << list2->val << " ";
		if (list2->next) {
			list2 = list2->next;
		} else {
			break;
		}
	}
	cout << endl;
	*/
	class Solution SL;
	struct ListNode * list_result = SL.addTwoNumbers(list, list2);

	while (list_result) {
		cout << list_result->val;
		if (list_result->next) {
			list_result = list_result->next;
		} else {
			break;
		}
	}

	cout << endl;

	return 0;
}
