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

void double_node_link(shared_ptr<AdNode> x, shared_ptr<AdNode> y) {
    y->last_node_ptr.push_back(x);
    x->next_node_ptr.push_back(y);
}

shared_ptr<AdNode>   sin(shared_ptr<AdNode>  x) {
    shared_ptr<AdNode>  sinNode = make_shared<AdNode>();
    sinNode->value = std::sin(x->value);
    sinNode->dvalue = std::cos(x->value) * x->dvalue;
    double_node_link(x, sinNode);
    return sinNode;
}

shared_ptr<AdNode> cos(shared_ptr<AdNode> x) {
    shared_ptr<AdNode>  cosNode = make_shared<AdNode>();
    cosNode->value = std::cos(x->value);
    cosNode->dvalue = -std::sin(x->value) * x->dvalue;
    double_node_link(x, cosNode);
    return cosNode;
}

shared_ptr<AdNode> ln(shared_ptr<AdNode> x){
    shared_ptr<AdNode>   lnNode = make_shared<AdNode>();
    lnNode->value = std::log(x->value);
    lnNode->dvalue = x->dvalue / x->value;
    double_node_link(x, lnNode);
    return lnNode;
}

void tree_node_link( shared_ptr<AdNode>   x ,  shared_ptr<AdNode>   y , shared_ptr<AdNode>   nextNode){
    x->next_node_ptr.push_back(nextNode);
    y->next_node_ptr.push_back(nextNode);
    nextNode->last_node_ptr.push_back(x);
    nextNode->last_node_ptr.push_back(y);
}

shared_ptr<AdNode>  operator+(shared_ptr<AdNode>  x , shared_ptr<AdNode>  y){
    shared_ptr<AdNode>   next_node = make_shared<AdNode>();
    (next_node)->value =x->value + y->value;
    (next_node)->dvalue =   x->dvalue +  y->dvalue; // product rule
    tree_node_link(x , y , next_node);
    return next_node;
}

shared_ptr<AdNode>  operator-(shared_ptr<AdNode>  x , shared_ptr<AdNode>  y){
    shared_ptr<AdNode>   next_node = make_shared<AdNode>();
    (next_node)->value =x->value - y->value;
    (next_node)->dvalue =   x->dvalue -  y->dvalue; // product rule
    tree_node_link(x , y , next_node);
    return next_node;
}
shared_ptr<AdNode>  operator*(shared_ptr<AdNode>  x , shared_ptr<AdNode>  y){
    shared_ptr<AdNode>   next_node = make_shared<AdNode>();
    (next_node)->value =x->value * y->value;
    (next_node)->dvalue =  y->value *  x->dvalue + x->value *  y->dvalue; // product rule
    tree_node_link(x , y , next_node);
    return next_node;
}

#include "iostream"

using namespace std;

int main() {
    shared_ptr<AdNode> x1 = make_shared<AdNode>(2,1);
    shared_ptr<AdNode> x2 = make_shared<AdNode>(5,0);
    shared_ptr<AdNode> y = x1*x2 * x1 *x2 ;

    cout << y->getValue() << ' ' << y->getDvalue() << endl;

}
