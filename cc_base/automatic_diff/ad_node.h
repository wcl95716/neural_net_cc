//
// Created by Panda on 2021/7/8.
//

#ifndef TEST_CC_PRO_AD_NODE_H
#define TEST_CC_PRO_AD_NODE_H

#include <vector>

using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
class AdNode {
    double value;
    double dvalue;
    double value3 = 1;

    //倒序方向
    vector< shared_ptr<AdNode> > last_node_ptr;
    //正序方向
    vector< weak_ptr<AdNode> > next_node_ptr;

public:
    friend shared_ptr<AdNode>  operator+(shared_ptr<AdNode>  x , shared_ptr<AdNode>  y);
    friend shared_ptr<AdNode>  operator-(shared_ptr<AdNode>  x , shared_ptr<AdNode>  y);
    friend shared_ptr<AdNode>  operator*(shared_ptr<AdNode>  x , shared_ptr<AdNode>  y);

    friend shared_ptr<AdNode> sin(shared_ptr<AdNode> x);
    friend shared_ptr<AdNode> cos(shared_ptr<AdNode> x);
    friend shared_ptr<AdNode> ln(shared_ptr<AdNode> x);

    friend  void double_node_link(shared_ptr<AdNode> x, shared_ptr<AdNode> y);
    friend void tree_node_link( shared_ptr<AdNode>   x ,  shared_ptr<AdNode>   y , shared_ptr<AdNode>   nextNode);
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
