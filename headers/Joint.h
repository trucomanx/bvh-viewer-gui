////////////////////////////////////////////////////////////
//  Created by Yuki Koyama.                               //
//  Copyright (c) 2012 Yuki Koyama. All rights reserved.  //
//  http://www-ui.is.s.u-tokyo.ac.jp/~koyama/             //
//                                                        //
//  This is released for NON-COMMERCIAL use only.         //
////////////////////////////////////////////////////////////

#pragma once

#include <vector>
#include <string>
#include "Vector3.h"


class BVHObject;

class Joint {
    typedef int Index;
    
public:
    std::string          name;
    Index                index;
    Index                parent;        // if no parent, - 1
    std::vector<Index>   children;
    Vector3d             offset;
    bool                 hasSite;
    Vector3d             site;
    std::vector<Index>   channels;
};
