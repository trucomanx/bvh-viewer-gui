////////////////////////////////////////////////////////////
//  Created by Yuki Koyama.                               //
//  Copyright (c) 2012 Yuki Koyama. All rights reserved.  //
//  http://www-ui.is.s.u-tokyo.ac.jp/~koyama/             //
//                                                        //
//  This is released for NON-COMMERCIAL use only.         //
////////////////////////////////////////////////////////////

#pragma once

#include <map>
#include "Joint.h"
#include "Channel.h"

class BVHObject {
    typedef int                 Index;
    typedef std::vector<double> Pose;
    
public:
    std::vector<Joint>   joints;
    std::vector<Channel> channels;
    std::vector<Pose>    motion;
    
    std::map<std::string, Index> jointNameToIndex;
    
    double       interval;
    int          nFrames;     // equal to motion.size()
    int          nChannels;   // equal to channels.size();
    bool         ready;
    std::string  name;
    
    bool         renderingJoint;
    bool         renderingBone;
    
    void clear();
    void init(std::string fileName);
    void render(int frameNum);
    
    BVHObject();
    ~BVHObject();
private:
    void renderJoint(Index joint, Pose pose);
    void renderBone(Vector3d position0, Vector3d position1);
};
