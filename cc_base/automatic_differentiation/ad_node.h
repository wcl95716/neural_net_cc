//
// Created by Panda on 2021/7/8.
//

#ifndef TEST_CC_PRO_AD_NODE_H
#define TEST_CC_PRO_AD_NODE_H

#include <vector>

using std::vector;

class AdNode {
    double value;
    double dvalue;
    double value3 = 1;
    //倒序方向
    vector<AdNode *> last_node;
    //正序方向
    vector<AdNode *> next_node;

    //倒序方向
    vector<std::shared_ptr<AdNode> > last_node_ptr;
    //正序方向
    vector<std::shared_ptr<AdNode> > next_node_ptr;
public:

    AdNode &operator+(AdNode &x);
    AdNode &operator-(AdNode &x);
    AdNode &operator*(AdNode &x);

    friend AdNode &sin(AdNode &x);
    friend AdNode &cos(AdNode &x);
    friend AdNode &ln(AdNode &x);

    void friend double_node_link(AdNode &x, AdNode &y);
    void tree_node_link(AdNode &nextNode, AdNode &otherNode);
    AdNode(double v, double d);

    AdNode();

    ~AdNode();


    double getValue() const {
        return value;
    }

    double getDvalue() const {
        return dvalue;
    }


};


#endif //TEST_CC_PRO_AD_NODE_H
