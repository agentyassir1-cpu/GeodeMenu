#include "ConfigNode.hpp"

bool ConfigNode::init()
{
    if (!SubCategoryNode::init())
        return false;

    this->setID("Config");

    addSubCategory("Button");

    return true;
}
