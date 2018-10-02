////////////////////////////////////////////////////////////
//  Created by Yuki Koyama.                               //
//  Copyright (c) 2012 Yuki Koyama. All rights reserved.  //
//  http://www-ui.is.s.u-tokyo.ac.jp/~koyama/             //
//                                                        //
//  This is released for NON-COMMERCIAL use only.         //
////////////////////////////////////////////////////////////

#pragma once

class Channel {
    typedef int Index;
public:
    enum ChannelEnum {
        X_ROTATION, Y_ROTATION, Z_ROTATION,
        X_POSITION, Y_POSITION, Z_POSITION,
    };
    Index          joint;
    ChannelEnum    type;
    Index          index;
};
