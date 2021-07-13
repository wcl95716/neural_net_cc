//Created by Panda on 2021/7/8.
#include "ad_node.h"
#include <cmath>
#include <iostream>


AdNode::AdNode() {}

AdNode::AdNode(double v, double d) {
    value = v;
    dvalue = d;
}

AdNode::~AdNode() {
    std::cout<<"释放node " <<' '<<value <<' '<<dvalue<<std::endl;
}

void double_node_link(AdNode &x, AdNode &y) {                                                                                         
    y.last_node.push_back(&x);
    x.next_node.push_back(&y);
}

AdNode &  sin(AdNode &x) {
    AdNode &sinNode = *new AdNode();
    sinNode.value = std::sin(x.value);
    sinNode.dvalue = std::cos(x.value) * x.dvalue;
    double_node_link(x, sinNode);
    return sinNode;
}

AdNode & cos(AdNode &x) {
    AdNode &cosNode = *new AdNode();
    cosNode.value = std::cos(x.value);
    cosNode.dvalue = -std::sin(x.value) * x.dvalue;
    double_node_link(x, cosNode);
    return cosNode;
}

AdNode & ln(AdNode &x) {
    AdNode &lnNode = *new AdNode();
    lnNode.value = std::log(x.value);
    lnNode.dvalue = x.dvalue / x.value;
    x.next_node.push_back(&lnNode);
    double_node_link(x, lnNode);
    return lnNode;
}

void AdNode::tree_node_link(AdNode &nextNode, AdNode &otherNode) {

    this->next_node.push_back(&nextNode);
    otherNode.next_node.push_back(&nextNode);
    nextNode.last_node.push_back(&otherNode);
    nextNode.last_node.push_back(this);
}

AdNode &AdNode::operator*(AdNode &x) {
    AdNode *y = new AdNode();
    (*y).value = value * x.value;
    (*y).dvalue = x.value * dvalue + value * x.dvalue; // product rule
    tree_node_link(*y, x);
    return *y;
}

AdNode &AdNode::operator-(AdNode &x) {
    AdNode *y = new AdNode();
    (*y).value = value - x.value;
    (*y).dvalue = dvalue - x.dvalue; // product rule
    tree_node_link(*y, x);
    return *y;
}

AdNode &AdNode::operator+(AdNode &x) {
    AdNode *y = new AdNode();
    (*y).value = value + x.value;
    (*y).dvalue = dvalue + x.dvalue; // product rule
    tree_node_link(*y, x);
    return *y;
}


#include "iostream"

using namespace std;

int main() {
    AdNode x1 = AdNode(2, 1);
    AdNode x2 = AdNode(5, 0);

    AdNode y =  x1 + x2 + x1;

    cout << y.getValue() << ' ' << y.getDvalue() << endl;

}
