//
// Created by Panda on 2021/6/21.
//

#ifndef CC_CODEBASE_BASIC_HEAD_H
#define CC_CODEBASE_BASIC_HEAD_H

#include <vector>
using std::vector;

/**
 * 实现简单的堆
 */
class BasicHead {

 private:
	vector<int> head_arr_;
	//空堆
	static bool GetMin(int &x, int &y) {
		return x < y;
	}
	static bool GetMax(int &x, int &y) {
		return x > y;
	}
	//向下维护
	void down(int, bool (*p)(int &, int &) = &GetMin);
	//向上维护
	void up(int, bool (*p)(int &, int &) = &GetMin);
 public:
	BasicHead() {
		head_arr_.push_back(0);
	}
	~BasicHead() {
	}
	//需要进行第一次建立
	BasicHead(vector<int> &input_arr);

	//insert new  number
	void addNum(int x);
	//del top new number
	void delTop();
	int getTop();
};

#endif //CC_CODEBASE_BASIC_HEAD_H


