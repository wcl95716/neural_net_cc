//
// Created by Panda on 2021/6/21.
//

#include "basic_head.h"
using std::swap;

//需要进行第一次建立
BasicHead::BasicHead(vector<int> &input_arr) {
	//产生一次复制 不伤害原有结构
	this->head_arr_ = input_arr;
	this->head_arr_.push_back(this->head_arr_[0]);
	for (int i = (head_arr_.size() - 1) / 2; i >= 1; --i) {
		down(i);
	}
}

void BasicHead::addNum(int x) {
	head_arr_.push_back(x);
	up(head_arr_.size() - 1);
}

void BasicHead::delTop() {
	head_arr_[1] = head_arr_.back();
	head_arr_.pop_back();
	down(1);
}
int BasicHead::getTop() {
	return head_arr_[1];
}

//向上调整
void BasicHead::up(int index, bool (*cmp)(int &, int &)) {
	while (index > 1) {
		int dad = index >> 1;
		if (cmp(head_arr_[index], head_arr_[dad])) {
			swap(head_arr_[index], head_arr_[dad]);
			index = dad;
		} else {
			break;
		}
	}
}
//向下调整
void BasicHead::down(int index, bool (*cmp)(int &, int &)) {
	while (index < head_arr_.size()) {
		int son1 = index << 1;
		int son2 = son1 | 1;
		int nex = son1;
		if (son1 >= head_arr_.size()) {
			break;
		}
		if (son2 < head_arr_.size() && !cmp(head_arr_[son1], head_arr_[son2])) {
			nex = son2;
		}
		if (!cmp(head_arr_[index], head_arr_[nex])) {
			swap(head_arr_[index], head_arr_[nex]);
			index = nex;
		} else {
			break;
		}
	}
}


