/*
	第一种：蛮力法
	时间复杂度为O（n2）
*/
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> two_sum(vector<int>& nums, int sum)
{
	vector<int> result;
	for (int index = 0; index < nums.size(); index++) {
		for (int j = index + 1; j < nums.size(); j++) {
			if(nums[index] + nums[j] == sum) {
				result.push_back(index);
				result.push_back(j);	
				return result;
			}
		} 
	}
	return result;
}

/*
	元素与索引对应关系表示采用：哈希表。这是一种空间换时间的做法，能够降低时间复杂度。
	构建键值对

	在C++中，哈希表是unordered_map。哈希表的特点就是查找快。
	unordered_map的函数：
	find：指向键等于 key 的元素的迭代器。若找不到这种元素，则返回尾后（见 end() ）迭代器。
	end：指向后随最后元素的迭代器。
*/

vector<int> two_sum_hash(vector<int> & nums, int sum)
{
	unordered_map<int,int> record;   //构建hash表
	for (int i = 0; i < nums.size(); i++) {
		int com = sum - nums[i];
		if (record.find(com) != record.end()) {   //找到相应的元素
			int res[] = {i, record[com]};    //数组初始化
			cout << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << " " << res[4] << endl;
			cout << sizeof(res) << i << record[com] << endl;
			return std::vector<int>(res,res+2);     //vector赋值。   这个地方为什么是res+2？
			/*
				vector的初始化，将res到res+2指定的两个元素拷贝到vector中。vector初始化的一种做法。
			*/
			//return std::vector<int>(i, record[com]);
		}
		record[nums[i]] = i;
	}
}

/*
	C语言实现hash表
*/

struct hash_data
{
	int key;
	int data;
	struct hash_data *next;
};

struct hash_table
{
	int hash_len;
	struct  hash_data ** head;    //这个地方得双指针
};

int hash_init(struct hash_table *table, int len)
{
	//输入参数校验
	if (len < 0) {
		return -1;
	}
	//申请内存，存放数据
	struct hash_data **tmp = malloc(sizeof(struct hash_data *) * len);
	if (tmp == NULL) {
		return -1;
	}
	table->head = tmp;
	memset(table->head, 0, sizeof(struct hash_data *) * len);
	table->hash_len = len;
	return 0;
}

void hash_free(struct hash_table table)
{
	for (int index; index < table.hash_len; index++) {
		struct hash_data * temp = table.head[i];
		while(temp){
			struct hash_data *temp_free = temp;
			temp = temp->next;
			free(temp_free);
		}
	}
	free(table.head);
	table.head = NULL;
	table.hash_len = 0;
}

struct hash_data* hash_find()
{

}

int hash_insert()
{

}


//散列函数是怎么确定的

int main()
{
	std::vector<int> v;
	v.push_back(5);
	v.push_back(19);
	v.push_back(10);
	v.push_back(2);
	std::vector<int> result;

	result = two_sum_hash(v,29);
	if(result.size() == 0) {
		cout << "can not find the sum index" << endl;
		return 0;
	}
	cout << result[0] << result[1] << endl;
	return 1;
}
